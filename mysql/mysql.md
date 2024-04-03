# mysql 服务器型数据库

1. 能够远程连接
2. 需要登陆，更加安全
3. 但会变得更重

## mysql语句

1. 显示数据库 show databases;
2. 创建数据库 create database if not exists`数据库名`;
3. 删除数据库 drop database`数据库名`;
4. 使用数据库 use `数据库名`;
5. 建表 create table if not exists `表名`(`表头` `类型` , `表头` `类型`);
6. 删除表 drop table `表名`；
7. 查看表头 desc `表名`;
8. 显示当前数据库的表 show tables;
9. 插入数据 insert into `表名` value (`数据`);
10. 删除数据 delete from `表名` where "`条件`";
11. 修改数据 update `表名` set `列名` where `条件`；
12. 创建索引/改变表的结构 alter tbale `表名` add index `索引名`(列名);
13. 查看索引: show index from `表名`;
14. 删除索引: drop index `索引名` on `表名`;
15. 显示事务(已自动提交为例)：show variables like 'autocommit';
16. 关闭事务(同上)：set autocommit = 0;
17. 回滚操作：rollback;
18. 提交操作：commit;

## 索引

对数据表的排序的一种数据结构: 排序树
主键会被自动添加为唯一索引

### 优缺点

优点:

1. 查找效率高
2. 排序速度更快

缺点:

1. 额外的物理空间占用
2. 插入和删除增加了维护的成本, 频繁的增删会降低效率

### 什么时候构建索引？

1. 经常查找的字段
2. 经常排序的字段
3. 唯一且不会经常修改的字段(主键)

## 事务

多条语句的集合, 要么都成功, 要么都失败
目的: 保证数据库数据的完整性

### 特点

1. 原子性：要么一起成功，要么一起失败
2. 一致性：数据库的处理结果符合预期
3. 隔离性：事务和事务之间互不相干
4. 持久性：事务做出的数据处理结果应该是能长久保存的

### 隐式事务

语句执行完毕, 自动提交修改

```
set autocommit = 0;
rollback; 回滚
commit; 提交
set autocommit = 1;
```

### 显示事务

start transaction; 开始事务

start transaction read only; 只读事务    提高数据库操作的效率。

### 事务在并发中出现的问题

1. 脏读数据：读到未提交的事务数据
2. 不可重复读：读到已经提交的被修改的数据
3. 幻读

### 隔离界别

1. 读未提交：会产生脏读
2. 读已提交：会产生不可重复读
3. 可重复读：会产生幻读
4. 串行

## MySQL API

(C接口)

```shell
apt install libmysqlclient-dev
```

## mysql连接池

原因：mysql客户端频繁连接服务器导致效率低下

实现原理：
