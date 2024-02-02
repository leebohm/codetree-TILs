#include <iostream>
#include <climits>

#define MAX_N 1000
#define MAX_H 100

using namespace std;

int n;
int k=17;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = INT_MAX;

    for(int i=0; i<= MAX_H; i++){
        int cost =0;
        for(int j=0; j<n;j++){
            if(arr[j]<i)
                cost += (arr[j]-i) * (arr[j]-i);
            if(arr[j] > i+k)
                cost += (arr[j]-i-k) * (arr[j] - i -k);
        }

        ans = min(ans, cost);
    }

    cout << ans;

    return 0;
}

// i보다 낮은 언덕은 높이가 i 가 되게 쌓으면 되고, 
// i+k 보다 높은 언덕은 i+k 가 되게 깎으면 되는데