#include <iostream>
#include "calculator.h"

using namespace std;

int main(){
    Calculator *opr = new Add;
    opr->A = 80;
    opr->B = 3;
    cout << opr->getResult() <<endl;
    delete opr;
    

    opr = new Sub;
    opr->A = 80;
    opr->B = 3;
    cout << opr->getResult() <<endl;
    delete opr;

    
    opr = new Mul;
    opr->A = 80;
    opr->B = 3;
    cout << opr->getResult() <<endl;
    delete opr;

    opr = new Div;
    opr->A = 80;
    opr->B = 3;
    cout << opr->getResult() <<endl;
    delete opr;

    system("pause");
    return 0;
}