#include <iostream>
#include <unordered_set>

using namespace std;

int n;
unordered_set<int> set1;

int main(){

    cin >> n;
    int ans =0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(set1.find(tmp) == set1.end()){
            ans++;
            set1.insert(tmp);
        }
    }

    cout << ans;
    
    return 0;
}