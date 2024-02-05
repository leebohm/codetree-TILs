// 1: 가위 2: 바위 3: 보
// 1: 가위 2: 보 3: 바위
// 1: 바위 2: 가위 3: 보 
// 1: 바위 2: 보 3 : 가위
// 1: 보 2: 가위 3: 바위
// 1: 보 2: 바위 3: 가위 

#include <iostream>
#include <string>
using namespace std;

int n;
int dev1[100];
int dev2[100];
string dev1_str[100];
string dev2_str[100];

void Change_dev1(int a, int i, int d){
    if(a==1){
        if(d==1) dev1_str[i] = "가위";
        if(d==2) dev1_str[i] = "바위";
        if(d==3) dev1_str[i] ="보";
    }
    if(a==2){
        if(d==1) dev1_str[i] = "가위";
        if(d==2) dev1_str[i] = "보";
        if(d==3) dev1_str[i] ="바위";
    }
    if(a==3){
        if(d==1) dev1_str[i] = "바위";
        if(d==2) dev1_str[i] = "가위";
        if(d==3) dev1_str[i] ="보";
    }
    if(a==4){
        if(d==1) dev1_str[i] = "바위";
        if(d==2) dev1_str[i] = "보";
        if(d==3) dev1_str[i] ="가위";
    }
    if(a==5){
        if(d==1) dev1_str[i] = "보";
        if(d==2) dev1_str[i] = "가위";
        if(d==3) dev1_str[i] ="바위";
    }
    if(a==6){
        if(d==1) dev1_str[i] = "보";
        if(d==2) dev1_str[i] = "바위";
        if(d==3) dev1_str[i] ="가위";
    }
}

void Change_dev2(int a, int i, int d){
    if(a==1){
        if(d==1) dev2_str[i] = "가위";
        if(d==2) dev2_str[i] = "바위";
        if(d==3) dev2_str[i] ="보";
    }
    if(a==2){
        if(d==1) dev2_str[i] = "가위";
        if(d==2) dev2_str[i] = "보";
        if(d==3) dev2_str[i] ="바위";
    }
    if(a==3){
        if(d==1) dev2_str[i] = "바위";
        if(d==2) dev2_str[i] = "가위";
        if(d==3) dev2_str[i] ="보";
    }
    if(a==4){
        if(d==1) dev2_str[i] = "바위";
        if(d==2) dev2_str[i] = "보";
        if(d==3) dev2_str[i] ="가위";
    }
    if(a==5){
        if(d==1) dev2_str[i] = "보";
        if(d==2) dev2_str[i] = "가위";
        if(d==3) dev2_str[i] ="바위";
    }
    if(a==6){
        if(d==1) dev2_str[i] = "보";
        if(d==2) dev2_str[i] = "바위";
        if(d==3) dev2_str[i] ="가위";
    }
}

int RSP(){
    int cnt =0;

    for(int i=0; i<n;i++){
        //cout << dev1_str[i] << " " << dev2_str[i] << endl;
        if(dev1_str[i] == "가위"&& dev2_str[i] == "보")
            cnt++;
        if(dev1_str[i] == "바위"&& dev2_str[i] == "가위")
            cnt++;
        if(dev1_str[i] == "보" && dev2_str[i] == "바위")
            cnt++;
        
    }
    return cnt; 
}

int main() {

    cin >> n;
    for(int i=0; i<n;i++)
        cin >> dev1[i] >> dev2[i];
    
    int ans = 0;
    for(int a=1; a<= 6; a++){
        for(int i=0; i<n;i++){
            //cout <<"a : " << a <<" i : " << i << endl;
            int tmp1 = dev1[i];
            int tmp2 = dev2[i];
            Change_dev1(a,i,tmp1);
            Change_dev2(a,i,tmp2);
            
        }
        int res = RSP();
        //cout << "result : " << res << endl;
        ans = max(ans, res);
    }
    
    cout << ans;
    

    // 여기에 코드를 작성해주세요.
    return 0;
}