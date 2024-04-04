#include <iostream>

#define MAX_N 1200000

using namespace std;

int n,q;
int colored[MAX_N+1];

int LastColoredNode(int dest){

    int ret = 0;

    while(dest){

        if(colored[dest])
            ret = dest;
        
        dest /= 2;
    }

    return ret;
}

int main(){
    
    cin >> n >> q;

    while(q--){
        int dest;
        cin >> dest;

        int ans = LastColoredNode(dest);
        cout << ans << endl;

        if(ans == 0)
            colored[dest] = 1;
    }
    
    return 0;
}