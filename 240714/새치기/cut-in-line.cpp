#include <iostream>

using namespace std;

#define MAX_N 100001
#define MAX_M 11

struct Node{
    int id;
    Node *prev, *next;
    Node (int id) : id(id), prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N];
Node *heads[MAX_M], *tail[MAX_M];

int lineNum[MAX_N];

void connect(Node *s, Node *e){
    if(nullptr != s) s->next = e;
    if(nullptr != e) e->prev = s;
}

void pop(Node *i){

    int l = lineNum[i->id];
    
    if(l == 0) return;
    
    if(head[l] == i) head[l] = head[l]->next;

    if(tail[l] == i) tail[l] = tail[l]->prev;

    connect(i->prev, i>next);

    lineNum[i->id] = 0;
    i->next = i->prev = nullptr;
}

void insertFront(Node *a, Node *b){
    
    int lineNumB = lineNum[b->id];

    if(head[lineNumB] == b) head[lineNumB] = a;
    pop(a);

    connect(b->prev, a);
    connect(a,b);

    lineNum[a->id] = lineNumB;
}

void popRangeAndInsertPrev(Node *a, Node *b, Node *c){
    int lineNumA = lineNum[a->id];
    int lineNumC = lineNum[c->id];

    if(head[lineNumA] == a) head[lineNumA] = b->next;
    if(tail[lineNumA] == b) tail[lineNumA] = a->prev;

    connect(a->prev, b->next);

    if(head[lineNumC] == c){
        connect(b,c);
        head[lineNumC] = a;
    }

    else { 
        connect(c->prev,a);
        connect(b,c);
    }

    Node *cur = a;
    while(cur != b->next){
        lineNum[cur->id] = lineNumC;
        cur = cur->next;
    }
}

void printLine(int l){
    Node *cur = head[l];

    if(cur == nullptr){
        cout << -1 << "\n";
        return;
    }

    while(nullptr !=cur){
        cout << cur->id <<" ";
        cur = cur->next;
    }
    cout << "\n";
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;

    for(int i=1; i<=m; i++){
        int l;
        cin >> l;

        for(int j=0; j<l; j++){
            int t;
            cin >> t;
            lineNum[t] = i;

            if(j==0){
                tail[i] = head[i] = nodes[t] = new Node(t);
            }
            else{
                nodes[t] = new Node(t);
                connect(tail[i], nodes[t]);
                tail[i] = nodes[t];
            }
        }
    }

    while(q--){
        int opt;
        cin >> opt;

        if(opt == 1){
            int a,b;
            cin >> a >> b;
            insertFront(nodes[a], nodes[b]);
        }
        else if(opt == 2){
            int a;
            cin >> a;
            pop(nodes[a]);
        }
        else if(opt == 3){
            int a,b,c;
            cin >> a >> b >> c;
            popRangeAndInsertPrev(nodes[a], nodes[b], nodes[c]);
        }
    }
    for(int i=1; i<=m; i++)
        printLine(i);
}