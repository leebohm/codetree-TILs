#include <iostream>
#include <string>

using namespace std;

#define MAX_N 100000

int n,q;

struct Node{
    string name;
    Node *prev, *next;
    Node(string name) : name(name), prev(nullptr), next(nullptr){}
};

void connect(Node *a , Node *b){
    if(a != nullptr)
        a->next = b;
    if(b != nullptr)
        b->prev = a;
}

void Pop(Node *a){
    connect(a->prev, a->next);
    a->prev = a->next = nullptr;   
}

void insertNext(Node *a, Node *b){
    connect(b,a->next);
    connect(a,b);

}



int main() {
    
    cin >> n >> q;
    string str;

    Node *cur, *prev;

    for(int i=1; i<=n; i++){
        cin >> str;
        Node *target = new Node(str);
        if(i==1){
            cur = target;
        }
        else{
            connect(prev, target);
        }
        if(i==n)
            connect(target,cur);
        prev = target;
    }
    int opt = 0;
    while(q--){
        cin >> opt;
        if(opt == 1){
            if(cur->next) cur = cur->next;
        }
        if(opt == 2){
            if(cur->prev) cur = cur->prev;
        }
        if(opt == 3){
            if(cur->next != cur)
                Pop(cur->next);
        }
        if(opt == 4){
            string x;
            cin >> x;
            insertNext(cur, new Node(x));
        }

    if(cur->next == cur->prev ||cur->next ==nullptr || cur->prev == nullptr) cout << -1 << '\n';
    else cout << cur->prev->name <<" " << cur->next->name << '\n';
    }

    

    // 여기에 코드를 작성해주세요.
    return 0;
}