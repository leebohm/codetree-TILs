#include <iostream>
#include <set>

using namespace std;

int t,k;
char x;
int n;
int tmp;
set<int> s;

int main() {
    cin >> t ;

    for(int i=0; i<t; i++){
        cin >> k;
        s.clear();
        for(int j=0; j< k; j++){
            cin >> x >> n;

            if(x == 'I'){
                s.insert(n);
            }

            else if(x == 'D' && n == 1){
                if(s.rbegin() != s.rend()){
                    tmp = *s.rbegin();
                    s.erase(tmp);
                }
            }

            else if(x == 'D' && n == -1){
                if(s.begin() != s.end()){
                    tmp = *s.begin();
                    s.erase(tmp);
                }
            }
        }
        if(s.begin() != s.end()){
            cout << *s.rbegin() << " " << *s.begin() << endl;
        }
        else{
            cout << "EMPTY" << endl;
    }
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}