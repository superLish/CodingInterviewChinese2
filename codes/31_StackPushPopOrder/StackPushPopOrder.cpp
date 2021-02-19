/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <cstdio>
#include <stack>
#include <cassert>

// 想这个问题的时候，一开始很难有思路，其实就是根据弹出序列，检查按压入顺序，是否存在合法的压入弹出操作相匹配。

//-------------实现一-----------------------
bool stack_match(const int* pPush, const int* pPop, const int n) {
    assert(pPush != nullptr && pPop != nullptr && n > 0);
    // bool is_match = true;
    int i_pop = 0;
    int i_push = 0;
    std::stack<int> m_stack;        // 辅助栈

    while (i_pop < n && i_push < n) {
        
        while (i_push < n && pPop[i_pop] != pPush[i_push]) {  // 先按弹出序列， 比对入栈序列，如果不匹配就压栈
            m_stack.push(pPush[i_push]);
            ++i_push;
            if (n == i_push) 
                return false;
        }
        
        ++i_pop;        // 过滤掉匹配的元素， 找到匹配的元素后，接着++i_pop找弹出序列的下一个元素是否匹配   
        ++i_push;

        while (!m_stack.empty() && m_stack.top() == pPop[i_pop]) {
            m_stack.pop();
            ++i_pop;
        }
    }

    if (i_push == n && i_pop == n)
        return true;
    else
        return false;        
}



bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
    bool bPossible = false;

    if(pPush != nullptr && pPop != nullptr && nLength > 0) {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;

        while(pNextPop - pPop < nLength) {
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while(stackData.empty() || stackData.top() != *pNextPop) {
                // 如果所有数字都压入辅助栈了，退出循环
                if(pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);

                pNextPush ++;
            }

            if(stackData.top() != *pNextPop)
                break;

            stackData.pop();
            pNextPop ++;
        }

        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }

    return bPossible;
}

// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected) {
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7() {
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

