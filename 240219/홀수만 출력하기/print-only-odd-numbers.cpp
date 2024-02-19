#include <iostream>
int n;
using namespace std;

int arr[10];

int main() {

    cin >> n;

    for(int i=0; i<n;i++){
        cin >> arr[i];
    }

    for(int i=0; i<n;i++){
        if(arr[i]%2==1 && arr[i]%3==0)
            cout << arr[i] << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}