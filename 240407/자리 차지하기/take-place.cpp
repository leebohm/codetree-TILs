#include <iostream>
#include <set>

#define MAX_N 100000

using namespace std;

int n,m;
int arr[MAX_N];

set<int> seats;

int main(){
    cin >>  n >> m;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=1; i<=m; i++)
        seats.insert(i);
    
    int ans = 0;

    for(int i=0; i<n; i++){
        set<int>::iterator idx = seats.upper_bound(arr[i]);
    
        if(idx != seats.begin()){
            idx--;
            seats.erase(*idx);

            ans++;
        }
        else break;
    }

    cout << ans;
    return 0;

}