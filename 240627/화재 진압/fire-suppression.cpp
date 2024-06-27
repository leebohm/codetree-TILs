#include <iostream>
#include <algorithm>

#define MAX_N 100001
using namespace std;

int n,m;
int arr1[MAX_N]; // 화재 발생 위치
int arr2[MAX_N]; // 소방서 위치


int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> arr1[i];
    
    sort(arr1 + 1, arr1+n+1);
    
    for(int i=1; i<=m; i++)
        cin >> arr2[i];
    
    sort(arr2 + 1, arr2+m+1);

    int j=1;
    int ans = 0; 
    for(int i=1; i<=n; i++){
        
        while(j+1<= m &&abs(arr1[i] - arr2[j]) > abs(arr1[i]-arr2[j+1]) ){
            j++;
        }
        
        ans = max(ans,abs(arr1[i] - arr2[j]));
        //cout << ans << endl;

    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}