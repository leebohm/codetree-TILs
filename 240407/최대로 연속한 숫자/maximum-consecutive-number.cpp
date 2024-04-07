#include <iostream>
#include <set>

using namespace std;

int n,m;
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=0; i<=n; i++)
        s.insert(i);
    
    int ans = 0;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        s.erase(tmp);
        set<int>::iterator it = s.begin();
        int val = *it;
        it++;
        int cnt = 1;
        ans = 0;
        while(it != s.end()){
            if(*it - val == 1){
                val = *it;
                cnt++;
            }   
            else{
                cnt = 1;
                val = *it;
            }
            ans = max(ans, cnt);
            it++;
        }
        cout << ans << endl;

    }
    
    // 여기에 코드를 작성해주세요.
    return 0;
}