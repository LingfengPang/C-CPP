#include <iostream>

using namespace std;

int main(){
    for(int i = 1;i<=9;i++){
        for(int j = 1;j<=i;j++){
            cout << i << " * " << j << " = " <<i*j;
            if(i==j)
                cout << endl;
            else
                cout << ' ';
        }
    }
    system("pause");
    return 0;
}