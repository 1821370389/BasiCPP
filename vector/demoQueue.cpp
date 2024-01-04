#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <stdio.h>

#define BUFFER_SIZE 5

int main()
{
    queue<int> q;

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        q.push(idx);
    }
    printf("size: %d\n", (int)q.size());
    while(!q.empty())
    {
        printf("%d\n", q.front());
        q.pop();
    }
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/* 层序遍历 */
vector<vector<int>> LevelOrder(TreeNode* root)
{
    if (!root) 
    {
        return {}; // 如果根节点为空，返回空的二维数组
    }

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    TreeNode* travelNode = NULL;

    while (!q.empty()) 
    {
        int size = q.size();
        vector<int> levelValues; // 存储当前层的节点值
        for (int idx = 0; idx < size; idx++) 
        {
            travelNode = q.front();
            q.pop();
            levelValues.push_back(travelNode->val);
            if (travelNode->left) 
            {
                q.push(travelNode->left);
            }
            if (travelNode->right) 
            {
                q.push(travelNode->right);
            }
        }
        res.push_back(levelValues); // 将当前层的节点值添加到结果中
    }
    return res;
}