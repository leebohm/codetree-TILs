#include <iostream>

int a,b,c;

using namespace std;

int main() {

    cin >> a>> b>> c;

    int div_ca = c/a;
    int div_cb = c/b;

    //int sum_div = div_ca + div_cb+1;
    int temp = 0;
    int ans = 0;

    for(int i=0; i<= div_ca+1; i++){
        for(int j=0; j<=div_cb+1; j++){
            if((a*i +b*j)<c) temp = a*i+b*j;
            
            ans = max(ans, temp);
        }
    }

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}