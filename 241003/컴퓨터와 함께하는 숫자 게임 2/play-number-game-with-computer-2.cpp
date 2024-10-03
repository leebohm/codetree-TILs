#include <iostream>
#include <climits>
using namespace std;

long long m;
long long a,b;
long long cnt = 0;

long long BS(long long x){
    long long left = 1;
    long long right = m;
    while(left <= right){
        long long mid = (left + right) / 2;
        cnt++;
        if(mid == x)
            return cnt;
        else if(mid < x)
            left = mid+1;
        else if(mid > x)
            right = mid-1;
    }
    return cnt;
}

int main() {
    cin >> m;
    cin >> a >> b;
    long long min_ans = INT_MAX;
    long long max_ans = -1;

    for(long long i=a; i<=b; i++){
        cnt = 0;
        long long tmp = BS(i);
        min_ans = min(min_ans, tmp);
        max_ans = max(max_ans, tmp);
    }
    cout << min_ans << " " << max_ans;
    return 0;
}