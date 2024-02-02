#include <iostream>

int n;
int x1[100];
int x2[100];

using namespace std;

bool Check(int x, int y, int a, int b){
    bool flag = true;
    if(y < a) flag = false;
    if(b < x) flag = false;
    return flag; 
}

int main() {

    cin >> n;
    
    for(int i=0 ;i < n; i++)
        cin >> x1[i] >> x2[i];
    
    bool possible = false;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            possible = Check(x1[i],x2[i],x1[j],x2[j] );
        }
    }
    if(possible) cout <<"Yes";
    else cout << "No";
    // 여기에 코드를 작성해주세요.
    return 0;
}