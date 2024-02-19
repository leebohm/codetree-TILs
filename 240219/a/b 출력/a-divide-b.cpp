#include <iostream>

int a,b;

using namespace std;

int main() {
    cin >> a>> b;
    cout << fixed;
    cout.precision(20);

    double c = (double) a/ (double) b;
    cout<< c;
    // 여기에 코드를 작성해주세요.
    return 0;
}