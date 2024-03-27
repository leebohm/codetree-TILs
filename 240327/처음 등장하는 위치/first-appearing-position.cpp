#include <iostream>
#include <map>

using namespace std;

int n;
map<int,int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        m.insert({tmp,i+1});
    }

    map<int,int>::iterator it;

    for(it = m.begin(); it != m.end(); it++ ){
        cout << it-> first << " " << it -> second << "\n";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}