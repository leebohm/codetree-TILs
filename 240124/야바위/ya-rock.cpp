#include <iostream>

int n;
int a[100], b[100], c[100];

using namespace std;

int main() {

    cin >> n;
    
    int max_score = 0;

    for(int i=0; i<n; i++)
        cin >> a[i] >> b[i] >> c[i];
    
    
    for(int i=0; i<3; i++){
        int cups[3]={};
        cups[i] = 1;
        int score = 0;
        for(int j= 0; j<n;j++){
            if(cups[a[j]]==1){
                cups[a[j]] = 0;
                cups[b[j]] = 1;
            } 
            else if(cups[b[j]]==1){
                cups[a[j]] =1;
                cups[b[j]] = 0;
            }
            if(cups[c[j]]==1) score++;
        }
        max_score = max(max_score,score);
    }

    cout << max_score;

    // 여기에 코드를 작성해주세요.
    return 0;
}