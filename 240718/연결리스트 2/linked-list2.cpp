#include <iostream>

#define MAX_N 100001

using namespace std;

int n,q,opt;

struct Node{
    int data;
    Node *prev, *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N];

void connect (Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

void popNode(int i){
    connect(nodes[i]->prev, nodes[i]->next);
    nodes[i]->prev = nullptr;
    nodes[i]->next = nullptr;
}

// j번 노드를 i번 노드 앞에 삽입
void insertPrev(int i, int j){
    connect(nodes[i]->prev, nodes[j]);
    connect(nodes[j], nodes[i]);
}

// j번 노드를 i 번 노드 뒤에 삽입 
void insertNext(int i,int j){
    connect(nodes[j],nodes[i]->next);
    connect(nodes[i], nodes[j]);   
}

void Print(int i){
    if(nodes[i]->prev == nullptr)
        cout << 0 <<" " ;
    if(nodes[i]->prev != nullptr)
        cout << nodes[i]->prev->data <<" ";

    if(nodes[i]->next == nullptr)
        cout << 0 << endl;
    if(nodes[i]->next != nullptr)
        cout << nodes[i]->next->data << endl;
}

int main(){

    cin >> n >> q;

    for(int i=1; i<=n; i++){
        nodes[i] = new Node(i);
    }

    while(q--){
        cin >> opt;
        int i,j;

        if(opt == 1){
            cin >> i;
            popNode(i);
        }
        else if(opt == 2){
            cin >> i >> j;
            insertPrev(i,j);
        }
        else if(opt == 3){
            cin >> i >> j;
            insertNext(i,j);
        }
        else if(opt == 4){
            cin >> i;
            Print(i);
        }
    }

    for(int i=1; i<=n; i++){
        if(nodes[i]->next == nullptr) 
            cout << 0 << " ";
        else
            cout << nodes[i]->next->data <<" ";
    }
    return 0;
}