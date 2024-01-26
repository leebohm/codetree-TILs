#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string str;

int main() {

    cin >> n;
    cin >> str;

    int ans =1;

    for(int i=1; i<n;i++){
        bool twice = false;

        for(int j=0; j<= n-i; j++){
            for(int k=j+1;k<=n-i;k++){
                bool issame = true;

                for(int l=0; l<i;l++){
                    if(str[j+l] != str[k+l]) issame = false;
                }

                if(issame) twice = true;
            }
        }
        if(twice) ans = i+1;
        else break;
    }

    cout << ans;

    return 0;

    
}