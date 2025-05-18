#include <iostream>
#include <string>

using namespace std;

string str;

int main(){
    cin >> str;
    int sz = (int) str.size();
    int ans = 0;
    for(int i=0; i<sz; i++){
        if(str[i] == '('){
            for(int j=i+1; j<sz; j++){
                if(str[j] == ')')
                    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}