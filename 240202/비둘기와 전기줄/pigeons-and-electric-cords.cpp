#include <iostream>

using namespace std;

int n;
int arr1[100];
int arr2[100];
int pigeon[10];

int main() {
    cin >> n;

    int ans =0;
    for(int i=0; i<n;i++){
        cin >> arr1[i] >> arr2[i];
        if(pigeon[arr1[i]] != 0) {
            if(pigeon[arr1[i]]-1 != arr2[i]) ans++;
        }
        pigeon[arr1[i]] = arr2[i]+1;

    }
    
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}