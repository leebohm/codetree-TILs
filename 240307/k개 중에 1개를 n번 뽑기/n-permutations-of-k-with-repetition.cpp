#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> vec;

void Print(){
    for(int i = 0; i< (int) vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void Choose(int curr_num){
    if(curr_num == n){
        Print();
        return ;
    }

    for(int i = 1; i<=k; i++){
        vec.push_back(i);
        Choose(curr_num+1);
        vec.pop_back();
    }

    return ;
}

int main() {

    cin >> k >> n;

    Choose(0);


    // 여기에 코드를 작성해주세요.
    return 0;
}