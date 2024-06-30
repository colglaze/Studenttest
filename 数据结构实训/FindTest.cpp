#include<iostream>
#include<fstream>
#include<string>
#include <time.h>  
#include<cmath>
#include<Windows.h>//头文件

using namespace std;

const int MaxSize = 500;
const char* file = "file.txt"; //关联待检索文件
static int k;                  //文章单词总数

//词频结构
struct word_frequency
{
    string word;    //单词
    int frequency;  //频率
    int key;        //关键码
}linelist_word_fre[MaxSize];

typedef word_frequency datatype;//元素类型

//线性表单链表结构体
struct Node
{
    datatype data;               //数据域
    Node* next;       //指针域
};

//二叉排序树结构
struct BiNode
{
    datatype data;
    BiNode* lchild, * rchild;
};

//菜单函数
string word_transition(string word);//大写英语单词转化成小写
int word_judge(string word);//判断单词中是否有大写字母
int line_word(string word);//统计文章词频(去掉重复单词)
void word_frequency_statistics();//词频统计函数

//线性表函数声明
void list_menu();         //线性表菜单
void seqlist_menu();      //顺序查找菜单
void seqlist_seq_menu();  //基于顺序表的顺序查找菜单
void linklist_seq_menu(); //基于链表的顺序查找菜单
void word_sort_menu();    //单词查找菜单
void half_seqlist_menu(); //折半查找菜单
void seqlist_half_sort();//基于顺序表的折半查找菜单        
void linklist_seq_word_sort_menu();//基于单链表顺序查找菜单
void seqlist_half_word_sort_menu();//顺序表折半查找菜单

//二叉排序树函数声明
void Bitree_menu();//二叉排序树菜单
void Bitree_seq_sort();//二叉排序树查找
void Bitree_word_sort_menu();

//哈希表函数声明
void Hash_menu();//哈希表菜单
void open_Hash_sort();//基于开放地址法的哈希查找
void link_Hash_sort();//基于链地址法的哈希查找
int  word_transition_key(string a);//将单词转换为唯一关键码
void open_Hash_word_sort_menu();//开放地址法查找菜单
void link_Hash_word_sort_menu();//链地址法查找菜单

//类-线性表
class SeqList
{
public:
    SeqList();                         //无参构造函数，建立空的顺序表
    SeqList(datatype a[], int n);      //有参构造函数，建立长度为n的顺序表
    ~SeqList();                        //析构函数
    int Length();                      //求线性表的长度
    int Empety();                      //顺序表判空函数
    void PrintList(int a);                  //遍历操作，按序号依次输出各元素
    int seqlist_locate(string a);      //按值查找
    int BinSearch1(string a);               //折半查找
    string return_word(int i);
    int return_fre(int i);
private:
    datatype word_fre[MaxSize];         //存放词频结构体的数组
    int length;                         //线性表的长度
};

//析构函数
SeqList :: ~SeqList() {}

//构造函数
SeqList::SeqList()
{
    length = 0;             //建立空的顺序表，将length 长度初始化为0
}

//顺序表判空函数
int SeqList::Empety()
{
    if (length == 0)
        return 1;
    else
        return 0;
}

//求线性表的长度
int SeqList::Length()
{
    return length;
}

//有参构造函数，建立长度为n的顺序表
SeqList::SeqList(datatype a[], int n)
{
    if (n > MaxSize)
    {
        cout << "单词数量过多，超出线性表最大容量" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        word_fre[i].word = a[i].word;
        word_fre[i].frequency = a[i].frequency;
    }
    length = n;
}

//按值查找
int SeqList::seqlist_locate(string a)
{
    for (int i = 0; i < k; i++)
    {
        if (word_fre[i].word == a)
            return i + 1;
    }
    return 0;
}

//折半查找
int  SeqList::BinSearch1(string a)
{

    int mid, low = 0, high = k - 1;             //初始查找区间是[1, k]
    while (low <= high)                      //当区间存在时
    {
        mid = (low + high) / 2;
        if (word_transition(a) < word_transition(word_fre[mid].word)) high = mid - 1;
        else if (word_transition(a) > word_transition(word_fre[mid].word)) low = mid + 1;
        else
        {
            if (mid > k / 2 && word_judge(a) == 1)
                return mid;                   //查找成功，返回元素序号
            else if (mid > k / 2 && word_judge(a) == 0)
                return mid + 1;
            if (mid < k / 2 && word_judge(a) == 1)
                return mid - 1;                   //查找成功，返回元素序号
            else if (mid < k / 2 && word_judge(a) == 0)
                return mid;
        }
    }
    return -1;                               //查找失败，返回-1
}

