[课程地址]()


#### 函数题

**01-复杂度3 二分查找**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1211848231062290434)

[C++ solution](./01/f1.cpp)

**02-线性结构1 两个有序链表序列的合并**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285952)

[C++ solution](./02/f2.cpp)

**04-树7 二叉搜索树的操作集**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590403)

[C++ solution](./03-05/f3.cpp)

***
#### 编程题

**01-复杂度1 最大子列和问题**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1211848231062290432)

[C++ solution](./01/ex1.cpp)

**01-复杂度2 Maximum Subsequence Sum**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1211848231062290433)

[C++ solution](./01/ex2.cpp)


**02-线性结构2 一元多项式的乘法与加法运算**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285953)

[C++ solution](./02/ex3.cpp)

**02-线性结构3 Reversing Linked List**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285954)

[C++ solution](./02/ex4.cpp)

[取巧方法：将有效节点存数组里逆序输出](./02/ex4_2.cpp)

~~最大N,最后剩K-1不反转 测例运行超时~~(已解决)
```c++
//反转模板
ptr lreverse(ptr head, int k)
{
    int cnt = 1;
	now = head->next;
    old = now->next;
    while(cnt < k)
    {
        tmp = old->next;
        old->next = now;
        now = old;
        old = tmp;
        cnt++;
    }
    head->next->next = old;
    return now;   
}
```
**02-线性结构4 Pop Sequence**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1231458941036285955)

[C++ solution](./02/ex5.cpp)

**03-树1 树的同构**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373040824320)

[C++ solution](./03-05/ex6.cpp)

**03-树2 List Leaves**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373045018624)

[C++ solution](./03-05/ex7.cpp)

**03-树3 Tree Traversals Again**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1234055373045018625)

[C++ solution1](./03-05/ex8.cpp):根据入栈出栈序列建树，然后对树进行后序遍历
[参考](https://github.com/Heliovic/PAT_Solutions/blob/master/1086/main.cpp)

[C++ solution2](./03-05/ex8_3.cpp):根据入栈顺序得到先序序列，出栈序列得到中序序列，由先序，中序推出后序
[参考](https://github.com/liuchuo/PAT/blob/master/AdvancedLevel_C%2B%2B/1086.%20Tree%20Traversals%20Again%20(25)%20.cpp)

**04-树4 是否同一棵二叉搜索树**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590400)

[C++ solution](./03-05/ex9.cpp)


**04-树5 Root of AVL Tree**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590401)

[C++ solution](./03-05/ex10.cpp)


**04-树6 Complete Binary Search Tree**

[问题描述](https://pintia.cn/problem-sets/1211841066264109056/problems/1236509430527590402)

[C++ solution]()

****

[问题描述]()

[C++ solution]()

****

[问题描述]()

[C++ solution]()

****

[问题描述]()

[C++ solution]()

****

[问题描述]()

[C++ solution]()
