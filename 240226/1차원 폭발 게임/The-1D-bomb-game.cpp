#include <iostream>

using namespace std;
int n,m;
int arr[100];
int temp[100];
int end_of_arr, end_of_temp;


int GetEndidx(int curr_idx, int num){
    int idx = curr_idx;
    for(int i=curr_idx+1; i<end_of_arr; i++){
        if(arr[i] == num) idx ++;
        else break;
    }
    return idx--;

}

void FillZero(int sidx, int eidx){
    for(int i=sidx; i<= eidx;i++)
        arr[i] = 0;
}

void MakeTemp (){
    end_of_temp = 0;
    for(int i=0; i<end_of_arr; i++){
        if(arr[i] != 0){
            temp[end_of_temp++] = arr[i];
        }
    }
    end_of_arr = end_of_temp;
}

void Copy(){
    for(int i=0; i<end_of_arr; i++)
        arr[i]= temp[i];
}

int main(){

    cin>> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    bool didexplode = false;

    do{
        didexplode = false;

        for(int i=0; i<n; i++){

            if(arr[i] == 0) continue;
            int idx = GetEndidx(i,arr[i]);

            if(idx - i +1 >= m){
                didexplode = true;
                FillZero(i,idx);
            }   

        }
        MakeTemp();
        Copy();
    }while(didexplode);

    cout << end_of_arr << endl;
    for(int i=0; i< end_of_arr; i++)
        cout << arr[i] << endl;
    return 0;
}