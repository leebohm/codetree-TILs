#include <iostream>
#define MAX_N 100001

using namespace std;

int n,k;
int arr[MAX_N];

int main() {
    
    cin >> n >> k;
    
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j = 1;
    int sub_sum = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        sub_sum = arr[i];
        while(j+1 <=n && sub_sum + arr[j+1] <=k){
            sub_sum += arr[j+1];
            ans++;
            //cout << i << " " << j+1 << " " << sub_sum << endl;
            sub_sum -= arr[j+1];
            j++;
        }
        
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}