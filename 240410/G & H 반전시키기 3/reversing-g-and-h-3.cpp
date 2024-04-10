#include <iostream>
#include <string>

using namespace std;

int n;
string src;
string des;
int cnt;
int ans;
void Change(int x, int y){
    for(int i = x-y+1; i<=x; i++ ){
        if(src[i] == 'G')
            src[i] = 'H';
        else
            src[i] = 'G';
    }
}
int main() {

    cin >> n >> src >> des;
    
    bool flag = true;
    for(int i=0; i<n; i++){
        if(cnt == 4){
            Change(i-1,cnt);
            ans++;
            flag = true;
            cnt = 0;
        }
        if(src[i] != des[i] && flag == true){
            cnt++;
            flag = false;
        }
        else if(src[i]!= des[i] && flag == false){
            cnt++;
        }
        else if(src[i] == des[i]){
            if(cnt >=1){
                ans++;
                Change(i-1,cnt);
                //cout << "i : " << i <<" , cnt : "<<cnt  <<" " << src << endl;
            }
            
            cnt = 0;
            flag = true;
        }
        //cout << "i : " << i <<" , cnt : "<<cnt  <<" " << src << endl;
    }
    if(cnt > 0){
        Change(n-1,cnt);
        ans++;
        //cout << src;
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}