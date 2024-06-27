#include <iostream>
#include <string>

using namespace std;

string str;

int main() {

    cin >> str;
    int n = str.size();

    int j = 0;
    int max_num = 0;

    for(int i=0; i<n; i++){
        while(j+1>i && str[i] != str[j+1])
            j++;
        if(j >= n)
            break;
        
        max_num = max(max_num, j-i+1);
    }
    if(max_num == 0)
        max_num = 1;
    cout << max_num;
    // 여기에 코드를 작성해주세요.
    return 0;
}