#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
string com;
set<int> s;

int main() {
    cin >> n;

    int x;
    for(int i=0; i<n; i++){
        
        cin >> com;

        if(com == "add"){
            cin >> x;
            s.insert(x);
        }

        else if(com == "remove"){
            cin >> x ;
            if(s.find(x) != s.end())
                s.erase(x);
        }

        else if(com == "find"){
            cin >> x;
            if(s.find(x) != s.end())
                cout << "true" << endl;
            else
                cout << "false" << endl;

        }

        else if(com == "lower_bound"){
            cin >> x ;
            if(s.lower_bound(x) != s.end())
                cout << *s.lower_bound(x) << endl;
            
            else 
                cout << "None"<< endl;
        }

        else if(com  == "upper_bound"){
            cin >> x ;
            if(s.upper_bound(x) != s.end())
                cout << *s.upper_bound(x) << endl;
            else
                cout << "None" << endl;
        }

        else if(com == "largest"){
            if(s.rbegin() != s.rend())
                cout << *s.rbegin() << endl;
            else
                cout << "None" << endl;
        }

        else if(com == "smallest"){
            if(s.begin() != s.end())
                cout << *s.begin() << endl;
            else
                cout << "None" << endl;
        }
        
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}