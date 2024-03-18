// 처음에 arr 로 받고, curr_idx로 조정하고 처음에 sum을 구해놓은 뒤, 빼면 되쟈나~~

#include <iostream>
#include <climits>
#include <vector>

#define MAX_2N 20
using namespace std;

int arr[MAX_2N];
int n;
int total =0;
int ans = INT_MAX;
vector<int> selected_num;

int Calc(){
    int sum1 = 0; 
    for(int i=0; i<(int) selected_num.size(); i++){
        sum1+= selected_num[i];
    }
    int sum2 = abs(total - sum1);
    return abs(sum2 - sum1);
}

void Choose(int curr_idx, int cnt){
    if(cnt == n){
        ans = min(ans, Calc());
        return;
    }
    if(curr_idx == 2*n-1)
        return;

    selected_num.push_back(arr[curr_idx]);
    Choose(curr_idx+1, cnt+1);
    selected_num.pop_back();

    Choose(curr_idx+1, cnt);
}

int main(){
    cin >> n;

    for(int i=0; i< 2*n; i++){
        cin >> arr[i];
        total += arr[i];
    }
    
    Choose(0,0);
    
    cout << ans;
    return 0;
}