#include <iostream>
#include <queue>

#define MAX_N 100001
using namespace std;


int n;
int arr[MAX_N];

int main() {

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    priority_queue<int> pq;

    pq.push(-arr[n]);
    int sum_val = arr[n];

    double ans = 0.0;
    for(int i = n-1; i>=2; i--){
        pq.push(-arr[i]);
        sum_val += arr[i];

        double avg = (1.0 * sum_val + pq.top()) / (n - i );
        ans = max(ans, avg);
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}