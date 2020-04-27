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

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

#include <cstdio>
#include<iostream>
#include<cassert>
using namespace std;


// ��ķ����� ���� ʱ�临�Ӷ�O(n^2), ���Ƽ�
int dupltcate_detect(const int* a, const int len) {
    assert(a != nullptr && len > 1);
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (a[i] == a[j]) 
                return a[i];
        }
    }

    return -1;
}

// ��û�и���һ����㷨�أ���Ŀ�����ᵽ��һ������Ϊn�������У����е����ֶ���[0,u-1]��Χ�ڣ�Ӧ��Ӧ����һ���������Ľ��㷨��
// ˼·�е�����Ͱ���򣬻���bloom�������� ʱ�临�Ӷ�O(n)
int duplicate_find(const int* a, const int len) {
    assert(a != nullptr && len > 1);
    // todo: �������ƺϷ��Լ�飬�������ֶ���[0,n-1]��Χ��
    bool flag[len] = {false};
    for (int i = 0; i < len; ++i) {
        if (flag[a[i]] == false) {
            flag[a[i]] = true;
        } else {
            return a[i];
        }
    }

    return -1;
}


// ���������Ȼ������Ĵ�����΢����һ�㣬������һ���ô����ǿռ临�Ӷȱ������С������Ŀռ临�Ӷ�O(n)�������O(1)��O(1)�Ĵ������ƻ���ԭ�����ݣ�ʱ�临�Ӷ���ͬ
// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
bool duplicate(int numbers[], int length, int* duplication) {
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i = 0; i < length; ++i) {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    // ��Ҫ˼·��: �������е�Ԫ���ų�����a����i=a[i]����ʽ
    for(int i = 0; i < length; ++i) {
        while(numbers[i] != i) {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            // ����numbers[i]��numbers[numbers[i]]             
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

// ====================���Դ���====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// �ظ�����������������С������
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

void test7() {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int v = dupltcate_detect(numbers, sizeof(numbers)/sizeof(int));
    cout << "test7 : " << v << endl;
}

void test8() {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int v = duplicate_find(numbers, sizeof(numbers)/sizeof(int));
    cout << "test8 : " << v << endl;
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

    return 0;
}