#include <bits/stdc++.h>

using namespace std;

#define MAXN (200000)

struct Node {
    int id;
    Node *prev, *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr){}
};

Node *nodes[MAXN+2];


int nodeCnt;

void connect(Node *s, Node *e){
    if(nullptr != s) s->next = e;
    if(nullptr != e) e->prev = s;
}

void insertNextRange(Node *s, Node *e, Node *v){
    //Node *nextV = v->next;
    connect(e,v->next);
    connect(v,s);
}

void insertPrevRange(Node *s, Node *e, Node *v){
    connect(v->prev, s);
    connect(e,v);
}

int main(){
    int q;
    cin >> q;

    nodeCnt = 1;
    nodes[1] = new Node(1);

    while(q--){
        int opt,a,b;
        cin >> opt;

        if(opt == 1){
            cin >> a >> b;
            int init = nodeCnt + 1;
            nodeCnt += b;

            for(int i=0; i<b; i++){
                nodes[init+i] = new Node(init + i);
                if(i!= 0)
                    connect(nodes[init+i-1],nodes[init+i]);
            }

            insertNextRange(nodes[init], nodes[init+b-1], nodes[a]);
        }

        if(opt == 2){
            int a,b;
            cin >> a >> b;
            int init = nodeCnt + 1;
            nodeCnt += b;

            for(int i=0; i<b; i++){
                nodes[init + i] = new Node(init + i);
                if(i!= 0) connect(nodes[init + i -1], nodes[init + i]);
            }

            insertPrevRange(nodes[init], nodes[init+b-1], nodes[a]);
        }

        if(opt == 3){
            int a;
            cin >> a;

            if(nodes[a]->prev == nullptr || nodes[a]->next == nullptr) cout << -1 <<"\n";
            else cout << nodes[a]->prev->id <<" "<< nodes[a]->next->id << "\n";
        }
    }
}