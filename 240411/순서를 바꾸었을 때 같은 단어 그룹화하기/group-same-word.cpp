#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
string str;
unordered_map<string,int> freq;

int main() {
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> str;
        sort(str.begin(), str.end());
        if(freq.count(str) == 0)
            freq.insert({str,1});
        else
            freq[str]++;
        ans = max(ans, freq[str]);
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}