#include <iostream>
#include <tuple>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

int n,x,y,d;
pair<int,int> pos[MAX_N];

int GetX(int idx){
    tie(x,y) = pos[idx];
    return x;
}

int GetY(int idx){
    tie(x,y) = pos[idx];
    return y;
}

int main() {
    
    cin >> n >> d;

    for(int i=1; i<=n; i++){
        cin >> x >> y;
        pos[i] = {x,y};
    }

    sort(pos+1, pos+n+1);

    int b = n;
    int ans = INT_MAX;

    for(int a = 1; a<=n; a++ ){
        while(b-1 >a && abs(GetY(b)-GetY(a)) < d ){
            b--;
        }
        if(abs(GetY(b)-GetY(a))>= d){
            ans = min(ans, abs(GetX(b)-GetX(a)));
        }
        
    }

    if(ans == INT_MAX)
        ans = -1;
    cout << ans;


    // 여기에 코드를 작성해주세요.
    return 0;
}