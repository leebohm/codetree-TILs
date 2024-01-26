#include <iostream>

int n;
int x[100], y[100];

using namespace std;

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];
    
    int ans =100;

    for(int i=2; i<=100; i+=2){  // n개의 줄
        for(int j=2; j<=100; j+=2){ 
            //cout << tempx <<" " << tempy << " " << endl;
            int cnt1=0,cnt2=0, cnt3=0, cnt4=0;

            for(int k=0; k<n;k++){

                if(x[k] <i && y[k]<j)
                    cnt1++;
                else if(x[k]<i && y[k] > j)
                    cnt2++;
                else if(x[k]>i && y[k] <j)
                    cnt3++;
                else 
                    cnt4++;
            }

            int cnt_m = max(cnt1,cnt2);
            cnt_m = max(cnt_m,cnt3);
            cnt_m = max(cnt_m,cnt4);

            ans = min(ans, cnt_m);
        }
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}