//返回顺序表的单词
string SeqList::return_word(int i)
{
    return word_fre[i].word;
}

//返回顺序表的单词的频率
int SeqList::return_fre(int i)
{
    return word_fre[i].frequency;
}

//输出线性表顺序表
void SeqList::PrintList(int a)
{
    system("cls");
    //输出到文件outfile中
    if (a == 1)
    {
        ofstream fout;
        fout.open("outfile1.txt");
        fout << "单词总数为：" << k << endl;
        fout << "词频" << "    " << "单词" << endl;
        for (int m = 0; m < k; m++)
        {
            fout << word_fre[m].frequency << "  " << word_fre[m].word << endl;
        }
    }
    else if (a == 2)
    {
        ofstream fout;
        fout.open("outfile3.txt");
        fout << "单词总数为：" << k << endl;
        fout << "词频" << "    " << "单词" << endl;
        for (int m = 0; m < k; m++)
        {
            fout << word_fre[m].frequency << "  " << word_fre[m].word << endl;
        }
    }
    cout << "单词总数为：" << k << endl;
    cout << "词频" << "       " << "单词" << endl;
    for (int i = 0; i < length; i++)
        cout << word_fre[i].frequency << "    " << word_fre[i].word << endl;
    if (a == 1)
        cout << "单词以及词频已经保存到文件outfile1.txt文件中" << endl;
    else if (a == 2)
        cout << "单词以及词频已经保存到文件outfile3.txt文件中" << endl;
    system("pause");
}

//统计文章词频(去掉重复单词)
int line_word(string word)
{
    for (int i = 0; i < MaxSize; i++)
    {
        if (linelist_word_fre[i].word == word)
        {
            linelist_word_fre[i].frequency += 1;
            return i;
        }
    }
    linelist_word_fre[k].word = word;
    linelist_word_fre[k].frequency = 1;
    k += 1;
    return 0;
}

//大写英语单词转化成小写
string word_transition(string word)
{
    for (int i = 0; i < int(word.size()); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;
    }
    return word;
}

//判断单词中是否有大写字母
int word_judge(string word)
{
    for (int i = 0; i < int(word.size()); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            return 1;
    }
    return 0;
}

//词频统计
void word_frequency_statistics()
{
    ifstream fin;
    fin.open(file);//关联文件file
    char ch;//用于获取字符 
    string word;//用于存放单词
    int i, j, m;
    for (i = 0; fin.get(ch); i++)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (word == "\0")//word为空，放入第一个字母
                word = ch;
            else
                word += ch;//word不为空，拼接字母组成单词
        }
        else
        {
            if (word != "\0")//判断之前的word里面是否有单词
            {
                line_word(word);//存放到结构体数组里面
            }
            word = "\0";//清空word
        }
    }
    //按照词典排序（冒泡排序）
    word_frequency temp;
    for (i = 0; i < k; i++)
    {
        m = i;
        for (j = i + 1; j < k; j++)
        {
            if (word_transition(linelist_word_fre[j].word) < word_transition(linelist_word_fre[m].word))//将单词转换成小写进行比较
                m = j;
        }
        //交换原始单词
        temp = linelist_word_fre[i];
        linelist_word_fre[i] = linelist_word_fre[m];
        linelist_word_fre[m] = temp;
    }
    for (i = 0; i < k; i++)
    {
        m = i;
        for (j = i + 1; j < k; j++)
        {
            if (word_transition(linelist_word_fre[j].word) == word_transition(linelist_word_fre[m].word))//两个单词相等
                if (linelist_word_fre[j].word < linelist_word_fre[m].word)//大写的排前面
                    m = j;
        }
        //交换原始单词
        temp = linelist_word_fre[i];
        linelist_word_fre[i] = linelist_word_fre[m];
        linelist_word_fre[m] = temp;
    }
    fin.close();
    return;
}

