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

// 面试题2：实现Singleton模式
// 题目：设计一个类，我们只能生成该类的一个实例。

#include<iostream>
using namespace std;

class Singleton {
public:
    ~Singleton(){}
    static Singleton* GetInstance() {
       static Singleton s = Singleton{};
       return &s;
    }

    void print() {
        cout << "singleton instance print info." << endl;
    }

// 单例模式关键是这里，不能通过构造函数来生成实例，要将其限定为private或者protected.
private:
    Singleton(){}

};


int main() {
    Singleton *a = Singleton::GetInstance();
    a->print();

    // Singleton *b = new Singleton();  

/*   如果上面的一条语句不注释掉，会报下面的编译错误。  
singleton.cpp: In function ‘int main()’:
singleton.cpp:43:34: error: ‘Singleton::Singleton()’ is private within this context
     Singleton *b = new Singleton();
                                  ^
singleton.cpp:34:5: note: declared private here
     Singleton(){}
*/
    return 0;
}