#include <iostream>
#include <unordered_map>

using namespace std;

string str;
int k;
unordered_map<char,int> m;
int n;
bool Canmove(int j){
    if(j+1 > n)
        return false;
    
    if(m.size()==k && m.find(str[j+1]) == m.end())
        return false;

    return true;
}
int main() {

    cin >> str >> k;
    n = (int) str.size();

    str = "#" + str;

    int j =0; 
    int ans = 0;

    for(int i=1; i<=n; i++){
        while(Canmove(j)== true){
            //cout << j+1  << " " << i<< endl;
            m[str[j+1]]++;
            j++;
        }
        
        ans = max(ans, j-i+1);
            //cout << "m.size() :  " << m.size() << endl;
        m[str[i]]--;
        if(m[str[i]]==0)
            m.erase(str[i]);
    }
    if(ans ==0)
        ans = 1;
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}