//线性表单词查找
int word_sort(SeqList L, string word)
{
    int i = L.seqlist_locate(word);
    return i;
}

//类-单链表
class LinkList
{
public:
    LinkList();                      //无参构造函数，建立只有头结点的空链表
    LinkList(datatype a[], int n);     //有参构造函数，建立有n个元素的单链表
    ~LinkList();                     //析构函数
    int Length();                     //求单链表的长度
    int Empety();
    datatype Get(int i);               //按位查找。查找第i个结点的元素值
    int Locate(string x);            //按值查找。查找值为x的元素序号

    void PrintList();                  //遍历操作，按序号依次输出各元素
private:
    Node* first;           //单链表的头指针
};

//无参单链表构造函数
LinkList::LinkList()
{
    first = new Node;              //生成头结点
    first->next = NULL;         //头结点的指针域置空
}

//单链表析构函数
LinkList :: ~LinkList()
{
    Node* q = NULL;
    while (first != NULL)        //释放单链表的每一个结点的存储空间
    {
        q = first;                 //暂存被释放结点
        first = first->next;         // first指向被释放结点的下一个结点
        delete q;
    }
}

//判空
int LinkList::Empety()
{
    if (first->next == NULL)
        return 1;
    else
        return 0;
}

//输出单链表
void LinkList::PrintList()
{
    system("cls");
    Node* p = first->next;//工作指针p初始化
    //输出到文件outfile中
    ofstream fout;
    fout.open("outfile2.txt");
    fout << "单词总数为：" << k << endl;
    fout << "词频" << "    " << "单词" << endl;
    while (p != NULL)
    {
        fout << p->data.frequency << "    " << p->data.word << endl;
        p = p->next;                 //工作指针p后移，注意不能写作p++
    }
    cout << "单词总数为：" << k << endl;
    cout << "词频" << "       " << "单词" << endl;
    Node* p1 = first->next;//工作指针p初始化
    while (p1 != NULL)
    {
        cout << p1->data.frequency << "    " << p1->data.word << endl;
        p1 = p1->next;                 //工作指针p后移，注意不能写作p++
    }
    cout << "单词以及词频已经保存到文件outfile2.txt文件中" << endl;
    system("pause");
}

//求链表长度
int LinkList::Length()
{
    Node* p = first->next;   //工作指针p初始化为开始接点
    int count = 0;                    //累加器count初始化
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;              //注意count的初始化和返回值之间的关系
}

//按值查找
int LinkList::Locate(string x)
{
    Node* p = first->next;   //工作指针p初始化
    int count = 1;                     //累加器count初始化
    while (p != NULL)
    {
        if (p->data.word == x) return count;     //查找成功，结束函数并返回序号
        p = p->next;
        count++;
    }
    return 0;                        //退出循环表明查找失败
}

//按位查找
datatype LinkList::Get(int i)
{
    Node* p = first->next;    //工作指针p初始化
    int count = 1;                     //累加器count初始化
    while (p != NULL && count < i)
    {
        p = p->next;                   //工作指针p后移
        count++;
    }
    if (p == NULL) throw "位置";
    else return p->data;
}

//带参数单链表构造函数
LinkList::LinkList(datatype a[], int n)
{
    first = new Node;                    //生成头结点
    Node* r = first, * s = NULL;           //尾指针初始化
    for (int i = 0; i < n; i++)
    {
        s = new Node; s->data = a[i];
        r->next = s; r = s;                 //将结点s插入到终端结点之后
    }
    r->next = NULL;        //单链表建立完毕，将终端结点的指针域置空
}

//类-二叉排序树
class BiSortTree
{
public:
    BiSortTree(datatype a[], int n);                   //构造函数
    ~BiSortTree() { Release(root); }              //析构函数
    void InOrder() { InOrder(root); }             //中序遍历二叉树
    BiNode* InsertBST(datatype x) { return InsertBST(root, x); }  //插入记录x
    BiNode* SearchBST(string k) { return SearchBST(root, k); }  //查找值为k的结点
    void printf();
private:
    void Release(BiNode* bt);
    BiNode* InsertBST(BiNode* bt, datatype x);
    BiNode* SearchBST(BiNode* bt, string k);
    void InOrder(BiNode* bt);                    //中序遍历函数调用
    BiNode* root;                                //二叉排序树的根指针
};

