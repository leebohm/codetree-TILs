#include <iostream>

using namespace std;

int a,b;

int main() {

    cin >> a >> b;
    int sum_val = 0;
    int cnt = 0;
    double avg = 0;
    
    for(int i=a; i<=b; i++){
        if(i % 5 == 0 || i % 7 == 0){
            sum_val += i;
            cnt++;
        }
    }

    avg = 1.0*sum_val / cnt;

    cout << fixed;
    cout.precision(1);
    cout << sum_val << " " << avg ;


    // 여기에 코드를 작성해주세요.
    return 0;
}