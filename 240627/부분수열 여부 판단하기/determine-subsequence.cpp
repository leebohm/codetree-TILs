#include <iostream>

#define MAX_N 100001

using namespace std;

int n,m;
int A[MAX_N];
int B[MAX_N];

bool Check(){
    int i=1;
    for(int j=1; j<=m; j++){
        while(i <= n && A[i] != B[j] ){
            i++;
        }
        if(i>n)
            return false;
    }

    return true;

}

int main() {
    int n,m;

    for(int i=1; i<=n; i++)
        cin >> A[i];
    
    for(int i=1; i<=m; i++)
        cin >> B[i];
    
    if(Check()== true)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}