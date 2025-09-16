#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLinear
{
private:
    PNODE first;
    int iSize;

public:
    SinglyLinear();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void Display();
    int Count();
};
SinglyLinear::SinglyLinear()
{
    first = NULL;
    iSize = 0;
}
void SinglyLinear::Display()
{
    PNODE temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int SinglyLinear::Count()
{
    return iSize;
}
void SinglyLinear::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iSize++;
}
void SinglyLinear::InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        PNODE temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}
void SinglyLinear::InsertAtPos(int iNo, int iPos)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if (iPos < 0 || iPos > iSize + 1)
    {
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE temp = first;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}
void SinglyLinear::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        first = first->next;
        delete temp;
    }
    iSize--;
}
void SinglyLinear::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }

    if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}
void SinglyLinear::DeleteAtPos(int iPos)
{
    if (iPos < 0 || iPos > iSize)
    {
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        PNODE targated = NULL;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        targated = temp->next;

        temp->next = targated->next;
        delete targated;
        iSize--;
    }
}
int main()
{
    SinglyLinear *sobj = new SinglyLinear();
    int iChoice = 0, iNo = 0, iPos = 0, iRet = 0;
    while (1)
    {
        cout << "\n________________________________________" << endl;
        cout << "Enter the desired operation that you want to perform on linkedlist" << endl;
        cout << "1:Insert the node at frist position" << endl;
        cout << "2:Insert the node at last position" << endl;
        cout << "3:Insert the node at desired position" << endl;
        cout << "4:Delete the frist node" << endl;
        cout << "5:Delete the last node" << endl;
        cout << "6:Delete the node at desired position" << endl;
        cout << "7:Display the content of linked list" << endl;
        cout << "8:Count the number of nodes from linked list" << endl;
        cout << "0:Terminate the application" << endl;
        cout << "_____________________________________________________" << endl;
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "Enter the data to insert" << endl;
            cin >> iNo;
            sobj->InsertFirst(iNo);
            break;
        case 2:
            cout << "Enter the data to insert" << endl;
            cin >> iNo;
            sobj->InsertLast(iNo);
            break;
        case 3:
            cout << "Enter the data to insert" << endl;
            cin >> iNo;
            cout << "Enter the position" << endl;
            cin >> iPos;
            sobj->InsertAtPos(iNo, iPos);
            break;
        case 4:
            sobj->DeleteFirst();
            break;
        case 5:
            sobj->DeleteLast();
            break;
        case 6:
            cout << "Enter the Position" << endl;
            cin >> iPos;
            sobj->DeleteAtPos(iPos);
            break;
        case 7:
            sobj->Display();
            break;
        case 8:
            iRet = sobj->Count();
            cout << "NUmber of nodes in the linked list are " << iRet << endl;
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