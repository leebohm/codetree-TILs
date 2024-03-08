#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> vec;

bool Possible(){
    int a = vec[0];
    int cnt = 1;
    int max_cnt = 0;
    for(int i=1; i<(int) vec.size(); i++){
        max_cnt = max(cnt, max_cnt);
        if(a == vec[i]){
            cnt++;
        }
        else if(a != vec[i]){
            a = vec[i];
            cnt = 1;
        }
    }
    if(max_cnt >= 3) return false;
    else return true;
}

void Choose(int cnt){

    if(cnt == n){
        if(Possible()){
            for(int i=0; i<(int) vec.size(); i++)
                cout << vec[i] <<" ";
            cout << endl;
        }
        return;
    }

    for(int i=1; i<=k; i++){
        vec.push_back(i);
        Choose(cnt+1);
        vec.pop_back();
    }
    return;
}

int main() {

    cin >> k >> n;

    Choose(0);
    // 여기에 코드를 작성해주세요.
    return 0;
}