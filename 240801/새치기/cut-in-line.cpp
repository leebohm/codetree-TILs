#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 100002
#define MAX_M 12

int n,m,q;
//unordered_map<int,int> lineNum; // index : node의 번호,  val : 줄의 번호 
int lineNum[MAX_N];

struct Node {
    int id;
    Node *prev, *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

Node *nodes[MAX_N] = {};
Node *heads[MAX_M] = {};

void connect(Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

void pop(Node *u){
    int line_num = lineNum[u->id];

    if(line_num == 0) return;

    if(heads[line_num] == u)
        heads[line_num] = u->next;
    Node *u_prev = u->prev;
    Node *u_next = u->next;
    connect(u_prev,u_next);

    u->prev = u->next = nullptr;
    lineNum[u->id] = 0;
}
void insertPrev(Node *a, Node *b){
    int line_num =  lineNum[b->id];

    if(heads[line_num] == b)
        heads[line_num] = a;
    
    connect(b->prev,a);
    connect(a,b);
    lineNum[a->id] = line_num;
}

void insertPrevRange(Node *a, Node *b, Node *c){
    Node *a_prev = a->prev;
    Node *b_next = b->next;
    connect(a_prev,b_next);

    if(heads[lineNum[a->id]] == a) heads[lineNum[a->id]] = b->next;

    int line_num = lineNum[c->id];

    if(heads[line_num] == c){
        connect(b,c);
        heads[line_num] = a; 
    }
    else{
        connect(c->prev,a);
        connect(b,c);
    }
    Node *cur = a;
    while(cur != c){
        lineNum[cur->id] = line_num;
        cur = cur->next;
    }
}

int main(){
    cin >> n >> m >> q;
    int nodecnt = 1;
    for(int i=1; i<=m; i++){
        int num;
        cin >> num;
        int init = 0;
        for(int j=1; j<= num; j++){
            int tmp;
            cin >> tmp;
            nodes[nodecnt] = new Node(tmp);
            lineNum[tmp] = i;
            if(j==1) {
                init = nodecnt;
                heads[i] = nodes[nodecnt];
            }
            nodecnt++;
        }
        for(int j= init+1; j<init+num; j++){
            connect(nodes[j-1],nodes[j]);
        }
    }

    for(int i=1; i<=q; i++){
        int opt,a,b,c;
        cin >> opt;
        if(opt == 1){
            cin >> a >> b;
            pop(nodes[a]);
            insertPrev(nodes[a],nodes[b]);
        }
        if(opt == 2){
            cin >> a;
            pop(nodes[a]);
        }
        if(opt == 3){
            cin >> a >> b >> c;
            insertPrevRange(nodes[a], nodes[b], nodes[c]);
        }
    }

    for(int i=1; i<=m; i++){
        Node *cur = heads[i];
        if(cur == nullptr)
            cout << -1 << endl;

        else{
            while(cur!=nullptr){
                cout << cur->id << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    }
    return 0;
}