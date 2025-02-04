#include <iostream>
#include <vector>

using namespace std;

int n;
//1 이상 4 이하의 숫자로만 이루어져 있다. 
vector<int> vec;
int cnt = 0;

void Print(){
    int sz = vec.size();
    for(int i=0; i<sz; i++)
        cout << vec[i] << " ";
    cout << "\n";
}

bool IsBeautiful(){
    int idx = 0;
    int sz = vec.size();
    while(true){
        if(idx >= sz)
            break;
        if(sz - idx < vec[idx])
            return false;
        int num = vec[idx];
        for(int i=idx; i < idx+num; i++){
            if(vec[i] != vec[idx])
                return false;
        }
        idx += num;
    }
    return true;
}

void Backtracking(int num){
    if(num == n+1){
        if(IsBeautiful()){
            cnt++;
            //Print();
        }
        return;
    }
    for(int i=1; i<=4; i++){
        vec.push_back(i);
        Backtracking(num+1);
        vec.pop_back();
    }
}

int main() {
    cin >> n;

    Backtracking(1);

    cout << cnt;

    return 0;
}
