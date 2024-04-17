#include <iostream>
#include <string>

#define MAX_M 100000
using namespace std;

string T,P;
int n;
int f[MAX_M];
int ans = 0;

void kmp(string t, string p){
    int t_n = (int) t.size();
    int p_m = (int) p.size();

    t = "#" + t;
    p = "#" + p;
    
    f[0] = -1;
    //cout << p << endl;

    for(int i=1; i<=p_m; i++){
        int j = f[i-1];
        while(j>=0 && p[i] != p[j+1])
            j = f[j];
        f[i] = j+1;
    }

    int j = 0;
    for(int i = 1; i<=t_n; i++ ){

        while(j>=0 && t[i] != p[j+1])
            j=f[j];
        j++;
        if(j==p_m){
            ans++;
            j=f[j];
        }
    }
}
int main() {

    cin >> n >> P>> T;


    T += T;
    T.pop_back();

    kmp(T,P);
    cout << ans;


    // 여기에 코드를 작성해주세요.
    return 0;
}