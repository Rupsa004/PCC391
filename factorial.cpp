#include<iostream>
using namespace std;

int fact(int n, int prod){
    if(n==0||n==1)
        return prod;
    else
        return fact(n-1,n*prod);
}
int main(){
    int i=1,n,x;
    cout<<"enter the number: ";
    cin>>n;
    x=fact(n,i);
    cout<<"factorial of "<<n <<" is "<<x<<endl;
    return 0;
}