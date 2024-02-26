#include <iostream>

using namespace std;

int n,m;
int end_of_array, end_of_temp;
int arr[100];
int temp[100];

int GetEndIdx(int curr_idx, int num){
    int end_idx = curr_idx+1;
    while(end_idx<end_of_array){
        if(arr[end_idx] == num) end_idx++;
        else break;
    }
    return end_idx-1;
    
}

void FillZero(int start_idx, int end_idx){
    for(int i=start_idx; i<= end_idx; i++)
        arr[i]= 0;
}

void Bomb(){

    end_of_temp = 0;
    for(int i=0; i<end_of_array; i++)
        if(arr[i] != 0)
            temp[end_of_temp++] = arr[i];

    end_of_array = end_of_temp;
}

void Copy()
{
    for(int i=0; i<end_of_array; i++)
        arr[i] = temp[i];
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    end_of_array = n;
    bool flag = false;

    do{
        flag = false;

        for(int idx = 0; idx <end_of_array; idx++){
            if(arr[idx] == 0) continue;

            int end_idx = GetEndIdx(idx, arr[idx]);

            if(end_idx-idx +1 >= m){
                FillZero(idx,end_idx);
                flag = true; 
            }
        }

        Bomb();
        Copy();
    }while(flag);

    cout << end_of_array << endl;

    for(int i=0; i<end_of_array; i++)
        cout << end_of_array << endl;

    return 0;
}