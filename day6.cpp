#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the binary value : ";
    cin>>n;
    int sum=0;
    int i=0;
    while(n>0){
        int c=n%10;
        sum=sum+c*pow(2,i);
        i++;
        n=n/10;
    }
    cout<<"value in decimal : "<<sum;

}