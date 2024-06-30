#include<iostream>
#include<fstream>
#include<string>
#include <time.h>  
#include<cmath>
#include<Windows.h>//ͷ�ļ�

using namespace std;

const int MaxSize = 500;
const char* file = "file.txt"; //�����������ļ�
static int k;                  //���µ�������

//��Ƶ�ṹ
struct word_frequency
{
    string word;    //����
    int frequency;  //Ƶ��
    int key;        //�ؼ���
}linelist_word_fre[MaxSize];

typedef word_frequency datatype;//Ԫ������

//���Ա�����ṹ��
struct Node
{
    datatype data;               //������
    Node* next;       //ָ����
};

//�����������ṹ
struct BiNode
{
    datatype data;
    BiNode* lchild, * rchild;
};

//�˵�����
string word_transition(string word);//��дӢ�ﵥ��ת����Сд
int word_judge(string word);//�жϵ������Ƿ��д�д��ĸ
int line_word(string word);//ͳ�����´�Ƶ(ȥ���ظ�����)
void word_frequency_statistics();//��Ƶͳ�ƺ���

//���Ա�������
void list_menu();         //���Ա�˵�
void seqlist_menu();      //˳����Ҳ˵�
void seqlist_seq_menu();  //����˳����˳����Ҳ˵�
void linklist_seq_menu(); //���������˳����Ҳ˵�
void word_sort_menu();    //���ʲ��Ҳ˵�
void half_seqlist_menu(); //�۰���Ҳ˵�
void seqlist_half_sort();//����˳�����۰���Ҳ˵�        
void linklist_seq_word_sort_menu();//���ڵ�����˳����Ҳ˵�
void seqlist_half_word_sort_menu();//˳����۰���Ҳ˵�

//������������������
void Bitree_menu();//�����������˵�
void Bitree_seq_sort();//��������������
void Bitree_word_sort_menu();

//��ϣ��������
void Hash_menu();//��ϣ��˵�
void open_Hash_sort();//���ڿ��ŵ�ַ���Ĺ�ϣ����
void link_Hash_sort();//��������ַ���Ĺ�ϣ����
int  word_transition_key(string a);//������ת��ΪΨһ�ؼ���
void open_Hash_word_sort_menu();//���ŵ�ַ�����Ҳ˵�
void link_Hash_word_sort_menu();//����ַ�����Ҳ˵�

//��-���Ա�
class SeqList
{
public:
    SeqList();                         //�޲ι��캯���������յ�˳���
    SeqList(datatype a[], int n);      //�вι��캯������������Ϊn��˳���
    ~SeqList();                        //��������
    int Length();                      //�����Ա�ĳ���
    int Empety();                      //˳����пպ���
    void PrintList(int a);                  //������������������������Ԫ��
    int seqlist_locate(string a);      //��ֵ����
    int BinSearch1(string a);               //�۰����
    string return_word(int i);
    int return_fre(int i);
private:
    datatype word_fre[MaxSize];         //��Ŵ�Ƶ�ṹ�������
    int length;                         //���Ա�ĳ���
};

//��������
SeqList :: ~SeqList() {}

//���캯��
SeqList::SeqList()
{
    length = 0;             //�����յ�˳�����length ���ȳ�ʼ��Ϊ0
}

//˳����пպ���
int SeqList::Empety()
{
    if (length == 0)
        return 1;
    else
        return 0;
}

//�����Ա�ĳ���
int SeqList::Length()
{
    return length;
}

//�вι��캯������������Ϊn��˳���
SeqList::SeqList(datatype a[], int n)
{
    if (n > MaxSize)
    {
        cout << "�����������࣬�������Ա��������" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        word_fre[i].word = a[i].word;
        word_fre[i].frequency = a[i].frequency;
    }
    length = n;
}

//��ֵ����
int SeqList::seqlist_locate(string a)
{
    for (int i = 0; i < k; i++)
    {
        if (word_fre[i].word == a)
            return i + 1;
    }
    return 0;
}

