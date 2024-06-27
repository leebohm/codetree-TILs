#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string str;
int n;
unordered_map<char,int> count;

int main(){
    
    cin >> str;
    n = (int) str.size();
    str = "#" + str;

    int j = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <=n && count[str[j+1]]!= 1){
            count[str[j+1]]++;
            j++;
        }

        ans = max(ans, j-i+1);
        count[str[i]]--;
    }

    if(ans ==0)
        ans =1;
    cout << ans;

}