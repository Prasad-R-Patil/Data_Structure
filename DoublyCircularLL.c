#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE Head, PNODE Tail)
{
    do
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    } while (Head != (Tail)->next);
    printf("NULL\n");
}
int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        Head = Head->next;
    } while (Head != Tail->next);
    return iCnt;
}
void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head) == NULL && (*Tail) == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn->next = (*Head);
        newn->next->prev = newn;
        *Head = newn;
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);
}
void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*Head) == NULL && (*Tail) == NULL)
    {
        return;
    }
    if ((*Head) == (*Tail))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        PNODE temp = (*Head);

        while (temp->next != (*Tail)->next)
        {
            temp = temp->next;
        }
        temp->next = newn;
        temp->next->prev = temp;
        *Tail = newn;
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);
}
void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    int iSize = Count((*Head), (*Tail));

    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (iPos < 0 || iPos > iSize + 1)
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(Head, Tail, iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(Head, Tail, iNo);
    }
    else
    {
        PNODE temp = (*Head);

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        temp->next->prev = temp;
    }
}
void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if (*Head == NULL && *Tail == NULL)
    {
        return;
    }

    if ((*Head) == (*Tail))
    {
        free(*Head);
        free(*Tail);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        PNODE temp = (*Head);
        *Head = (*Head)->next;
        free(temp);
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);
}
void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if (*Head == NULL && *Tail == NULL)
    {
        return;
    }

    if (*Head == (*Tail))
    {
        free(*Head);
        free(*Tail);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        PNODE temp = (*Head);

        while (temp->next->next != (*Tail)->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        *Tail = temp;
    }
    (*Tail)->next = (*Head);
    (*Head)->prev = (*Tail);
}
void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{

    int iSize = Count(*Head, *Tail);

    if (iPos < 0 || iPos > iSize)
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    else if (iPos == iSize + 1)
    {
        DeleteLast(Head, Tail);
    }
    else
    {
        PNODE temp = (*Head);
        PNODE targated = NULL;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        targated = temp->next;
        temp->next = targated->next;
        temp->next->prev = temp;
        free(targated);
    }
}
int main()
{
    PNODE first = NULL;
    PNODE last = NULL;

    int iChoice = 0, iNo = 0, iPos = 0, iRet = 0;

    while (1)
    {
        printf("\n________________________________________\n");
        printf("Enter the desired operation that you want to perform on linkedlist\n");
        printf("1:Insert the node at frist position\n");
        printf("2:Insert the node at last position\n");
        printf("3:Insert the node at desired position\n");
        printf("4:Delete the frist node\n");
        printf("5:Delete the last node\n");
        printf("6:Delete the node at desired position\n");
        printf("7:Display the content of linked list\n");
        printf("8:Count the number of nodes from linked list\n");
        printf("0:Terminate the application\n");
        printf("_____________________________________________________\n");
        scanf("%d", &iChoice);
        iPos = 0;
        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);

            InsertFirst(&first, &last, iNo);
            break;
        case 2:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);

            InsertLast(&first, &last, iNo);
            break;
        case 3:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);

            printf("Enter the position\n");
            scanf("%d", &iPos);

            InsertAtPos(&first, &last, iNo, iPos);

            break;
        case 4:
            DeleteFirst(&first, &last);
            break;
        case 5:
            DeleteLast(&first, &last);
            break;
        case 6:
            printf("Enter the position\n");
            scanf("%d", &iPos);
            DeleteAtPos(&first, &last, iPos);
            break;
        case 7:
            Display(first, last);
            break;
        case 8:
            iRet = Count(first, last);
            printf("Number of nodes in the linked list are %d\n", iRet);
            break;
        case 0:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}