#include <iostream>
bool straight,flush1,four,three;
int pairs;
using namespace std;
struct Card
{
    /* data */
    int num;
    char kind;
};
typedef Card card;
card c[5];
int m[12] = {0};

void readCards(){
    int n,k;
    for(int i = 0;i<5;i++){
        cin >> n >> k;
        if(n>=0&&n<=12&&k>='a'&&k<='d'){
            m[n]++;
            c[i].num = n;
            c[i].kind = k;
        }else{
            cout << "bad card"<<endl;
            break;
        }
    }
}
void analyCards(){
    straight = false;
    flush1 = false;
    four =false;
    three = false;
    pairs = 0;

    for(int i = 0;i<4;i++){
        if(c[i].kind != c[i+1].kind){
            flush1 = false;
            break;
        }
        flush1 = true;
    }
    int rank = 0;
    int numConsec = 0;
    while(m[rank]!=0){rank++;}
    for(int i = rank;i<13;i++){
        if(m[i] == 1)
            numConsec++;
        else
        {
        break;
        }
    }
    if(numConsec == 5){
        straight = true;
        return;
    }

    for(int i = 0;i<13;i++){
        if(m[i] == 3){
            three = true;
            //return;
        }
        else if(m[i] == 4){
            four = true;
            return;
        }
        else if(m[i]==2){
            pairs++;
        }
    }


}
int main(){
    readCards();
    analyCards();
    //printResult();
}