/*
 * @Autor: violet apricity ( Zhuangpx )
 * @Date: 2021-11-15 16:18:52
 * @LastEditors: violet apricity ( Zhuangpx )
 * @LastEditTime: 2021-11-28 02:07:50
 * @FilePath: \work\DSExperiment\DSE2\z_BinaryTree.h
 * @Description:  Zhuangpx : Violet && Apricity:/ The warmth of the sun in the winter /
 */

/*
    File: z_BinaryTree.h
    包含z_binaryTree类，实现了二叉树链式存储的类包装，由于本地编辑器和种种原因，此处一同将函数定义和声明在头文件中给出。
*/

// #pragma
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

// const int MAXSIZE = 0x3f3f3f;
// 最大节点规模
#ifndef MAXSIZE
#define MAXSIZE 1000
#endif

template <class T>
class z_binaryTree //  二叉树(二叉链式存储)
{
public:
    struct Node //  节点结构体
    {
        T data;                  //  数据域
        bool lflag = 0;          //  线索化左标记=>标记左子是否表示前继节点
        bool rflag = 0;          //  线索化右标记=>标记右子是否表示后序节点
        struct Node *leftChild;  //  左子节点
        struct Node *rightChild; //  右子节点
    };

    // z_binaryTree();                              //构造函数
    // z_binaryTree(char str[]);                    //构造函数

    ~z_binaryTree() { z_deleteBTree(); } //析构函数=>调用二叉树删除函数

    void z_deleteBTree(); //删除函数=>删除二叉树

    void z_initBTree(char str[]); //初始化函数=>利用字符串表示法初始化二叉树

    bool z_find(const T &val, Node *&rec); //查找函数=>查找节点值为val的节点返回至rec，成功返true失败返回false

    bool z_getLeftChild(const T &val, T &rec); //捕捉某数据的左子节点数据至rec，成功返true失败返回false

    bool z_getRightChild(const T &val, T &rec); //捕捉某数据的右子节点数据至rec，成功返true失败返回false

    // void z_display(const Node *&node = root);
    void z_display(Node *&node); //输出函数=>按字符串表示法输出二叉树

    int z_getNodeNum(); //返回节点总数

    int z_getLeafNodeNum(); //返回叶节点数

    int z_getDegree(); //返回二叉树的度数

    // int z_getDepth(const Node *&node = root);
    int z_getDepth(Node *&node); //返回二叉树的深度

    // void z_preTraRecu(const Node *&node = root);
    void z_preTraRecu(Node *&node); //递归实现先序遍历

    void z_preTraNonRecu(); //非递归实现先序遍历

    // void z_inTraRecu(const Node *&node = root);
    void z_inTraRecu(Node *&node); //递归实现中序遍历

    void z_inTraNonRecu(); //非递归实现中序遍历

    // void z_postTraRecu(const Node *&node = root);
    void z_postTraRecu(Node *&node); //递归实现后序遍历

    void z_postTraNonRecu(); //非递归实现后序遍历

    // void z_preThread(const Node *&node = root);
    // z_binaryTree z_getPreThreadTree();

    // void z_inThread(const Node *&node = root);
    void z_inThread(Node *&node); //中序线索化二叉树
    // z_binaryTree z_getInThreadTree();

    // void z_postThread(const Node *&node = root);
    // z_binaryTree z_getPostThreadTree();

    T z_getRootInPre();  //返回根节点前驱
    T z_getRootInNext(); //返回根节点后序

    struct Node *root = NULL; //根节点指针

    void setLeafNodeNum(int cnt) {leafNodeNum = cnt;}    // 设置leafNodeNum

private:
    struct Node *St[MAXSIZE]; //  存储节点
    int nodeNum;              //  节点个数
    int leafNodeNum;          //  叶子节点个数
    bool getLeafNodeNum;      //  叶节点数是否获取过
    int degree;               //  树的度
    bool getDegree;           //  树的度是否获取过
    int depth /*height*/;     //  树的深度/高度
    bool getDepth;            //  树的深度是否获取过
    Node *rootInPre = NULL;   //  根节点前驱
    Node *rootInNext = NULL;  //  根节点后继
};


