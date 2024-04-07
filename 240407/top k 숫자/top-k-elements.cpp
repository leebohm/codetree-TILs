#include <iostream>
#include <set>

using namespace std;

int n,k;
set<int> s;

int main() {
    
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(s.find(tmp) == s.end())
            s.insert(tmp);
    }

    set<int>::iterator it = s.lower_bound(1000000000);

    for(int i=0; i<k; i++){
        cout << *it << " " ;
        it --;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}