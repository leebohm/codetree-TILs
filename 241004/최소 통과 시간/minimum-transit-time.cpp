#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_M 100001
#define MAX_T 1000000000

int n,m;
long long tunnel[MAX_M];

bool IsPossible(long long t){
    long long cnt = 0;
   // cout << "t : " << t << endl;
    for(int i=0; i<m; i++){
        cnt += t / tunnel[i];
        //cout << "cnt : " << cnt << endl;
    }
    return cnt >=n;
}

int main(){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> tunnel[i];
    }
    sort(tunnel, tunnel + m);
    
    long long left = 1; 
    long long right = MAX_T;
    long long ans = MAX_T;
    while(left <= right){
        long long  mid = (left + right) / 2;
        if(IsPossible(mid)){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }
    cout << ans ;
    return 0;
}