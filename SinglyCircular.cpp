#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
class SinglyCircular
{
private:
    PNODE first;
    PNODE last;
    int size;

public:
    SinglyCircular();
    void Display();
    int Count();
    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void InsertAtPos(int iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};
SinglyCircular::SinglyCircular()
{
    first = NULL;
    last = NULL;
    size = 0;
}
void SinglyCircular::Display()
{
    PNODE temp = first;
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != last->next);
}
int SinglyCircular::Count()
{
    return size;
}
void SinglyCircular::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    size++;
}
void SinglyCircular::InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        PNODE temp = first;

        while (temp->next != last->next)
        {
            temp = temp->next;
        }
        temp->next = newn;
        last = newn;
    }
    last->next = first;
    size++;
}
void SinglyCircular::InsertAtPos(int iNo, int iPos)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

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
        temp->next = newn;
        size++;
    }
}
void SinglyCircular::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    if (first == last)
    {
        delete first;
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;

        first = first->next;
        delete temp;
    }
    last->next = first;
    size--;
}
void SinglyCircular::DeleteLast()
{

    if (first == NULL && last == NULL)
    {
        return;
    }
    if (first == last)
    {
        delete first;
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;

        while (temp->next->next != last->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        last = temp;
    }
    last->next = first;
    size--;
}
void SinglyCircular::DeleteAtPos(int iPos)
{
    if (iPos < 0 || iPos > size)
    {
        size--;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size)
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
        size--;
    }
}
int main()
{

    SinglyCircular *sobj = new SinglyCircular();
    int iChoice = 0, iPos = 0, iRet = 0, iNo = 0;

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
            sobj->InsertFirst(iNo);
            break;
        case 2:
            cout << "Enter the data to insert\n";
            cin >> iNo;
            sobj->InsertLast(iNo);
            break;
        case 3:
            cout << "Enter the data to insert\n";
            cin >> iNo;
            cout << "Enter the position\n";
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
            cout << "Enter the position\n";
            cin >> iPos;
            sobj->DeleteAtPos(iPos);
            break;
        case 7:
            sobj->Display();
            break;
        case 8:
            iRet = sobj->Count();
            cout << "Number of nodes in the linked list are " << iRet << endl;
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Enter Invalid Choise\n";
            break;
        }
    }
    return 0;
}