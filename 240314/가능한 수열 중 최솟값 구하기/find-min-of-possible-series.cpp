#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;
bool flag = false;

bool Possible(){
    int cnt = 0;
    for(int tmp = 1; tmp< (int)vec.size()/2+1; tmp++){
        for(int i=0;i<(int) vec.size()-tmp; i++){
            cnt = 0;
            for(int j=i; j<i+tmp;j++){
                if(j+tmp < (int) vec.size())
                    if(vec[j] == vec[j+tmp]){
                        cnt ++;
                    }
                if(cnt == tmp) return false;
            }
        }
    }
    return true;
}

void Output(){
    for(int i=0; i<(int) vec.size(); i++){
        cout << vec[i];
    }
    exit(0);
}

void Choose(int cnt){
    if(cnt == n){
        Output();            
    }
    
    for(int i=4; i<=6; i++){
        vec.push_back(i);
        if(Possible())
            Choose(cnt+1);
        vec.pop_back();
    }
    return;
}

int main() {

    cin >> n;

    Choose(0);

    // 여기에 코드를 작성해주세요.
    return 0;
}