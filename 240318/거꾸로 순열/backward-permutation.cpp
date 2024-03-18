#include <iostream>
#include <vector>

#define MAX_N 9
using namespace std;

bool visited[MAX_N];
vector<int> vec;
int n;

void Print(){
    for(int i=0; i<(int) vec.size(); i++)
        cout << vec[i] <<" ";
    cout << endl;
}

void Choose(int cnt){
    if(cnt == n+1){
        Print();
        return;
    }

    for(int i=n; i>=1; i--){
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
    Choose(1);
    // 여기에 코드를 작성해주세요.
    return 0;
}