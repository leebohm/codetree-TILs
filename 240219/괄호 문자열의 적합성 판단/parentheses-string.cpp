#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> carr;
string str;

int main() {
    cin >> str;
    bool flag = true;
    int n = str.size();
    for(int i=0; i<n;i++){
        if(str[i] == '(' ){
            carr.push('(');
        }
        else{
            if(carr.empty()){
                flag = false;
            }
            else
                carr.pop();
        }
    }
    if(carr.empty()==false){
        flag = false;
    }

    if(flag== true) cout << "Yes";
    else
        cout <<"No";

    // 여기에 코드를 작성해주세요.
    return 0;
}