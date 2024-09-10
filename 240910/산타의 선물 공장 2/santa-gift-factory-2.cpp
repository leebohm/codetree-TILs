#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>


using namespace std;

#define MAX_N 100000

int n,m; // n 개의 벨트, m 개의 선물을 준비
int q; // 명령의 수 q
deque<int> belts[MAX_N];
unordered_map<int,int> idx2belts_num; // 선물 번호 -> 벨트 번호 

void Print(){
    for(unordered_map<int,int>::iterator it = idx2belts_num.begin(); it!=idx2belts_num.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}
void make_factory(){
    // 100
    cin >> n >> m;
    int num;
    for(int i=1; i<=m; i++){ // i = 선물 번호
        cin >> num;  // num은 벨트 번호
        belts[num].push_back(i);
        idx2belts_num[i] = num;
    }
}

void move_everything(){
    // 200
    int src, dst;
    cin >> src >> dst;
    // 1. 선물들의 벨트 번호 정보 바꿔주기 
    int num = (int) belts[src].size();
    if(num == 0){
        cout << (int) belts[dst].size() << endl;
        return; // src 번째 벨트에 선물이 존재하지 않다면 아무것도 옮기지 않아도 된다. 
    }

    for(int i=0; i<num; i++){
        idx2belts_num[belts[src][i]] = dst;
    }

    // 2. dst 벨트로 옮겨주기 
    deque<int> tmp;
    tmp = belts[dst];
    belts[dst] = belts[src];
    num = (int) tmp.size();
    for(int i=0; i<num; i++){
        belts[dst].push_back(tmp[i]);
    }
    num = (int) belts[dst].size();
    cout << num << endl;

    // 3. src 벨트 깨끗이 지워주기
    belts[src].clear();
}

void replace_front(){
    // 300
    int src, dst;
    cin >> src >> dst;

    int num1 = (int) belts[src].size();
    int num2 = (int) belts[dst].size();
    if(num1 == 0 && num2 == 0){
        cout << 0 << endl;
        return;
    }

    else if(num1 != 0 && num2 != 0){
        int src_num = belts[src].front(); belts[src].pop_front();
        int dst_num = belts[dst].front(); belts[dst].pop_front();

        // 1. 벨트 번호 정보 바꾸기
        idx2belts_num[src_num] = dst;
        idx2belts_num[dst_num] = src;

        // 2. 옮기기
        belts[src].push_front(dst_num);
        belts[dst].push_front(src_num);

        int num = (int)belts[dst].size();
        cout << num << endl;
    }
    else if(num1 == 0 && num2 != 0){
        int dst_num = belts[dst].front(); belts[dst].pop_front();
        idx2belts_num[dst_num] = src;
        belts[src].push_front(dst_num);
        int num = (int)belts[dst].size();
        cout << num << endl;
    }
    else if(num1 != 0 && num2 == 0){
        int src_num = belts[src].front(); belts[src].pop_front();
        idx2belts_num[src_num] = dst;
        belts[dst].push_front(src_num);
        int num = (int)belts[dst].size();
        cout << num << endl;
    }

}

void give_gift(){
    // 400
    int src, dst;
    cin >> src >> dst;

    int num = (int) belts[src].size();
    if(num <= 1){
        cout << (int) belts[dst].size() << endl;
        return;
    }
    
    num = num / 2;
    // 1. 선물의 벨트 번호 정보 바꿔주기
    for(int i=0; i<num; i++){
        idx2belts_num[belts[src][i]] = dst;
    }
    
    // 2. dst 벨트로 옮겨주기 
    deque<int> tmp;
    for(int i=0; i<num; i++){
        tmp.push_back(belts[src][i]);
        belts[src].pop_front();
    }
    num = (int) belts[dst].size();
    for(int i=0; i<num; i++){
        tmp.push_back(belts[dst][i]);
    }
    belts[dst] = tmp;
    num = (int) belts[dst].size();
    cout << num << endl;
}

void get_gift_info(){
    // 500
    int pnum;
    cin >> pnum;
    int belts_num = idx2belts_num[pnum];
    int num = (int) belts[belts_num].size();
    int a = -1;
    int b = -1;
    for(int i=0; i<num; i++){
        if(belts[belts_num][i] == pnum){
            if(i+1 < num)
                b = belts[belts_num][i+1];
            if(i-1 >= 0)
                a = belts[belts_num][i-1];
        }
    }
    cout << a + 2*b << endl;
}

void get_belt_info(){
    // 600
    int bnum;
    cin >> bnum;

    int c = (int) belts[bnum].size();
    int a,b;
    if(c == 0){
        a = -1; 
        b = -1;
    }
    else{
        a = belts[bnum].front();
        b = belts[bnum][c-1];
    }
    cout << a + 2*b + 3*c << endl;
}
int main() {

    cin >> q;
    int opt;
    for(int i=0; i<q; i++){
        cin >> opt;
        //cout << "opt : " << opt << endl;
        if(opt == 100){
            // 1. 공장 설립
            make_factory();
        }
        else if(opt == 200){
            // 2. 물건 모두 옮기기
            move_everything();
        }
        else if(opt == 300){
            // 3. 앞 물건만 교체하기
            replace_front();
            
        }
        else if(opt == 400){
            // 4. 물건 나누기
            give_gift();
        }
        else if(opt == 500){
            // 5. 선물 정보 얻기
            get_gift_info();
        }
        else if(opt == 600){
            // 6. 벨트 정보 얻기 
            get_belt_info();
        }
        //Print();
        
    }
    return 0;
}