#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {

    for(int i=0; i<3; i++)
        cin >> arr[i];

    sort(arr, arr+3);

    int tmp1 = arr[1] - arr[0];
    int tmp2 = arr[2] - arr[1];
    int tmp3 = max(tmp1, tmp2);
    tmp3 -= 1;
    cout << tmp3; 

    // 여기에 코드를 작성해주세요.
    return 0;
}