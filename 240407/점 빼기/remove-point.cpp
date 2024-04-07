#include <iostream>
#include <tuple>
#include <set>

#define MAX_N 100000

using namespace std;

int n,m;

pair<int,int> points[MAX_N];
set<pair<int,int> > s;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        points[i] = make_pair(x,y);
    }

    for(int i=0; i<n; i++)
        s.insert(points[i]);
    
    while(m--){
        int k;
        cin >> k;

        if(s.upper_bound(make_pair(k,-1)) == s.end())
            cout << "-1 -1" << endl;
        
        else{
            pair<int,int> target = *s.upper_bound(make_pair(k,-1));
            int x,y;
            tie(x,y) = target;
            cout << x << " " << y << endl;
            s.erase(target);
        }
    }
    return 0;
}