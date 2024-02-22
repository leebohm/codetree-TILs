#include <iostream>

using namespace std;

int n,t;
int arr1[200];
int arr2[200];
int arr3[200];

void Move(){
    for(int i=0; i<t; i++){
        int temp1 = arr1[n-1];
        int temp2 = arr2[n-1];
        int temp3 = arr3[n-1];

        for(int j=n-2;j>=0; j--){
            arr1[j+1] = arr1[j];
            arr2[j+1] = arr2[j];
            arr3[j+1] = arr3[j];
        }

        arr1[0] = temp3;
        arr2[0] = temp1;
        arr3[0] = temp2;


    }
}
void Input(){
    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int i=0; i<n; i++)
        cin >> arr2[i];
    for(int i=0; i<n; i++)
        cin >> arr3[i];
}

void Output() {
    for(int i=0; i<n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
        cout << arr2[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
        cout << arr3[i] << " ";
}

int main() {

    cin >> n >> t;

    Input();

    Move();

    Output();
    // 여기에 코드를 작성해주세요.
    return 0;
}