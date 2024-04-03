#include <iostream>
#include <vector>
#include <cmath>

#define MAX_N 1024

using namespace std;

vector<int> vec;
int k;
int arr[MAX_N];

void InOrder(int x){
    if( x > pow(2,k)-1)
        return;
    InOrder(x*2);
    vec.push_back(x);
    InOrder(x*2+1);
}

void Output(){
    for(int i=0; i<(int) vec.size(); i++){
        cout << vec[i] << " ";
    }
}

int main() {

    cin >> k;

    for(int i=1; i<=pow(2,k)-1; i++){
        cin >> arr[i];
    }
    InOrder(1);
    //Output();

    for(int idx_k = 0; idx_k <k;idx_k++){
        for(int i = 0; i<pow(2,idx_k); i++){
            cout << arr[vec[i+pow(2,idx_k)-1]]<<" ";
        }
        cout << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}