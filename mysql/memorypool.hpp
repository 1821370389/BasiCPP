#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

// #define NodeSize 8
// #define MemoryBlockSize 1024
#define MEMORYPOOL(T, count) void* operator new(size_t size)        \
{                                                                   \
    std::cout << "重载new" << std::endl;                            \
    return MemoryPool<sizeof(T), count>::GetInstance()->malloc();   \
}                                                                   \
void operator delete(void *p)                                       \
{                                                                   \
    std::cout << "重载deletel" << std::endl;                        \
    MemoryPool<sizeof(T), count>::GetInstance()->free(p);           \
}                                                                   \

/*
    内存池
    不同的内存池可以实现不同的功能
    如：小块内存池，大块内存池
    小块内存池：
        一次性申请多个小块内存
        一次性释放多个小块内存
    大块内存池：
        一次性申请多个大块内存
        一次性释放多个大块内存
*/

template<int NodeSize, int MemoryBlockSize>
class MemoryPool
{
public:
    /* 单例 */
    static MemoryPool *GetInstance()
    {
        static MemoryPool instance;
        return &instance;
    }

    void* malloc();
    void free(void* p);

    ~MemoryPool()
    {
        std::cout << "内存池析构函数" << std::endl;
        NodeHeader = nullptr;
        while(BlockHeader)
        {
            MemoryBlock *tmp = BlockHeader;
            BlockHeader = BlockHeader->next;
            delete tmp;
        }
    }



private:
    MemoryPool()
    {
        NodeHeader = nullptr;
        BlockHeader = nullptr;
    }

private:
    /* 小块内存节点 */
    union FreeNode          // 联合体
    {
        char data[NodeSize];
        FreeNode *next;     // 嵌入式指针
    };
    /* 内存块 */
    struct MemoryBlock
    {
        FreeNode Node[MemoryBlockSize];
        MemoryBlock *next;
    };
    
    FreeNode *NodeHeader;
    MemoryBlock *BlockHeader;
    
};

/* 申请内存 */
template<int NodeSize, int MemoryBlockSize>
void *MemoryPool<NodeSize, MemoryBlockSize>::malloc()
{
    /* 没空闲节点:扩容 */
    if (NodeHeader == nullptr)
    {
        MemoryBlock *newBlock = new MemoryBlock;   // 申请新的大块内存块
        newBlock->next = BlockHeader;
        BlockHeader = newBlock;

        for (int i = 0; i < MemoryBlockSize; i++)
        {
            newBlock->Node[i].next = NodeHeader;
            NodeHeader = &newBlock->Node[i];
        }

        // for(int idx = 0; i < MemoryBlockSize - 1; i++)
        // {
        //     newBlock->Node[i].next = &newBlock->Node[i+1];
        // }
        // newBlock->Node[MemoryBlockSize - 1].next = nullptr;
        // /* 头插 */
        // newBlock->next = BlockHeader;
        // BlockHeader = newBlock;
        // NodeHeader = &newBlock->Node[0];    // 把大内存第一个节点地址给NodeHeader
    }
    FreeNode *node = NodeHeader;
    NodeHeader = NodeHeader->next;
    memset(node, 0, NodeSize);
    return node;

}
/* 释放内存 */
template<int NodeSize, int MemoryBlockSize>
void MemoryPool<NodeSize, MemoryBlockSize>::free(void *p)
{
    FreeNode *node = static_cast<FreeNode *>(p);
    memset(node, 0, NodeSize);
    node->next = NodeHeader;
    NodeHeader = node;
}



