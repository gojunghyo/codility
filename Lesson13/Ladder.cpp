//
// Created by MZ01-GOJGHO on 2023/03/24.
//


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<cmath>
int a[50004];
int getCnt(int num) {
    //cout << "num = " << num <<  " : " << " a[num] = " << a[num] <<'\n';
    int max = pow(2,30);

    if(num == 0 || num == 1) return 1;
    if(a[num]) return a[num];

    a[num] = (getCnt(num-1) + getCnt(num-2)) % max;
    return a[num];
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    a[0] = 1;
    a[1] = 1;

    int len = A.size();
    vector<int> v;
    for(int i=0; i<len; i++){
        //cout << "A[i] = " << A[i] << '\n';
        int value = getCnt(A[i]);
        int p = pow(2, B[i]);
        v.push_back(value%p);
    }

    return v;
}