#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isvaild(long long star,long long end,string num){
    long long first,second,sum;
    if(num[star] == 0 && end-star > 1)
        return false;//数字不能以0开头
    else{
        cout << (end-star > 1)<<(num[star] == 0) <<endl;
        cout <<star<<":"<< num[star]<<endl;
        cout << end-star <<endl;        
    }
    //long long first,second,sum;
   // cout <<star<<":"<< num[star]<<endl;
    //cout << end-star <<endl;

    first = atoi(num.substr(0,star).c_str());
    // if(num[star] == 0 && end-star == 1)
    //     second = 0;
    // else
    second = atoi(num.substr(star,end-star).c_str());
    while(1){
        cout <<"1st: "<< first <<endl;
        cout <<"2nd: "<< second <<endl;
        //first = atoi(num.substr(0,star-0).c_str());
        //second = atoi(num.substr(star,star-end).c_str());
        sum = first+second;
        
        string res = to_string(sum);
        cout <<"res: "<< res <<endl;
        long long len = res.length(); 
        if(len+end>num.length()||num.substr(end,len) != res)
            return false;
        else if(num.substr(end,len) == res){
            if(len+end == num.length())
                return true;
            first = second;
            second = sum;
            //star = end;
            end = end+len;
        }
    }
    return false;
        
}
bool isAdditiveNumber(string num) {
    long long n = num.length();
    for(long long secondStar = 1;secondStar<n-1;secondStar++){
        if(num[0] == '0'&&secondStar!=1)
            break;
        for(long long secondEnd = secondStar+1;secondEnd<=n;secondEnd++){//右边开区间
            if(isvaild(secondStar,secondEnd,num))
                return true;
        }
    }
    return false;
}
int main(){
    string s;
    while(cin >> s){
        if(s == "quit")
            break;
        cout << isAdditiveNumber(s) <<endl;
    }
    return 0;
}