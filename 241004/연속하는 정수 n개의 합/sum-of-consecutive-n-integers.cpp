#include <iostream>

using namespace std;

#define MAX_N 100001

int n;
long long m;
int arr[MAX_N];


int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int j = 0;
    int cnt = 0;
    long long tmp = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <= n && tmp + arr[j+1] <= m){
            tmp += arr[j+1];
            j++;
        }
        if(tmp == m)
            cnt++;
        tmp -= arr[i];
    }
    cout << cnt;
    return 0;
}