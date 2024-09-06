#include <iostream>
using namespace std;

#define MAX_N 1000002
int n,q;

int arr[MAX_N];
int pre_sum[MAX_N];

int main() {
    
    cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }
    
    for(int i=1; i<=MAX_N; i++){
        pre_sum[i] = pre_sum[i-1] + arr[i];
    }
    
    for(int i=0; i<q;i++){
        int a,b;
        cin >> a >> b;
        if( a== 0)
            cout << pre_sum[b] << endl;
        else
            cout << pre_sum[b] - pre_sum[a-1] << endl;
    }
    
    return 0;
}