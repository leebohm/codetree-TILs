#include <iostream>

// n 개의 수가 주어졌을 때 각각이 수에 적절한 변화를 주어 
// 최종적으로 나오는 수 들중에서 최대 최소 간의 차가 k 이하가 되게끔
// 만들려고 한다... 
// 그럼 최솟값을 완전탐색 하면 될 듯? 

int n, k;
using namespace std;

int arr[100];

int main() {

    cin >> n >> k;

    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    int ans = 1e9;

    for(int i=0; i<10000; i++){
        int cost = 0;
        for(int j=0; j<n;j++){
            if((arr[j] <= i+k) && (arr[j] >= i)) continue;
            else if( arr[j] > i+k){
                cost += abs(arr[j]-i-k);
            }
            else if(arr[j]<i){
                cost += abs(arr[j]-i);
            }
        }
        ans = min(cost, ans);
    }

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}