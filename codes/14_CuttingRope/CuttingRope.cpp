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

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

/*
向这种最优化问题，一般可以考虑动态规划解决
*/
// ====================动态规划====================
int maxProductAfterCutting_solution1(int length) {
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    // 由下向上计算，是为了减少重复计算
    int max = 0;
    for(int i = 4; i <= length; ++i) {
        max = 0;
        for(int j = 1; j <= i / 2; ++j) {
            int product = products[j] * products[i - j];
            if(max < product)
                max = product;

            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;
}

/*
这个问题，还可以用数学的方法解决，而且这种方法是最高效的，难点在于数学证明，要证明这种方法是正确的。

数学证明： 当n>=5时， 有2(n-2)>n及3(n-3)>n成立，即，当绳子剩下的长度大于等于5的时候，我们应该还要继续剪成长度为2或3的绳子。
并且，3(n-3)>=2(n-2)，也就是说，我们应该尽可能多剪长度为3的绳子。

*/
// ====================贪婪算法====================
int maxProductAfterCutting_solution2(int length) {
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    // 尽可能的剪成3
    int timesOf3 = length / 3;

    if(length - timesOf3 * 3 == 1)
        timesOf3 -= 1;

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
}

void divided(int length, int* product) {
    if (length < 3)
        return;

    for (int i = 2; i <= length / 2; ++i) {
        divided(length-i, product);
        int p = product[i] * product[length-i];
        if (p > product[length]) {
            product[length] = p;
        }
    }
}

// 这种方法好理解，但是效率却是最差的
int maxProductAfterCutting_solution3(int length) {
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int product[length + 1];
    for (int i = 0; i < length + 1; ++i) {
        product[i] = i;
    }

    divided(length, product);


    return product[length];
}


void test(const char* testName, int length, int expected) {
    int result1 = maxProductAfterCutting_solution1(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;

    int result3 = maxProductAfterCutting_solution3(length);
    if(result3 == expected)
        std::cout << "Solution3 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution3 for " << testName << " FAILED." << std::endl;
}

void test1() {
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2() {
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3() {
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4() {
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5() {
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6() {
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7() {
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8() {
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9() {
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10() {
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11() {
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    cout << endl << "test done." << endl;

    return 0;
}
