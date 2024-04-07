#include <iostream>

using namespace std;

int n;
int cnt1, cnt2, cnt3;

int main() {

    cin >> n;
    for(int i=1; i<=n; i++){
        if(i%12 == 0)
            cnt3++;
        
        else if(i%3 == 0)
            cnt2++;

        else if(i%2 == 0)
            cnt1++;
         

    }

    cout << cnt1 << " " << cnt2 << " " << cnt3;
    // 여기에 코드를 작성해주세요.
    return 0;
}