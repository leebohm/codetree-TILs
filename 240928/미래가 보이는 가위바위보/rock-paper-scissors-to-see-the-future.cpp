#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
char matches[MAX_N];

int L[MAX_N], R[MAX_N];
int ans;

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> matches[i];
    
    char shapes[]= "PHS";

    for(int s =0; s<3; s++){
        char shape = shapes[s];
        int same_cnt = 0;

        for(int i=0; i<n; i++){
            if(matches[i] == shape)
                same_cnt += 1;
            L[i] = max(L[i], same_cnt);
        }
    }

    for(int s= 0; s<3; s++){
        char shape = shapes[s];

        int same_cnt = 0;
        for(int i=n-1; i >=0; i--){
            if(matches[i] == shape)
                same_cnt += 1;
            
            R[i] = max(R[i], same_cnt);
        }
    }

    for(int i=0; i<n-1; i++)
        ans = max(ans, L[i] + R[i+1]);

    cout << ans;
    return 0;
}