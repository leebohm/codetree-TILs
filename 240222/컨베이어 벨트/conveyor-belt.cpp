#include <iostream>

using namespace std;

int n,t;
int arr1[200];
int arr2[200];

void Belt(){
    for(int i=0; i<t; i++){
        int temp1 = arr1[n-1];
        int temp2 = arr2[n-1];
        for(int j=n-2; j>=0; j--){
            arr1[j+1] = arr1[j];
        }
        for(int j=n-2; j>=0; j--){
            arr2[j+1] = arr2[j];
        }
        arr1[0] = temp2;
        arr2[0] = temp1;
    }
}

int main() {

    cin >> n >> t;

    for(int i=0; i<n;i++)
        cin >> arr1[i];

    for(int i=0; i<n;i++)
        cin >> arr2[i];

    Belt();

    for(int i=0; i<n;i++)
        cout << arr1[i] <<" ";

    cout << endl;
    for(int i=0; i<n;i++)
        cout << arr2[i] << " ";    

    // 여기에 코드를 작성해주세요.
    return 0;
}