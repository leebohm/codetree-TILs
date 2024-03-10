// #include <iostream>
// #include <algorithm>

// #define MAX_N 12
// #define MAX_K 4

// using namespace std;

// int n,m,k;
// int nums[MAX_N], pieces[MAX_K];

// int ans;

// int Calc(){
//     int score = 0;
//     for(int i=0; i<k; i++)
//         score += (pieces[i] >= m);
//     return score;
// }

// void FindMax(int cnt){
//     ans = max(ans, Calc());

// }

#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
int arr[12];
vector<int> horse; // 선택된 말의 순서 
int horse_pos[4];
int ans;

void ResetHorsePos(){
    for(int i=0; i<4; i++)
        horse_pos[i] = 0;
}

void MoveHorse(){
    for(int i=0; i<=(int)horse.size(); i++){
        horse_pos[horse[i]-1] += arr[i];
    }
}

int GetScore(){
    int score = 0;
    for(int i=0; i<k; i++){
        if(horse_pos[i]>=m-1) score++;
    }
    //cout << "score : " << score << endl;
    return score;
}

void Output(){
    cout << "horse_pos : ";
    for(int i=0; i<4; i++)
        cout << horse_pos[i] << " ";
    cout << endl;
}

void Choose(int cnt){
    
    if(cnt == n){
        //cout << "horse size : " << (int) horse.size() <<  endl;
        ResetHorsePos();
        MoveHorse();
        //Output();
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
    cout << ans << endl;

    // for(int i=0; i<4; i++)
    //     cout << horse_pos[i] << " ";
    return 0;
}