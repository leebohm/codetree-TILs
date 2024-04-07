#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n,m;
int arr[100000];
int main() {
    cin >> n >> m;
   
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        int tmp = arr[i];
        while(tmp != 0){
            if(s.find(tmp)==s.end()){
                s.insert(tmp);
                break;
                }
            tmp--;
            
        }
	    if(tmp==0)
		    break;
    }
	int ans = (int) s.size();
    cout << ans;
    return 0;
}