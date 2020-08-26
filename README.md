### CodingInterviewChinese2
《剑指Offer》第二版源代码, Fork from [zhedahht/CodingInterviewChinese2](https://github.com/zhedahht/CodingInterviewChinese2)。

代码运行环境Linux，在学习与思考其实现时，添加了一些自己的理解与其他实现的代码。所有题目索引如下

[面试题1：赋值运算符函数](./01_AssignmentOperator)  

[面试题2：实现单例模式](./02_Singleton)             

[面试题3：找出数组中重复的数字](./03_DuplicationInArray)

[面试题4：二维数组中的查找](./04_FindInPartiallySortedMatrix)

[面试题5：替换空格](./05_ReplaceSpaces)

[面试题6：从尾到头打印链表](./06_PrintListInReverseOrder)

[面试题7：重建二叉树](./07_COnstructBinaryTree)

[面试题8：二叉树的下一个结点](./08_NextNodeInBinaryTrees)

[面试题9：用两个栈实现队列](./09_QueueWithTwoStacks)

[面试题10：斐波那契数列](./10_Fibonacci)

[面试题11：旋转数组的最小数字](./11_MinNumberInRotatedArray)

[面试题12：矩阵中的路径](./12_StringPathInMatrix)

[面试题13：机器人的运动范围](./13_RobotMove)

[面试题14：剪绳子](./14_CuttingRope)——动态规划

[面试题15：二进制中1的个数](./15_NumberOfBinary)

[面试题16：数值的整数次方](./16_Power)

[面试题17：打印1到最大的n位数](./17_Print1ToMaxOfNDigits)

[面试题18：01.在O(1)时间删除链表结点](./18_01_DeleteNodeInList)

[面试题18: 02.删除链表中重复的结点](./18_02_DeleteDuplicatedNode)

### 思路总结

1. 有很多问题，刚开始一看，比较复杂，一时不知道怎么解决？但往往复杂问题是可以分解为有限个子问题，而子问题是比较容易解决的。或者说是这么一种解题思想，当问题比较复杂时，我们往往可以分析一下，是否可以将问题进行分解，分解为若干已解决的问题，这样复杂问题就有解了。     

2. 有一些问题，如果能用数学的方法解决，往往效率是最高的，计算机擅长遍历枚举的方式解决问题，但这样的代价就是效率往往不是很高。数学的方法解决需要对数学比较敏感，并不是所有问题都可以找到数学的解决方式。比较典型的就是[面试题14：剪绳子](./14_CuttingRope)这个问题，如果用动态规划解的话，效率较低，但如果用数学的方法去解，则是最高效的。但是自己要证明这么解是正确的。

3. 关于效率的问题？怎么提高代码执行效率，或者说性能，一个很重要的思路就是分析当前代码有没有重复计算的问题，如果有，想办法减少重复计算，效率一定会提升，但代价也许是空间的开销增大，需要针对具体问题具体进行权衡。