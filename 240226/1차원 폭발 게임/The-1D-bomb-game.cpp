#include <iostream>
using namespace std;


int n,m;
int arr[100];
int idx[100];


pair<int,int> Check() {

    int temp = arr[0];
    int cnt = 1;
    int idx =0;
    int max_cnt=0;
    for(int i=1; i<n; i++){
        if(arr[i] == temp){
            cnt++;
            max_cnt = max(cnt, max_cnt);
            if(max_cnt == cnt)
                idx = i;
            //cout<< "if : "<<i <<" "<<temp << " " << cnt<< endl;
        }
        else{
            //cout<< "else :" << i<<" " <<temp << endl;
            temp = arr[i];
            cnt=1;
        }
    }

    if(max_cnt >= m)
        return make_pair(idx,max_cnt);
    else
        return make_pair(0,0);
}


void MakeZero(int idx, int cnt){
    for(int i=0; i<n; i++){
        if(i<=idx && i>=(idx-cnt+1)) arr[i] = 0;
    }
}

void Fall(){
    int next_idx = 0;
    for(int i=0; i < n; i++){
        if(arr[i] !=0)
            idx[next_idx++] = arr[i];
    }
    for(int i=0; i<next_idx; i++){
        arr[i] = idx[i];
    }
    n = next_idx;
}

int main() {
    
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    pair<int,int> res = Check();

    int p = res.first;
    int q = res.second;

    MakeZero(p,q);
    

    while(p!=0 && q!=0){
        Fall();
        res = Check();
        p = res.first;
        q = res.second;
        MakeZero(p,q);
    }


    if(n==0)
        cout << 0;
    else{
        cout << n << endl;
        for(int i=0; i<n; i++)
                cout << arr[i] << " " ;
            // 여기에 코드를 작성해주세요.
    }
    
    return 0;
}