#include<iostream>
#include<map>
using namespace std;
int main (){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    map<char,int> ans;
    for(int i=0;i<s.length();i++){
        ans[s[i]]++;
    }
     for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout <<it->first<< it->second;
    }
}