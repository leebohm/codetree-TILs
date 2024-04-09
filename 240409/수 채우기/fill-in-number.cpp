#include <iostream>
#include <climits>

using namespace std;

int n;

int main() {

    cin >> n;
    
    int cnt = INT_MAX;

    int tmp1 = n / 5;
    int tmp2 = n / 2;

    for(int i=0; i<=tmp1; i++){
        for(int j=0; j<=tmp2; j++){
            int tmp3 = 5*i + 2*j;
            int tmp4 = 0;
            if(tmp3 == n){
                tmp4 = i+j;
                cnt = min(cnt, tmp4);
            }
            
        }
    }


    if(n < 2 || cnt == INT_MAX)
        cout << -1;
    else
        cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}