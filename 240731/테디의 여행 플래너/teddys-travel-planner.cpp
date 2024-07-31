#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *prev, *next;
    Node (string data) : data(data), prev(nullptr), next(nullptr) {};
};

void connect(Node *s, Node *e){
    if(nullptr != s) s->next = e;
    if(nullptr != e) e->prev = s;
}

void insertNext(Node *target, Node *s){
    connect(s, target->next);
    connect(target, s);
}

void pop(Node *u){
    connect(u->prev, u->next);
    u->prev = u->next = nullptr;
}

int main(){
    int n,q;

    cin >> n >> q;
    Node *cur, *prev;

    for(int i=1; i<=n; i++){
        string x;
        cin >> x;
        Node *target = new Node(x);

        if( i== 1){
            cur = target;
        }
        else{
            connect(prev, target);
        }
        if(i==n) connect(target, cur);
        prev = target;
    }

    while(q--){
        int opt;
        cin >> opt;

        if(opt == 1){
            if(cur -> next != nullptr) cur = cur->next;
        }

        if(opt == 2){
            if(cur->prev != nullptr ) cur = cur->prev;
        }

        if(opt == 3){
            if(cur->next != cur)
                pop(cur->next);
        }

        if(opt == 4){
            string x;
            cin >> x;
            insertNext(cur, new Node(x));
        }

        if(cur->next == cur->prev || cur->next == nullptr || cur->prev == nullptr) cout << -1 << "\n";
        else cout << cur->prev->data << " " << cur->next->data << "\n";
    
    }
}