//�۰����
int  SeqList::BinSearch1(string a)
{

    int mid, low = 0, high = k - 1;             //��ʼ����������[1, k]
    while (low <= high)                      //���������ʱ
    {
        mid = (low + high) / 2;
        if (word_transition(a) < word_transition(word_fre[mid].word)) high = mid - 1;
        else if (word_transition(a) > word_transition(word_fre[mid].word)) low = mid + 1;
        else
        {
            if (mid > k / 2 && word_judge(a) == 1)
                return mid;                   //���ҳɹ�������Ԫ�����
            else if (mid > k / 2 && word_judge(a) == 0)
                return mid + 1;
            if (mid < k / 2 && word_judge(a) == 1)
                return mid - 1;                   //���ҳɹ�������Ԫ�����
            else if (mid < k / 2 && word_judge(a) == 0)
                return mid;
        }
    }
    return -1;                               //����ʧ�ܣ�����-1
}

//����˳���ĵ���
string SeqList::return_word(int i)
{
    return word_fre[i].word;
}

//����˳���ĵ��ʵ�Ƶ��
int SeqList::return_fre(int i)
{
    return word_fre[i].frequency;
}

//������Ա�˳���
void SeqList::PrintList(int a)
{
    system("cls");
    //������ļ�outfile��
    if (a == 1)
    {
        ofstream fout;
        fout.open("outfile1.txt");
        fout << "��������Ϊ��" << k << endl;
        fout << "��Ƶ" << "    " << "����" << endl;
        for (int m = 0; m < k; m++)
        {
            fout << word_fre[m].frequency << "  " << word_fre[m].word << endl;
        }
    }
    else if (a == 2)
    {
        ofstream fout;
        fout.open("outfile3.txt");
        fout << "��������Ϊ��" << k << endl;
        fout << "��Ƶ" << "    " << "����" << endl;
        for (int m = 0; m < k; m++)
        {
            fout << word_fre[m].frequency << "  " << word_fre[m].word << endl;
        }
    }
    cout << "��������Ϊ��" << k << endl;
    cout << "��Ƶ" << "       " << "����" << endl;
    for (int i = 0; i < length; i++)
        cout << word_fre[i].frequency << "    " << word_fre[i].word << endl;
    if (a == 1)
        cout << "�����Լ���Ƶ�Ѿ����浽�ļ�outfile1.txt�ļ���" << endl;
    else if (a == 2)
        cout << "�����Լ���Ƶ�Ѿ����浽�ļ�outfile3.txt�ļ���" << endl;
    system("pause");
}

//ͳ�����´�Ƶ(ȥ���ظ�����)
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

//��дӢ�ﵥ��ת����Сд
string word_transition(string word)
{
    for (int i = 0; i < int(word.size()); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;
    }
    return word;
}

//�жϵ������Ƿ��д�д��ĸ
int word_judge(string word)
{
    for (int i = 0; i < int(word.size()); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
            return 1;
    }
    return 0;
}

//��Ƶͳ��
void word_frequency_statistics()
{
    ifstream fin;
    fin.open(file);//�����ļ�file
    char ch;//���ڻ�ȡ�ַ� 
    string word;//���ڴ�ŵ���
    int i, j, m;
    for (i = 0; fin.get(ch); i++)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (word == "\0")//wordΪ�գ������һ����ĸ
                word = ch;
            else
                word += ch;//word��Ϊ�գ�ƴ����ĸ��ɵ���
        }
        else
        {
            if (word != "\0")//�ж�֮ǰ��word�����Ƿ��е���
            {
                line_word(word);//��ŵ��ṹ����������
            }
            word = "\0";//���word
        }
    }
    //���մʵ�����ð������
    word_frequency temp;
    for (i = 0; i < k; i++)
    {
        m = i;
        for (j = i + 1; j < k; j++)
        {
            if (word_transition(linelist_word_fre[j].word) < word_transition(linelist_word_fre[m].word))//������ת����Сд���бȽ�
                m = j;
        }
        //����ԭʼ����
        temp = linelist_word_fre[i];
        linelist_word_fre[i] = linelist_word_fre[m];
        linelist_word_fre[m] = temp;
    }
    for (i = 0; i < k; i++)
    {
        m = i;
        for (j = i + 1; j < k; j++)
        {
            if (word_transition(linelist_word_fre[j].word) == word_transition(linelist_word_fre[m].word))//�����������
                if (linelist_word_fre[j].word < linelist_word_fre[m].word)//��д����ǰ��
                    m = j;
        }
        //����ԭʼ����
        temp = linelist_word_fre[i];
        linelist_word_fre[i] = linelist_word_fre[m];
        linelist_word_fre[m] = temp;
    }
    fin.close();
    return;
}

