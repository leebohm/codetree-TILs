#include <iostream>

int x,y;
int digits[9];
using namespace std;

int main() {

    cin >> x >> y;

    int ans =0;

    for(int i=x;i<=y; i++){
        int num = i;
        int cnt = 0;
        bool flag = true;
        while(num){
            cnt++;
            digits[cnt] = num%10;
            num /= 10;
            
        }

        
        for(int j=1; j<=cnt;j++){
            if(digits[j]!=digits[cnt-j+1]) flag = false;
        }

        if(flag){
            ans++;
        }
        }   
    cout << ans; 
    // 여기에 코드를 작성해주세요.
    return 0;
}