#include <iostream>
#include <string>
#include <algorithm>

#define MAX_A 40
#define MAX_N 15

using namespace std;

int arr[MAX_N];

int main() {
    
    for(int i=0; i<MAX_N;i++)
        cin >> arr[i];
    
    for(int a=1;a<=MAX_A;a++)
        for(int b=a;b<=MAX_A;b++)
            for(int c=b; c<=MAX_A;c++)
                for(int d=c;d<=MAX_A;d++){
                    int arr2[MAX_N] = {a,b,c,d,a+b,b+c,c+d,d+a,a+c,b+d,a+b+c,a+b+d,a+c+d,b+c+d,a+b+c+d};

                    sort(arr2,arr2+MAX_N);
                    sort(arr, arr+MAX_N);

                    bool issame = true;

                    for(int i=0; i<MAX_N;i++)
                        if(arr[i]!=arr2[i]) issame= false;

                    if(issame)
                        printf("%d %d %d %d",a,b,c,d);
                }
                
    return 0;
}