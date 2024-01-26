#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string seat;

int MinDist(){
    int min_dist = n;

    for(int i=0; i<n;i++)
        for(int j=i+1;j<n;j++)
            if(seat[i]=='1' && seat[j]=='1')
                min_dist = min(min_dist,j-i);
    
    return min_dist;
}

int main() {
    cin >> n;
    cin >> seat;

    int ans =0;
    for(int i=0; i<n;i++){
        if(seat[i]=='0'){
            seat[i] ='1';
            ans = max(ans, MinDist());
            seat[i] = '0';
        }
    }
    cout << ans;
    return 0;
}