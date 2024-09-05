#include <iostream>
using namespace std;

#define MAX_N 1002

int n,k;

int arr[MAX_N];
int pre_sum[MAX_N];

int Get_sum(int s,int e){
    return pre_sum[s] - pre_sum[e];
}
int main() {
    
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=n; i++)
        pre_sum[i] = pre_sum[i-1] + arr[i];
    
    int cnt = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(Get_sum(j,i) == k){
                cnt++;
            }
        }   
    }
    cout << cnt;

    return 0;
}