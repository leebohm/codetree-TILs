#include <iostream>
#include <algorithm>

#define MAX_N 50001
using namespace std;

int n,k;
int arr[MAX_N];
int l[MAX_N];
int r[MAX_N];

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    sort(arr+1, arr+n+1);

    int i=1;
    int max_num = 0;
    for(int j=1; j<=n; j++){
        while(i+1 <= j && arr[j] - arr[i] > k)
            i++;
        
        max_num = max(max_num, j-i+1);
        l[i] = max_num;
    }

    max_num = 0;
    int j=n;
    for(int i=n; i>=1; i--){
        while(j-1 >=i && arr[j] - arr[i] > k)
            j--;
        
        max_num = max(max_num, j-i+1);
        r[i] = max_num;
    }

    int ans = l[n];
    for(int i=1; i<n; i++)
        ans= max(ans, l[i]+r[i+1]);
    cout << ans;
    return 0;
}