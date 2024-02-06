// 처음 n 명의 사람이 서있는 순서
// 알파벳으로 주어짐 
// 인접한 두 사람의 위치를 계속 바꾸는 행위만 가능 

#include <iostream>
using namespace std;

int n; 
char arr[26];

int main() {
    
    cin >> n;
    
    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    bool flag = true;
    int ans = 0; 

    while(flag){
        bool check = true; 
        for(int i=0; i<n-1 ;i++){
            if ((arr[i+1] - arr[i] ) != 1) check = false;
        }
        if (check) flag = false;  

        for(int i=0; i<n-1;i++){
            if(arr[i+1]-arr[i]<0) {
                char tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                ans++;
            }
        }

    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}