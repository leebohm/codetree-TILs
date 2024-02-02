// 나는 모든 구간을 나눠보는 완전탐색을 하려고 하니 어려웠다. 
// 가능한 최댓값에 대해 완전 탐색을 하는 문제였다.... 

// 가능한 모든 최댓값 중에서 하나를 최댓값으로 임의로 설정한 뒤, 
// 그 최댓값에 맞게 구간이 m 개로 나누어지는지 판단하고, 
// 나누어지는 최댓값 중 가장 작은 값을 구하면 된다. 


// 주어진 숫자를 순서대로 탐색하며, 현재 숫자에 바로 전 숫자를 더했을 때 
// 설정한 최댓값보다 크다면, 해당 숫자부터 시작하는 새로운 구간이 있다는 뜻
// 만약 숫자 하나가 설정한 최댓값보다 크다면 구간을 나눌 수 없다는 의미


#include <iostream>
#include <algorithm>

#define MAX_A 10000
#define MAX_N 100

using namespace std;

int n,m;
int a[MAX_N];

int main() {
    cin >> n >> m;

    for(int i=0; i<n;i++)
        cin >> a[i];
    
    int ans = MAX_A;

    for(int i=1; i<=MAX_A; i++){

        bool possible = true;
        int section = 1;

        int cnt =0;
        for(int j=0;j<n;j++){
            if(a[j] > i){
                possible = false;
                break;
            }
            if(cnt + a[j]> i){
                cnt = 0;
                section++;
            }
            cnt += a[j];
        }

        if(possible && section <= m){
            ans = min(ans, i);
        }
    }
    cout << ans;

    return 0;
}