#include <iostream>
#include <cmath>
#include <string>
using namespace std;




int main(){
    //num是一个两位数
    int num;
    string res;
    cin >> num;
    if(num < 10||num>99){
        return 0;
    }
    int _1stdig = num/10;
    int _2nddig = num%10;
    if(num == 10){
        cout <<"ten"<<endl;
    }
    switch (_1stdig)
    {
    case 1:break;
    case 2: res+="twenty";break;
    case 3: res+="thirty";break;
    case 4: res+="forty";break;
    case 5: res+="fifty";break;
    case 6: res+="sixty";break;
    case 7: res+="seventy";break;
    case 8: res+="eighty";break;
    case 9: res+="ninty";break;
    default:
        break;
    }
    if(_2nddig == 0 ){
        cout << res <<endl;
        system("pause");
        return 0;
    }
    else if(_1stdig >= 2)
        res+="-";
    if(num >= 20)
        switch (_2nddig)
        {
        case 1: res+="one";break;
        case 2: res+="two";break;
        case 3: res+="three";break;
        case 4: res+="four";break;
        case 5: res+="five";break;
        case 6: res+="six";break;
        case 7: res+="seven";break;
        case 8: res+="eigh";break;
        case 9: res+="nine";break;
        default:
            break;
        }
    else
            switch (_2nddig)
        {
        case 1: res+="eleven";break;
        case 2: res+="twelve";break;
        case 3: res+="thirteen";break;
        case 4: res+="fourteen";break;
        case 5: res+="fifteen";break;
        case 6: res+="sixteen";break;
        case 7: res+="seventeen";break;
        case 8: res+="eighteen";break;
        case 9: res+="nineteen";break;
        default:
            break;
        }

        cout << res <<endl;
        system("pause");
        return 0;

}