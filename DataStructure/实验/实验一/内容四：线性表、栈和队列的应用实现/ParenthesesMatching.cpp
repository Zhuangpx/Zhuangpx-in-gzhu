/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-12 20:51:33
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-13 01:32:11
 * @FilePath: \work\DSExperiment\DSE1\E4\ParenthesesMatching.cpp
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File : ParenthesesMatching.cpp
    ParenthesesMatching();
    ~ParenthesesMatching();
    bool IsMatching();
*/

#include "ParenthesesMatching.h"
using namespace std;

ParenthesesMatching::ParenthesesMatching()
{
    /*
    (  [  {    )  ]  }
    0  1  2    5  6  7
    */
    /*
    用哈希表存下三种括号匹配情况：
    记括号字符映射的整数，当二者差为5匹配成功，当二者差小于3为同边不同级括号，否则为不同变括号
    */
    for (int i = 0; i < 3; i++)
    {
        Matching[LeftParentheses[i]] = i;
    }
    for (int i = 5; i < 8; i++)
    {
        Matching[RightParentheses[i - 5]] = i;
    }
}

ParenthesesMatching::~ParenthesesMatching() {}

bool ParenthesesMatching::IsMatching(const string& s)
{
    z_stack z_s;    //  临时栈
    for (int i = 0; i < s.size(); ++i)
    {
        if (z_s.z_empty() || (abs(Matching[z_s.z_top()] - Matching[s[i]]) <= 2 && Matching[s[i]] < 3))  //  情况一：栈为空或栈顶和当前括号同边
        {
            z_s.z_push(s[i]);
        }
        else if (Matching[s[i]] - Matching[z_s.z_top()] == 5) //  情况二：栈顶与当前匹配
        {
            z_s.z_pop();
        }
        else
        {
            return false;   //  情况三：不匹配
        }
    }
    if (z_s.z_empty())    //  判最后是否剩余
        return true;
    else
        return false;
}