//���Ա��ʲ���
int word_sort(SeqList L, string word)
{
    int i = L.seqlist_locate(word);
    return i;
}

//��-������
class LinkList
{
public:
    LinkList();                      //�޲ι��캯��������ֻ��ͷ���Ŀ�����
    LinkList(datatype a[], int n);     //�вι��캯����������n��Ԫ�صĵ�����
    ~LinkList();                     //��������
    int Length();                     //������ĳ���
    int Empety();
    datatype Get(int i);               //��λ���ҡ����ҵ�i������Ԫ��ֵ
    int Locate(string x);            //��ֵ���ҡ�����ֵΪx��Ԫ�����

    void PrintList();                  //������������������������Ԫ��
private:
    Node* first;           //�������ͷָ��
};

//�޲ε������캯��
LinkList::LinkList()
{
    first = new Node;              //����ͷ���
    first->next = NULL;         //ͷ����ָ�����ÿ�
}

//��������������
LinkList :: ~LinkList()
{
    Node* q = NULL;
    while (first != NULL)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
    {
        q = first;                 //�ݴ汻�ͷŽ��
        first = first->next;         // firstָ���ͷŽ�����һ�����
        delete q;
    }
}

//�п�
int LinkList::Empety()
{
    if (first->next == NULL)
        return 1;
    else
        return 0;
}

//���������
void LinkList::PrintList()
{
    system("cls");
    Node* p = first->next;//����ָ��p��ʼ��
    //������ļ�outfile��
    ofstream fout;
    fout.open("outfile2.txt");
    fout << "��������Ϊ��" << k << endl;
    fout << "��Ƶ" << "    " << "����" << endl;
    while (p != NULL)
    {
        fout << p->data.frequency << "    " << p->data.word << endl;
        p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
    }
    cout << "��������Ϊ��" << k << endl;
    cout << "��Ƶ" << "       " << "����" << endl;
    Node* p1 = first->next;//����ָ��p��ʼ��
    while (p1 != NULL)
    {
        cout << p1->data.frequency << "    " << p1->data.word << endl;
        p1 = p1->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
    }
    cout << "�����Լ���Ƶ�Ѿ����浽�ļ�outfile2.txt�ļ���" << endl;
    system("pause");
}

//��������
int LinkList::Length()
{
    Node* p = first->next;   //����ָ��p��ʼ��Ϊ��ʼ�ӵ�
    int count = 0;                    //�ۼ���count��ʼ��
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;              //ע��count�ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ
}

//��ֵ����
int LinkList::Locate(string x)
{
    Node* p = first->next;   //����ָ��p��ʼ��
    int count = 1;                     //�ۼ���count��ʼ��
    while (p != NULL)
    {
        if (p->data.word == x) return count;     //���ҳɹ��������������������
        p = p->next;
        count++;
    }
    return 0;                        //�˳�ѭ����������ʧ��
}

//��λ����
datatype LinkList::Get(int i)
{
    Node* p = first->next;    //����ָ��p��ʼ��
    int count = 1;                     //�ۼ���count��ʼ��
    while (p != NULL && count < i)
    {
        p = p->next;                   //����ָ��p����
        count++;
    }
    if (p == NULL) throw "λ��";
    else return p->data;
}

