#include <iostream>

// n개의 숫자가 주어지고, 그 중 최대 L개의 서로 다른 원소의 값
// 아 뭐야 L개만큼 골라 1을 더해줘야하잖아. 
// H 점수를 최대로 만드는 프로그램
// H 점수란 특정 수열이 주어졌을 때 
// H 이상인 숫자의 수가 H 개 이상인 것 중 최댓값.

//이것도 아까 문제처럼 최댓값 완탐으로 풀면 될 것 같은데 
// 1부터 100까지가 가능한 최댓값이고, 
// h보다 1만큼 작으면 1 더해줘서 h 이상으로 만든 후, 
// cnt 세서 L 보다 작거나 같으면 되는 거 아니여!!

int n, l;
using namespace std;
int arr[100];

int main() {

    cin >> n >> l;
    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    int ans =0;
    for(int h= 1; h<= 100; h++){
        int cnt =0; 
        int cnt_l = 0;
        for(int i=0 ; i<n;i++){
            if(arr[i]>=h) cnt++;
            if(cnt_l < l)
                if(arr[i]+1 == h) {
                    cnt_l++;
                    cnt++;
                }
        }

        if((cnt >= h) && (cnt_l <= l))
            ans = max(h,ans);
    }
    cout << ans; 
            // 여기에 코드를 작성해주세요.
    return 0;
}