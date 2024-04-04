#include <iostream>
#include <unordered_set>

using namespace std;

int N, G;
unordered_set<int> s;
int arr[100000];

int main(){
    cin >> N >> G;
    
    s.insert(1);

    for(int i=0; i<G; i++){
        int num;
        cin >> num;
        int cnt = 0;
        for(int j=0; j<num; j++){
            cin >> arr[j];
            if(s.find(arr[j]) != s.end()){ // set안에 있을 때
                cnt++;
            }
        }
        if(cnt +1 == num){
            for(int j=0; j<num ; j++)
                s.insert(arr[j]);
        }
    }
    int ans = 0;

    for(int i=1; i<=N ;i++){
        if(s.find(i) != s.end())
            ans++;
    }
    cout << ans;
    return 0;
}