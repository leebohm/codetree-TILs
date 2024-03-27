#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
int k,v;
map<int,int> m;
string cmd;

int main() {

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >>  k >> v;
            //m.insert({k,v});
            m[k] = v;
        }

        else if(cmd == "remove"){
            cin >> k;
            m.erase(k);
        }

        else if(cmd == "find"){
            cin >> k;
            if(m.find(k)!= m.end())
                cout << m.find(k)->second << endl;
            else
                cout << "None" << endl;
        }

        else{
            if(!m.empty()){
                for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
                    cout << it->second << " ";
                }
                cout << endl;
            }
            else{
                cout << "None" << endl;
            }
            

        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}