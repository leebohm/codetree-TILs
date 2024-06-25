#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define OPERATOR_NUM 4
#define MAX_N 1000000


int n;
bool visited[MAX_N*2];
int step[MAX_N*2];
queue<int> q;
int ans;


enum OPERATOR{
    SUB,
    ADD,
    DIV2,
    DIV3
};

bool InRange(int num){
    return 1<= num && num <= 2*n - 1;
}

bool CanGo(int num){
    return InRange(num) && visited[num] == false;
}

bool CanCal(int num, int op){
    if(op == SUB || op == ADD)
        return true;
    else if(op == DIV2)
        return num % 2 == 0;
    else if(op == DIV3)
        return num % 3 == 0;
}

int Calculate(int num, int op){
    if(op == SUB){
        num--;
        return num;
    }
    else if(op == ADD){
        num++;
        return num;
    }
    else if(op == DIV2){
        num /= 2;
        return num;
    }
    else if(op == DIV3){
        num /= 3;
        return num;
    }
}

void Push(int num, int st){
    q.push(num);
    visited[num] = true;
    step[num] = st;

}

void FindMin(){
    while(!q.empty()){
        int curr_num = q.front();
        q.pop();
        for(int i=0; i<OPERATOR_NUM; i++){
            if(CanCal(curr_num,i) == false)
                continue;
            int next_num = Calculate(curr_num,i);
            if(CanGo(next_num) == true)
                Push(next_num,step[curr_num]+1);
        }
    }
    ans = step[1];
}

int main(){
    cin >> n;

    Push(n,0);
    FindMin();

    cout << ans;
    return 0;
}