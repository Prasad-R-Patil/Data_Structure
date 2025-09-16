#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *Arr;
};

typedef struct stack STACK;
typedef struct stack *PSTACK;
typedef struct stack **PPSTACK;
int Peek(PSTACK Ptr)
{
    return Ptr->Arr[Ptr->top];
}
int StackBottom(PSTACK Ptr)
{
    return Ptr->Arr[0];
}
int isFull(PSTACK Ptr)
{
    if (Ptr->top == Ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(PSTACK Ptr)
{
    if (Ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Push(PPSTACK Ptr, int iNo)
{
    if (isFull(*Ptr))
    {
        printf("Stack is OverFlow...\n");
    }
    else
    {
        (*Ptr)->top++;
        (*Ptr)->Arr[(*Ptr)->top] = iNo;
    }
}
int Pop(PPSTACK Ptr)
{
    if (isEmpty(*Ptr))
    {
        printf("Stack is UnderFlow....\n");
        return -1;
    }
    else
    {
        int iNo = (*Ptr)->Arr[(*Ptr)->top];
        (*Ptr)->top--;
        return iNo;
    }
}
int *Display(PSTACK Ptr)
{
    int i = 0;
   
    int *Brr = NULL;
    Brr = (int *)malloc(sizeof(int) * Ptr->top + 1);

    for (i = 0; i <= Ptr->top; i++)
    {
        Brr[i] = Ptr->Arr[i];
    }
    return Brr;
}

int main()
{
    PSTACK sobj = NULL;
    int iChoice = 0;
    int iNo = 0;
    int *Brr = NULL;
    int i = 0;
    sobj = (PSTACK)malloc(sizeof(STACK));

    sobj->size = 100;
    sobj->top = -1;
    sobj->Arr = (int *)malloc(sizeof(int) * sobj->size);

    while (1)
    {
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Size\n");
        printf("7. Peek\n");
        printf("8. StackBottom\n");
        printf("9. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Plese Enter the number to Push into stack\n");
            scanf("%d", &iNo);

            Push(&sobj, iNo);
            break;
        case 2:
            printf("Pop elements is %d\n", Pop(&sobj));
            break;
        case 3:
            Brr = Display(sobj);

            for (i = 0; i <= sobj->top; i++)
            {
                printf("%d\n", Brr[i]);
            }
            break;
        case 4:

            if (isEmpty(sobj))
            {
                printf("Stack is UnderFlow..\n");
            }
            else
            {
                printf("Stack is not UnderFlow..\n");
            }

            break;
        case 5:

            if (isFull(sobj))
            {
                printf("Stack is OverFlow..\n");
            }
            else
            {
                printf("Stack is not OverFlow..\n");
            }
            break;
        case 6:
            printf("Size of Stack is %d\n", sobj->top + 1);
            break;
        case 7:
            printf("The Top most elements of stack is %d\n", Peek(sobj));
            break;
        case 8:
            printf("The Bottom most elements of stack is %d\n", StackBottom(sobj));
            break;
        case 9:
            printf("Exit from Application\n");
            exit(0);
            break;
        default:
            printf("Plese enter the valid choise..\n");
            break;
        }
    }

    return 0;
}