#include <iostream>
#include <unordered_map>

#define MAX_N 100000

using namespace std;

struct Node{
    int id;
    Node *prev, *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N] = {};
unordered_map<int,int> info;

int n,m;

void connect(Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

void pop(Node *u){
    cout << u->next->id <<" " << u->prev->id << endl;
    connect(u->prev,u->next);
    u->prev = u->next = nullptr;
}

int main(){

    cin >> n >> m;
    int num;
    for(int i=1; i<=n; i++){
        cin >> num;
        nodes[i] = new Node(num);
        info[num] = i;
    }
    for(int i=2; i<=n; i++){
        connect(nodes[i-1],nodes[i]);
    }
    connect(nodes[n], nodes[1]);

    for(int i=1; i<=m; i++){
        cin >> num;
        pop(nodes[info[num]]);
    }
    return 0;
}