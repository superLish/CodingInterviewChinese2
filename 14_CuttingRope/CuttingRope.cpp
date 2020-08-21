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
解决这个问题的难点在于怎么去分割绳子，因为分割绳子有很多中方法，怎么分割能保证程序有结束的时候。
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

    // 这里其实是由下到上分割绳子
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
解决这个问题，最好是有一定的数学基础，有一个算数基本定理， 有助于理解下面的贪婪算法
【算数基本定理（整数的唯一分解定理）】任何大于1的整数n可表示成有限个（可重复）素数的乘积，而且不计乘积中因子顺序时分解还是唯一的。

在这个问题中，对于任意整数长度的n，都可以分解为有限个素数的乘积，而大于3的素数都可以用2和3表示，为什么呢？
因为素数一定是奇数，而2和3可以表示所有的奇数，也即能表示所有的素数。所以，n就可以被表示为有限个3和有限个2的相加。

还有一个证明，一根绳子围成一个矩形，当矩形为正方形时面积最大，这个可以自己列式子证明，a+b=n  y = a*b = a*(n-a) = -a^2 + na，
这个式子当a=n/2时，y取得最大值，所以有上面的结论。

*/
// ====================贪婪算法====================
int maxProductAfterCutting_solution2(int length) {
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    // 尽可能多地减去长度为3的绳子段
    int timesOf3 = length / 3;

    // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
    // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
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

// 动态规划的解法如果比较难理解，下面这种利用递归的解法，比较容易理解一些，利用product记录了长度为n的最大分解值，
// 利用递归不断的分割绳子，当然这种易于理解的代价就是性能是3种方法中最差的。
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


// ====================测试代码====================
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
