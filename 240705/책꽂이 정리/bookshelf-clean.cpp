#include <iostream>

#define MAX_N 250001
#define MAX_K 100
using namespace std;

int k, n, q;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int data) :data(data), prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N];
Node *heads[MAX_K+1], *tails[MAX_K+1];

bool empty(int i){
    return nullptr == heads[i];
}

void connect(Node *u, Node *v){
    u->next = v;
    v->prev = u;
}

Node* pop_front(int i){
    Node *ret = heads[i];

    if(nullptr != ret){
        heads[i] = ret->next;
        ret->next = nullptr;

        if(nullptr != heads[i])
            heads[i]->prev = nullptr;
        else
            tails[i] = nullptr;
    }
    return ret; 
}

Node* pop_back(int i){
    Node *ret = tails[i];

    if(nullptr != ret){
        tails[i] = ret->prev;
        ret->prev = nullptr;
        if(nullptr != tails[i])
            tails[i]->next = nullptr;
        else
            heads[i] = nullptr;
    }
    return ret;
}

void push_front(int i, Node *singleton){
    if(nullptr == heads[i]){
        heads[i] = tails[i] = singleton;
    }
    else{
        connect(singleton,heads[i]);
        heads[i] = singleton;
    }
}

void push_back(int i, Node *singleton){
    if(nullptr == tails[i]){
        heads[i] = tails[i] = singleton;
    }
    else{
        connect(tails[i], singleton);
        tails[i] = singleton;
    }
}

void move_all_front(int i, int j){
    if(i==j || empty(i))
        return;
    if(empty(j)){
        heads[i] = heads[i];
        tails[j] = tails[i];
    }
    else{
        connect(tails[i], heads[j]);
        heads[j] = heads[i];
    }
    heads[i] = tails[i] = nullptr;
}

void move_all_back(int i, int j){
    if(i==j || empty(i))
        return;
    if(empty(j)){
        heads[j] = heads[i];
        tails[j] = tails[i];
    }
    else{
        connect(tails[j], heads[i]);
        tails[j] = tails[i];
    }
    heads[i] = tails[i] = nullptr;
}


int main() {
    
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        nodes[i] = new Node(i);
    
    for(int i=1; i<n; i++)
        connect(nodes[i], nodes[i+1]);
    
    for(int i=1; i<=k; i++)
        heads[i] = tails[i] = nullptr;
    
    heads[1] = nodes[1];
    tails[1] = nodes[n];

    cin >> q;
    for(int t = 0; t <q; t++){
        int tmp,i,j;
        cin >> tmp >> i >> j;
        if(tmp == 1){
            Node *node = pop_front(i);
            if(nullptr != node)
                push_back(j,node);
        }
        else if(tmp == 2){
            Node *node = pop_back(i);
            if(nullptr != node)
                push_front(j,node);
        }
        else if(tmp == 3){
            move_all_front(i,j);
        }
        else if(tmp == 4){
            move_all_back(i,j);
        }
    }

    for(int i=1; i<=k; i++){
        int cnt =0;
        Node *cur = heads[i];
        while(nullptr != cur){
            cnt++;
            cur = cur->next;
        }
        cout << cnt;

        cur = heads[i];
        while(nullptr != cur){
            cout << ' ' << cur->data;
            cur = cur->next;
        }
        cout <<'\n';
    }

    for(int i=1; i<=n; i++){
        delete nodes[i];
        nodes[i] = nullptr;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}