/*  初始化函数=>利用字符串表示法初始化二叉树
*/
template <class T>
void z_binaryTree<T>::z_initBTree(char str[])
{
    root = NULL;    //  根节点初始化赋空
    int now = -1;   //  表示当前(父)节点
    char ch;        //  临时字符变量
    Node *temp = NULL;  //  临时节点指针
    bool child = 0; //  child布尔值 表示左子(false)还是右子(true)
    for (int i = 0; str[i] != '\0'; ++i)
    {
        //  叶节点 将叶节点总数leafNodeNum+1 并记录getLeafNodeNum
        if (i > 0 && str[i] != '(' && str[i - 1] != ',' && str[i - 1] != '(' && str[i - 1] != ')')
            getLeafNodeNum = 1, leafNodeNum++;
        ch = str[i];    //  捕捉当前字符
        switch (ch)     //  switch判断
        {
        case '(':       //  进入左子循环
            now++;      //  新增
            St[now] = temp; //  节点存入St里
            child = 0;  //  右左切换
            if (degree == 0)    //  树的度数由0变1
                degree++;
            break;
        case ')':       //  结束右子循环
            now--;      //  返回
            //depth++
            break;
        case ',':       //  进入右子循环
            child = 1;  //  左右切换
            if (degree == 1)    //  树的度数由1变2
                degree++;
            break;
        default:        //  当前是字符 进行存储
            temp = new Node;
            temp->data = ch;
            temp->leftChild = temp->rightChild = NULL;
            nodeNum++;  //  节点总数增加
            if (root == NULL)   //  未有根节点 赋为根节点
            {
                root = temp;
            }
            else    //  已有根节点 进行父子关系的维护
            {
                if (!child)
                    St[now]->leftChild = temp;
                else
                    St[now]->rightChild = temp;
            }
        }
    }
}


/*  删除函数=>删除二叉树
*/
template <class T>
void z_binaryTree<T>::z_deleteBTree()
{
    queue<Node *> q; //  队列存储节点
    q.push(root);
    while (!q.empty()) //  BFS遍历节点并删除
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL) //  空节点不需要删除
            continue;
        if (temp->leftChild != NULL && temp->lflag == 0) //  左子节点存在且未线索化
            q.push(temp->leftChild);
        if (temp->rightChild != NULL && temp->rflag == 0) //  右子节点存在且未线索化
            q.push(temp->rightChild);
        delete temp; //  删除当前节点
    }
}


/*  查找函数=>查找节点值为val的节点返回至rec，成功返true失败返回false
*/
template <class T>
bool z_binaryTree<T>::z_find(const T &val, Node *&rec)
{
    queue<Node *> q;    //  队列存储节点
    q.push(root);
    while (!q.empty())  //  BFS遍历节点并判断
    {
        Node *temp = q.front();
        q.pop();
        if (temp->data == val)  //  找到返回true
        {
            rec = temp;
            return 1;
        }
        if (temp->leftChild != NULL)
            q.push(temp->leftChild);
        if (temp->rightChild != NULL)
            q.push(temp->rightChild);
    }
    return 0;   //  找不到返回false
}


/*  捕捉某数据的左子节点数据返回至rec，成功返true失败返回false
*/
template <class T>
bool z_binaryTree<T>::z_getLeftChild(const T &val, T &rec)
{
    Node *temp;
    bool ok = this->z_find(val, temp);  //查找当前数据所在节点
    if (!ok || temp->leftChild == NULL) //不存在返回false
        return 0;
    else
    {
        rec = temp->leftChild->data;
        return 1;
    }
}


/*  捕捉某数据的右子节点数据返回至rec，成功返true失败返回false
*/
template <class T>
bool z_binaryTree<T>::z_getRightChild(const T &val, T &rec)
{
    Node *temp;
    bool ok = this->z_find(val, temp);   //查找当前数据所在节点
    if (!ok || temp->rightChild == NULL) //不存在返回false
        return 0;
    else
    {
        rec = temp->rightChild->data;
        return 1;
    }
}


