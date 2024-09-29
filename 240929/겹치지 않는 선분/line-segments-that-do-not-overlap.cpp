#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

#define MAX_N 100001

int x1[MAX_N];
int x2[MAX_N];
set<int> s1;
set<int> s2;
unordered_map<int,int> mapper;

int n;

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x1[i] >> x2[i];
        mapper[x1[i]] = x2[i];
        s1.insert(x1[i]);
    }

    for(int i=0; i<n; i++){
        set<int>::iterator it;
        it = s1.upper_bound(x1[i]);
        if(it == s1.end())
            continue;
        int tmp = mapper[*it];
        if(tmp < x2[i]){
            s2.insert(x1[i]);
            s2.insert(*it);
        }
    }

    set<int>::iterator it;
    for(it = s2.begin(); it != s2.end(); it++){
        if(s1.find(*it) != s1.end()){
            s1.erase(*it);
        }
    }

    int ans = s1.size();
    cout << ans;

    return 0;
}