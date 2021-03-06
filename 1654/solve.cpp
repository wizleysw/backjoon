// https://www.acmicpc.net/problem/1654
// 랜선 자르기
// Written in C++ langs
// 2020. 02. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int K, N;
long long LAN[1000001]={0,};
long long H=0;

long long getH(long long val){
    long long res = 0;
    for(long long i=0; i<K; i++){
        if(LAN[i]>=val){
            res += LAN[i] / val;
        }
    }
    return res;
}

void bisect(long long begin, long long end){
    if(end - begin <=1){
        H = begin;
    }
    else{
        long long mid = (begin+end)/2;
        
        if(getH(mid) >= N){
            return bisect(mid, end);
        }
        else{
            return bisect(begin, mid);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    long long maxM = 0;
    for(long long i=0; i<K; i++){
        cin >> LAN[i];
        maxM = max(maxM, LAN[i]);
    }
    
    bisect(0, maxM+1);
    cout << H << "\n";
    
    return 0;
    
}

