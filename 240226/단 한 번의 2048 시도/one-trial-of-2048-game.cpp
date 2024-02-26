#include <iostream>
using namespace std;

#define MAX_N 4

int arr[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];


void Down(){
    for(int j=0; j<MAX_N; j++ ){
        int temp_row = MAX_N-1;
        for(int i = MAX_N-1; i>=0; i--){
            if(arr[i][j] != 0){
                temp[temp_row--][j] = arr[i][j];
            }
                
        }
    }
}

void Down_sum(){
    for(int j=0; j<MAX_N;j++){
        for(int i=MAX_N-1; i>= 0; i--){
            if(arr[i][j] == arr[i-1][j]){
                arr[i][j] *= 2;
                arr[i-1][j] = 0;
            }
                
        }
    }
}

void Up(){
    for(int j=0; j<MAX_N; j++){
        int temp_row = 0;
        for(int i = 0; i<MAX_N; i++){
            if(arr[i][j]!=0)
                temp[temp_row++][j] = arr[i][j];
        }
    }
}

void Up_sum () {
    for(int j=0;j<MAX_N; j++){
        for(int i=0; i<MAX_N-1; i++){
            if(arr[i][j] == arr[i+1][j]){
                arr[i+1][j] = 0;
                arr[i][j] *= 2;
            } 
        }
    }
}




void Left(){
    for(int i=0; i<MAX_N;i++){
        int temp_col = 0;
        for(int j = 0 ; j<MAX_N ; j++ ){
            if(arr[i][j] != 0){
                temp[i][temp_col++] = arr[i][j]; 
            }
                
        }
    }
}

void Left_sum(){
    for(int i=0; i<MAX_N;i++){
        for(int j = 0 ; j<MAX_N-1 ; j++ ){
            if(arr[i][j] == arr[i][j+1]){
                arr[i][j] *=2;
                arr[i][j+1] = 0;
            }
                
        }
    }
}

void Right(){
    for(int i=0; i<MAX_N; i++){
        int temp_col = MAX_N-1;
        for(int j=MAX_N-1; j>=0; j--){
            if(arr[i][j]!= 0){
                temp[i][temp_col--] = arr[i][j];
            }
                
        }
    }
}

void Right_sum (){
    for(int i=0; i<MAX_N; i++)
        for(int j=MAX_N-1; j>=0 ; j--){
            if(arr[i][j]== arr[i][j-1]){
                arr[i][j-1] =0;
                arr[i][j] *= 2;
            }
        }
}

void Copy(){

    for(int i=0;i<MAX_N; i++)
        for(int j=0; j<MAX_N; j++)
            arr[i][j] = temp[i][j];
}

void Reset(){
    for(int i=0; i<MAX_N; i++)
        for(int j=0; j<MAX_N; j++)
            temp[i][j] =0;
}

int main() {

    for(int i=0; i<MAX_N; i++){
        for(int j=0; j<MAX_N ; j++){
            cin >> arr[i][j];
        }
    }
    char dir ;
    cin >> dir;

    if(dir == 'R'){
        Right();
        Copy();
        Reset();
        Right_sum();
        Right();
        Copy();
    } 
    else if( dir == 'U'){
        Up();
        Copy();
        Reset();
        Up_sum();
        Up();
        Copy();
    }
    else if (dir == 'D'){
        Down();
        Copy();
        Reset();
        Down_sum();
        Down();
        Copy();
    }
    else {
        Left();
        Copy();
        Reset();
        Left_sum();
        Left();
        Copy();
    }


    for(int i=0; i<MAX_N; i++){
        for(int j=0; j<MAX_N ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}