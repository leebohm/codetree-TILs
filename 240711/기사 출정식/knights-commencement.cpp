#include <iostream>
#include <unordered_map>

#define MAX_N 100001

using namespace std;

int n,m;
unordered_map<int,int> maps;

struct Node{
    int id;
    Node *prev, *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr){}
};

void connect(Node *a, Node *b){
    if(a->next == nullptr)
        a->next = b;
    if(b->prev == nullptr)
        b->prev = a;
}

Node *nodes[MAX_N] = {};

void Pop(Node *a){
    Node *next_a = a->next;
    Node *prev_a = a->prev;

    connect(next_a,prev_a);

    a = a->next = a->prev = nullptr;
}

int main() {

    cin >> n >> m;
    
    int tmp = 0;

    for(int i=0; i<n; i++){
        cin >> tmp;
        nodes[i] = new Node(tmp);
        maps[tmp] = i;
    }

    for(int i=0; i<n-1; i++){
        connect(nodes[i], nodes[i+1]);
    }
    connect(nodes[n-1],nodes[0]);

    for(int i=0;i<m; i++){
        cin >> tmp;
        cout << nodes[maps[tmp]]->next->id << " " << nodes[maps[tmp]]->prev->id << endl;
        Pop(nodes[maps[tmp]]);
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}