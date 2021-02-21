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

// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <cstdio>
#include "ComplexList.h"
#include<vector>
#include<iostream>
using namespace std;


#define MY


// 第一种思路，先复制主链，再赋值sibling。  解决这个问题的关键在配对这个过程，后面一种实现思路很巧妙的利用链表本身解决了配对问题，算法效率最忧
#ifdef MY

ComplexListNode* NodeClone(ComplexListNode* pNode) {
    ComplexListNode* copy = CreateNode(pNode->m_nValue);
    copy->m_pSibling = pNode;
    return copy;
}



ComplexListNode* Clone(ComplexListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;

    // 1. Clone 主链
    ComplexListNode* pNewHead = NodeClone(pHead);
    ComplexListNode* pPrev = pNewHead;
    ComplexListNode* pCur1 = pHead->m_pNext;
    while (pCur1 != nullptr) {
        ComplexListNode* copy = NodeClone(pCur1);
        pPrev->m_pNext = copy;
        pPrev = copy;
        pCur1 = pCur1->m_pNext;
    }    

    // 2. 新旧节点地址结对, 这里也可以用哈希表
    std::vector<std::pair<ComplexListNode*, ComplexListNode*>> m_vector;
    ComplexListNode* pCur2 = pNewHead;
    while(pCur2 != nullptr) {
        auto pair = std::make_pair(pCur2->m_pSibling, pCur2);
        m_vector.push_back(pair);
        pCur2 = pCur2->m_pNext;
    }

    // for (auto p : m_vector) {
    //     cout << "<" << p.first->m_nValue << ", " << p.second->m_nValue << ">  "; 
    // }

    // 3. 赋值m_pSibling
    ComplexListNode* pNewCur = pNewHead;
    ComplexListNode* pOldCur = pHead;
    while (pOldCur != nullptr) {
        ComplexListNode* pSib = pOldCur->m_pSibling;

        ComplexListNode* pNewSib = nullptr;
        for (auto p : m_vector) {
            if (p.first == pSib) {
                pNewSib = p.second;
                break;
            }
        }
        pNewCur->m_pSibling = pNewSib;

        pOldCur = pOldCur->m_pNext;
        pNewCur = pNewCur->m_pNext;
    }

    return pNewHead;
}

#endif


#ifndef MY
void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;
 
        pNode->m_pNext = pCloned;
 
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
 
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;
 
    if(pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
 
    while(pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
 
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
 
    return pClonedHead;
}
#endif

// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead) {
    printf("\n");
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1() {
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2() {
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3() {
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4() {
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5() {
    Test("Test5", nullptr);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

