#include <iostream>
#include <climits>

#define MAX_N 100001
using namespace std;

int n,s;
int arr[MAX_N];

int main(){
    
    cin >> n >> s;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j=0; 
    int ans = INT_MAX;
    int sub_sum = 0;
    for(int i=1; i<=n; i++){
        while(j+1 < n && sub_sum < s){
            sub_sum += arr[j+1];
            j++;
        }
        if(sub_sum >= s)
            ans = min(ans, j-i+1);
        sub_sum -= arr[i];
    }
    if(ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}