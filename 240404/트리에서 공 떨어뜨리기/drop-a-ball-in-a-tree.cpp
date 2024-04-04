#include <iostream>

#define MAX_N 200000

using namespace std;

int n;
long long k;
int left_num[MAX_N+1], right_num[MAX_N+1];
int ans;

void DFS(int x, long long ball_num){
    if(left_num[x] == -1 && right_num[x] == -1){
        ans = x;
        return;
    }

    if(left_num[x] == -1)
        DFS(right_num[x], ball_num);
    
    else if(right_num[x] == -1)
        DFS(left_num[x], ball_num);
    
    else if(ball_num%2 ==1)
        DFS(left_num[x], (ball_num+1)/2);

    else
        DFS(right_num[x],ball_num/2);
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> left_num[i] >> right_num[i];
    
    cin >> k;

    DFS(1,k);

    cout << ans;

    return 0;
}