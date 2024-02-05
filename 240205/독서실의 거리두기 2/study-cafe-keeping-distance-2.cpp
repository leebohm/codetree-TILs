#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int fin_i,fin_j;

void findMax(){
    int dist = 0;
    for(int i=0; i<n;i++){
        if(str[i]=='1'){
        for(int j=i+1; j<n;j++){
            if(str[j]=='1'){
                dist = max(dist, j-i);
                if(dist == j-i){
                    fin_i = i; fin_j = j;
                }
                break;
            }
        }
    }
    }
}

int findMin(){
    int dist = 1e9;
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            if(str[i] == '1' && str[j]=='1'){
                dist = min(dist, j-i);
                break;
            }

        }
    }
    return dist;
}

int main() {

    cin >> n;
    cin >> str;

    findMax();
    
    str[(fin_j-fin_i)/2+fin_i] = '1';
    int ans =1e9;
    ans = findMin();
    str[(fin_j-fin_i)/2+fin_i] = '0';

    if(str[n-1]=='0'){
        str[n-1] = '1';
        ans = max(ans, findMin());
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}