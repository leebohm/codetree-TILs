#include <iostream>
#include <string>
#include <map>

#define MAX_N 100000

using namespace std;

int n;
map<string,int> m;
string str[MAX_N];

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> str[i];
        m[str[i]]++;
    }

    map<string,int>::iterator it;

    for(it = m.begin(); it != m.end(); it++){
        cout << it -> first << " " << it ->second << endl;
    }
    
    // 여기에 코드를 작성해주세요.
    return 0;
}