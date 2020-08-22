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

// ������15����������1�ĸ���
// ��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ���������
// ��9��ʾ�ɶ�������1001����2λ��1������������9���ú������2��

#include <cstdio>
#include <cmath>
using namespace std;


int NumberOf1_Solution1(int n) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (n & flag)
            count++;

        flag = flag << 1;       // �ƶ�flag��int�͹��ƶ�32��
    }

    return count;
}

// ���ֱȽ����뵽�� ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ߵ�1���0
int NumberOf1_Solution2(int n) {
    int count = 0;

    while (n) {
        ++count;
        n = (n - 1) & n;
    }

    return count;
}

// �������뵽�Ľⷨ����Ȼ������Ҳ�����ġ�
int NumberOf1_Solution3(int number) {
    int n = number;
    if (0 == number) {
        return 0;
    }

    int count = 0;
    if (n < 0) {
        n = std::abs(n);
        ++count;
    }

    if (number > 0) {
        while(number > 0) {
            if (number & 1 == 1) {
                ++count;
            } 
            number = number >> 1;
        }
    }

    return count;
}

// ====================���Դ���====================
void Test(int number, unsigned int expected) {
    int actual = NumberOf1_Solution1(number);
    if (actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    actual = NumberOf1_Solution3(number);
    if (actual == expected)
        printf("Solution3: Test for %p passed.\n", number);
    else
        printf("Solution3: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[]) {
    // ����0���ڴ��������0
    Test(0, 0);

    // ����1���ڴ��������1
    Test(1, 1);

    // ����10���ڴ��������2
    Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    Test(0x80000000, 1);

    return 0;
}

