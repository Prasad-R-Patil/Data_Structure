#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
   int iSize;
   int Top;
   char *Arr;
};

typedef struct stack STACK;
typedef struct stack *PSTACK;

int isEmpty(PSTACK ptr)
{
   if (ptr->Top == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
int isFull(PSTACK ptr)
{
   if (ptr->Top == ptr->iSize - 1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
void Push(PSTACK ptr, char ch)
{
   if (isFull(ptr))
   {
      printf("Stack is Full\n");
   }
   else
   {
      ptr->Top++;
      ptr->Arr[ptr->Top] = ch;
   }
}
char Pop(PSTACK ptr)
{
   if (isEmpty(ptr))
   {
      printf("Stack is empty\n");
   }
   else
   {
      char ch = ptr->Arr[ptr->Top];
      ptr->Top--;
      return ch;
   }
}
int match(char a, char b)
{
   if ((a == '(' && b == ')') || (a == '{' && b == '}') || a == '[' && b == ']')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
bool MultipleParenthesis(PSTACK ptr, char *Exp)
{
   int i = 0;
   while (Exp[i] != '\0')
   {
      if (Exp[i] == '(' || Exp[i] == '{' || Exp[i] == '[')
      {
         Push(ptr, Exp[i]);
      }
      else if (Exp[i] == ')' || Exp[i] == '}' || Exp[i] == ']')
      {
         if (isEmpty(ptr))
         {
            return false;
         }
         char ch = Pop(ptr);

         if (!match(ch, Exp[i]))
         {
            return false;
         }
      }
      i++;
   }
   if (isEmpty(ptr))
   {
      return true;
   }
   else
   {
      return false;
   }
}
int main()
{
   char Exp[50];
   PSTACK sp = NULL;

   sp = (PSTACK)malloc(sizeof(STACK));

   sp->iSize = 80;
   sp->Top = -1;
   sp->Arr = (char *)malloc(sizeof(char) * sp->iSize);

   printf("Enter the expression\n");
   scanf("%[^'\n']s", Exp);

   bool bRet = MultipleParenthesis(sp, Exp);

   if (bRet == true)
   {
      printf("Parenthesis is match\n");
   }
   else
   {
      printf("Parenthesis is not match\n");
   }

   return 0;
}