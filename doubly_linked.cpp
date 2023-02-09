#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *pre;
    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->pre = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
};
class linkedlist
{

public:
    Node *head;
    Node *tail;
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_head(int);
    void insert_at_tail(int);
    void insert_at_pos(int, int);
    void delete_at_head();
    void delete_at_tail();
    void delete_at_pos(int);
    void display();
    void backwarddisply();
    void sort();
    bool search(int);
    int nthposvalue(int);
    int valuepos(int);
    void reverse();
};
void linkedlist::insert_at_head(int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }
    newnode->next = head;
    if (head != NULL)
    {
        head->pre = newnode;
    }

    head = newnode;
}

void linkedlist::insert_at_tail(int value)
{

    if (head == NULL)
    {
        insert_at_head(value);
        return;
    }

    Node *newnode = new Node(value);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->pre = temp;
    tail = newnode;
    newnode->next=NULL;
}
void linkedlist::insert_at_pos(int data, int pos)
{
    if (head == NULL)
    {
        insert_at_head(data);
        return;
    }
    int listsize = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        listsize++;
        temp = temp->next;
    }
    if (pos >= listsize)
    {
        insert_at_tail(data);
        return;
    }
    Node *tem1;
    temp = head;
    Node *newnode = new Node(data);
    while (pos-- > 1)
    {
        tem1 = temp;
        temp = temp->next;
    }
    tem1->next = newnode;
    newnode->pre = tem1;
    newnode->next = temp;
    temp->pre = newnode;
}
void linkedlist::delete_at_head()
{
    Node *tem = head;
    if (tem == NULL)
    {
        return;
    }
    head = tem->next;
    head->pre = NULL;
    delete tem;
}
void linkedlist::delete_at_tail()
{
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    Node *tem1;
    while (temp->next != NULL)
    {
        tem1 = temp;
        temp = temp->next;
    }
    tem1->next = NULL;
    delete temp;
}
void linkedlist::delete_at_pos(int pos)
{
    if (head == NULL)
    {
        return;
    }
    int listsize = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        listsize++;
        temp = temp->next;
    }
    if (pos > listsize)
    {
        return;
    }
    if (pos == listsize)
    {
        delete_at_tail();
        return;
    }
    if (pos == 1)
    {
        delete_at_head();
        return;
    }
    Node *tem1;
    temp = head;
    while (pos-- > 1)
    {
        tem1 = temp;
        temp = temp->next;
    }
    tem1->next = temp->next;
    Node *f = temp->next;
    f->pre = tem1;
    delete temp;
}
void linkedlist::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void linkedlist::backwarddisply()
{
    Node *temp = tail;
    // while (temp->next != NULL)
    // {

    //     temp = temp->next;
    // }
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->pre;
    }
    cout << endl;
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

    while (current->next != NULL)
    {
        index = current->next;

        while (index != NULL)
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
bool linkedlist::search(int val)
{
    if (head == NULL)
    {
        return false;
    }
    Node *tem = head;
    while (tem->next != NULL)
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
        return -1;
    }
    Node *tem = head;
    int listsize = 0;
    while (tem->next != NULL)
    {
        listsize++;
        tem = tem->next;
    }
    if (listsize < pos)
    {

        return -1;
    }
    tem = head;
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
void linkedlist::reverse()
{
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;
    }
    if (temp != NULL)
        head = temp->pre;
}
int main()
{
    linkedlist list;
    list.insert_at_tail(1);
    list.insert_at_tail(2);
    list.insert_at_tail(2);
    list.insert_at_tail(9);
    list.insert_at_tail(2);
    list.insert_at_tail(2);
    list.insert_at_tail(2);

    cout << "After insertion at tail: ";
    list.display();

    cout << "After insertion at head: ";
    //list.insert_at_head(0);
    //list.insert_at_pos(98, 8);
    //list.insert_at_pos(98, 10);

    // list.display();
    // list.backwarddisply();
    //  list.delete_at_head();
    //  list.delete_at_head();
    // list.backwarddisply();

    // list.display();
    // list.delete_at_tail();
    // list.display();
    // list.backwarddisply();
    // list.delete_at_pos(5);
    list.display();
    list.backwarddisply();
    // list.sort();
    //cout << list.nthposvalue(5) << endl;
    //cout << list.valuepos(9) << endl;
    //cout << list.search(98) << endl;
   // list.reverse();
    list.display();

    return 0;
}