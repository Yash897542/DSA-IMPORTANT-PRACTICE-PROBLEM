#include<iostream>
using namespace std;
int climbstairs(int n ){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    return climbstairs(n-1) + climbstairs(n-2);
}
int main(){
    int n ;
    cin>> n;
    cout<< climbstairs(n) << endl;
    return 0;
}