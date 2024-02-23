#include <iostream>
#include <string>
#include <climits>

using namespace std;

string str;
int n;

void Shift(){
    char temp = str[n-1];
    for(int i=n-2; i>=0; i--){
        str[i+1] = str[i];
    }
    str[0] = temp;
}

int RunLengthEncoding(){
    char temp = str[0];
    int cnt = 1; 
    for(int i=1; i<n; i++){
        if(str[i] == temp) continue;
        else{
            cnt ++;
            temp = str[i];
        }
    }
    if(cnt == 1 && n >= 10) return 3;
    return cnt*2;
}

int main() {
    cin >> str;

    n = str.length();
    int ans = INT_MAX;
    if(n!= 1){
        for(int i=0; i<n-1; i++){
            Shift();
            ans = min(ans, RunLengthEncoding());
        }
    }
    if(n==1) ans = 2;
    cout << ans;
        // 여기에 코드를 작성해주세요.
    return 0;
}