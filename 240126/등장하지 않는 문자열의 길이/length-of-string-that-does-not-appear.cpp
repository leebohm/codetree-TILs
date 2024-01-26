#include <iostream>
#include <string>

int n;

using namespace std;

string inp[1];

int main() {
    cin>> n;
    cin >> inp[0];

    int tmp_ans =0;
    int ans =0;

    for(int i=0; i<n;i++){
        for(int j=0; j<n/2+1;j++){
            string str = {};
            for(int k=i;k<=j;k++){
                str += inp[0][k];
            }

            for(int p=j+1;p<n;p++){
                for(int q=j+1;q<n;q++){
                    string temp = {};
                    for(int k=p;k<=q;k++){
                        temp+=inp[0][k];
                    }
                    if(str ==temp ) tmp_ans = q-p+1; 
                    ans = max(tmp_ans,ans);
                    
                }
            }
        }
    }

    cout << ans+1;
    // 여기에 코드를 작성해주세요.
    return 0;
}