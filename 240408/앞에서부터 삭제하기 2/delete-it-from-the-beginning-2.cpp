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

    double ans = 0.0;
    for(int k =1; k<=n-2; k++){
        int sum_val = 0;
        int cnt = 0;
        priority_queue<int> pq;

        for(int j=k+1; j<=n; j++ ){
            pq.push(-arr[j]);
            sum_val += arr[j];
            cnt++;
        }

        int tmp = pq.top();
        sum_val += tmp;
        double avg = (1.0 * sum_val) / (cnt-1);
        ans = max(ans, avg);
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}