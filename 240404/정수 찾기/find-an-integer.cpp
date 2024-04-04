#include <iostream>
#include <unordered_set>

#define MAX_N 100000

using namespace std;

unordered_set<int> a_set;

int b_arr[MAX_N];
int n;
int m;

int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a_set.insert(tmp);
    } 

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b_arr[i];
    }

    for(int i=0; i<m; i++){
        if(a_set.find(b_arr[i]) != a_set.end()){
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}