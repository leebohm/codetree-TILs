#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
int arr[12];
vector<int> horse; // 선택된 말의 순서 
int horse_pos[4];
int ans;


int MoveHorse(){
    for(int i=0; i<(int)horse.size(); i++){
        horse_pos[horse[i]-1] += arr[i];
    }
}

int GetScore(){
    int score = 0;
    for(int i=0; i<k; i++){
        if(horse_pos[i]>=m-1) score++;
    }
    return score;
}

void Choose(int cnt){

    if(cnt == n){
        MoveHorse();
        ans = max(ans,GetScore());
        return;
    }

    for(int i=1; i<=k; i++){
        horse.push_back(i);
        Choose(cnt+1);
        horse.pop_back();
    }
    return;
}

int main() {

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    Choose(0);
    cout << ans;

    return 0;
}

// 중복으로 말을 뽑아야함. k개의 말을 중복으로 n번 뽑아야 함