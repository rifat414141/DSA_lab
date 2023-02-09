#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Node{
    int data;
    Node* next;
};
class linked_list{
public:
    Node* head;
    linked_list(){
        head = NULL;
    }
    void insert(int val){
        Node* node = new Node();
        node->data = val;
        if(head==NULL){
            head = node;
        }
        node->next = head;
        head = node;
    }
    void print(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<' ';
            temp = temp->next;
        }
    }

};
bool is_circle(linked_list a, linked_list b){
    Node* f = a.head;
    Node* l = b.head;
    while(f && f->next){
        f = f->next->next;
        l = l->next;
        if(f==l){
            return true;
        }
    }
    return false;
}
void solve()
{
    linked_list l;
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        int x;
        cin>>x;
        l.insert(x);
    }
    l.print();
}

int main()
{
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    // cin >> T;
    while(T--){
        solve();
    }
}