#include <iostream>
#include <string>

using namespace std;

int n;
string src;
string des;

void Change(int idx){
    for(int i = idx; i>=0; i--){
        if(src[i] == 'G')
            src[i] = 'H';
        
        else
            src[i] = 'G';
    }
}

int main() {

    cin >> n >> src >> des;
    
    int ans = 0;
    
    for(int i=n-1; i>=0; i--){
        if(src[i] != des[i]){
            Change(i);
            ans++;
        }       
    }

    cout << ans;
    
    // 여기에 코드를 작성해주세요.
    return 0;
}