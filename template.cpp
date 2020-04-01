

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Data
{
    int n;
};
struct NODE
{
    Data data;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
//craete node
NODE *CreateNode(Data data)
{
    NODE *node = new NODE;
    if (node == NULL)
    {
        return NULL;
    }
    node->data = data;  //gan data cho node
    node->pNext = NULL; //pNext tro toi null
}
//Khoi tao danh sach lien ket
void Init(LIST &lst)
{
    lst.pHead = lst.pTail = NULL;
}
bool isEmpty(LIST lst)
{
    if (lst.pHead == NULL)
    {
        return true;
    }
}
void AddHead(LIST &lst, NODE *pNode)
{
    if (isEmpty(lst))
    {
        lst.pHead = lst.pTail = pNode;
    }
    else
    {
        pNode->pNext = lst.pHead;
        lst.pHead = pNode;
    }
}
void AddTail(LIST &lst, NODE *p)
{
    if (lst.pHead == NULL)
    {
        lst.pHead = lst.pTail = p;
    }
    else
    {
        lst.pTail->pNext = p;
        lst.pTail = p;
    }
}
void Input(LIST &lst)
{
    Init(lst); // khoi tao node
    for (int i = 1;; i++)
    {
        Data x;
        cin >> x.n;
        if (x.n == 0 && i == 1)
        {
            cout << "Danh sach rong.";
            break;
        }
        if (x.n == 0)
        {
            break;
        }
        NODE *p = CreateNode(x);
        AddTail(lst, p);
    }
}
void Output(LIST lst)
{
    int dem = 0;
    NODE *i;
    for (i = lst.pHead; i != NULL; i = i->pNext)
    {
        dem++;
        // if (i->data.n == 0)
        // {
        //     cout << "Danh sach rong.";
        //     break;
        // }
        cout << i->data.n << " ";
        // if (i->data.n == 0)
        // {
        //     break;
        // }
    }
    if (dem != 0)
        cout << "\nDanh sach co " << dem << " phan tu.";
}

int main()
{

    LIST lst;
    Input(lst);
    if (isEmpty(lst) == false)
        cout << "Danh sach vua nhap la: ";
    Output(lst);
    return 0;
}
struct Node
{
	int info;
	Node* pNext;
};
struct List
{
	Node* pHead;	
	Node* pTail;	
};

void CreateList(List &l)
{
	l.pHead = NULL;		
	l.pTail = NULL;		
}


Node* CreateNode(int newinfo)
{
	Node* p = new Node;
	if (p == NULL)	
	{
		return NULL;	
	}
	p->info = newinfo;
	p->pNext = NULL;
	return p;
}



void AddTail(List &l, Node* p)
{
	if (l.pHead == NULL)		
		l.pHead = l.pTail = p;	
	else
	{
		l.pTail->pNext = p;		
		l.pTail = p;			
	}
}


void NhapDuLieu(List &l,int &Dem)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0) break;
		Dem++;
		Node* p = CreateNode(x);	
		AddTail(l, p);
	}
}

void XuatDuLieu(List &l, int Dem)
{
	if (Dem == 0)
	{
		cout << "Danh sach rong.";
	}
	else
	{
		cout << "Danh sach vua nhap la:";
		for (Node* i = l.pHead; i != NULL; i = i->pNext)
			cout << " " << i->info;
		cout << endl<<"Danh sach co " << Dem << " phan tu.";
	}
}


int main()
{
	List l;
	int Dem = 0;
	CreateList(l);
	NhapDuLieu(l,Dem);
	XuatDuLieu(l,Dem);
	cout << endl;
	return 0;
}