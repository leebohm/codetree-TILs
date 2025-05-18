#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 105

using namespace std;

int n,k;
pair<int,int> info[MAX_N];

int main(){

    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        int pos;
        char c_tmp;
        cin >> pos >> c_tmp;
        int i_tmp = -1;
        if(c_tmp == 'G')
            i_tmp = 1;
        else
            i_tmp = 2;
        info[i] = {pos,i_tmp};
    }

    sort(info, info+n);
    
    int ans = 0;

    if(n == 1)
        ans = info[0].second;
        
    for(int s=0; s<n; s++){
        for(int e= s+1; e<n; e++){
            int tmp_score = 0;
            if(abs(info[s].first - info[e].first) <=k){
                for(int idx = s; idx<=e; idx++){
                    tmp_score += info[idx].second;
                }
            }
            ans = max(tmp_score, ans);
        }
    }

    cout << ans;

    return 0;
}