#include <iostream>
#include <algorithm>

#define MAX_NUM 20

using namespace std;

int n,m;
int A[MAX_NUM];

int ans;

void FindMaxXor(int curr_idx, int cnt, int curr_val){
    if(cnt == m){
        ans = max(ans, curr_val);
        return;
    }

    if(curr_idx == n)
        return;
    
    FindMaxXor(curr_idx+1, cnt, curr_val);
    FindMaxXor(curr_idx+1, cnt+1, curr_val^A[curr_idx]);
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> A[i];
    
    FindMaxXor(0,0,0);

    cout << ans;

    return 0;
}