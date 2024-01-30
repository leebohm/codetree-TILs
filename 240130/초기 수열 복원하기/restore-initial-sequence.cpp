// #include <iostream>

// using namespace std;

// int n,temp;
// int arr[1000];
// int ans[1001];


// int main() {
//     cin >> n;
//     for(int i=0; i<n-1;i++)
//         cin >> arr[i]; // arr의 1번째 원소는 ans의 1,2번째 원소의 합

//     for(int i=1; i<arr[0]-1;i++){
//         ans[0] = i; // arr 를 i로 분해 
//         for(int j=1; j<n;j++){
//             temp = arr[j-1]-ans[j-1]; // arr에서 i를 뺀게 ans의 2번째 
//             if(temp>0) ans[j] = temp;
//             else break;
//         }
//         if(ans[n-1]!=0){
//             bool flag = true;
//             int arr3[n] = {};
//             for(int i=0; i<n;i++){
//                 if(arr3[ans[i]]!=0)arr3[ans[i]]++;
//                 if(arr3[ans[i]]>=2) flag = false;
//             }
//             if(flag){
//             for(int i=0; i<n;i++)
//                 cout<< ans[i] << " " ;
//             break;   
//             }     
//         }


//     }


//     // 여기에 코드를 작성해주세요.
//     return 0;
// }

#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int n;
int a[MAX_N];
int arr[MAX_N];

int main() {
    cin >> n;

    for(int i=0; i<n-1; i++)
        cin >> a[i];
    
    for(int i=1; i<=n;i++){
        arr[0] = i;

        for(int j=1; j<n; j++){
            arr[j] = a[j-1] - arr[j-1];
        }

        bool satisfied = true;
        bool exist[MAX_N+1] = {};

        for(int j=0; j<n;j++){
            if(arr[j] <=0 || arr[j] > n) satisfied = false;
            else{
                if(exist[arr[j]]) satisfied = false;
                exist[arr[j]] = true;
            }
        }
       
        if(satisfied) {
            for(int j=0; j<n;j++)
                cout << arr[j] << " ";
            return 0;
        }
    }
}