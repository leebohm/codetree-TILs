#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int,int> xy;
int x, y;

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        if(xy.find(x) == xy.end())
            xy[x] = y;
        else{
            if(xy[x] < y) // 기존것이 더 작은 상황
                continue;
            else
                xy[x] = y; // 새로 들어온 것이 더 작은 상황.
        }
    }

    long long ans = 0;
    for(unordered_map<int,int>::iterator it = xy.begin(); it != xy.end(); it++)
        ans += it->second;
    
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}