//输出函数
void  BiSortTree::InOrder(BiNode* bt)//递归输出二叉排序树
{
    //输出到文件outfile中
    ofstream fout;
    fout.open("outfile4.txt", ios::out | ios::app);//添加到文件尾
    if (bt == NULL) return;              //递归调用的结束条件
    else
    {
        InOrder(bt->lchild);               //前序递归遍历bt的左子树
        cout << bt->data.frequency << "    " << bt->data.word << endl;          //访问根结点bt的数据域
        fout << bt->data.frequency << "    " << bt->data.word << endl;
        fout.close();
        InOrder(bt->rchild);               //前序递归遍历bt的右子树  
    }
}

//查找函数
BiNode* BiSortTree::SearchBST(BiNode* bt, string k)
{
    if (bt == NULL) return NULL;
    if (bt->data.word == k) return bt;
    else if (bt->data.word > k) return SearchBST(bt->lchild, k);
    else return SearchBST(bt->rchild, k);
}

//插入函数
BiNode* BiSortTree::InsertBST(BiNode* bt, datatype x)
{
    if (bt == NULL)//找到插入位置
    {
        BiNode* s = new BiNode;
        s->data = x;
        s->lchild = NULL;
        s->rchild = NULL;
        bt = s;
        return bt;
    }
    else if (word_transition(bt->data.word) > word_transition(x.word))
    {
        bt->lchild = InsertBST(bt->lchild, x);
        return bt;
    }
    else
    {
        bt->rchild = InsertBST(bt->rchild, x);
        return bt;
    }

}

//构造函数
BiSortTree::BiSortTree(datatype a[], int n)
{
    root = NULL;
    for (int i = 0; i < n; i++)
        root = InsertBST(root, a[i]);
}

//析构函数
void BiSortTree::Release(BiNode* bt)
{
    if (bt == NULL) return;
    else {
        Release(bt->lchild);                   //释放左子树
        Release(bt->rchild);                   //释放右子树
        delete bt;                            //释放根结点
    }
}

//输出二叉排序树到屏幕和outfile4.txt
void BiSortTree::printf()
{
    system("cls");
    ofstream fout;
    fout.open("outfile4.txt");//清空文件
    fout << "单词总数为：" << k << endl;
    fout << "词频" << "    " << "单词" << endl;
    InOrder();//输出到屏幕
    system("pause");
    return;
}

//类-哈希表
class HashTable1
{
public:
    HashTable1();                       //构造函数，初始化空散列表
    ~HashTable1();                      //析构函数
    int Insert(word_frequency a);       //插入
    int Search(string word);            //查找
    word_frequency Get(int a);
    void Print();
private:
    int H(int k);                        //散列函数
    word_frequency ht[MaxSize];          //闭散列表
};

//构造函数
HashTable1::HashTable1()
{
    for (int i = 0; i < MaxSize; i++)
    {
        ht[i].key = 0;
        ht[i].word = "empty";
        ht[i].frequency = 0;                        // 0表示该散列单元为空
    }
}

//析构函数
HashTable1 :: ~HashTable1()
{
}

//除留余数法-散列函数
int HashTable1::H(int k)
{
    return k % MaxSize;
}

//输出函数
void HashTable1::Print()
{
    system("cls");
    //输出到文件outfile中
    ofstream fout;
    fout.open("outfile5.txt");
    fout << "单词总数为：" << k << endl;
    fout << "词频" << "    " << "单词" << endl;
    for (int i = 0; i < MaxSize; i++)
    {
        if (ht[i].key != 0)
        {
            fout << ht[i].frequency << "\t" << ht[i].word << endl;
            cout << ht[i].frequency << "\t" << ht[i].word << endl;
        }
    }
    system("pause");
}
//查找函数
int HashTable1::Search(string word)
{
    int k = word_transition_key(word);
    int i, j = H(k);                        //计算散列地址
    i = j;                                  //设置比较的起始位置
    while (ht[i].key != 0)
    {
        if (ht[i].key == k) return i;         //查找成功
        else i = (i + 1) % MaxSize;                 //向后探测一个位置,开放地址法？
    }
    return 0;                                      //查找失败
}

