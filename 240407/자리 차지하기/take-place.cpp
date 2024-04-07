#include <iostream>
#include <set>

#define MAX_N 100000
using namespace std;

int n,m;
set<int> s;
int arr[MAX_N];

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=m; i++)
        s.insert(i);

    int ans = 0;
    for(int i=0; i<n; i++){
        set<int>::iterator idx = s.upper_bound(arr[i]);

        if(idx != s.begin()){
            idx--;
            s.erase(*idx);
            ans++;
        }
        else
            break;
    }

    cout << ans ;


    return 0;
}