#include <iostream>
#include <deque>
#include <tuple>
#include <unordered_map>
using namespace std;

#define MAX_M 11
#define MAX_N 100001
int q,n,m; // q : 명령의 개수 , n : 물건의 배수, m : 벨트의 개수 
// 물건, 벨트 1번부터! 

deque<int> belts[MAX_M]; // idx : 벨트 번호, value : 물건 인덱스 
pair<int,int> stuffs[MAX_N]; // idx : 물건 인덱스 / 고유 번호 & 무게 
unordered_map<int,int> idx2belt; // 물건 인덱스 -> 벨트 번호 
unordered_map<int,int> id2idx; // 물건 고유 번호 -> 물건 인덱스 

void Factory(){
    cin >> n  >> m;
    int t = n / m;
    int id, w;
    // 1. 고유 번호 입력 받기 
    for(int belt_num=1; belt_num<=m; belt_num++){
        for(int j=1; j<=t; j++){
            cin >> id;
            int idx = (belt_num-1)*t+j;
            belts[belt_num].push_back(idx);
            stuffs[idx] = make_pair(id,0);
            idx2belt[idx] = belt_num;
            id2idx[id] = idx;
        }  
    }
    
    // 2. 무게 입력 받기 

    for(int belt_num=1; belt_num<=m; belt_num++){
        for(int j=1; j<=t; j++){
            cin >> w;
            int idx = (belt_num-1)*t+j;
            stuffs[idx].second = w;
        }  
    }
}

void PrintStuffs(){
    for(int i=1; i<=n; i++){
        cout << stuffs[i].first << " " << stuffs[i].second << endl;
    }
}

void PrintBelts(){
    for(int i=1; i<=m; i++){
        int num = (int) belts[i].size();
        for(int j=0; j<num; j++){
            cout << belts[i][j] << " ";
        }
        cout << endl;
    }
}

void Drop (int belt_num, int idx){

    // 1. 일단 belts 에서 내보내기 
    belts[belt_num].pop_front();
    // 2. 물건 인덱스 -> 벨트 번호 업데이트 
    idx2belt[idx] = -1;

}
void Drop_Stuff(){
    int w_max;
    cin >> w_max;
    int ans = 0;
    for(int belt_num=1; belt_num<=m; belt_num++){ // 벨트 개수대로 돌아가며 w_max 이하라면 하차
        int idx = belts[belt_num][0];
        int w_tmp = stuffs[idx].second;
        if( w_tmp <= w_max){ // w_max 이하라면 하차
            Drop(belt_num, idx); // 이 벨트 번호 위에 올려져 있는 이 인덱스 상자를 떨어뜨려라!
            ans += w_tmp; // 하차된 상자 무게에 더하기 
        }
        else{ // 이상이라면 맨 뒤로 보내기 
            belts[belt_num].pop_front(); // 앞에서 빼고
            belts[belt_num].push_back(idx); // 다시 뒤에 삽입 
        }
    }
    cout << ans << endl;
}

void Remove_Stuff(int belt_num, int idx){
    // 1. 그 벨트에서 상자를 제거하고 뒤에 있는 상자들 앞으로 한칸씩 내려오기 
    // 구현 방법 : 새로운 deque 선언하고, 이 인덱스 아닌 것만 복붙하기 
    deque<int> tmp;
    int num = belts[belt_num].size();
    for(int i=0; i<num; i++){
        if(belts[belt_num][i] == idx)
            continue;
        tmp.push_back(belts[belt_num][i]);
    }
    belts[belt_num] = tmp;
    
    // 2. 업데이트 해야할 정보 업데이트 하기 
    idx2belt[idx] = -1;
}

void Remove(){
    int r_id;
    cin >> r_id;

    // 1. 이 고유번호 -> 인덱스 -> 존재하는 벨트 번호 찾기
    int idx = id2idx[r_id];

    // 1-1. 벨트 번호 있는 경우
    if(idx2belt.find(idx) != idx2belt.end() && idx2belt[idx] != -1){
        int belt_num = idx2belt[idx];
        // 2. 그 벨트에서 상자를 제거하고 뒤에 있는 상자들 앞으로 한칸씩 내려오기 
        Remove_Stuff(belt_num,idx);
        // 3. r_id 출력하기 
        cout << r_id << endl;
    }
    
    // 1-2. 벨트 번호 없는 경우 (-1 이거나 end() 인 경우)
    // -1 출력하기. 
    else{
        cout << -1 << endl;
    }

}

