#include <iostream>
#include <cmath>

#define MAX_N 1024
using namespace std;

int k,n;
int a[MAX_N+1];
int tree_num[MAX_N+1];
int cnt = 1;

void InOrder(int x){
    if(x > n)
        return;
    
    InOrder(x*2);
    tree_num[x] = a[cnt++];
    InOrder(x*2+1);
}

int main(){
    cin >> k;

    n = pow(2,k) -1;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    InOrder(1);

    for(int i=1; i<=k; i++ ){
        for(int j= pow(2,i-1); j<= pow(2,i)-1; j++){
            cout << tree_num[j] <<" ";
        }
        cout << endl;
    }

    return 0;
}