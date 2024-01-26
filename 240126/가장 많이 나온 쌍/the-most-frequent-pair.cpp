#include <iostream>

int n,m;
using namespace std;
int a[100],b[100];

int main() {
    cin >> n >> m;

    for(int i=0; i<m;i++)
        cin >> a[i] >> b[i];
    
    int ans =0;
    for(int i=1; i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            int cnt =0;
            for(int k=0; k<m;k++){

                if((i==a[k]&&j==b[k])||(i==b[k]&&j==a[k])){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}