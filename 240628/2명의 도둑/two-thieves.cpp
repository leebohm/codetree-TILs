#include <iostream>
#include <algorithm>

#define MAX_N 10
#define MAX_M 5

using namespace std;

int n,m,c;
int weight[MAX_N][MAX_N];

int a[MAX_M];

int ans =0 ;
int max_val;

void FindMaxSum(int curr_idx, int curr_weight, int curr_val){
    if(curr_idx == m){
        if(curr_weight <= c)
            max_val = max(max_val, curr_val);
        return;
    }

    FindMaxSum(curr_idx+1, curr_weight, curr_val);

    FindMaxSum(curr_idx+1, curr_weight+a[curr_idx], curr_val+a[curr_idx]*a[curr_idx]);
}


int FindMax(int sx, int sy){
    for(int i=sy; i<=sy + m -1; i++)
        a[i-sy] = weight[sx][i];
    
    max_val = 0;
    FindMaxSum(0,0,0);
    return max_val;
}

bool Intersect(int a, int b, int c, int d){

    return !(b<c || d<a);
}

bool Possible(int sx1, int sy1, int sx2, int sy2){
    if(sy1 + m -1 >= n || sy2 + m -1  >= n)
        return false;
    
    if(sx1 != sx2)
        return true;

    if(Intersect(sy1, sy1 + m-1, sy2, sy2+m-1))
        return false;
    return true;
}

int main(){
    cin >> n >> m >> c;

    for(int i=0; i<n ;i++ )
        for(int j=0; j<n; j++)
            cin >> weight[i][j];
    
    for(int sx1 = 0; sx1 < n; sx1++)
        for(int sy1 = 0; sy1< n; sy1++)
            for(int sx2 = 0; sx2 <n; sx2++)
                for(int sy2=0; sy2 < n; sy2++){
                    if(Possible(sx1, sy1, sx2, sy2))
                        ans = max(ans, FindMax(sx1, sy1)+ FindMax(sx2,sy2));
                }
    
    cout << ans;
    return 0;
}