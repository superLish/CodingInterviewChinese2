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

/*
思路一：
1. 每打印一个元素后，都要判断是否需要顺时针转向（也就是说你要知道什么时候要转向）
2. 什么时候停（可以采用计数的方法，到达矩阵的总数的时候，就停）
3. 特殊情况，比如只有一个元素，矩阵只有一行或者一列的情况

思路一比较难以实现，考虑实现思路二

思路二： 
1. 每次只打印矩阵的最外圈，第二次打印的时候，传入新的矩阵（去掉原有矩阵的最外圈）
2. 当矩阵行或者列出现0行或者0列的时候，结束。
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
void print_matrix_outer_circle(int** matrix, const int columns, const int rows) {
    assert(matrix != nullptr && columns > 0 && rows > 0);
    const int ccol = columns - 1;
    const int crow = rows -1;
    int r = 0;
    int c = 0;
    int stop = number_of_matric_circle(columns, rows);
    while (stop > 0) {
        int number = matrix[r][c];
        printNumber(number);
        --stop;

        if (0 == r && c < ccol) {
            ++c;
            continue;
        }

        if (ccol == c && r < crow) {
            ++r;
            continue;
        }

        if (crow == r && c > 0) {
            --c;
            continue;
        }

        if (0 == c && r > 0) {
            --r;
            continue;
        }
    }

}


// 每次打印一圈，然后剥掉最外圈，成为一个新的矩阵，再打印
void print_matrix_clockwisely(int** matrix, int columns, int rows) {
    cout << "matrix poiinter: " << matrix << endl;
    
    assert(matrix != nullptr && columns > 0 && rows > 0);
    int i = 0;
    int j = 0;
    while (columns > 0 && rows > 0) {
        print_matrix_outer_circle(matrix, columns, rows);
        columns = columns - 2;
        rows = rows - 2;
        matrix = matrix;
        cout << "matrix poiinter: " << matrix << endl;

    }
}



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
    for(int i = start; i <= endX; ++i)
    {
        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; ++i)
        {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; --i)
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一行
    if(start < endX && start < endY - 1)
    {
        for(int i = endY - 1; i >= start + 1; --i)
        {
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

