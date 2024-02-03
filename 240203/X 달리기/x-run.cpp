#include <iostream>
#include <cmath>

int x;

using namespace std;

int main() {

    cin >> x;
    
    int y = sqrt(x);

    int sec = 0;
    int tmp = 0; 
    for(int v = 1; v <=y; v++){
        tmp += v*1;
        sec++;
    }
    for(int v= y-1; v>=1 ; v--){
        tmp += v*1;
        sec++;
    }
    if(tmp == x) cout << sec;
    while(tmp!=x){
        tmp += 1;
        sec++;
    }
    if(tmp == x) cout << sec;

    // 여기에 코드를 작성해주세요.
    return 0;
}