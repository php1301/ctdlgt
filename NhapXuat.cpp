#include <iostream>
using namespace std;
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