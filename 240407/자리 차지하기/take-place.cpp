#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n,m;
int arr[100000];

int main() {

    cin >> n >>  m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int tmp = arr[i];
        while(tmp--){
            if(s.find(tmp) == s.end()){
                s.insert(tmp);
                break;
            }
                
        }

        if(tmp== 0 ){
            break;
        }

        s.insert(tmp);
    }

    int ans = (int) s.size();

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}