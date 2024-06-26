#include <iostream>
#include <algorithm>

#define MAX_N 100001

int arr[MAX_N];
int n,s;

using namespace std;

int main(){

    cin >> n >> s;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int ans = MAX_N + 1; // 구간 길이를 의미 
    int j =0; 
    int sum_val = 0;

    for(int i=1; i<=n;i++){
        while(j+1 <=n && sum_val <s){
            sum_val += arr[j+1];
            j++;
        }

        if(sum_val < s)
            break;
        ans = min(ans, j-i+1);
        sum_val -= arr[i];
    }

    if(ans == MAX_N + 1)
        ans = -1;

    cout << ans;
    return 0;
}