#include <iostream>

using namespace std;

int n;
int a[10],b[10];

int main() {
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> a[i] >> b[i];
        }

    int ans = b[0]+1;
    for(int x = a[0]; x<=b[0];x++){
        int temp = x;
        bool flag = true;
        temp *=2;
        for(int i=0; i<n;i++){
                if(temp >= a[i] && temp <= b[i]) temp *= 2;
                else {
                    flag = false;
                    break;}
        }
        if(flag) ans = min(x,ans);    
    }
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}