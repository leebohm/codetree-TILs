#include <iostream>
#include <vector>

#define MAX_N 100000
#define MAX_K 6
#define MAX_DIGIT 10

using namespace std;

int n;
int arr[MAX_N];

void RadixSort(){
    int p = 1;
    for(int pos = 0; pos <MAX_K ; pos++){
        vector<int> arr_new[MAX_DIGIT];

        for(int i=0; i<n;i++){
            int digit = (arr[i]/p%10);
            arr_new[digit].push_back(arr[i]);
        }

        int index = 0; 

        for(int i=0; i<MAX_DIGIT;i++)
            for(int j=0; j<(int) arr_new[i].size(); j++)
                arr[index++] = arr_new[i][j];
        p*=10;
    }
}

int main() {

    cin >> n;

    for(int i=0; i<n;i++)
        cin >> arr[i];

    RadixSort();

    for(int i=0; i<n;i++)
        cout << arr[i] << " ";
    
    return 0;
}