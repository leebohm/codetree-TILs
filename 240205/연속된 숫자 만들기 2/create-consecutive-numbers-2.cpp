#include <iostream>
#include <algorithm>

#define MAX_N 3

using namespace std;

int n=3;
int a[MAX_N];

int main() {
    
    for(int i=0; i <n;i++)
        cin >> a[i];
    
    sort(a,a+n);

    if(a[0]+1 == a[1] && a[1] +1 == a[2])
        cout << 0;

    else if (a[0] + 2== a[1] || a[1] + 2 == a[2])
        cout << 1;
    
    else 
        cout << 2;

    return 0;
}