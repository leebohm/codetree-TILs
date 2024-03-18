#include <iostream>
#include <climits>
#include <vector>

#define MAX_N 10
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int ans = INT_MAX;
vector<int> vec;
bool visited[MAX_N];

void Print(){
    cout << "Print : " ;
    for(int i=0; i<(int) vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
int Calc(){
    //Print();
    int sum1 = 0;
    for(int i=0; i<(int) vec.size()-1; i++){
        if(arr[vec[i]][vec[i+1]] == 0)
            sum1 += 100000;
        else{
            sum1 += arr[vec[i]][vec[i+1]];
            //cout << arr[vec[i]][vec[i+1]] << " ";
        }
    }
    if(arr[vec[(int) vec.size()-1]][vec[0]] == 0)
        sum1 += 1000000;
    else
        sum1 += arr[vec[(int) vec.size()-1]][vec[0]];
    //cout << arr[vec[(int) vec.size()-1]][vec[0]] <<" " << sum1 << endl;
    //cout << endl;
    return sum1;
}

void Choose(int cnt){
    if(cnt == n){
        ans = min(ans, Calc());
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        visited[i] = true;
        vec.push_back(i);
        
        Choose(cnt+1);
        
        vec.pop_back();
        visited[i] = false;
    }
}

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    Choose(0);
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}