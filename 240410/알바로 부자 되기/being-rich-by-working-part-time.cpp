#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 1000

using namespace std;
int n;
int dp_index[MAX_N];
tuple<int,int,int> info[MAX_N];
int s,e,p;

void Output(){
    for(int i=0; i<n; i++)
        cout << dp_index[i] << " ";
    cout << endl;
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s >> e >> p;
        info[i] = {s,e,p};
    }

    tie(s,e,p) = info[0];
    dp_index[0] = p;

    for(int i=1; i<n; i++){
        tie(s,e,p) = info[i];

        dp_index[i] = p;
        
        for(int j=0; j<i; j++){

            int bs,be,bp;
            tie(bs, be, bp) = info[j];
            if(be < s)
                dp_index[i] = max(dp_index[j] + p, dp_index[i]);        
        }

        //Output();
    }
    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, dp_index[i]);
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}