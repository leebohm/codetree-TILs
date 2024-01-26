#include <iostream>

int n,m;
int arr[101];
using namespace std;

int main() {

    cin >> n >> m;

    for(int i=1; i<=n;i++)
        cin >> arr[i];

    int ans =0;
    
    for(int i=1; i<=m;i++){ // 움직임
        
        int num = i;
        for(int j=1; j<=n;j++){ // 시작위치
            int temp = arr[j];
            int tmp_ans = 0;
            while(num){
                tmp_ans += temp;
                temp = arr[temp];
                num--;

            }
            ans = max(ans, tmp_ans);

        }

    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}