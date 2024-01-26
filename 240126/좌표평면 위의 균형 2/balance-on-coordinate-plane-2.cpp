#include <iostream>

int n;
int x[100], y[100];

using namespace std;

int main() {

    cin >> n;

    for(int i=0; i<n; i+=2)
        cin >> x[i] >> y[i];
    
    int ans =1e9;

    for(int i=0; i<100; i+=2){  // n개의 줄
        for(int j=0; j<100; j+=2){ 
            int tempx = i, tempy =j;
            int cnt1=0,cnt2=0, cnt3=0, cnt4=0;
            for(int k=0; k<n;k++){

                if(x[k] <tempx && y[k]<tempy)
                    cnt1++;
                else if(x[k]<tempx && y[k] > tempy)
                    cnt2++;
                else if(x[k]>tempx && y[k] <tempy)
                    cnt3++;
                else if(x[k]>tempx && y[k] > tempy)
                    cnt4++;
            }

            int cnt_1 = max(cnt1,cnt2);
            int cnt_2 = max(cnt3,cnt4);

            int final_cnt = max(cnt_1,cnt_2);

            ans = min(ans, final_cnt);
        }
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}