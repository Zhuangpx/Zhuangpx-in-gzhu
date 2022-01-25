/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-12 20:43:46
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 01:23:44
 * @FilePath: \work\DSExperiment\DSE1\E4\ParenthesesMatching.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : ParenthesesMatching.h
*/

#pragma once
#include <iostream>
#include <string>
#include <map>
#include "z_stack.h"
using namespace std;

class ParenthesesMatching
{
public:
    ParenthesesMatching();            //  构造函数
    ~ParenthesesMatching();           //  析构函数
    bool IsMatching(const string &s); //  匹配函数
private:
    char LeftParentheses[3] = {'(', '[', '{'};  //  左括号
    char RightParentheses[3] = {')', ']', '}'}; //  右括号
    map<char, int> Matching;                    //  哈希表
    /*
    匹配情况（根据哈希值）
    (  [  {    )  ]  }
    0  1  2    5  6  7
    */
};

typedef ParenthesesMatching PM;
