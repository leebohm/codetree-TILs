#include <iostream>

#define MAX_N 100001

using namespace std;

int n;
int count_arr[MAX_N];
int arr[MAX_N];

int main() {
    
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <= n && count_arr[arr[j+1]]!= 1){
            count_arr[arr[j+1]]++;
            //cout << i << " " << j+1 << " " << arr[j+1] << endl;
            j++;
        }

        ans = max(ans, j-i+1);
        count_arr[arr[i]]--;
    }
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}