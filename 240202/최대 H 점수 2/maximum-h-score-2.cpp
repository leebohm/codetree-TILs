#include <iostream>

// n개의 숫자가 주어지고, 그 중 최대 L개의 서로 다른 원소의 값
// H 점수를 최대로 만드는 프로그램
// H 점수란 특정 수열이 주어졌을 때 
// H 이상인 숫자의 수가 H 개 이상인 것 중 최댓값.

int n, l;
using namespace std;
int arr[100];

int main() {

    cin >> n >> l;
    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    int ans = 0; 
    for(int i=0; i<n;i++){
        int h = arr[i];
        int cnt = 0;
        for(int j=0; j<n;j++){
            if(i!= j){
                if(arr[j]>=h)
                    cnt++;
            }
        }
        if(cnt >= h)
            ans = max(ans,arr[i]);
    }

    cout << ans;
        // 여기에 코드를 작성해주세요.
    return 0;
}