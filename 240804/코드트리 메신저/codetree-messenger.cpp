#include <iostream>
using namespace std;

#define MAX_N 100001

int n,q; // n : 채팅방의 수, q : 명령의 수 
int ans = 0;
struct Node{
    int id;
    int aut; // 권한 
    Node *parent, *left, *right;
    bool button;
    Node(int id,Node *node):id(id),aut(0),parent(node),left(nullptr),right(nullptr),button(true){}
};

Node *nodes[MAX_N] = {};

int PreOrder(Node *cur,int cnt){

    //cout << cur->id << " " << cur->aut <<" " << cnt << endl;
    if(cnt <= cur->aut && cur->button == true && cnt != 0)
        ans++;
    cnt++;
    if(cur->left != nullptr && cur->left->button == true)
        PreOrder(cur->left, cnt);    
    if(cur->right != nullptr && cur->right->button == true) 
        PreOrder(cur->right,cnt);
    
    return ans;
}

int main() {
    cin >> n >> q;
    nodes[0] = new Node(0,nullptr); // 0번 노드는 메인 채팅방. 
    for(int i=0; i<q; i++){
        int opt,c1,c2,power;
        cin >> opt;
       
        if( opt == 100){ // 사내 메신저 준비 

            for(int j=1; j<=n; j++){ // 1번부터 n번 노드 까지의 부모 노드 번호
                int pnum = 0;
                cin >> pnum; // 부모 노드 번호 받아서 
                nodes[j] = new Node(j,nodes[pnum]);  // 자신 id와 부모 노드 번호 저장

                if(nodes[pnum]->left == nullptr){ // 부모 노드의 왼쪽 자식 노드 없을 경우 저장.
                    nodes[pnum]->left = nodes[j];
                    //cout << pnum << " " << nodes[pnum]->left->id << endl;
                }
                else{
                    nodes[pnum]->right = nodes[j]; // 오른쪽 자식 노드 저장
                    //cout << pnum << " " << nodes[pnum]->right->id << endl;
                }

            }
            
            for(int j=1; j<=n; j++){ // 권한 정보 저장. 
                int aut_n;
                cin >> aut_n;
                nodes[j]->aut = aut_n;
            }
        }

        else if(opt == 200){ // 알림망 설정 on,off
            cin >> c1;
            if(nodes[c1]->button == true)
                nodes[c1]->button = false;
            else
                nodes[c1]->button = true;
        }

        else if(opt == 300){ // 권한 세기 변경
            cin >> c1 >> power;
            nodes[c1]->aut = power;
        }

        else if(opt == 400){ // 부모 채팅방 교환
            cin >> c1 >> c2;
        
            Node *c1_par = nodes[c1]->parent;
            Node *c2_par = nodes[c2]->parent;
            nodes[c1]->parent = c2_par;
            nodes[c2]->parent = c1_par;
            
            if(nodes[c1]->parent->left == nodes[c2])
                nodes[c1]->parent->left = nodes[c1];
            else if(nodes[c1]->parent->right == nodes[c2])
                nodes[c1]->parent->right = nodes[c1];
            
            if(nodes[c2]->parent->left == nodes[c1])
                nodes[c2]->parent->left = nodes[c2];
            else if(nodes[c2]->parent->right == nodes[c1])
                nodes[c2]->parent->right = nodes[c2];
            
        }

        else if(opt == 500){ // 알림을 받을 수 있는 채팅방 조회
            cin >> c1;
            ans = 0;
            ans = PreOrder(nodes[c1],0);
            cout << ans << endl;
        }
    }
    return 0;
}

/*
1. 사내 메신저 준비 
0번 부터 N번까지 n+1까지의 채팅방 
메인채팅방을 제외한 각 채팅방은 부모 채팅방 있음. 
메인 채팅방의 번호는 항상 0번, 각 채팅방의 부모 채팅방 번호들은 Parents라는 이름으로 주어짐.
아 parents 배열 index : 각 노드 번호, value : 부모 채팅방 번호 

authority : 권한
위로 몇층 올라갈 수 있는지를 의미

2. 알림망 설정 on/off
- 처음 모든 채팅방의 알림망 설정은 켜져 있다.
이 기능이 작동되면  
on->off로 바꾸고, off->on으로 바꿔준다. 
off : 자기 자신을 포함해서 아래에서 올라온 모든 알림을 더이상 위로 올려보내지 않음

3. 권한 세기 변경 

4. 부모 채팅방 교환 

5. 알림을 받을 수 있는 채팅방 수 조회
예. 1번 채팅방까지 알림이 도달할 수 있는 채팅방은 3,4,8으로 총 3개이다. -> 이거 어떻게 조회하지?
*/