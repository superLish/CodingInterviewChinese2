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

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include <cstdio>
#include <string>
#include <stack>
#include <memory.h>

using namespace std;

bool hasPathCore1(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);
/* 
* matrix: 表示字符矩阵
* rows, cols: 矩阵的行列数
* str: 待查找的字符串  */
bool hasPath(const char* matrix, int rows, int cols, const char* str) {
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    bool *visited = new bool[rows * cols];  //因为不能再次进入已经过的格子，所以需要将已路过的格子做标记
    memset(visited, 0, rows * cols);

    // 遍历所有的格子
    int pathLength = 0;
    for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
            if(hasPathCore1(matrix, rows, cols, row, col, str, pathLength, visited)) {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

// 检测从某一格子开始，是否有匹配的字符路径  , 递归实现
bool hasPathCore1(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited) {
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col]) {
        ++pathLength;
        visited[row * cols + col] = true;

        // 检测邻格子有无相匹配的
        hasPath = hasPathCore1(matrix, rows, cols, row, col - 1, str, pathLength, visited)
               || hasPathCore1(matrix, rows, cols, row - 1, col, str, pathLength, visited)
               || hasPathCore1(matrix, rows, cols, row, col + 1, str, pathLength, visited)
               || hasPathCore1(matrix, rows, cols, row + 1, col, str, pathLength, visited);

        if(!hasPath) {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}

// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected) {
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1() {
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2() {
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3() {
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4() {
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5() {
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6() {
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7() {
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8() {
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9() {
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10() {
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11() {
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12() {
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}


/*
// 判断，某一格子的邻节点是否有匹配的，如有，返回true并返回匹配节点的位置
bool isMatch(const char* matrix, int rows, int cols, int row, int col, char s, int* _row, int* _col, bool* visited) {
    if (row - 1 >= 0 && !visited[(row-1)*col + col] && matrix[(row-1)*col + col] == s) {
        *_row = row - 1;
        visited[(row-1)*col + col] = true;
        return true;
    }

    if (row + 1 <= rows && !visited[(row+1)*col + col] && matrix[(row+1)*col + col] == s) {
        *_row = row + 1;
        visited[(row+1)*col + col] = true;
        return true;
    }

    if (col - 1 >= 0 && !visited[row*(col-1) + col - 1] && matrix[row*(col-1) + col - 1] == s) {
        *_col = col - 1;
        visited[row*(col-1) + col - 1] = true;
        return true;
    }

    if (col + 1 <= cols && !visited[row*(col+1) + col + 1] && matrix[row*(col+1) + col + 1] == s) {
        *_col = col + 1;
        visited[row*(col+1) + col + 1] = true;
        return true;
    }

    return false;
} 

// fixme: 这个问题有点类似于深度优先搜索， 用递归的方法实现最简单 
// 检测从某一格子开始，是否有匹配的字符路径 
bool hasPathCore2(const char* matrix, int rows, int cols, int row, int col, const char* str, int pathLength, bool* visited) {
    char s = str[pathLength];
    char c = matrix[row * col + col];
    if (s != c) {
        return false;
    } 

    visited[row * col + col] = true;
    int _row = row;
    int _col = col;
    for (int i = pathLength + 1; i < strlen(str); ++i) {
        s = str[i];
        if (!isMatch(matrix, rows, cols, _row, _col, s, &_row, &_col, visited)) {
            return false;
        }
    }

    return true;
}

*/
