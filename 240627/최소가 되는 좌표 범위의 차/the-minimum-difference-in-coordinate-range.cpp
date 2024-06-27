#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

#define MAX_N 100001
using namespace std;

int n,d;
int x,y;
pair<int,int> pos[MAX_N];
set<pair<int,int> > pos_set;

int getmin(){
    if(pos_set.empty()) return 0;
    return pos_set.begin()->first;
}

int getmax(){
    if(pos_set.empty()) return 0;
    return pos_set.rbegin()->first;
}


int main(){
    cin >> n >> d;

    for(int i=1; i<=n; i++)
        cin >> pos[i].first >> pos[i].second;
    
    sort(pos+1, pos+n+1);

    int j =0; 
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        while(j+1<=n && getmax() - getmin() < d){
            pos_set.insert({pos[j+1].second, pos[j+1].first});
            j++;
        }

        if(getmax()- getmin() < d)
            break;
        
        ans = min(ans, pos[j].first - pos[i].first);
        pos_set.erase({pos[i].second,pos[i].first});

    }
    if(ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}