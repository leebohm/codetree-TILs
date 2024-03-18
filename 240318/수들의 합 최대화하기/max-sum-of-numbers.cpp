#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10

using namespace std;

int n;
int grid[MAX_N][MAX_N];
bool visited[MAX_N];
vector<int> picked;

int ans;

void FindMax(int row){

    if(row == n){
        int sum =0;
        for(int i=0; i<(int) picked.size(); i++)
            sum+= grid[i][picked[i]];
        ans= max(ans, sum);
        return;
    }

    for(int i=0; i<n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        picked.push_back(i);

        FindMax(row +1);
        visited[i] = false;
        picked.pop_back();
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    FindMax(0);

    cout << ans;
    return 0;
    
}