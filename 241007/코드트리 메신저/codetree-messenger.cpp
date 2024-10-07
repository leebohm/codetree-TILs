#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001
#define MAX_D 22

int n,q;
int a[MAX_N], p[MAX_N], val[MAX_N];
bool noti[MAX_N];
int nx[MAX_N][MAX_D];

void init(){
    for(int i=1; i<=n; i++)
        cin >> p[i];
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] > 20)
            a[i] = 20;
    }

    for(int i=1; i<=n; i++){
        int cur = i;
        int x = a[i];
        nx[cur][x]++;
        while(p[cur] && x){
            cur = p[cur];
            x--;
            if(x) nx[cur][x]++;
            val[cur]++;
        }
    }
}

void toggle_noti(int chat){ // chat 노드의 알림을 토글하기 
    if(noti[chat] == true){ // 알림이 꺼져있었을 때
        int cur = p[chat]; // chat 노드의 바로 위 부모 노드 
        int num = 1; 

        while(cur){
            for(int i=num; i<=21; i++){ // 왜 i를 1부터 21 까지 도는 거지? 
                val[cur] += nx[chat][i];
                if(i>num) nx[cur][i-num] += nx[chat][i];
            }
            if(noti[cur]) break;
            cur = p[cur];
            num++;
        }
        noti[chat] = false;
    }
    else{ // 알림이 켜져있었을 때
        int cur = p[chat];
        int num = 1;
        while(cur){
            for(int i=num; i<= 21; i++){
                val[cur] -= nx[chat][i];
                if(i>num) nx[cur][i-num] -= nx[chat][i];
            }
            if(noti[cur]) break;
            cur = p[cur];
            num++;
        }
        noti[chat] = true;

    }
}

void change_power(int chat, int power){
    int bef_power = a[chat]; // 권한 
    power = min(power, 20);
    a[chat] = power;

    nx[chat][bef_power]--; // 왜 줄이지 일단 init 하는 느낌 
    if(!noti[chat]){ // 알림 켜져있으면 
        int cur = p[chat];
        int num = 1; // 1칸 위 부모 노드 부터 시작 
        while(cur) {
            if(bef_power>= num) val[cur]--; // 아까 앞에서 줄인거 반영시키는 느낌. 
            if(bef_power> num) nx[cur][bef_power-num]--; // 부모노드의 1칸위 로 못간다 
            if(noti[cur])break;
            cur = p[cur];
            num++;
        }
    }

    nx[chat][power]++;
    if(!noti[chat]){
        int cur = p[chat];
        int num = 1;
        while(cur){
            if(power >= num) val[cur]++;
            if(power > num) nx[cur][power-num]++;
            if(noti[cur]) break;
            cur = p[cur];
            num++;
        }
    }
}

void change_parent(int chat1, int chat2){
    bool bef_noti1 = noti[chat1];
    bool bef_noti2 = noti[chat2];

    if(!noti[chat1]) toggle_noti(chat1); // 현재노드 켜져있으면 끄기?
    if(!noti[chat2]) toggle_noti(chat2);

    swap(p[chat1], p[chat2]);

    if(!bef_noti1) toggle_noti(chat1); // 끈거 켜기. 이거 하는 이유 무엇? 부모가 달라졌으니 새로운 부모에 적용하려고
    if(!bef_noti2) toggle_noti(chat2);

}

void print_count(int chat){
    cout << val[chat] << "\n";
}

int main(){
    cin >> n >> q;

    while(q--){
        int query;
        cin >> query;
        if(query == 100){
            init();
        }

        else if(query == 200){
            int chat;
            cin >> chat;
            toggle_noti(chat);
        }
        else if(query == 300){
            int chat, power;
            cin >> chat >> power;
            change_power(chat, power);
        }
        else if(query == 400){
            int chat1, chat2;
            cin >> chat1 >> chat2;
            change_parent(chat1, chat2);
        }
        else if(query == 500){
            int chat;
            cin >> chat;
            print_count(chat);
        }

    }
    return 0;
}