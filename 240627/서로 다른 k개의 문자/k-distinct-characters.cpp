#include <iostream>
#include <unordered_map>

using namespace std;

string str;
int k;
unordered_map<char,int> m;

int main() {

    cin >> str >> k;
    int n = (int) str.size();

    str = "#" + str;

    int j =0; 
    int ans = 0;

    for(int i=1; i<=n; i++){
        while(j+1 <=n && m.size() <= k){
            //cout << j+1  << " " << i<< endl;
            m[str[j+1]]++;
            j++;
        }
        if(m.size() <= k){
            ans = max(ans, j-i+1);
            //cout << "m.size() :  " << m.size() << endl;
        }
        m[str[i]]--;
    }
    if(ans ==0)
        ans = 1;
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}