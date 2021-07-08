#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<string>
#include<map>
#include <cmath>
#include <deque>
#include <algorithm>
#include <stack>
#include <fstream>
#include <list>
using namespace std;
long long int josephus_queries(long long int a,long long int b){
    long long int kos = a - pow(2,floor(log2(a)));
    if(b<=kos){
        return 2*b;
    }
    long long int last_ko = 2*kos + 1;
    if(a==b){
        return last_ko;
    }
    long long int rounds = floor(log2(a)) - 1;
    long long int i;
    long long int result;
    long long int round_beg_kos;
    long long int ko_diff = 2;
    long long int left_diff = 1;
    for(i=rounds;i>=0;i--){
        kos += pow(2,i);
        if(kos>=b){
            break;
        }
        ko_diff *= 2;
        left_diff *= 2;
    }
    if(i>=0){
        kos -= pow(2,i);
    }
    long long int kos_left = b - kos;
    long long int possible_round_kos;
    if(last_ko + left_diff > a){
        possible_round_kos = 0;
    }else{
        possible_round_kos = 1;
        possible_round_kos += (a - (last_ko + left_diff))/ko_diff;   
    }
    if(kos_left>possible_round_kos){
        left_diff *=2;
        kos_left -= possible_round_kos;
        ko_diff *= 2;
        round_beg_kos = last_ko%ko_diff;
        long long int temp = round_beg_kos - left_diff;
        if(temp<0){
            result = round_beg_kos + ((2*kos_left - 1) * left_diff);
        }else{
            result = temp + (kos_left - 1)*ko_diff;
        }
        return result;
    }else{
        result = last_ko + ((2*kos_left - 1) * left_diff);
        return result;
    }
 
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<josephus_queries(a,b)<<endl;
    }
 
    return 0;
}