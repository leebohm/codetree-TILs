#include <iostream>
#include <set>
#include <tuple>

define MAX_N 100000

using namespace std;

int n,t;
set<pair<int,int> > people_x;
set<tuple<double, int, int> > event_t;

int x[MAX_N], v[MAX_N];

void AddEvent(int x1, int v1, int x2, int v2){

    if(v1 <= v2)
        return;
    
    event_t.insert(make_tuple(1.0 * (x2-x1) / (v1 - v2), x1, v2));
}

void RemoveEvent(int x1, int v1, int x2, int v2){
    
    if(v1 <= v2)
        return;
    
    event_t.erase(make_tuple(1.0 * (x2 - x1)/ (v1-v2), x1, v1));
}

int main() {

    cin >> n >> t;
    for(int i=0; i<n; i++)
        cin >> x[i] >> v[i];
    
    for(int i=0; i<n; i++)
        people_x.insert(make_pair(x[i],v[i]));
    
    for(int i=0; i<n-1; i++)
        AddEvent(x[i],v[i],x[i+1],v[i+1]);
    
    while(!event_t.empty()){

        double curr_t; int x,v;
        tie(curr_t,x,v) = *event_t.begin();

        if(curr_t > t)
            break;

        people_x.erase(make_pair(x,v));
        event_t.erase(make_tuple(curr_t,x,v));

        set<pair<int,int> >::iterator it  = people_x.upper_bound(make_pair(x,v));
        int nx, nv;
        tie(nx,nv) = *it;

        if(it != people_x.begin()){
            it--;
            int px,pv;
            tie(px,pv) = *it;
            RemoveEvent(px,pv,x,v);
            AddEvent(px,pv,nx,nv);
        }
    }

    cout << (int) people_x.size();

    retunr 0;
}