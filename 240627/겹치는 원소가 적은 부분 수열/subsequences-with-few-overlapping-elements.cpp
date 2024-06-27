#include <iostream>
#include <unordered_map>
#define MAX_N 100001

using namespace std;
int n,k;
unordered_map<int,int> m;

int arr[MAX_N];

bool Cango(int j){
    if(j+1 > n)
        return false;
    if(m[arr[j+1]]>=k)
        return false;
    return true;
}
// 같은 원소가 k개 이하로 들어있는 가장 긴 연속 부분 수열의 길이 
int main() {
    
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j = 0;
    int ans = 0 ;
    for(int i=1; i<=n; i++){
        while(Cango(j)){
            m[arr[j+1]]++;
            j++;
        }

        ans = max(ans, j-i+1);

        m[arr[i]]--;
        if(m[arr[i]]==0)
            m.erase(arr[i]);
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}