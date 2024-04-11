#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;
unordered_map<char, int> freq;

int main() {

    cin >> str;

    for(int i=0; i<(int)str.size(); i++){
        if(freq.find(str[i]) == freq.end())
            freq[str[i]] = 1;
        else
            freq[str[i]]++;         
    }
    bool flag = false;

    for(int i=0; i<(int)str.size(); i++){
        if(freq[str[i]] ==1){
            cout << str[i];
            flag = true;
            break;
        }
    }

    if(flag == false)
        cout << "None";
    // 여기에 코드를 작성해주세요.
    return 0;
}