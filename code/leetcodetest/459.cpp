#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kmp(const string &s,const string &t,int first){
    vector<int> next(t.length(),-1);
    int j = 0,k = -1;
    //求解next数组
    while(j<t.length()-1){
        if(k == -1 || t[k] == t[j]){
            j++,k++;
            if(t[k]!=t[j])
                next[j] = k;
            else
                next[j] = next[k];
            //cout<<next[j]<<" ";
        }
        else k = next[k];
    }
    //进行匹配
    j = first,k = 0;

    while(j<s.length()&&k<t.length()){
        cout <<"int loop star"<<endl;
        if(k == -1||s[j] == t[k]){
            k++,j++;
        }
        else
            k = next[k];
        cout <<j<<endl;
        cout <<k<<endl;
        cout <<s.length()<<endl;
        cout <<t.length()<<endl;
        cout <<"int loop end"<<endl;
        if(j<s.length()&&k<t.length()){
            cout <<"loop can next"<<endl;
        }else{
            cout<<(j<s.length())<<endl;
            cout <<k<<endl;
            cout <<t.length()<<endl;
            cout<<(k<t.length())<<endl;
        }
    }

    cout <<k<<endl;
    return (k>=t.length())?(j-t.length()):-1;
}
int repeatedSubstringPattern(string s) {
    int index = kmp(s+s,s,1);
    // if(index == -1||index == s.length())
    //     return false;
    return index ;
}

int main(){
    //vector
    //getNext("ana");
    cout <<repeatedSubstringPattern("aba")<<endl;
    while(1);
    return 0;
}