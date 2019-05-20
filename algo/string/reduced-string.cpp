#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string reducer3(string s){
    string out;
    for(int i=0;i<s.length();i++){
        if(out.empty() || out.back()!=s[i]){
            out.push_back(s[i]);
        }
        else{
           out.pop_back(); 
        }
    }
    //string res(out);
    return out;
}
string reducer2(string s){
    if(s.empty())
        return s;
   
    string r1(s);
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            s.erase(i,2);
            if(s.empty())
                return s;
            i--;
        }
    }
    string r2(s);
    
    if(r1.compare(r2)==0)
        return r2;
    return reducer2(r2);
    
    
}
string reducer(string s){
    string r;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            i++;
        }
        else{
            r+=s[i];
        }
    }
    if(s.compare(r)==0){
        return r;
    }
    else{
        return reducer(r);
    }
}

int main() {
    string s;
    cin>>s;
    string result=reducer3(s);
    cout<<(result.empty()?"Empty String":result);
    return 0;
}
