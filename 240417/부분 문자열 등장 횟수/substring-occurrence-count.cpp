#include <string>
#include <iostream>

#define MAX_M 100000

using namespace std;

string T;
string P;
int f[MAX_M+1];

int ans = 0;
int main(){
    cin >> T;
    cin >> P;

    int n = (int) T.size();
    int m = (int) P.size();

    T = "#" + T;
    P = "#" + P;

    f[0] = -1;

    for(int i=1; i<=m; i++){
        int j = f[i-1];

        while(j>=0 && P[i] != P[j+1])
            j = f[j];
        
        f[i] = j+1;
    }

    int j = 0;

    for(int i=1; i<=n; i++){

        while(j>=0 && T[i] != P[j+1])
            j = f[j];
        
        j++;

        if(j == m){
            ans++;
            j = f[j];
        }

    }

    cout << ans;

    return 0;
}