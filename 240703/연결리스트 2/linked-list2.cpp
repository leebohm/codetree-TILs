#include <bits/stdc++.h>

using namespace std;

struct Node{
    int id;
    Node *prev, *next;
    Node(int id):id(id), prev(nullptr), next(nullptr){}
};

void insertPrev(Node *u, Node *singleton){
    singleton->prev = u->prev;
    singleton->next = u;
    
    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void insertNext(Node *u, Node *singleton){
    singleton->next = u->next;
    singleton->prev = u;

    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
}

void pop(Node *u){
    if(u->prev != nullptr)
        u->prev->next =  u->next;
    if(u->next != nullptr)
        u->next->prev = u->prev;
    
    u->prev = u->next = nullptr;
}
int n,q;
Node *nodes[100005] = {};

int main(){
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        nodes[i] = new Node(i);
    }

    for(int t=0; t<q; t++){
        int tmp = 0;
        int i,j =0;
        cin >> tmp;
        if(tmp == 1){
            cin >> i;
            pop(nodes[i]);
        }
        else if(tmp == 2){
            cin >> i>> j;
            insertPrev(nodes[i],nodes[j]); 
        }
        else if(tmp == 3){
            cin >> i >> j;
            insertNext(nodes[i],nodes[j]);
        }
        else if(tmp == 4){
            cin >>i;
            cout << ((nodes[i]->prev == nullptr) ? 0 : nodes[i]->prev->id )<<' '
            << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->id) << '\n';
        }
    }
    for(int i=1;i<=n;i++){
        cout << ((nodes[i]->next == nullptr)? 0: nodes[i]->next->id) << ' ';
    }
    return 0;
}