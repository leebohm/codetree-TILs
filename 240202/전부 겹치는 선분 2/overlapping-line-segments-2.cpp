#include <iostream>
#include <climits>

using namespace std;

int n;
int x1[100];
int x2[100];

int main() {

    cin >> n;

    for(int i=0; i<n;i++)
        cin >> x1[i] >> x2[i];

    
    bool flag = false;
    for(int i=0; i<n;i++){ // 이 선을 사용하지 않을 예정
        int min_x2 = INT_MAX;
        int max_x1 = 0;
        for(int j=0; j<n; j++){
            if(i!=j){
                min_x2 = min(min_x2,x2[j]);
                max_x1 = max(max_x1,x1[j]);
            }
        }
        if(min_x2 >= max_x1) {
            flag = true;
            }
        if(flag) break;
    }
    if(flag) cout << "Yes";
    else cout << "No";
    // 여기에 코드를 작성해주세요.
    return 0;
}