#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_N 100001


int n,r;

vector<int> tree[MAX_N];
bool visited[MAX_N];
bool visited2[MAX_N];
vector<int> children[MAX_N];
int central_node = -1;
bool flag;
vector<int> real_tree[MAX_N];
int treeDP[MAX_N];


void DFS(int idx){
    int num = tree[idx].size();
    for(int i=0; i<num; i++){
        int tmp = tree[idx][i];
        if(visited[tmp] == false){
            visited[tmp] = true;
            children[idx].push_back(tmp);
            DFS(tmp);
        }
    }
}

void findCentralNode(int idx){
    int num = children[idx].size();
    if(num >= 2 && flag == false){
        central_node = idx;
        flag = true;
        return;
    }
    for(int i=0; i <num ;i++){
        int tmp = children[idx][i];
        findCentralNode(tmp);
    }
}

void DFS2(int idx){

    int num = tree[idx].size();
    treeDP[idx] = 1;

    for(int i=0; i<num; i++){
        int tmp = tree[idx][i];
        if(visited2[tmp] == false){
            real_tree[idx].push_back(tmp);
            visited2[tmp] = true;
            DFS2(tmp);
            treeDP[idx] += treeDP[tmp];
        }
    }
}


int main(){
    
    cin >> n >> r;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    visited[r] = true;
    DFS(r);
    findCentralNode(r);
    visited2[central_node] = true;
    DFS2(central_node);

    int num = real_tree[central_node].size();
    int max_val = INT_MIN;
    int min_val = INT_MAX;



    for(int i=0; i<num; i++){
        int tmp = real_tree[central_node][i];
        max_val = max(max_val,treeDP[tmp]);
        min_val = min(min_val,treeDP[tmp]);
    }
    if(max_val == INT_MIN || min_val == INT_MAX){
        cout << 0;
    }
    else
        cout << abs(max_val-min_val);

    return 0;
}

/*
일단 트리를 입력받고, -> 일단 트리 만들었음 
중앙노드를 찾고, -> 찾았음. 
근데 중앙노드를 찾는 과정에서도 한번 트리를 만들고,,, 그리고 또 한번더 만들어야하나? 
그 다음에 그 중앙노드를 루트로 하는 트리를 만들어야함 -> children 벡터 배열을 다시 만들어야함
그리고 그 다음에 다음 서브트리의 정점의 수를 구하고, 최대최소를 비교해야함.
*/