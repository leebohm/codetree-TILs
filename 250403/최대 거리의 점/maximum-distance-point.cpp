#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 200005

int n,m;
int arr[MAX_N];

int ReturnCnt(long long x){
    int cnt = 1;
    int rct_pos = 0;
    for(int i=1; i<n; i++){
        if(arr[i] - arr[rct_pos] >= x){
            cnt++;
            rct_pos = i;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    long long left = 0;
    long long right = 1000000005;
    long long ans = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(ReturnCnt(mid) >= m){ // m 보다 크거나 같다 mid 가 작아지면 개수 더 많아짐.. mid 가 커져야함 
            //cout << "left : " << left <<" right : " << right <<" : " << mid <<" cnt : " << ReturnCnt(mid) << "\n";
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }

    cout << ans;
    return 0;
}