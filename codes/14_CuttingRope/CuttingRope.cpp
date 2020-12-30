/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��

#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

/*
���������Ż����⣬һ����Կ��Ƕ�̬�滮���
*/
// ====================��̬�滮====================
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

    // �������ϼ��㣬��Ϊ�˼����ظ�����
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
������⣬����������ѧ�ķ���������������ַ��������Ч�ģ��ѵ�������ѧ֤����Ҫ֤�����ַ�������ȷ�ġ�

��ѧ֤���� ��n>=5ʱ�� ��2(n-2)>n��3(n-3)>n����������������ʣ�µĳ��ȴ��ڵ���5��ʱ������Ӧ�û�Ҫ�������ɳ���Ϊ2��3�����ӡ�
���ң�3(n-3)>=2(n-2)��Ҳ����˵������Ӧ�þ����ܶ������Ϊ3�����ӡ�

*/
// ====================̰���㷨====================
int maxProductAfterCutting_solution2(int length) {
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    // �����ܵļ���3
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

// ���ַ�������⣬����Ч��ȴ������
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
