#include <iostream>
#include <unordered_map>
#include <climits>

#define MAX_N 100001
#define MAX_M 11

using namespace std;

int n,m,q;
struct Node{
    int id;
    Node *prev, *next;
    Node(int id) : id(id) , prev(nullptr), next(nullptr){}
};

Node *nodes[MAX_N] = {};

unordered_map<int,int> nodesNum;
Node *head[MAX_M] = {};
Node *tail[MAX_M] = {};

void connect(Node *s, Node *e){
    if(s != nullptr) s->next = e;
    if(e != nullptr) e->prev = s;
}

int main() {

    cin >> n >>m >>q;

    for(int i=1; i<=m; i++){
        int t;
        cin >>t;
        Node *cur = nullptr;
        for(int j=1; j<=t; j++){
            int tmp;
            cin >> tmp;
            nodesNum[tmp] = i;
            nodes[tmp] = new Node(tmp);

            if(j==1){
                head[i] = nodes[tmp];
                cur = nodes[tmp];
            }
            else{
                connect(cur, nodes[tmp]);
                cur = cur->next;
                tail[i] = nodes[tmp];
            }

            if(j==t){
                connect(tail[i],head[i]);
            }
        }
        
    }

    for(int i=1; i<=q; i++){
        int opt,a,b;
        cin >> opt;

        if(opt == 1){
            cin >> a >> b;

            int nodeNumA = nodesNum[a];
            Node *t_node = nodes[b]->next;
            while(t_node != nodes[b]){
                nodesNum[t_node->id] = nodeNumA;
                t_node = t_node->next;
            }
            nodesNum[nodes[b]->id] = nodeNumA;

            connect(nodes[b]->prev,nodes[a]->next);
            connect(nodes[a],nodes[b]);
            head[nodeNumA] = nodes[a];
            tail[nodeNumA] = nodes[a]->prev;
        }

        else if(opt == 2){
            cin >> a >> b;
            tail[m] = nodes[b]->prev;
            connect(nodes[a]->prev, nodes[b]);
            Node *t_node = nodes[a]->next;
            head[++m] =nodes[a];
            while(t_node != nodes[b]){
                nodesNum[t_node->id] = m;
                t_node = t_node->next;
            }
            connect(tail[m], head[m]);
        }
        else if(opt == 3){
            cin >>a;
            int num = nodesNum[nodes[a]->id];
            Node *cur = head[num];
            int tmp = cur->id;
            cur = cur->next;
            while(cur != head[num]){
                if(tmp > cur->id){
                    tmp =  cur->id;
                }
                cur = cur->next;
            }
            cur = nodes[tmp];
            cout << cur->id << " ";
            cur = cur->prev;
            while(cur != nodes[tmp]){
                cout << cur->id << " ";
                cur = cur->prev;
            }
        }
    }


    // 여기에 코드를 작성해주세요.
    return 0;
}