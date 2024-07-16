#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 100002

struct Node {
    int id;
    Node *prev, *next;
    Node(int id) : id(id) , prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N];

unordered_map<int,int> studentId;

void connect(Node *s, Node *e){
    if(nullptr != s) s->next = e;
    if(nullptr != e) e->prev = s;
}

void connectCircle(Node *u, Node *v){
    Node *vPrev = v->prev;
    Node *uNext = u->next;

    connect(u,v);
    connect(vPrev,uNext);
}

void splitCircle(Node *u, Node *v){
    Node *uPrev = u->prev;
    Node *vPrev = v->prev;

    connect(uPrev, v);
    connect(vPrev, u);
}

void printLine(Node *target){
    int mn = target->id;
    Node *cur = target;

    while(true){
        cur = cur->next;
        if(cur != nullptr) mn = min(mn,cur->id);
        if(cur == target) break;
    }
    Node *init = nodes[studentId[mn]];
    cur = nodes[studentId[mn]];
    while(true){
        cout<< cur->id <<' ';
        cur = cur->prev;
        if(cur->id == init->id ) break;
    }
}

int main(){
    int n,m,q;
    cin >> n >> m >> q;

    int nodeCnt = 1;

    for(int i=1; i<=m; i++){
        int l;
        cin >> l;
        Node *start, *tail;
        for(int j=0; j<l; j++){
            int t;
            cin >> t;
            studentId[t] = nodeCnt;
            nodes[nodeCnt] = new Node(t);
            if(j==0){
                start = nodes[nodeCnt];
                tail = nodes[nodeCnt];
            }
            else{
                connect(tail,nodes[nodeCnt]);
                tail = nodes[nodeCnt];
                if(j==l-1){
                    connect(tail,start);
                }
            }
            nodeCnt++;
        }
    }

    while(q--){
        int opt;
        cin >> opt;

        if(opt == 1 ){
            int a,b;
            cin >> a >> b;
            connectCircle(nodes[studentId[a]], nodes[studentId[b]]);
        }

        if(opt == 2){
            int a,b;
            cin >> a >> b;
            splitCircle(nodes[studentId[a]], nodes[studentId[b]]);
        }

        if(opt == 3){
            int a;
            cin >> a;
            printLine(nodes[studentId[a]]);
        }
    }
}