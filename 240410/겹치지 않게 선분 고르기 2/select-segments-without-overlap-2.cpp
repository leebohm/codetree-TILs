#include <iostream>
#include <tuple>
#include <climits>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int n;
int x,y;
pair<int,int> xy[MAX_N];
int dp[MAX_N];
int max_y = 0;

void Output(){
    for(int i=0; i<=max_y; i++)  
        cout << dp[i]  <<" ";
    cout << endl;
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        max_y = max(y, max_y);
        xy[i] = make_pair(x,y);
        dp[y] = 1;
    }
    sort(xy, xy+n);

    for(int i=1; i<n; i++){
        int cx,cy;
        tie(cx,cy) = xy[i];
        for(int j=0; j<i; j++){
            int bx, by;
            tie(bx, by) = xy[j];
            if(by < cx){
                dp[cy] = max(dp[by]+1, dp[cy]);
            }

        }
        //Output();
    }

    int ans = 0;
    for(int i=0; i<= max_y; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}