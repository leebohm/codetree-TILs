#include <iostream>

using namespace std;

struct Node{
    string data;
    Node *prev, *next;
    Node(string data) : data(data), prev(nullptr), next(nullptr) {}
};

void connect(Node *s, Node *e){
    if(nullptr != s) s->next = e;
    if(nullptr != e) e->prev = s;
}

void insertNext(Node *target, Node *s){
    connect(s, target->next);
    connect(target, s);
}

void insertPrev(Node *target, Node *s){
    connect(target->prev, s);
    connect(s, target);
}

void printNode(Node *target){
    string n = "(Null)";

    if(target->prev == nullptr) cout << n << " ";
    else cout << target->prev->data << " ";

    cout << target->data << " ";

    if(target->next == nullptr) cout << n << "\n";
    else cout << target->next->data << "\n";
}

int main(){

    string sInit;
    cin >> sInit;

    Node *cur = new Node(sInit);

    int n;
    cin >> n;
    
    while(n--){
        int opt;
        cin >> opt;

        if(opt == 1){
            string data;
            cin >> data;
            Node *target = new Node(data);
            insertPrev(cur, target);
        }

        if(opt == 2){
            string data;
            cin >> data;
            Node *target = new Node(data);
            insertNext(cur, target);
        }

        if(opt == 3){
            if(cur->prev != nullptr) cur= cur->prev;
        }

        printNode(cur);
    }
}