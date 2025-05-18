#include <iostream>

using namespace std;

#define MAX_N 105

int n;
int arr[MAX_N];

int main(){
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int s = 0; s < n; s++){
        for(int e = s; e < n; e++){
            int sum_val = 0;
            for(int idx = s; idx <= e; idx++){
                sum_val += arr[idx];
            }
            double avg = (double) sum_val / (e-s+1);
            bool flag = false;
            for(int idx = s; idx <= e; idx++){
                if(arr[idx] == avg)
                    flag = true;
            }
            if(flag)
                ans++;
        }
    }
    cout << ans;
    return 0;
}