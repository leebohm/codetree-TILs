#include <iostream>

#define MAX_NUM 19
#define UNUSED -1

using namespace std;

int memo[MAX_NUM+1];

void InitializeMemo(){
    for(int i=0; i<= MAX_NUM; i++)
        memo[i] = UNUSED;
}

int NumOfUniqueBST(int n){
    if(memo[n] != UNUSED)
        return memo[n];
    
    if(n <= 1)
        return 1;
    
    int number_of_unique_bst = 0;

    for(int i=0; i<n; i++)
        number_of_unique_bst += NumOfUniqueBST(i) * NumOfUniqueBST(n-i-1);

    return memo[n] = number_of_unique_bst;
}

int main() {
    int n;
    cin >> n;
    InitializeMemo();

    cout << NumOfUniqueBST(n);
}