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

// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

void printNumber(int number);

//-------------------实现一--------------------------

/*
思路： 
1. 一圈一圈的打印
2. 计算出打印几圈，可以用行列最小的值决定，circul = min(r, c) / 2 + min(r,c) % 2
3. 特殊情况，比如只有一个元素，矩阵只有一行或者一列的情况
*/

// 返回r*c矩阵最外圈元素数量
const int number_of_matric_circle(const int c, const int r) {
    assert(c > 0 && r > 0);

    if (1 == c) {
        return r;
    }

    if (1 == r) {
        return c;
    }

    return c*r - (c-2)*(r-2);
}

// 顺时针打印矩阵的最外圈，只打印一圈
void print_matrix_outer_circle(int** matrix, const int columns, const int rows, const int start) {
    assert(matrix != nullptr && columns > 0 && rows > 0 && start >= 0);
    const int cEdgecol = columns - start - 1;   
    const int cEdgerow = rows - start - 1;
    int r = start;
    int c = start;
    int stop = number_of_matric_circle(columns - 2*start, rows - 2*start);
    while (stop > 0) {
        int number = matrix[r][c];
        printNumber(number);
        --stop;

        if (start == r && c < cEdgecol) {
            ++c;
            continue;
        }

        if (cEdgecol == c && r < cEdgerow) {
            ++r;
            continue;
        }

        if (cEdgerow == r && c > start) {
            --c;
            continue;
        }

        if (start == c && r > start) {
            --r;
            continue;
        }
    }
}


// 一圈一圈的打印，计算出要打几圈
void print_matrix_clockwisely(int** matrix, int columns, int rows) {
    assert(matrix != nullptr && columns > 0 && rows > 0);
    int start = 0;
    int c = columns;
    int r = rows;
    int min = std::min(columns, rows);
    int count = min/2 + min % 2;
    for (int start = 0; start < count; ++start) {
        print_matrix_outer_circle(matrix, columns, rows, start);
    }
}


//----------------实现二----------------------------

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);


void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;

    int start = 0;

    while(columns > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(numbers, columns, rows, start);

        ++start;
    }
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印一行
    for(int i = start; i <= endX; ++i)    {
        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列
    if(start < endY) {
        for(int i = start + 1; i <= endY; ++i) {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if(start < endX && start < endY) {
        for(int i = endX - 1; i >= start; --i) {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一行
    if(start < endX && start < endY - 1) {
        for(int i = endY - 1; i >= start + 1; --i) {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void printNumber(int number) {
    printf("%d\t", number);
}

// ====================测试代码====================
void Test(int columns, int rows) {
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j) {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    // PrintMatrixClockwisely(numbers, columns, rows);
    print_matrix_clockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main() {
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}

