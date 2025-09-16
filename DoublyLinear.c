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
void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d|->", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}
int Count(PNODE Head)
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}
void InsertFirst(PPNODE Head, int iNo)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = (*Head);
        newn->next->prev = newn;
        *Head = newn;
    }
}
void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
        *Head = newn;
    }
    else
    {
        PNODE temp = (*Head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        temp->next->prev = temp;
    }
}
void InsertAtPos(PPNODE Head, int iNo, int iPos)
{
    int iSize = Count(*Head);
    PNODE newn = NULL;
    newn = malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (iPos < 0 || iPos > iSize + 1)
    {
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(Head, iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(Head, iNo);
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
void DeleteFirst(PPNODE Head)
{
    if (*Head == NULL)
    {
        return;
    }
    if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = (*Head);
        *Head = (*Head)->next;
        free(temp);
    }
}
void DeleteLast(PPNODE Head)
{
    if (*Head == NULL)
    {
        return;
    }
    if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = (*Head);
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = Count(*Head);

    if (iPos < 0 || iPos > iSize)
    {
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if (iPos == iSize)
    {
        DeleteLast(Head);
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
        printf("\n_____________________________________________________\n");

        scanf("%d", &iChoice);
        iPos = 0;
        switch (iChoice)
        {
        case 1:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);
            InsertFirst(&first, iNo);

            break;
        case 2:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);
            InsertLast(&first, iNo);
            break;
        case 3:
            printf("Enter the data to insert\n");
            scanf("%d", &iNo);
            printf("Enter the position\n");
            scanf("%d", &iPos);
            InsertAtPos(&first, iNo, iPos);
            break;
        case 4:
            DeleteFirst(&first);
            break;
        case 5:
            DeleteLast(&first);
            break;
        case 6:
            printf("Enter the position\n");
            scanf("%d", &iPos);
            DeleteAtPos(&first, iPos);
            break;
        case 7:
            Display(first);
            break;
        case 8:
            iRet = Count(first);
            printf("Number of notes in the linked list are %d\n", iRet);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Enter invalid Choice\n");
        }
    }

    return 0;
}