#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100002

int n,k,b;
int arr[MAX_N];
int pre_sum[MAX_N];
int ans = INT_MAX;

int get_sum(int s,int e){
    return pre_sum[s] - pre_sum[e];
}
int main() {

    cin  >> n >> k >> b;

    for(int i=0; i<b; i++){
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }

    for(int i=1; i<=n; i++){
        pre_sum[i] = pre_sum[i-1] + arr[i];
    }

    for(int i=k; i<=n; i++){
        ans = min(ans, get_sum(i,i-k));
    }
    cout << ans;
    
    return 0;
}