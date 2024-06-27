#include <iostream>

#define MAX_N 100001
using namespace std;

int n,m;
int arr[MAX_N];
int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j = 0;
    int sub_sum = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <=n && sub_sum < m ){
            sub_sum += arr[j+1];
            //cout <<i << " " << j+1 << " " << sub_sum << endl;
            j++;
        }
        if(sub_sum == m)
            ans++;

        sub_sum -= arr[i];
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}