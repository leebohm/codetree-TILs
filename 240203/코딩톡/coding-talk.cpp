#include <iostream>
#define MAX_M 100

using namespace std;

int n,p,m;
char c[MAX_M];
int u[MAX_M];

int main() {

    cin >> n >> m >> p;

    for(int i=0; i<m; i++)
        cin >> c[i] >> u[i];

    if(u[p-1]==0) return 0;

    for(int i=0; i<n;i++){
        char person = 'A' + i;
        bool read = false;

        for(int j=0; j<m;j++)
            if(u[j] >= u[p-1] && c[j] == person)
                read=true;
        
        if(read == false)
            cout << person << " ";
    }

    return 0;
}