#include <iostream>
#include <string>

#define MAX_N 100002
using namespace std;

int n,q;

struct Node{
    string name;
    Node *prev, *next;
    Node(string name):name(name), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N] = {};

void connect(Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

int main(){
    
    cin >> n >> q;

    string citysname;

    for(int i=1; i<=n; i++){
        cin >> citysname;
        nodes[i] = new Node(citysname);
    }

    for(int i=2; i<=n; i++){
        connect(nodes[i-1], nodes[i]);
    }
    connect(nodes[n], nodes[1]);

    int opt;
    Node *pin = nodes[1];
    while(q--){
        cin >> opt;
        if(opt == 1){
            if(pin->next != pin)
                pin = pin->next;
        }
        else if(opt == 2){
            if(pin->prev != pin)
                pin = pin->prev;
        }
        else if(opt == 3){
            if(pin->next != pin){
                Node *pin_next = pin->next;
                connect(pin, pin_next->next);
                pin_next = nullptr;
            }
        }
        else if(opt == 4){
            cin >> citysname;
            Node *pin_next = pin->next;
            Node *newcity = new Node(citysname);
            connect(pin,newcity);
            connect(newcity,pin_next);
        }
        if(pin->prev == pin->next)
            cout << -1 << endl;
        else if(pin->next == nullptr)
            cout << -1 << endl;
        else if(pin->prev == nullptr)
            cout << -1 << endl;
        else
        cout << pin->prev->name <<" " << pin->next->name << endl;
    }

    return 0;
}