### CodingInterviewChinese2
《剑指Offer》第二版源代码, Fork from [zhedahht/CodingInterviewChinese2](https://github.com/zhedahht/CodingInterviewChinese2)。

代码运行环境Linux，在学习与思考其实现时，添加了一些自己的理解与其他实现的代码。所有题目代码索引如下

[面试题1：赋值运算符函数](./codes/01_AssignmentOperator/AssignmentOperator.cpp)           
[面试题2：实现单例模式](./codes/02_Singleton/singleton.cpp)                  
[面试题3：找出数组中重复的数字](./codes/03_DuplicationInArray)        
[面试题4：二维数组中的查找](./codes/04_FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp)           
[面试题5：替换空格](./codes/05_ReplaceSpaces/ReplaceSpaces.cpp)           
[面试题6：从尾到头打印链表](./codes/06_PrintListInReversedOrder/PrintListInReversedOrder.cpp)             
[面试题7：重建二叉树](./codes/07_ConstructBinaryTree/ConstructBinaryTree.cpp)         
[面试题8：二叉树的下一个结点](./codes/08_NextNodeInBinaryTrees/NextNodeInBinaryTrees.cpp)             
[面试题9：用两个栈实现队列](./codes/09_QueueWithTwoStacks/QueueWithTwoStacks.cpp)             
[面试题10：斐波那契数列](./codes/10_Fibonacci/Fibonacci.cpp)              
[面试题11：旋转数组的最小数字](./codes/11_MinNumberInRotatedArray/MinNumberInRotatedArray.cpp)            
[面试题12：矩阵中的路径](./codes/12_StringPathInMatrix/StringPathInMatrix.cpp)            
[面试题13：机器人的运动范围](./codes/13_RobotMove/RobotMove.cpp)          
[面试题14：剪绳子](./codes/14_CuttingRope/CuttingRope.cpp)——动态规划              
[面试题15：二进制中1的个数](./codes/15_NumberOf1Binary/NumberOf1InBinary.cpp)         
[面试题16：数值的整数次方](./codes/16_Power/Power.cpp)            
[面试题17：打印1到最大的n位数](./codes/17_Print1ToMaxOfNDigits/Print1ToMaxOfNDigits.cpp)          
[面试题18：01.在O(1)时间删除链表结点](./codes/18_01_DeleteNodeInList/DeleteNodeInList.cpp)            
[面试题18: 02.删除链表中重复的结点](./codes/18_02_DeleteDuplicatedNode/DeleteDuplicatedNode.cpp)          
[面试题19：正则表达式匹配](./codes/19_RegularExpressionsMatching/RegularExpressions.cpp)          
[面试题20：表示数值的字符串](./codes/20_NumericStrings/NumericStrings.cpp)            
[面试题21：调整数组顺序使奇数位于偶数前面](./codes/21_ReorderArray/ReorderArray.cpp)          
[面试题22：链表中倒数第k个结点](./codes/22_KthNodeFromEnd/KthNodeFromEnd.cpp)         
[面试题23：链表中环的入口结点](./codes/23_EntryNodeInListLoop/EntryNodeInListLoop.cpp)            
[面试题24：反转链表](./codes/24_ReverseList/ReverseList.cpp)          
[面试题25：合并两个排序的链表](./codes/25_MergeSortedLists/MergeSortedLists.cpp)          
[面试题26：树的子结构](./codes/26_SubstructureInTree/SubstructureInTree.cpp)                  
[面试题27：二叉树的镜像](./codes/27_MirrorOfBinaryTree/MirrorOfBinaryTree.cpp)            
[面试题28：对称的二叉树](./codes/28_SymmetricalBinaryTree.cpp)          
[面试题29：顺时针打印矩阵](./codes/29_PrintMatrix/PrintMatrix.cpp)          
[面试题30：包含min函数的栈](./codes/30_MinInStack/StackWithMin.h)
[面试题31：栈的压入、弹出序列](./codes/31_StackPushPopOrder/StackPushPopOrder.cpp)           
[面试题32：打印二叉树(不分行从上往下/分行从上到下打印二叉树/之字形打印二叉树)](./codes/32_PrintTree)         
[面试题33：二叉搜索树的后序遍历序列](./codes/33_SquenceOfBST/SquenceOfBST.cpp)                    
[面试题34：二叉树中和为某一值的路径](./codes/34_PathInTree/PathInTree.cpp)           
[面试题35：复杂链表的复制](./codes/35_CopyComplexList)


---
### 总结

1. 有很多问题，刚开始一看，比较复杂，一时不知道怎么解决？但往往复杂问题是可以分解为有限个子问题，而子问题是比较容易解决的。或者说是这么一种解题思想，当问题比较复杂时，我们往往可以分析一下，是否可以**将问题进行分解，分解为若干已解决的问题**，这样复杂问题就有解了。     

2. 有一些问题，如果能用数学的方法解决，往往效率是最高的，计算机擅长遍历枚举的方式解决问题，但这样的代价就是效率往往不是很高。数学的方法解决需要对数学比较敏感，并不是所有问题都可以找到数学的解决方式。比较典型的就是[面试题14：剪绳子](./14_CuttingRope)这个问题，如果用动态规划解的话，效率较低，但如果用数学的方法去解，则是最高效的。但是自己要证明这么解是正确的。

3. 关于效率的问题？怎么提高代码执行效率，或者说性能，一个很重要的思路就是分析当前代码有没有重复计算的问题，如果有，想办法**减少重复计算**，效率一定会提升，但代价也许是空间的开销增大，需要针对具体问题具体进行权衡。其中提升性能的一个思路就是**空间换时间**。

4. **防御性编程**，增加程序代码的鲁棒性。这是很好的一种编程习惯。要十分注意一些边界条件，这些边界条件也是测试的重点项。

5. 如果你解决一个问题的时间复杂度是`O(N^2)`，你可能需要想一下，是否有优化的办法能降下来，将为`O(Nlog(N))`，再降为`O(N)`，就非常好了，如果能直接降为`O(1)`，往往是利用数学的办法，直接去解。