void Move_to_Front(int belt_num, int idx){
    // 구현 방법 1. 그 상자부터 맨 뒤에 까지 tmp_deque에 저장
    // 2. 다시 맨 처음부터 그 상자 전까지 tmp_deque에 저장. 
    int num = (int) belts[belt_num].size();
    bool flag = false;
    int n_th = 0; // 인덱스가 해당 벨트에서 몇번째인지 파악
    deque<int> tmp;
    for(int i=0; i < num; i++){
        if(belts[belt_num][i] == idx){
            flag = true;
            n_th = i;
        }
        if(flag == true){
            tmp.push_back(belts[belt_num][i]);
        }
    }
    for(int i=0; i<n_th; i++){
        tmp.push_back(belts[belt_num][i]);
    }
    belts[belt_num] = tmp;

}

void Check(){
    int f_id;
    cin >> f_id;
    // 1. 고유번호 -> 인덱스 -> 벨트 번호 
    // 1-1. 벨트 번호 있으면 번호 출력
    // 1-2. 벨트 번호 -1 이거나 없으면 -1 출력
    // 2. 상자가 있는 경우 해당 상자 위에 모든 상자를 전부 앞으로 가져오기
    int idx = id2idx[f_id];
    if(idx2belt.find(idx) != idx2belt.end() && idx2belt[idx] != -1){
        int belt_num = idx2belt[idx];
        Move_to_Front(belt_num, idx);
        cout << belt_num << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void Move_to_next_belt(int next_belt_num, int belt_num){
    // 1. 벨트 뒤에 가져다 붙이기 
    // 2. 업데이트 할 정보 업데이트 하기
    //deque<int> belts[MAX_M]; // idx : 벨트 번호, value : 물건 인덱스 
    //pair<int,int> stuffs[MAX_N]; // idx : 물건 인덱스 / 고유 번호 & 무게 
    //unordered_map<int,int> idx2belt; // 물건 인덱스 -> 벨트 번호 
    // unordered_map<int,int> id2idx; // 물건 고유 번호 -> 물건 인덱스  
    while(belts[belt_num].empty() != true){
        int idx= belts[belt_num].front(); belts[belt_num].pop_front();
        belts[next_belt_num].push_back(idx);

        idx2belt[idx] = next_belt_num;
    }

    belts[belt_num].push_back(-1);

}

void Broke(){
    int belt_num;
    cin >> belt_num;

    // 1. 해당 벨트 정상일 경우
    if(belts[belt_num][0] != -1){
        // 2. 바로 오른쪽 벨트 번호 구하기
        int next_belt_num = (belt_num + 1) % m; 
        if(next_belt_num == 0)
            next_belt_num = m;
        // 3. 그 벨트 뒤에 가져다 붙이기 
        Move_to_next_belt(next_belt_num, belt_num);
        // 4. 벨트 번호 출력
        cout << belt_num << endl;
    }

    // 1-1. 해당 벨트 이미 망가져 있는 경우
    else{
        cout << -1 << endl;
    }
}
int main() {
    cin >> q;
    for(int i=0; i<q; i++){
        int opt;
        cin >> opt;
        //cout << "opt : " << opt << endl;
        if(opt == 100){
            // 1. 공장 설립
            Factory();
            //PrintStuffs();
            //PrintBelts();
        }
        else if(opt == 200){
            // 2. 물건 하차
            Drop_Stuff();
            //PrintStuffs();
            //PrintBelts();
        }
        else if(opt == 300){
            Remove();
            //PrintStuffs();
            //PrintBelts();
        }
        else if(opt == 400){
            Check();
            //PrintStuffs();
            //PrintBelts();
        }
        else if(opt == 500){
            Broke();
        }
    }
    return 0;
}