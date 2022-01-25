/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-22 20:08:02
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-28 00:14:10
 * @FilePath: \work\DSExperiment\DSE2\BTreeTest.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File: BTreeTest.h
    二叉树测试
*/

#pragma
#include <iostream>
#include <cstring>
#include "z_BinaryTree.h"

void BTreeTest()
{
    char str[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    z_binaryTree<char> px;
    px.z_initBTree(str);
    cout << "Display:\n";
    px.z_display(px.root);
    cout << '\n';
    char c = 'H';
    char l, r;
    px.z_getLeftChild(c, l);
    px.z_getRightChild(c, r);
    cout << c << " : LeftChild = " << l << " ; RightChile = " << r << '\n';
    cout << "Node sum:" << px.z_getNodeNum() << " ; Leaf Node Sum:" << px.z_getLeafNodeNum() << " ; Degree:" << px.z_getDegree() << " ; Depth:" << px.z_getDepth(px.root) << '\n';
    cout << "Pre:\n";
    px.z_preTraRecu(px.root);
    cout << '\n';
    px.z_preTraNonRecu();
    cout << '\n';
    cout << "In:\n";
    px.z_inTraRecu(px.root);
    cout << '\n';
    px.z_inTraNonRecu();
    cout << '\n';
    cout << "Post:\n";
    px.z_postTraRecu(px.root);
    cout << '\n';
    px.z_postTraNonRecu();
    cout << '\n';
    cout << "Thread:\n";
    px.z_inThread(px.root);
    cout << "Root is :" << px.root->data << " ; It's pre:" << px.z_getRootInPre() << " ; next:" << px.z_getRootInNext() << '\n';
}
