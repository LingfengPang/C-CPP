#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    int num = rand()%100+1;
    int guess;

    while(1){
        cin >> guess;
        if(guess == num)
            break;
        else if(guess > num)
            cout << "too large"<<endl;
        else 
            cout << "too small"<<endl;
    }
    system("pause");
    return 0;

}