#include <iostream>

int n,k;

using namespace std;

int arr[1000];

int main() {

    cin >> n >> k;
    int min_a = 1e9, max_a = 0;
    for(int i=0; i<n;i++){
        
        cin >> arr[i];
        min_a = min(min_a,arr[i]);
        max_a = max(max_a,arr[i]);
    }
    int ans =0;
    for(int i=min_a;i<=max_a;i++){
        int num = 0;
        for(int j=0;j<n;j++){
            if((arr[j]-i)<=k && (arr[j]-i)>=0) {
                num++;
                //cout << i << " " << arr[j] << endl;
                }
        }
        ans = max(ans,num);
        
    }
    
    cout << ans;

    // 여기에 코드를 작성해주세요.

    return 0;
}