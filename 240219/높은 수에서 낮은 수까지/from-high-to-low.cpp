#include <iostream>

int a,b;
using namespace std;

int main() {
    
    cin >> a>> b;

    int max_num = max(a,b);
    int min_num = min(a,b);

    for(int i=max_num; i>= min_num; i--)
        cout << i << " ";
    // 여기에 코드를 작성해주세요.
    return 0;
}