#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class linkedlist
{
public:
    Node *head;
    Node *tail;
    int size;
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertnode(int);
    void insertnodeatbegin(int);
    void insertnodeatapos(int, int);
    void printlist();
    void frontDelete();
    void deletenode(int);
    void endDelete();
    bool search(int);
    int nthposvalue(int);
    int valuepos(int);
    void sort();
    void reverse();
};

void linkedlist::insertnode(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}
void linkedlist::insertnodeatbegin(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    tail->next = head;
    size++;
}
void linkedlist::insertnodeatapos(int data, int pos)
{
    if (pos > size + 1 || pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }

    if (pos == 1)
    {
        insertnodeatbegin(data);
        return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;
    while (pos-- > 2)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}
void linkedlist::printlist()
{

    if (head == NULL)
    {
        cout << "listemplty()" << endl;
        return;
    }
    Node *tem = head;
    while (tem->next != head)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
    cout << tem->data << endl;
}
void linkedlist::frontDelete()
{
    if (head == NULL)
    {
        cout << "The list is already empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    tail->next = head;

    delete temp;
}
void linkedlist::endDelete()
{
    if (head == NULL)
    {
        cout << "The list is already empty" << endl;
        return;
    }
    Node *tem = head;
    Node *tem1 = NULL;
    while (tem->next != head)
    {
        tem1 = tem;
        tem = tem->next;
    }
    tem1->next = head;
    tail = tem1;
    delete tem;
}
void linkedlist::deletenode(int pos)
{
    if (head == NULL)
    {
        cout << "listemplty()" << endl;
        return;
    }
    if (pos > size + 1 || pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (pos == size)
    {
        endDelete();
        return;
    }
    Node *tem = head;
    if (pos == 1)
    {
        frontDelete();
        return;
    }
    Node *tem1 = NULL;
    while (pos-- > 1)
    {
        tem1 = tem;
        tem = tem->next;
    }
    tem1->next = tem->next;
    delete tem;
}
bool linkedlist::search(int val)
{
    if (head == NULL)
    {
        return false;
    }
    Node *tem = head;
    while (tem->next != head)
    {
        if (tem->data == val)
            return true;
        tem = tem->next;
    }
    return false;
}
int linkedlist::nthposvalue(int pos)
{
    if (head == NULL)
    {
        cout << "listemplty()" << endl;
        return -1;
    }
    if (pos > size + 1 || pos < 1)
    {
        std::cout << "Invalid position" << std::endl;
        return -1;
    }
    Node *tem = head;
    if (pos == 1)
    {
        return head->data;
    }
    while (pos-- > 1)
    {
        tem = tem->next;
    }
    return tem->data;
}
int linkedlist::valuepos(int val)
{
    Node *tem = head;
    int pos = 0;
    while (tem->next != NULL)
    {
        pos++;
        if (tem->data == val)
            return pos;
        tem = tem->next;
    }
    return -1;
}
void linkedlist::sort()
{
    Node *current = head;
    Node *index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }

    while (current->next != head)
    {
        index = current->next;

        while (index != head)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
void linkedlist::reverse()
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != head)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main()
{
    linkedlist list;
    list.insertnode(3);
    list.insertnode(0);
    list.insertnode(9);
    list.insertnode(5);
    list.insertnode(9);
    list.insertnode(367889);
    // list.deletenode(3);
    list.insertnode(987);
    list.insertnode(79);
    list.insertnode(45);
    // list.insertnodeatbegin(2431);
    // list.insertnodeatbegin(21);
    list.insertnodeatapos(10, 2);
    // list.frontDelete();
    // list.insertnodeatapos(10, 15);
    // list.deletenode(3);
    list.endDelete();
    cout << "Beforesort" << endl;
    list.printlist();
    // list.frontDelete();
    // list.endDelete();
    // list.reverse();

     list.sort();
    cout << "aftersort" << endl;
    list.printlist();
    //     cout << (list.search(9) ? "YES" : "NO") << endl;
    //     cout << (list.search(10) ? "YES" : "NO") << endl;
    //     cout << list.nthposvalue(3) << endl;
    //     cout << list.valuepos(79) << endl;
    return 0;
}
