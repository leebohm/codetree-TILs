// 이동 전과 이동 후의 사람 수를 비교하며, 특정 집에서 이동 전의 사람수가 
// 이동 후보다 많다면 그 차만큼의 사람을 다음 집으로 이동시킨다 
// 이동거리를 최소화 시키려면 이동할 사람의 수만큼 현재의 집에서 다음 집으로 
// 이동시키며 이동한 사람의 수를 세면 된다... 

// 현재 번호의 집에 대해 이동전과 이동 후의 사람 수를 비교했을때 
// 이동전의 사람 수가 더 많다면 그 차만큼의 사람을 현재 집의 사람 수에서 
// 뺀 뒤 다음 집의 사람수에 더해주면 된다... 
#include <iostream>

#define MAX_N 100

using namespace std;

int n;

int a[MAX_N], b[MAX_N];
int ans;

int main() {

    cin >> n;

    for(int i=0; i<n;i++)
        cin >> a[i];
    for(int i=0; i<n;i++)
        cin >> b[i];
    
    for(int i=0; i<n;i++) {
        if(a[i] > b[i]){
            int num = a[i] - b[i];
            a[i] -= num;
            a[i+1] += num;
            ans += num;
        }
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}