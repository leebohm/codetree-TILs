#include <iostream>

int n;

using namespace std;
int arr[100];

int main() {

    cin >> n;

    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    int ans = 1e9;

    for(int i=0; i<n;i++){
        arr[i] *=2;
        
        for(int j=0; j<n;j++){
            int arr2[n] = {};
            int cnt =0;
            int diff = 0;
            for(int k=0; k<n;k++){
                if(j!=k) arr2[cnt++] = arr[k];
                
                
            }

            for(int m = 1; m<n-1;m++){
                    diff += abs(arr2[m-1]-arr2[m]);
                }
            ans = min(ans, diff);

        }

        arr[i] /=2;
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}