//�������������캯��
LinkList::LinkList(datatype a[], int n)
{
    first = new Node;                    //����ͷ���
    Node* r = first, * s = NULL;           //βָ���ʼ��
    for (int i = 0; i < n; i++)
    {
        s = new Node; s->data = a[i];
        r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
    }
    r->next = NULL;        //����������ϣ����ն˽���ָ�����ÿ�
}

//��-����������
class BiSortTree
{
public:
    BiSortTree(datatype a[], int n);                   //���캯��
    ~BiSortTree() { Release(root); }              //��������
    void InOrder() { InOrder(root); }             //�������������
    BiNode* InsertBST(datatype x) { return InsertBST(root, x); }  //�����¼x
    BiNode* SearchBST(string k) { return SearchBST(root, k); }  //����ֵΪk�Ľ��
    void printf();
private:
    void Release(BiNode* bt);
    BiNode* InsertBST(BiNode* bt, datatype x);
    BiNode* SearchBST(BiNode* bt, string k);
    void InOrder(BiNode* bt);                    //���������������
    BiNode* root;                                //�����������ĸ�ָ��
};

//�������
void  BiSortTree::InOrder(BiNode* bt)//�ݹ��������������
{
    //������ļ�outfile��
    ofstream fout;
    fout.open("outfile4.txt", ios::out | ios::app);//��ӵ��ļ�β
    if (bt == NULL) return;              //�ݹ���õĽ�������
    else
    {
        InOrder(bt->lchild);               //ǰ��ݹ����bt��������
        cout << bt->data.frequency << "    " << bt->data.word << endl;          //���ʸ����bt��������
        fout << bt->data.frequency << "    " << bt->data.word << endl;
        fout.close();
        InOrder(bt->rchild);               //ǰ��ݹ����bt��������  
    }
}

//���Һ���
BiNode* BiSortTree::SearchBST(BiNode* bt, string k)
{
    if (bt == NULL) return NULL;
    if (bt->data.word == k) return bt;
    else if (bt->data.word > k) return SearchBST(bt->lchild, k);
    else return SearchBST(bt->rchild, k);
}

