#include <iostream>
#include <string>
using namespace std;

#define MAX_N 10002
int l[MAX_N];
int r[MAX_N];
string str;
int n;

int main() {

    cin >> n;
    cin >> str;

    str = '#' + str;

    for(int i=1; i<=n; i++){
        if(str[i] == 'C')
            l[i] = l[i-1]+1;    
        else
            l[i] = l[i-1];
    }
    
    if(str[n] == 'W')
        r[n] = 1;
    
    for(int i=n-1; i>=1; i--){
        if(str[i] == 'W')
            r[i] = r[i+1]+1;
        else
            r[i] = r[i+1];
    }
    
    long long ans = 0;
    for(int i=2; i<=n-1; i++){
        if(str[i] == 'O'){
            ans += (l[i-1] * r[i+1]);
        }
    }
    cout << ans;
    return 0;
}