/*  输出函数=>按字符串表示法输出二叉树
*/
template <class T>
// void z_binaryTree<T>::z_display(const Node *&node = root)
void z_binaryTree<T>::z_display(Node *&node)
{
    if (node == NULL)   //  节点空 返回
        return;
    else
    {
        cout << node->data << ' ';  //  输当前节点数据
        Node *lchi = node->leftChild;   //  左
        Node *rchi = node->rightChild;  //  右
        if (lchi == NULL && rchi == NULL)   //  无子 返回
            return;
        else
        {
            cout << "( ";   //  开始处理儿子
            this->z_display(lchi);  //  递归左
            if (rchi)
            {
                cout << ", ";   //  递归右
                this->z_display(rchi);
            }
            cout << ") ";   //  结束儿子的处理
        }
    }
}


/*  返回节点总数
*/
template <class T>
int z_binaryTree<T>::z_getNodeNum()
{
    return nodeNum;
}


/*  返回叶节点数
    注意到在初始化时已经计算过叶节点数 此处只是为了练习和完整性添加此内容
*/
template <class T>
int z_binaryTree<T>::z_getLeafNodeNum()
{
    if (getLeafNodeNum) //  已经算过 直接返回
        return leafNodeNum;
    else    //  没算过 进行计算
    {
        int cnt = 0;
        queue<Node *> q;    //  队列存储节点
        q.push(root);
        while (!q.empty())  //  BFS遍历遍历节点并统计
        {
            Node *temp = q.front();
            q.pop();
            if (temp->leftChild != NULL)
                q.push(temp->leftChild);
            if (temp->rightChild != NULL)
                q.push(temp->rightChild);
            // if (temp->leftChild == NULL && temp->rightChild == NULL)
            //     cnt++;
            //  当前为叶节点 总数+1
            if ((temp->leftChild->lflag == 1 || temp->leftChild == NULL) && (temp->rightChild->rflag == 1 || temp->rightChild == NULL))
                cnt++;
        }
        getLeafNodeNum = 1;
        setLeafNodeNum(cnt);
        return cnt;
    }
}


/*  返回二叉树的度数
*/
template <class T>
int z_binaryTree<T>::z_getDegree()
{
    return degree;
}


/*  返回二叉树的深度
*/
template <class T>
// int z_binaryTree<T>::z_getDepth(const Node *&node = root)
int z_binaryTree<T>::z_getDepth(Node *&node)
{
    int ldepth = 0, rdepth = 0;
    if (node == NULL)
        return 0;
    else       //   递归左右子树最大者+1
        return max(this->z_getDepth(node->leftChild), this->z_getDepth(node->rightChild)) + 1;
}


/*  递归实现先序遍历
*/
template <class T>
// void z_binaryTree<T>::z_preTraRecu(const Node *&node = root)
void z_binaryTree<T>::z_preTraRecu(Node *&node)
{
    if (node != NULL)
    {
        cout << node->data << ' ';
        this->z_preTraRecu(node->leftChild);
        this->z_preTraRecu(node->rightChild);
    }
}


/*  递归实现中序遍历
*/
template <class T>
// void z_binaryTree<T>::z_inTraRecu(const Node *&node = root)
void z_binaryTree<T>::z_inTraRecu(Node *&node)
{
    if (node != NULL)
    {
        this->z_inTraRecu(node->leftChild);
        cout << node->data << ' ';
        this->z_inTraRecu(node->rightChild);
    }
}


/*  递归实现后序遍历
*/
template <class T>
// void z_binaryTree<T>::z_postTraRecu(const Node *&node = root)
void z_binaryTree<T>::z_postTraRecu(Node *&node)
{
    if (node != NULL)
    {
        this->z_postTraRecu(node->leftChild);
        this->z_postTraRecu(node->rightChild);
        cout << node->data << ' ';
    }
}


/*  非递归实现先序遍历
*/
template <class T>
void z_binaryTree<T>::z_preTraNonRecu()
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        if (temp->rightChild != NULL)
            st.push(temp->rightChild);
        if (temp->leftChild != NULL)
            st.push(temp->leftChild);
        cout << temp->data << ' ';
    }
}

