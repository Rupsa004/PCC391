#include<iostream>
#include<cmath>
using namespace std;

int cnt=0;
void towerOfHanoi(int n, char src, char aux, char dest){
    cnt++;
    if(n==1){
        cout<<"disk: "<<n<<"from "<<src<<"to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,aux);
    cout<<"disk: "<<n<<"from "<<src<<"to "<<dest<<endl;
    towerOfHanoi(n-1,aux,src,dest);
}
int main(){
    int n;
    cout<<"the no of disk: "<<endl;
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    if(cnt==pow(2,n)-1){
        cout<<"the no of moves: "<<cnt<<endl;
    }
    return 0;
}