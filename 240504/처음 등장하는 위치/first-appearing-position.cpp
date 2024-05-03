#include <iostream>
#include <map>

using namespace std;

int n;
map<int,int> first_appear;

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){

        int a;
        cin >> a; 

        if(first_appear.find(a) == first_appear.end())
            first_appear[a] = i;
    }

    for(map<int,int>::iterator it = first_appear.begin(); it != first_appear.end(); it++){
        cout << it -> first << " " << it-> second << endl;
    }

    return 0;
}