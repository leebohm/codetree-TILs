#include <iostream>
#include <string>
#include <map>

#define MAX_N 10000

using namespace std;

int n;
string words[MAX_N];
map<string,int> freq;

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        freq[words[i]]++;
    
    map<string,int>::iterator it;

    for(it = freq.begin(); it != freq.end(); it++){
        string word = it-> first;
        int cnt = it-> second;
        double ratio = (double) cnt / n * 100;

        cout << fixed;
        cout.precision(4);
        cout << word << " " << ratio << endl;
    }

    return 0;
}