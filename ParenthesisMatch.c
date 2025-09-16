#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack
{
    int iSize;
    int Top;
    char *Arr;
};

typedef struct stack STACK;
typedef struct stack * PSTACK;

int isFull(PSTACK ptr)
{
   if(ptr->Top==ptr->iSize-1)
   {
       return 1;
   }
   else
   {
      return 0;
   }
}
int isEmpty(PSTACK ptr)
{
   if(ptr->Top==-1)
   {
       return 1;
   }
   else
   {
      return 0;
   }
}
void Push(PSTACK ptr,char ch)
{
   if(isFull(ptr))
   {
       printf("Stack is Full\n");
   }
   else
   {
       ptr->Top++;
       ptr->Arr[ptr->Top]=ch;
   }
}
void Pop(PSTACK ptr)
{
   if(isEmpty(ptr))
   {
      printf("Stack is Empty\n");
   }
   else
   {
      ptr->Top--;
   }
}
bool ParenthesisMatching(PSTACK ptr,char *Exp)
{
    while(*Exp != '\0')
    {
        if(*Exp=='(')
        {
            Push(ptr,*Exp);
        }
        else if(*Exp==')')
        {
            if(isEmpty(ptr))
            {
                return false;
            }
            Pop(ptr);
        }
        Exp++;
    }
    if(isEmpty(ptr))
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
    PSTACK sp=NULL;
    char Exp[50];
    bool bRet=false;


    sp=(PSTACK)malloc(sizeof(STACK));
    sp->iSize=80;
    sp->Top=-1;
    sp->Arr=(char *)malloc(sizeof(char)*sp->iSize);

    printf("Enter the Expression\n");
    scanf("%[^'\n']s",Exp);

    bRet=ParenthesisMatching(sp,Exp);

    if(bRet==true)
    {
        printf("Parenthesis is matching\n");
    }
    else
    {
      printf("Parenthesis is not matching\n");
    }
    return 0;
}