#include <iostream>

#define MAX_N 250002

using namespace std;

int n, q;

struct Node {
    int id;
    Node *prev, *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N];

void connect(Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

void Change(int a, int b, int c, int d){

    Node *preva = nodes[a]->prev;
    Node *nextb = nodes[b]->next;

    Node *prevc = nodes[c]->prev;
    Node *nextd = nodes[d]->next;

    connect(preva, nodes[c]);
    if(nextb != nodes[c])
        connect(nodes[d], nextb);
    else
        connect(nodes[d], nodes[a]);
    if(prevc != nodes[b])
        connect(prevc, nodes[a]);
    else
        connect(nodes[d], nodes[a]);
    connect(nodes[b], nextd);
}

int main(){
    
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        nodes[i] = new Node(i);
    }

    for(int i=2; i<=n; i++){
        connect(nodes[i-1], nodes[i]);
    }

    while(q--){
        int a, b, c, d;
        cin >> a >> b>> c>> d;
        Change(a,b,c,d);
    }

    Node *cur = nodes[1];
    while(cur->prev != nullptr)
        cur = cur->prev;

    for(int i=1; i<=n; i++){
        cout << cur->id << " ";
        cur = cur->next;
    }
    return 0;
}