//插入函数
int HashTable1::Insert(word_frequency f_word_key)
{
    int k = word_transition_key(f_word_key.word);
    int i, j = H(k);                        //计算散列地址
    i = j;                                  //设置比较的起始位置
    while (ht[i].key != 0)
    {
        if (ht[i].key == k) return -1;        //原有元素k,不能插入 
        else i = (i + 1) % MaxSize;                 //向后探测一个位置
    }
    ht[i].key = k;
    ht[i].word = f_word_key.word;
    ht[i].frequency = f_word_key.frequency;
    return i;                             //返回插入位置 
}

//获取单词以及频率
word_frequency  HashTable1::Get(int a)
{
    if (a >= 0)
        return ht[a];
    else
        return ht[0];
}

//将单词转换为唯一关键码
int  word_transition_key(string word)
{
    int a[18] = { 0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136 };//最长识别17个字母的的单词
    int key = 0;
    for (int i = 0; i < int(word.size()); i++)
    {
        key += int(word[i]);
    }
    key += int('z') * a[int(word.size())];
    return key;
}

//类-哈希表-链地址法
class HashTable2
{
public:
    HashTable2();                       //构造函数，初始化开散列表
    ~HashTable2();                      //析构函数，释放同义词子表结点
    int Insert(datatype fword);                       //插入
    Node* Search(string word);              //查找
    void Print();
private:
    int H(int k);                             //散列函数
    Node* ht[MaxSize];             //开散列表
};

//构造函数
HashTable2::HashTable2()
{
    for (int i = 0; i < MaxSize; i++)
    {
        ht[i] = NULL;
    }
}

//析构函数
HashTable2 :: ~HashTable2()
{
    Node* p = NULL, * q = NULL;
    for (int i = 0; i < MaxSize; i++)
    {
        p = ht[i];
        q = ht[i];
        while (p != NULL)
        {
            p = p->next;
            delete q;
            q = p;
        }
    }
}

//除留余数法-散列函数
int HashTable2::H(int k)
{
    return k % MaxSize;
}

//输出到屏幕和文本文件outfile6.txt
void HashTable2::Print()
{
    system("cls");
    //输出到文件outfile中
    ofstream fout;
    fout.open("outfile6.txt");
    fout << "单词总数为：" << k << endl;
    fout << "词频" << "    " << "单词" << endl;
    Node* p = NULL;
    for (int i = 0; i < MaxSize; i++)
    {
        p = ht[i];
        while (p != NULL)
        {
            fout << p->data.frequency << "\t" << p->data.word << "\t" << endl;
            cout << p->data.frequency << "\t" << p->data.word << "\t" << endl;
            p = p->next;
        }
    }
    system("pause");

}

//查找函数
Node* HashTable2::Search(string word)
{
    int k = 0;
    k = word_transition_key(word);
    int j = H(k);                          //计算散列地址
    Node* p = ht[j];                      //工作指针p初始化
    while (p != NULL)
    {
        if (p->data.key == k)
            return p;
        else
            p = p->next;
    }
    return NULL;                             //查找失败
}

//插入函数
int HashTable2::Insert(datatype fword)
{
    int k = 0;
    k = word_transition_key(fword.word);
    fword.key = k;
    int j = H(k);                              //计算散列地址

    Node* p = Search(fword.word);
    if (p != NULL)
        return -1;                            //已存在元素k，无法插入 
    else {
        p = new Node;
        p->data.key = fword.key;
        p->data.frequency = fword.frequency;
        p->data.word = fword.word;
        p->next = ht[j];
        ht[j] = p;
        return 1;                              //插入成功标志 
    }
}


