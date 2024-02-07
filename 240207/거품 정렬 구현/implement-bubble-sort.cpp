#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    bool flag ;

    do{
        flag = true;
        for(int i=0; i<n-1;i++){
            
            if(arr[i]>arr[i+1]){
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                flag = false;
            }

        }
    }while(flag == false);

    for(int i=0; i<n;i++)
        cout << arr[i] << " ";
    // 여기에 코드를 작성해주세요.
    return 0;
}