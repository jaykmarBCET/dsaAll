#include <iostream>
using namespace std;
#include <string>

int permutation(string str,string ans){
    if(str.size()==i){
        cout<<ans<<" ";
    }

    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        str = str.substr(0,i) + str.substr(i+1);
        permutation(str,ans+ch);
    }

    
}