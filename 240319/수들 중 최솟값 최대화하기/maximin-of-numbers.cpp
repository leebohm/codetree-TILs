#include <iostream>
#include <vector>
#include <climits>
#define MAX_N 10
using namespace std;

int n;
int ans;
int arr[MAX_N][MAX_N];
vector<int> cols;
bool visited[MAX_N];

int Calc(){
    int min_val = INT_MAX;
    for(int i=0; i<n; i++){
        min_val = min(min_val,arr[i][cols[i]]);
    }
    return min_val;
}

void Choose(int row){
    if(row == n){
        ans = max(ans, Calc());
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        cols.push_back(i);
        Choose(row+1);
        cols.pop_back();
        visited[i] = false;
    }
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    Choose(0);
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}