/*  非递归实现中序遍历
*/
template <class T>
void z_binaryTree<T>::z_inTraNonRecu()
{
    if (root == NULL)
        return;
    Node *temp = root;
    stack<Node *> st;
    while (!st.empty() || temp != NULL)
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->leftChild;
        }
        if (!st.empty())
        {
            temp = st.top();
            st.pop();
            cout << temp->data << ' ';
            temp = temp->rightChild;
        }
    }
}

/*  非递归实现后序遍历 (存在适当装换成先序中序的方法)
*/
template <class T>
void z_binaryTree<T>::z_postTraNonRecu()
{
    if (root == NULL)
        return;
    vector<Node *> path;    //  path保存遍历结果
    stack<pair<Node *, bool>> st;   //  st保存pair值，第一关键字为Node指针表示节点，第二关键字为bool值表示是否当前节点遍历过子节点
    st.push({root, 0});
    while (!st.empty())
    {
        auto temp = st.top();
        st.pop();
        if (temp.first == NULL)
            continue;
        if (temp.second)    //  当前节点遍历过子子节点
        {
            path.push_back(temp.first);
        }
        else
        {
            //post  后序遍历 此段适当修改可做先序和中序
            st.push({temp.first, 1});
            if (temp.first->rightChild != NULL)
                st.push({temp.first->rightChild, 0});
            if (temp.first->leftChild != NULL)
                st.push({temp.first->leftChild, 0});

            //pre 修改成先序
            // if(temp.first->rightChild!=NULL) st.push({temp.first->rightChild,0});
            // if(temp.first->leftChild!=NULL) st.push({temp.first->leftChild,0});
            // st.push( {temp.first,1} );

            //in  修改成中序
            // if(temp.first->rightChild!=NULL) st.push({temp.first->rightChild,0});
            // st.push( {temp.first,1} );
            // if(temp.first->leftChild!=NULL) st.push({temp.first->leftChild,0});
        }
    }
    for (auto x : path)
        cout << x->data << ' ';
}


/*  中序线索化二叉树
*/
template <class T>
// void z_binaryTree<T>::z_inThread(const Node *&node = root)
void z_binaryTree<T>::z_inThread(Node *&node)
{
    if (root == NULL)
        return;
    //先处理处中序遍历结果
    vector<Node *> path;
    stack<pair<Node *, bool>> st;
    st.push({root, 0});
    while (!st.empty())
    {
        auto temp = st.top();
        st.pop();
        if (temp.first == NULL)
            continue;
        if (temp.second)
        {
            path.push_back(temp.first);
        }
        else
        {
            if (temp.first->rightChild != NULL)
                st.push({temp.first->rightChild, 0});
            st.push({temp.first, 1});
            if (temp.first->leftChild != NULL)
                st.push({temp.first->leftChild, 0});
        }
    }
    //对中序遍历结果逐个判断
    for (int i = 0; i < path.size(); i++)
    {
        //无左子且有前驱
        if (path[i]->leftChild == NULL && i > 0)
        {
            path[i]->lflag = 1;
            path[i]->leftChild = path[i - 1];
            //前驱是根节点 说明根节点后继是当前节点
            if (path[i - 1] == root)
            {
                rootInNext = path[i];
            }
        }
        //无右子且有后继
        if (path[i]->rightChild == NULL && i + 1 < path.size())
        {
            path[i]->lflag = 1;
            path[i]->leftChild = path[i + 1];
            //后继是根节点 说明根节点前驱是当前节点
            if (path[i + 1] == root)
            {
                rootInPre = path[i];
            }
        }
    }
}


/*  返回根节点前驱
*/
template <class T>
T z_binaryTree<T>::z_getRootInPre()
{
    if (rootInPre == NULL)
        return 0;
    else
        return rootInPre->data;
}


/*  返回根节点后继
*/
template <class T>
T z_binaryTree<T>::z_getRootInNext()
{
    if (rootInNext == NULL)
        return 0;
    else
        return rootInNext->data;
}