//���뺯��
BiNode* BiSortTree::InsertBST(BiNode* bt, datatype x)
{
    if (bt == NULL)//�ҵ�����λ��
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

//���캯��
BiSortTree::BiSortTree(datatype a[], int n)
{
    root = NULL;
    for (int i = 0; i < n; i++)
        root = InsertBST(root, a[i]);
}

//��������
void BiSortTree::Release(BiNode* bt)
{
    if (bt == NULL) return;
    else {
        Release(bt->lchild);                   //�ͷ�������
        Release(bt->rchild);                   //�ͷ�������
        delete bt;                            //�ͷŸ����
    }
}

//�����������������Ļ��outfile4.txt
void BiSortTree::printf()
{
    system("cls");
    ofstream fout;
    fout.open("outfile4.txt");//����ļ�
    fout << "��������Ϊ��" << k << endl;
    fout << "��Ƶ" << "    " << "����" << endl;
    InOrder();//�������Ļ
    system("pause");
    return;
}

//��-��ϣ��
class HashTable1
{
public:
    HashTable1();                       //���캯������ʼ����ɢ�б�
    ~HashTable1();                      //��������
    int Insert(word_frequency a);       //����
    int Search(string word);            //����
    word_frequency Get(int a);
    void Print();
private:
    int H(int k);                        //ɢ�к���
    word_frequency ht[MaxSize];          //��ɢ�б�
};

//���캯��
HashTable1::HashTable1()
{
    for (int i = 0; i < MaxSize; i++)
    {
        ht[i].key = 0;
        ht[i].word = "empty";
        ht[i].frequency = 0;                        // 0��ʾ��ɢ�е�ԪΪ��
    }
}

//��������
HashTable1 :: ~HashTable1()
{
}

//����������-ɢ�к���
int HashTable1::H(int k)
{
    return k % MaxSize;
}

//�������
void HashTable1::Print()
{
    system("cls");
    //������ļ�outfile��
    ofstream fout;
    fout.open("outfile5.txt");
    fout << "��������Ϊ��" << k << endl;
    fout << "��Ƶ" << "    " << "����" << endl;
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
//���Һ���
int HashTable1::Search(string word)
{
    int k = word_transition_key(word);
    int i, j = H(k);                        //����ɢ�е�ַ
    i = j;                                  //���ñȽϵ���ʼλ��
    while (ht[i].key != 0)
    {
        if (ht[i].key == k) return i;         //���ҳɹ�
        else i = (i + 1) % MaxSize;                 //���̽��һ��λ��,���ŵ�ַ����
    }
    return 0;                                      //����ʧ��
}

//���뺯��
int HashTable1::Insert(word_frequency f_word_key)
{
    int k = word_transition_key(f_word_key.word);
    int i, j = H(k);                        //����ɢ�е�ַ
    i = j;                                  //���ñȽϵ���ʼλ��
    while (ht[i].key != 0)
    {
        if (ht[i].key == k) return -1;        //ԭ��Ԫ��k,���ܲ��� 
        else i = (i + 1) % MaxSize;                 //���̽��һ��λ��
    }
    ht[i].key = k;
    ht[i].word = f_word_key.word;
    ht[i].frequency = f_word_key.frequency;
    return i;                             //���ز���λ�� 
}

//��ȡ�����Լ�Ƶ��
word_frequency  HashTable1::Get(int a)
{
    if (a >= 0)
        return ht[a];
    else
        return ht[0];
}

//������ת��ΪΨһ�ؼ���
int  word_transition_key(string word)
{
    int a[18] = { 0,0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136 };//�ʶ��17����ĸ�ĵĵ���
    int key = 0;
    for (int i = 0; i < int(word.size()); i++)
    {
        key += int(word[i]);
    }
    key += int('z') * a[int(word.size())];
    return key;
}

//��-��ϣ��-����ַ��
class HashTable2
{
public:
    HashTable2();                       //���캯������ʼ����ɢ�б�
    ~HashTable2();                      //�����������ͷ�ͬ����ӱ���
    int Insert(datatype fword);                       //����
    Node* Search(string word);              //����
    void Print();
private:
    int H(int k);                             //ɢ�к���
    Node* ht[MaxSize];             //��ɢ�б�
};

//���캯��
HashTable2::HashTable2()
{
    for (int i = 0; i < MaxSize; i++)
    {
        ht[i] = NULL;
    }
}

//��������
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

//����������-ɢ�к���
int HashTable2::H(int k)
{
    return k % MaxSize;
}

//�������Ļ���ı��ļ�outfile6.txt
void HashTable2::Print()
{
    system("cls");
    //������ļ�outfile��
    ofstream fout;
    fout.open("outfile6.txt");
    fout << "��������Ϊ��" << k << endl;
    fout << "��Ƶ" << "    " << "����" << endl;
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

//���Һ���
Node* HashTable2::Search(string word)
{
    int k = 0;
    k = word_transition_key(word);
    int j = H(k);                          //����ɢ�е�ַ
    Node* p = ht[j];                      //����ָ��p��ʼ��
    while (p != NULL)
    {
        if (p->data.key == k)
            return p;
        else
            p = p->next;
    }
    return NULL;                             //����ʧ��
}

//���뺯��
int HashTable2::Insert(datatype fword)
{
    int k = 0;
    k = word_transition_key(fword.word);
    fword.key = k;
    int j = H(k);                              //����ɢ�е�ַ

    Node* p = Search(fword.word);
    if (p != NULL)
        return -1;                            //�Ѵ���Ԫ��k���޷����� 
    else {
        p = new Node;
        p->data.key = fword.key;
        p->data.frequency = fword.frequency;
        p->data.word = fword.word;
        p->next = ht[j];
        ht[j] = p;
        return 1;                              //����ɹ���־ 
    }
}


//���˵�
void major_menu()
{
    for (; 1;)
    {

        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---�˵�---" << endl;
        cout << "1.�������Ա�Ĳ���" << endl;
        cout << "2.���ڶ����������Ĳ���" << endl;
        cout << "3.���ڹ�ϣ��Ĳ���" << endl;
        cout << "4.�˳�ϵͳ" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char major_menu_key;
        cin >> major_menu_key;
        switch (major_menu_key)
        {
        case '1': list_menu(); break;
        case '2': Bitree_menu(); break;
        case '3': Hash_menu(); break;
        case '4': cout << "ϵͳ���˳�" << endl; return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }
    return;
}

//���Ա���ز˵�
//���Ա�˵�
void list_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---�������Ա�Ĳ���---" << endl;
        cout << "1.˳�����" << endl;
        cout << "2.�۰����" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char list_menu_key;
        cin >> list_menu_key;
        switch (list_menu_key)
        {
        case '1': seqlist_menu(); break;
        case '2': half_seqlist_menu(); break;
        case '3': return;
        default:  cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//˳����Ҳ˵�
void seqlist_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---˳�����---" << endl;
        cout << "1.����˳����˳�����" << endl;
        cout << "2.���������˳�����" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char seqlist_menu_key;
        cin >> seqlist_menu_key;
        switch (seqlist_menu_key)
        {
        case '1': seqlist_seq_menu(); break;
        case '2': linklist_seq_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//����˳����˳����Ҳ˵�
void seqlist_seq_menu()
{
    SeqList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---����˳����˳�����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char seqlist_seq_menu_key;
        cin >> seqlist_seq_menu_key;
        switch (seqlist_seq_menu_key)
        {
        case '1': L.PrintList(1); break;
        case '2': word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//���������˳����Ҳ˵�
void linklist_seq_menu()
{
    //linklist_seq_word_frequency_statistics();
    LinkList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---���������˳�����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char linklist_seq_menu_key;
        cin >> linklist_seq_menu_key;
        switch (linklist_seq_menu_key)
        {
        case '1': L.PrintList(); break;
        case '2': linklist_seq_word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//���Ա��ʲ��Ҳ˵�
void word_sort_menu()
{
    SeqList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << L.return_word(i - 1) << endl;
        cout << "�˵��ʵĴ�Ƶ��" << L.return_fre(i - 1) << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << (k + 1) / 2 << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;

    }
    system("pause");
    return;

}

//�����ʲ��Ҳ˵�
void linklist_seq_word_sort_menu()
{
    LinkList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << L.Get(i).word << endl;
        cout << "�˵��ʵĴ�Ƶ��" << L.Get(i).frequency << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << (k + 1) / 2 << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;

    }
    system("pause");
    return;

}

//�۰���Ҳ˵�
void half_seqlist_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---�۰����---" << endl;
        cout << "1.����˳�����۰����" << endl;
        cout << "2.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char list_half_sort_key;
        cin >> list_half_sort_key;
        switch (list_half_sort_key)
        {
        case '1': seqlist_half_sort(); break;
        case '2': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//����˳�����۰���Ҳ˵�
void seqlist_half_sort()
{
    SeqList L(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---����˳�����۰����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char seqlist_half_menu_key;
        cin >> seqlist_half_menu_key;
        switch (seqlist_half_menu_key)
        {
        case '1': L.PrintList(2); break;
        case '2': seqlist_half_word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }
    return;
}

//˳����۰���Ҳ˵�
void seqlist_half_word_sort_menu()
{
    SeqList L(linelist_word_fre, k);
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << L.return_word(i) << endl;
        cout << "�˵��ʵĴ�Ƶ��" << L.return_fre(i) << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << double((log(double(k) + 1) / log(2)) - 1) << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;

    }
    system("pause");
    return;

}

//������������ز˵�
//�����������˵�
void Bitree_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---��������������---" << endl;
        cout << "1.���ڶ�����������˳�����" << endl;
        cout << "2.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char Bitree_menu_key;
        cin >> Bitree_menu_key;
        switch (Bitree_menu_key)
        {
        case '1': Bitree_seq_sort(); break;
        case '2': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//���ڶ�����������˳�����
void Bitree_seq_sort()
{
    BiSortTree B(linelist_word_fre, k);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---����˳����˳�����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char Bitree_seq_sort_key;
        cin >> Bitree_seq_sort_key;
        switch (Bitree_seq_sort_key)
        {
        case '1': B.printf(); break;
        case '2': Bitree_word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//�������������ҵ��ʲ˵�
void Bitree_word_sort_menu()
{
    BiSortTree B(linelist_word_fre, k);
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << p->data.word << endl;
        cout << "�˵��ʵĴ�Ƶ��" << p->data.frequency << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << k << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }
    system("pause");
    return;
}

//��ϣ����غ���
//��ϣ��˵�
void Hash_menu()
{
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---��ϣ��---" << endl;
        cout << "1.���ڿ��ŵ�ַ���Ĺ�ϣ����" << endl;
        cout << "2.��������ַ���Ĺ�ϣ����" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char Hash_menu_key;
        cin >> Hash_menu_key;
        switch (Hash_menu_key)
        {
        case '1': open_Hash_sort(); break;
        case '2': link_Hash_sort(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }
    return;
}

void open_Hash_word_sort_menu()
{
    HashTable1 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    double load_factor = k / MaxSize;//ɢ�б��װ������
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << HT.Get(i).word << endl;
        cout << "�˵��ʵĴ�Ƶ��" << HT.Get(i).frequency << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << (1 + 1 / (1 - load_factor)) / 2 << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;

    }
    system("pause");
    return;
}

//���ڿ��ŵ�ַ���Ĺ�ϣ����
void open_Hash_sort()
{
    HashTable1 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---���ڿ��ŵ�ַ���Ĺ�ϣ����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char open_Hash_sort_key;
        cin >> open_Hash_sort_key;
        switch (open_Hash_sort_key)
        {
        case '1': HT.Print(); break;
        case '2': open_Hash_word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

//��������ַ���Ĺ�ϣ����
void link_Hash_sort()
{
    HashTable2 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    for (; 1;)
    {
        system("cls");
        cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
        cout << "---��������ַ���Ĺ�ϣ����---" << endl;
        cout << "1.��Ƶͳ��" << endl;
        cout << "2.���ʲ���" << endl;
        cout << "3.������һ��" << endl;
        cout << "�밴��Ӧ�����ּ�����ѡ��" << endl;
        char link_Hash_sort_key;
        cin >> link_Hash_sort_key;
        switch (link_Hash_sort_key)
        {
        case '1': HT.Print(); break;
        case '2': link_Hash_word_sort_menu(); break;
        case '3': return;
        default: cout << "����Ĳ�����Ч���ţ�����������" << endl; system("pause");
        }
    }

    return;
}

void link_Hash_word_sort_menu()
{
    HashTable2 HT;
    for (int j = 0; j < k; j++)
        HT.Insert(linelist_word_fre[j]);
    double load_factor = k / MaxSize;//ɢ�б��װ������
    system("cls");
    cout << "*******************���ڲ�ͬ���Ե�Ӣ�ĵ��ʵĴ�Ƶͳ�ƺͼ���ϵͳ*******************" << endl;
    cout << "---���ʲ���---" << endl;
    cout << "������Ҫ���ҵĵ��ʣ�";
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
        cout << "�˵���Ϊ��" << p->data.word << endl;
        cout << "�˵��ʵĴ�Ƶ��" << p->data.frequency << endl;
        cout << "���Ҹõ��������ѵ�ʱ�䣺" << time * 1000000 << "ns" << endl;
        cout << "ƽ�����ҳ��ȣ�" << 1 + (load_factor) / 2 << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;

    }
    system("pause");
    return;
}


int main()
{
    word_frequency_statistics();
    major_menu();//���˵�
    return 0;
}