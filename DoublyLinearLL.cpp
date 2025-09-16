#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;

class DoublyLinearLL
{
private:
    PNODE first;
    int size;

public:
    DoublyLinearLL();
    void Display();
    int Count();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};
DoublyLinearLL::DoublyLinearLL()
{
    first = NULL;
    size = 0;
}
void DoublyLinearLL::Display()
{
    PNODE temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int DoublyLinearLL::Count()
{
    return size;
}
void DoublyLinearLL::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }

    size++;
}
void DoublyLinearLL::InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

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
        temp->next->prev = temp;
    }
    size++;
}
void DoublyLinearLL::InsertAtPos(int iNo, int iPos)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (iPos < 0 || iPos > size + 1)
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == size + 1)
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
        newn->next->prev = newn;
        temp->next = newn;
        temp->next->prev = temp;
        size++;
    }
}
void DoublyLinearLL::DeleteFirst()
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
        first->prev = NULL;
        delete temp;
    }
    size--;
}
void DoublyLinearLL::DeleteLast()
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
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}
void DoublyLinearLL::DeleteAtPos(int iPos)
{
    if (iPos < 0 || iPos > size)
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size + 1)
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
        temp->next->prev = temp;
        delete targated;
        size--;
    }
}
int main()
{
    DoublyLinearLL *dobj = new DoublyLinearLL();
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
            cout << "Enter the data to insert\n";
            cin >> iNo;
            dobj->InsertFirst(iNo);
            break;
        case 2:
            cout << "Enter the data to insert\n";
            cin >> iNo;
            dobj->InsertLast(iNo);
            break;
        case 3:
            cout << "Enter the data to insert\n";
            cin >> iNo;
            cout << "Enter the position\n";
            cin >> iPos;
            dobj->InsertAtPos(iNo, iPos);
            break;
        case 4:
            dobj->DeleteFirst();
            break;
        case 5:
            dobj->DeleteLast();
            break;
        case 6:
            cout << "Enter the position\n";
            cin >> iPos;
            dobj->DeleteAtPos(iPos);
            break;
        case 7:
            dobj->Display();
            break;
        case 8:
            iRet = dobj->Count();
            cout << "Number nodes in the linked list are " << iRet << endl;
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