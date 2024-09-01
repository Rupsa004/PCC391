#include<iostream>
using namespace std;

int fibo(int n,int a=0,int b=1){
    if(n==0){
        return a;
    }
    else{
        return fibo(n-1,b,a+b);
    }
}
int main(){
    int n;
    cout<<"enter the position of fibonacci: ";
    cin>>n;
    cout<<"fibonacci at the position is "<<n<<" "<<fibo(n)<<endl;
    return 0;
}