#include <iostream>
using namespace std;

#define MAX_N 100001

int n,q;
int sum_1[MAX_N];
int sum_2[MAX_N];
int sum_3[MAX_N];
int a,b;

void init(){
    for(int i=1; i<=n; i++){
        sum_1[i] += sum_1[i-1];
        sum_2[i] += sum_2[i-1];
        sum_3[i] += sum_3[i-1];
    }
}

int main() {
    
    cin >> n >> q;

    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            sum_1[i] = 1;
        }
        else if(tmp == 2){
            sum_2[i] = 1;
        }
        else if(tmp == 3){
            sum_3[i] = 1;
        }
    }

    init();
    
    for(int i=1; i<=q; i++){
        cin >> a >> b;
        cout << sum_1[b] - sum_1[a-1] <<" " << sum_2[b] - sum_2[a-1] << " " << sum_3[b] - sum_3[a-1] << endl;
    }

    return 0;
}

/*
1부터 n까지 번호가 붙은 n개의 돌이 있습니다.
각 돌은 그룹 1,2,3 하나에 무조건 속합니다.
각 돌이 어떤 그룹에 속하는지 주어졌을 때
Q개의 돌 번호 범위마다 각 그룹의 돌이 몇개씩 있는지 구하는 프로그ㅐㅁ 
*/