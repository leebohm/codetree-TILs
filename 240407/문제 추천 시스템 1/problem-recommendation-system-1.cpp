#include <iostream>
#include <set>
#include <string>

using namespace std;

int n,m;
int p,l;
set<pair<int,int>> s;
string str;
int x;

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p >> l;
        s.insert(make_pair(l,p));
    }

    cin >> m;

    for(int i=0; i<m; i++){
        cin >> str;

        if(str == "sv"){
            cin >> p >> l;
            s.erase(make_pair(l,p));
        }
        
        else if(str == "ad"){
            cin >> p >> l;
            s.insert(make_pair(l,p));
        }

        else {
            cin >> x;
            if (x == 1){
                pair<int,int> p = *s.rbegin();
                cout << p.second << endl;
            }
            else{
                pair<int,int> p = *s.begin();
                cout << p.second << endl;
            }

        }
            
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}