//主菜单
void major_menu()
{
    for (; 1;)
    {

        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---菜单---" << endl;
        cout << "1.基于线性表的查找" << endl;
        cout << "2.基于二叉排序树的查找" << endl;
        cout << "3.基于哈希表的查找" << endl;
        cout << "4.退出系统" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char major_menu_key;
        cin >> major_menu_key;
        switch (major_menu_key)
        {
        case '1': list_menu(); break;
        case '2': Bitree_menu(); break;
        case '3': Hash_menu(); break;
        case '4': cout << "系统已退出" << endl; return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }
    return;
}

//线性表相关菜单
//线性表菜单
void list_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于线性表的查找---" << endl;
        cout << "1.顺序查找" << endl;
        cout << "2.折半查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char list_menu_key;
        cin >> list_menu_key;
        switch (list_menu_key)
        {
        case '1': seqlist_menu(); break;
        case '2': half_seqlist_menu(); break;
        case '3': return;
        default:  cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//顺序查找菜单
void seqlist_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---顺序查找---" << endl;
        cout << "1.基于顺序表的顺序查找" << endl;
        cout << "2.基于链表的顺序查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char seqlist_menu_key;
        cin >> seqlist_menu_key;
        switch (seqlist_menu_key)
        {
        case '1': seqlist_seq_menu(); break;
        case '2': linklist_seq_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//基于顺序表的顺序查找菜单
void seqlist_seq_menu()
{
    SeqList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于顺序表的顺序查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char seqlist_seq_menu_key;
        cin >> seqlist_seq_menu_key;
        switch (seqlist_seq_menu_key)
        {
        case '1': L.PrintList(1); break;
        case '2': word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//基于链表的顺序查找菜单
void linklist_seq_menu()
{
    //linklist_seq_word_frequency_statistics();
    LinkList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于链表的顺序查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char linklist_seq_menu_key;
        cin >> linklist_seq_menu_key;
        switch (linklist_seq_menu_key)
        {
        case '1': L.PrintList(); break;
        case '2': linklist_seq_word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//线性表单词查找菜单
void word_sort_menu()
{
    SeqList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[20];
    double time = 0.00;
    for (int m = 0; m < 20; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        word_sort(L, word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 30;
    int i = word_sort(L, word);
    if (i)
    {
        cout << "此单词为：" << L.return_word(i - 1) << endl;
        cout << "此单词的词频：" << L.return_fre(i - 1) << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << (k + 1) / 2 << endl;
    }
    else
    {
        cout << "查找失败" << endl;

    }
    system("pause");
    return;

}

//链表单词查找菜单
void linklist_seq_word_sort_menu()
{
    LinkList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[40];
    double time = 0.00;
    for (int m = 0; m < 40; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        L.Locate(word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 40;
    int i = L.Locate(word);
    if (i)
    {
        cout << "此单词为：" << L.Get(i).word << endl;
        cout << "此单词的词频：" << L.Get(i).frequency << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << (k + 1) / 2 << endl;
    }
    else
    {
        cout << "查找失败" << endl;

    }
    system("pause");
    return;

}

//折半查找菜单
void half_seqlist_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---折半查找---" << endl;
        cout << "1.基于顺序表的折半查找" << endl;
        cout << "2.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char list_half_sort_key;
        cin >> list_half_sort_key;
        switch (list_half_sort_key)
        {
        case '1': seqlist_half_sort(); break;
        case '2': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//基于顺序表的折半查找菜单
void seqlist_half_sort()
{
    SeqList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于顺序表的折半查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char seqlist_half_menu_key;
        cin >> seqlist_half_menu_key;
        switch (seqlist_half_menu_key)
        {
        case '1': L.PrintList(2); break;
        case '2': seqlist_half_word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }
    return;
}

//顺序表折半查找菜单
void seqlist_half_word_sort_menu()
{
    SeqList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[10];
    double time = 0.00;
    for (int m = 0; m < 10; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        L.BinSearch1(word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 10;
    int i = L.BinSearch1(word);
    if (i >= 0)
    {
        cout << "此单词为：" << L.return_word(i) << endl;
        cout << "此单词的词频：" << L.return_fre(i) << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << double((log(double(k) + 1) / log(2)) - 1) << endl;
    }
    else
    {
        cout << "查找失败" << endl;

    }
    system("pause");
    return;

}

//二叉排序树相关菜单
//二叉排序树菜单
void Bitree_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---二叉排序树查找---" << endl;
        cout << "1.基于二叉排序树的顺序查找" << endl;
        cout << "2.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char Bitree_menu_key;
        cin >> Bitree_menu_key;
        switch (Bitree_menu_key)
        {
        case '1': Bitree_seq_sort(); break;
        case '2': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//基于二叉排序树的顺序查找
void Bitree_seq_sort()
{
    BiSortTree B(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于顺序表的顺序查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char Bitree_seq_sort_key;
        cin >> Bitree_seq_sort_key;
        switch (Bitree_seq_sort_key)
        {
        case '1': B.printf(); break;
        case '2': Bitree_word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//二叉排序树查找单词菜单
void Bitree_word_sort_menu()
{
    BiSortTree B(linelist_word_fre, k);
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[40];
    double time = 0.00;
    for (int m = 0; m < 40; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        B.SearchBST(word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 40;
    BiNode* p = NULL;
    p = B.SearchBST(word);
    if (p != NULL)
    {
        cout << "此单词为：" << p->data.word << endl;
        cout << "此单词的词频：" << p->data.frequency << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << k << endl;
    }
    else
    {
        cout << "查找失败" << endl;
    }
    system("pause");
    return;
}

//哈希表相关函数
//哈希表菜单
void Hash_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---哈希表---" << endl;
        cout << "1.基于开放地址法的哈希查找" << endl;
        cout << "2.基于链地址法的哈希查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char Hash_menu_key;
        cin >> Hash_menu_key;
        switch (Hash_menu_key)
        {
        case '1': open_Hash_sort(); break;
        case '2': link_Hash_sort(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }
    return;
}

void open_Hash_word_sort_menu()
{
    HashTable1 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    double load_factor = k / MaxSize;//散列表的装填因子
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[10];
    double time = 0.00;
    for (int m = 0; m < 10; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        HT.Search(word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 10;
    int i = HT.Search(word);
    if (i)
    {
        cout << "此单词为：" << HT.Get(i).word << endl;
        cout << "此单词的词频：" << HT.Get(i).frequency << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << (1 + 1 / (1 - load_factor)) / 2 << endl;
    }
    else
    {
        cout << "查找失败" << endl;

    }
    system("pause");
    return;
}

//基于开放地址法的哈希查找
void open_Hash_sort()
{
    HashTable1 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于开放地址法的哈希查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char open_Hash_sort_key;
        cin >> open_Hash_sort_key;
        switch (open_Hash_sort_key)
        {
        case '1': HT.Print(); break;
        case '2': open_Hash_word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

//基于链地址法的哈希查找
void link_Hash_sort()
{
    HashTable2 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    for (; 1;)
    {
        system("cls");
        cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
        cout << "---基于链地址法的哈希查找---" << endl;
        cout << "1.词频统计" << endl;
        cout << "2.单词查找" << endl;
        cout << "3.返回上一级" << endl;
        cout << "请按相应的数字键进行选择：" << endl;
        char link_Hash_sort_key;
        cin >> link_Hash_sort_key;
        switch (link_Hash_sort_key)
        {
        case '1': HT.Print(); break;
        case '2': link_Hash_word_sort_menu(); break;
        case '3': return;
        default: cout << "输入的不是有效符号，请重新输入" << endl; system("pause");
        }
    }

    return;
}

void link_Hash_word_sort_menu()
{
    HashTable2 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    double load_factor = k / MaxSize;//散列表的装填因子
    system("cls");
    cout << "*******************基于不同策略的英文单词的词频统计和检索系统*******************" << endl;
    cout << "---单词查找---" << endl;
    cout << "请输入要查找的单词：";
    string word;
    cin >> word;
    double time1[40];
    double time = 0.00;
    for (int m = 0; m < 40; m++)
    {
        LARGE_INTEGER fr;
        LARGE_INTEGER st;
        LARGE_INTEGER ed;
        QueryPerformanceFrequency(&fr);
        QueryPerformanceCounter(&st);
        HT.Search(word);
        QueryPerformanceCounter(&ed);
        time1[m] = (double)(ed.QuadPart - st.QuadPart) / (double)fr.QuadPart;
        time += time1[m];
    }
    time = time / 40;
    Node* p = HT.Search(word);
    if (p != NULL)
    {
        cout << "此单词为：" << p->data.word << endl;
        cout << "此单词的词频：" << p->data.frequency << endl;
        cout << "查找该单词所花费的时间：" << time * 1000000 << "ns" << endl;
        cout << "平均查找长度：" << 1 + (load_factor) / 2 << endl;
    }
    else
    {
        cout << "查找失败" << endl;

    }
    system("pause");
    return;
}


int main()
{
    word_frequency_statistics();
    major_menu();//主菜单
    return 0;
}