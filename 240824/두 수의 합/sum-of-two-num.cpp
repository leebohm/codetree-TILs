#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 100001
int n,k;
unordered_map<int,int> maps;
int nums[MAX_N];

int main(){
    cin >>  n >> k;

    for(int i=0; i<n; i++){
        cin >> nums[i];
        if(maps.find(nums[i]) == maps.end())
            maps[nums[i]] = 1;
        else
            maps[nums[i]]++;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int tmp = k-nums[i];
        if(maps.find(tmp) != maps.end()){
            ans += (maps[tmp] * maps[nums[i]]);
            maps[tmp] = 0;
        }
    }
    cout << ans;
}