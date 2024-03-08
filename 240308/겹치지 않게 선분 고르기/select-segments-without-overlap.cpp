#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n;
int k;
vector<pair<int,int>> line; // 입력되는 선분에 대한 정보
vector<int> vec; // 어떤 선분을 선택할 것인지에 대한 정보
bool flag = false;
int ans = 0; 

bool Overlab(int x1, int y1, int x2, int y2){
    return (x1 <= y2 )||(x2 <= y1); // true 면 겹치는 것 
}

bool Possible(){
    if((int) vec.size() > 1){
        int x1,y1;
        int key = vec[0];
        tie(x1,y1) = line[key -1];
        int x2,y2;
        for(int i=1; i<(int) vec.size(); i++){
            tie(x2,y2) = line[(int) vec[i] -1];
            if(Overlab(x1,y1,x2,y2) == false){ // 안겹치면 
                continue;
            }
            else return false; // 겹치면 false 반환
            x1 = x2;
            y1 = y2;
        }
    }
    else 
        return true;

    return true;
}

void Choose(int idx){
    if(idx == k){
        if(Possible()){ // 안겹치면? 
            ans = max(ans, (int) vec.size());
        }
        return;
    }
    for(int i=1;i<=3; i++){
        vec.push_back(i);
        Choose(idx+1);
        vec.pop_back();
    }
}


int main() {

    int a,b;

    cin >> n;
    

    for(int i=0; i<n; i++){
        cin >> a >> b;
        line.push_back(make_pair(a,b));
    }
    for( k=1; k<=n; k++){ // k 가 의미하는 것은 선분 중에 몇개의 선분을 뽑을 것인지
        vec.clear();
        Choose(0);
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}

// 겹치치 않게 뽑을 수 있는 최대 선분의 수.. 그러면.. 음 ... 
//  내 생각에는 .. 먼저 일단 예를 들면 선분 3개 중에 3개 고르거나 2개 골라서 겹치는지 아닌지 판단하고
// 그 다음에 맥스 값을 계산하면 되는 것 같은데..