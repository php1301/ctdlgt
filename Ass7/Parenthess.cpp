#include <iostream>
using namespace std;

struct NODE
{
   char info;
   struct NODE *pNext;
};

struct STACK
{
   NODE *pHead;
   NODE *pTail;
};

void CreateStack(STACK &s)
{
   s.pHead = NULL;
   s.pTail = NULL;
}

NODE *CreateNode(char x)
{
   NODE *p = new NODE;
   if (p == NULL)
      return NULL;
   p->info = x;
   p->pNext = NULL;
   return p;
}

bool IsEmpty(STACK s)
{
   if (s.pHead == NULL)
      return true;
   return false;
}

void Push(STACK &s, NODE *p)
{
   if (s.pHead == NULL)
      s.pHead = s.pTail = p;
   else
   {
      p->pNext = s.pHead;
      s.pHead = p;
   }
}

void Pop(STACK &s)
{
   NODE *p = s.pHead;
   s.pHead = s.pHead->pNext;
   delete p;
}

int Top(STACK &s, char &trave)
{
   if (!IsEmpty(s))
   {
      trave = s.pHead->info;
      return trave;
   }
}

int chk2(char b)
{
   char a = b;
   if (a == ')')
      return 2;
   else if (a == ']')
      return 3;
   else if (a == '}')
      return 4;
   else
      return 0;
}

int chk1(char a)
{
   if (a == '(')
      return 2;
   else if (a == '[')
      return 3;
   else if (a == '{')
      return 4;
   else
      return 0;
}

bool Check(string asb)
{
   string str = asb;
   int top = 0;
   int n;
   char x;
   n = str.length();
   STACK a;
   NODE *PNode;
   CreateStack(a);
   char s;
   for (int i = 0; i < n; i++)
   {
      if (str[i] == '(' || str[i] == '[' || str[i] == '{')
      {
         PNode = CreateNode(str[i]);
         Push(a, PNode);
         continue;
      }

      if (IsEmpty(a))
         return false;

      switch (str[i])
      {
      case ')':

         x = Top(a, s);
         Pop(a);
         if (x == '{' || x == '[')
            return false;
         break;

      case '}':

         x = Top(a, s);
         Pop(a);
         if (x == '(' || x == '[')
            return false;
         break;

      case ']':

         x = Top(a, s);
         Pop(a);
         if (x == '(' || x == '{')
            return false;
         break;
      }
   }
   return (IsEmpty(a));
}

int main()
{
   string a;
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> a;
      if (Check(a) == true)
      {
         cout << "YES";
      }
      else
      {
         cout << "NO";
      }
   }
}