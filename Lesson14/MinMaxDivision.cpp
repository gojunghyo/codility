// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isDivisable(int mid, int k, vector<int> v) {
    int size = k;
    int sum = 0;

    for(int i=0; i<v.size(); i++){
        sum+=v[i];
        if(sum > mid) {
            size--;
            sum = v[i];
        }
        if(size == 0) return false;
    }
}

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here
    int sum = 0, max = 0;
    int len = A.size();

    for(auto i : A){
        sum += i;
        if(max < i) {
            max = i;
        }
    }


    int ret = sum;
    while(max <= sum) {
        int mid = (max + sum) / 2;
        if(isDivisable(mid, K , A)){
            ret = mid;
            sum = mid - 1;
        }else{
            max = mid + 1;
        }
    }

    return ret;
}