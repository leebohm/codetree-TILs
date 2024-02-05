#include <iostream>
#include <algorithm>

using namespace std;
int arr[3];

int cnt = 0;

void Case1 () { // 왼쪽, 가운데 사이가 3이상인 경우
    int tmp1 = arr[1]; // 오른쪽을 왼쪽 +2 로 이동시킴 -> 오른쪽이 가운데가됨
    arr[1] = arr[0]+2;
    arr[2] = tmp1; // 가운데가 오른쪽이 됨.  

    cnt++;

    // 그럼 0 0+2 ? 상태가 됨. 맨 오른쪽을 0+1 로 이동시키면 끝
    int tmp2 = arr[1];
    arr[1] = arr[0]+1;
    arr[2] = tmp2;

    cnt++;
}

void Case2() {  // 가운데, 오른쪽 사이가 3이상인 경우 
    int tmp1 = arr[1];  // 왼쪽을 가운데 +2로 이동시킴 -> 왼쪽이 가운데가 됨
    arr[1] = arr[1]+2; 
    arr[0] = tmp1; // 가운데가 왼쪽이 됨
    cnt++;

    int tmp2 = arr[1];
    arr[1] = arr[0]+1;
    arr[2] = tmp2;
    cnt++;
    
}

int main() {

    for(int i=0; i<3;i++)
        cin >> arr[i];
    
    sort(arr, arr+3);


    while(arr[1]-arr[0]!=1 && arr[2]-arr[1]!=1){
        if (arr[1]-arr[0]==2) cnt++;
        else if (arr[2]-arr[2]==2) cnt++;
        else if(arr[1]- arr[0]>= 3) Case1();

        else if(arr[2] - arr[1]>=3) Case2();

    }

    cout << cnt;
    
    // 여기에 코드를 작성해주세요.
    return 0;
}