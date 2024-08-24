#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string str;
unordered_map<string, int> maps;

int main() {
    
    cin >> n;
    int ans = 0;

    for(int i=0; i<n; i++){
        cin >> str;
        if(maps.find(str) == maps.end()){
            maps[str] = 1;
        }
        else
            maps[str]++;
        ans = max(ans, maps[str]);
    }

    cout << ans;


    return 0;
}