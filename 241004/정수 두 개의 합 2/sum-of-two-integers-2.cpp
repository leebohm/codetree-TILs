#include <iostream>

using namespace std;

#define MAX_N 100001

int n,k;
int arr[MAX_N];

int main(){

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int j = 0;
    int cnt = 0;
    int tmp = 0;
    for(int i=1; i<=n; i++){
        tmp = arr[i];
        while(j+1 <=n && tmp + arr[j+1] <= k){
            j++;
            if(tmp + arr[j] <= k){
                tmp += arr[j];
                cnt++;
                break;
            }
        }
        tmp -= arr[i];
    }
    cout << cnt;
    return 0;
}