// 아 문제를 너무 어렵게 풀었따... 
// 여러 선분이 최소한 하나의 지점에서 겹치는 지는 
// 한 선분이라고 시작점이 다른 끝점보다 뒤에 온다면 선분이 전부 겹칠 수 없음 
// 아 이런 경우에는 완전 탐색할 일이 아니라 반례 1개만 찾으면 풀리는 문제구나 

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int x1, x2; 
int max_x1; 
int min_x2 = INT_MAX;

int main() {
    cin >> n;

    for(int i=0; i<n;i++){
        cin >> x1 >> x2;
        max_x1 = max(max_x1, x1);
        min_x2 = min(min_x2, x2);
    }
    if(min_x2 >= max_x1)
        cout << "Yes";
    else 
        cout << "No";
    
    return 0;
}

// #include <iostream>

// int n;
// int x1[100];
// int x2[100];

// using namespace std;

// bool Check(int x, int y, int a, int b){
//     bool flag = true;
//     if(y < a) flag = false;
//     if(b < x) flag = false;
//     return flag; 
// }

// int main() {

//     cin >> n;
    
//     for(int i=0 ;i < n; i++)
//         cin >> x1[i] >> x2[i];
    
//     int cnt =1;
//     for(int i=0; i<n; i++){
        
//         bool possible = false;
//         for(int j=i+1; j<n; j++){
//             possible = Check(x1[i],x2[i],x1[j],x2[j] );
//         }

//         if(possible) cnt++;
//     }
//     if(cnt== n) cout <<"Yes";
//     else cout << "No";
//     // 여기에 코드를 작성해주세요.
//     return 0;
// }