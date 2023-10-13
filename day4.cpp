#include<iostream>
using namespace std;
bool reverse(string& s,int i){
    
    int n=s.length()-1;
    if(n-i>i){
        return true;
    }
    if(s[n-i]!=s[i]){
        return false;
    }
    i--;
    reverse(s,i);
    return true;
}
int main(){
    string s;
    cin>>s;
    if(reverse(s,s.length()-1)){
        cout<<"PANIDROM";

    }
    else{
        cout<<"No";
    }
}