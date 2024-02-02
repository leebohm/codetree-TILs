#include <iostream>
#include <vector>

int n,k;
using namespace std;

int arr[100];
int arr2[1000000];

// 기록해놔야 하는 것 : 폭발한 폭탄의 정수, 폭발한 폭탄의 수

int main() {

    cin >> n >> k;
    for(int i=0; i<n;i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        for(int j= i-k; j<= i+k ; j++){
            if(j>=0 && j<n &&(i!=j)){
                if(arr[i] == arr[j]){
                    arr2[arr[i]]++;
                }
            }
        }
    }
    int max_bomb = 0; 
    int num = 0;
    for(int i=0; i<1000000; i++){
        max_bomb = max(max_bomb, arr2[i]);
        if(max_bomb == arr2[i])
            num = i;

    }
    cout << num;
    // 여기에 코드를 작성해주세요.
    return 0;
}