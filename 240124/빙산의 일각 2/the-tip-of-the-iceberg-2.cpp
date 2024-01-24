#include <iostream>

int n;
int arr_h[100];

using namespace std;

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr_h[i];


    int ans =0;
    for(int i=1;i<=1000; i++){
        
        int levelofsea = i;
        bool flag = false;
        int island = 0;
        int cnt =0;
        for(int j=0; j<n;j++){
            if(arr_h[j]> levelofsea) island++;
            else island = 0;
            if(island==1) cnt++;

        }
        ans = max(ans, cnt);

        
    }
    
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}