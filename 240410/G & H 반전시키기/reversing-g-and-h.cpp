#include <iostream>
#include <string>

using namespace std;

int n;
string str_src;
string str_des;

int main() {

    cin >> n >> str_src >> str_des;

    int cnt = 0;
    int max_idx = 0;
    int max_cnt = 0;
    int ans = 0;

    while(true){
        if(str_des == str_src)
            break;
        max_cnt = 0;
        cnt  = 0;
        max_idx = 0;
        for(int i=0; i<n; i++){
            if(str_des[i] != str_src[i]){
                cnt++;
            }
            else{
                cnt = 0;
            }
            if(max_cnt < cnt){
                max_cnt = cnt;
                max_idx = i;
            }
        }
        //cout << max_cnt << " " << max_idx << endl;
        int start = max_idx - max_cnt +1;
        for(int i= start; i < start + max_cnt; i++){
            if(str_src[i] == 'G')
                str_src[i] = 'H'
;
            else{
                str_src[i] = 'G';
                //cout << str_src << endl;
            }
        }
        ans++;
    }

    cout << ans;


    // 여기에 코드를 작성해주세요.
    return 0;
}