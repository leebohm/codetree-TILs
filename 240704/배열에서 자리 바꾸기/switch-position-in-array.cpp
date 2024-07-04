#include <bits/stdc++.h>

#define MAX_N 250001

using namespace std;
 
struct Node{
    int id;
    Node *prev, *next;
    Node(int id):id(id), prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N] = {};

void connect (Node *s, Node *e){
    if(s != nullptr)
        s->next = e;
    if(e!= nullptr)
        e->prev = s;
}

void swap_abcd(Node *a, Node *b, Node *c, Node *d){
    Node *after_prevA = c->prev;
    Node *after_nextB = d->next;

    Node *after_prevC = a->prev;
    Node *after_nextD = b->next;

    if(b->next == c){
        after_prevA = d;
        after_nextD = a;
    }
    if(d->next == a){
        after_nextB = c;
        after_prevC = a;
    }

    connect(after_prevA,a);
    connect(b,after_nextB);
    connect(after_prevC,c);
    connect(d,after_nextD);
}

int main(){

    int n,q;
    cin >> n >> q;

    for(int i=1; i<=n; i++)
        nodes[i] = new Node(i);
    
    for(int i=1; i<n; i++)
        connect(nodes[i], nodes[i+1]);
    
    int a,b,c,d;

    for(int i = 0; i<q; i++){
        cin >> a>> b>> c>> d;
        swap_abcd(nodes[a],nodes[b],nodes[c],nodes[d]);
    }

    Node *cur = nodes[1];
    while(cur->prev != nullptr)
        cur = cur->prev;

    while(n--){
        cout << cur->id << ' ';
        cur = cur->next;
    }
    

    return 0;
}