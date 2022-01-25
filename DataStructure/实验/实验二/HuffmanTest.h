/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-23 15:21:19
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-28 16:59:10
 * @FilePath: \work\DSExperiment\DSE2\HuffmanTest.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File: HuffmanTest.h
    哈夫曼测试
*/

// #pragma
#include <iostream>
#include <cstring>
#include "z_Huffman.h"

void HuffmanTest()
{
    char sc[] = "The Chinese official said he viewed the TrumpPresidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States, and Western democracies in general, haven't risen to the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure";
    // char str[] = "";
    cout << sc << '\n';
    int len = 0;
    char s[MAXSIZE] = {};
    int w[MAXSIZE] = {};
    cout << "\n# Statistical data: #\n";
    CodeCalcu(sc, s, w, len);
    for (int i = 0; i < strlen(s); i++)
        cout << s[i] << ' ' << w[i] << '\n';
    z_huffman zpx(s, w, len);
    zpx.z_huffTree();
    zpx.z_huffCode();
    zpx.z_displayHfCode();
    zpx.z_show(sc);
    cout << '\n';
}