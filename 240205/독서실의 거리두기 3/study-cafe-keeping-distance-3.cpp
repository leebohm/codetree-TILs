// 최대한 거리를 두면서 자리 배치 
// 한명 배치한구, 최대한의 거리 두기를 실행한 간격을 출력 
// 단, 양쪽 끝 자리에는 항상 사람이 앉아있음. 

#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int fin_i, fin_j = 0; 

int FindMax(){
    int dist = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1; j<n;j++){
            if(str[i]=='1' && str[j]=='1'){
                dist = max(dist, j-i);
                fin_i = i; fin_j=j;
                break;
            }
            
        }
    return dist;
}

int FindMin(){
    int dist = 1e9;
    for(int i=0;i<n;i++)
        for(int j=i+1; j<n;j++){
            if(str[i]=='1' && str[j]=='1'){
                dist = min(dist, j-i);
                fin_i = i; fin_j=j;
                break;
            }
            
        }
    return dist;
}

int main() {
    
    cin >> n;
    cin >> str;
    
    int ans = 0;
    FindMax();
    str[(fin_j-fin_i)/2+fin_i]='1';
    ans = FindMin();

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}