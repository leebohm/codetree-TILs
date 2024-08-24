#include <iostream>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int,int> maps;

int main() {
    
    cin >> n >> m;
    int tmp;

    for(int i = 0; i<n; i++){
        cin >> tmp;
        if(maps.find(tmp) == maps.end())
            maps[tmp] = 1;
        else
            maps[tmp]++;
    }

    for(int i=0; i<m; i++){
        cin >> tmp;
        cout << maps[tmp] << " ";
    }

    return 0;
}