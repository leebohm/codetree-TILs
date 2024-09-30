#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

#define MAX_N 100001

int x1[MAX_N];
int x2[MAX_N];
set<int> s1;
set<int> s2;
set<int> ans_set;
unordered_map<int,int> x1_2_x2;
unordered_map<int,int> x2_2_x1;

int n;

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x1[i] >> x2[i];
        x1_2_x2[x1[i]] = x2[i];
        x2_2_x1[x2[i]] = x1[i]; 
        s1.insert(x1[i]);
        s2.insert(x2[i]);
    }

    for(int i=0; i<n; i++){
        set<int>::iterator it;
        it = s1.upper_bound(x1[i]);
        if(it == s1.end())
            continue;

        while(*it < x2[i]){ // c가 b보다 작을 때까지 
            int d = x1_2_x2[*it]; // tmp : d
            if(d < x2[i]){ // d가 b보다 작은 경우? 
                ans_set.insert(*it);
                ans_set.insert(x1[i]);
                s1.erase(*it);
            }
            else
                break;
            it = s1.upper_bound(x1[i]);
            if(it == s1.end())
                break;
        }
    }

    set<int>::iterator it;
    for(it = ans_set.begin(); it != ans_set.end(); it++){
        if(s1.find(*it) != s1.end()){
            s1.erase(*it);
        }
    }

    int ans = s1.size();
    cout << ans;

    return 0;
}