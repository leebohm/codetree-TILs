#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n,m;
set<int> s_num;
set<tuple<int,int,int> > s_len;

int main(){

    cin >> n >> m;
    
    s_num.insert(-1);
    s_num.insert(n+1);

    s_len.insert(make_tuple(-(n+1),-1,n+1));

    for(int i=0; i<m; i++){

        int y;
        cin >> y;

        s_num.insert(y);

        set<int>::iterator it;
        it = s_num.find(y);
        it++;
        int z = *it;

        it = s_num.find(y);
        it--;
        int x = *it;

        s_len.erase(make_tuple(
            -(z-x-1),x,z
        ));

        s_len.insert(make_tuple(
            -(y-x-1),x,y
        ));
        s_len.insert(make_tuple(
            -(z-y-1),y,z
        ));

        int best_length;
        tie(best_length, ignore, ignore) = *s_len.begin();
        cout << -best_length << endl;
    }

    return 0;
}