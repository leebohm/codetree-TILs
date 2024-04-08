#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 100000
using namespace std;

int n;
int arr[MAX_N];
vector<int> vec;

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    int cost = 0;

    for(int i=0; i<n; i++){
        sort(vec.begin(), vec.end());
        int a = 0, b = 0;
        if(vec[0] == INT_MAX || vec[1] == INT_MAX)
            break;
        a = vec[0]; 
        b = vec[1];
        vec[0] = INT_MAX;
        vec[1] = INT_MAX;
        vec.push_back(a+b);
        cost += a+b;
    }

    cout << cost;


    // 여기에 코드를 작성해주세요.
    return 0;
}