#include <iostream>
#include <vector>

using namespace std;


int n,k;
vector<int> path;
bool Check(){
    int cnt = 0;
    for(int i=0; i<(int)path.size()-1; i++){
        if(path[i] == path[i+1])
            cnt++;
        else
            cnt = 0;
        if(cnt >= 2)
            return false;
    }
    return true;
}

void Print(){
    for(int i=0; i < (int) path.size(); i++){
        cout << path[i] <<" ";
    }
    cout <<"\n";
    return;
}

void Backtracking(int cnt){
    if(cnt == n){
        if(Check())
            Print();
        return;
    }

    for(int i=1; i<=k; i++){
        path.push_back(i);
        Backtracking(cnt+1);
        path.pop_back();
    }
}

int main(){

    cin >> k >> n;

    Backtracking(0);

    return 0;
}