#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 100001

using namespace std;

int n,k;
pair<int,int> candy[MAX_N];

int CandyPos(int idx){
    int pos;
    tie(pos, ignore) = candy[idx];
    return pos;
}

int CandyCnt(int idx){
    int cnt;
    tie(ignore, cnt) = candy[idx];
    return cnt;
}

int main(){

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        int cnt, pos;
        cin >> cnt >> pos;

        candy[i] = {pos,cnt};
    }

    sort(candy+1, candy+n+1);

    int j=0; 
    int ans =0;
    int sub_sum = 0;

    for(int i=1; i<=n; i++){
        while(j+1 <=n && CandyPos(j+1) - CandyPos(i) <= 2*k){
            sub_sum += CandyCnt(j+1);
            j++;
            //cout << i << " " << j << " " << sub_sum << endl;
        }
        ans = max(sub_sum, ans);
        sub_sum -= CandyCnt(i);
    }

    cout << ans;
    return 0;

}