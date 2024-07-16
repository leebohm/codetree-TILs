#include <iostream>
#include <string>

using namespace std;

struct Node {
    string id;
    Node *prev, *next;
    Node (string id) : id(id) , prev(nullptr), next(nullptr){}
};


void insertPrev (Node *s, Node *e){
    Node *sPrev = s->prev;

    if(sPrev != nullptr) sPrev->next = e;
    if(e != nullptr) e->prev = sPrev;
    if(s != nullptr) s->prev = e;
    if(e != nullptr) e->next = s;
}

void insertNext (Node *s , Node *e){
    Node *sNext = s->next;

    if(sNext != nullptr) sNext->prev = e;
    if(e != nullptr) e->next = sNext;
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}
int n;


int main() {

    string str;

    cin >> str;
    
    Node *cur = new Node(str);

    cin >> n;
    int opt = 0;

    for(int i=0; i<n; i++){
        cin >> opt;
        if(opt == 1){
            cin >> str;
            Node *tmp = new Node(str);
            insertPrev(cur, tmp);

        }
        if(opt == 2){
            cin >> str;
            Node *tmp = new Node(str);
            insertNext(cur, tmp);

        }
        if(opt == 3){
            if(cur->prev != nullptr)
                cur = cur->prev;
        }
        if(opt == 4){
            if(cur->next != nullptr)
                cur = cur->next;
        }

        if(cur->prev == nullptr)
            cout << "(Null)" << " ";
        else
            cout << cur->prev->id << " ";

        if(cur == nullptr)
            cout << "(Null)" << " ";
        else
            cout << cur->id << " ";

        if(cur->next == nullptr)
            cout << "(Null)" << endl;
        else
            cout << cur->next->id << endl;

            
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}