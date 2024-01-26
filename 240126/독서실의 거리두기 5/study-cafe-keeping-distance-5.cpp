#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int arr[20];

int main() {

    cin >> n;
    cin >> str;

    for(int i=0; i<n;i++)
        arr[i] = str[i]-'0';
    int ans =0;

    for(int i=0; i<n;i++){ // x 를 놓을 위치
        int temp[n] = {};
        for(int j=0; j<n;j++) //초기화
            temp[j] = arr[j];

       

        if(temp[i]!=1) temp[i] = 1; // x 배치
        else continue;

        //빈자리 최솟값 구하기
        int cnt = 0;
        int min_cnt = 1e9;
        
        for(int k=0;k<n;k++){
            if(temp[k]==0) cnt++;
            else {
                if(cnt!=0) min_cnt = min(min_cnt,cnt);
                cnt =0;}
        }

        ans = max(min_cnt,ans);
    }
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}