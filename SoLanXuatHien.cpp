#include<iostream>
using namespace std;

typedef struct Node
{
	int Info;
	struct Node* PNext;
}NODE;

typedef struct List
{
	NODE* PHead;
	NODE* PTail;
}LIST;

void CreateList(LIST& L)
{
	L.PHead = NULL;
	L.PTail = NULL;
}

bool IsEmpty(LIST L)
{
	if (L.PHead == NULL) return 1;
	else return 0;
}

NODE* GetNode(int x)
{
	NODE* PNew = new NODE;
	if (PNew == NULL)
	{
		exit(1);
	}
	else
	{
		PNew->Info = x;
		PNew->PNext = NULL;
	}
	return PNew;
}

void AddList(LIST& L, Node* P)
{
	if (IsEmpty(L) == 1)
	{
		L.PHead = P;
		L.PTail = L.PHead;
	}
	else
	{
		L.PTail->PNext = P;
		L.PTail = P;
	}
}

void ReadTheData(LIST& L)
{
	CreateList(L);
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		NODE* PNew = GetNode(x);
		AddList(L, PNew);
	}
}

int Count(LIST L, int x)
{
	int dem = 0;
	NODE* p = L.PHead;
	while (p != NULL)
	{
		if (p->Info == x) dem++;
		p = p->PNext;
	}
	return dem;
}

bool Find(LIST L, int x)
{
	NODE* p = L.PHead;
	while (p != NULL)
	{
		if (p->Info == x) return 1;
		p = p->PNext;
	}
	return 0;
}

void PrintTheReSult(LIST L,LIST &Check)
{
	NODE* Pout = L.PHead;
	CreateList(Check);
	if (IsEmpty(L)) cout << "Danh sach rong.";
	else
	{
		cout << "Danh sach vua nhap la: ";
		while (Pout != NULL)
		{
			cout << Pout->Info << " ";
			Pout = Pout->PNext;
		}
		cout << endl << "So lan xuat hien cua tung phan tu trong danh sach la: " << endl;
		NODE* P = L.PHead;
		while (P != NULL)
		{
			if (Count(L, P->Info) != 0 && Find(Check,P->Info) == 0) 
			{
				cout << P->Info << ": " << Count(L, P->Info);
				cout << endl;
				NODE* P2 = GetNode(P->Info);
				AddList(Check, P2);
			}
			P = P->PNext;
		}
	}
}

int main()
{
	LIST L,Check;
	int Max = -100000;

	ReadTheData(L);
	PrintTheReSult(L,Check);

	return 0;
}