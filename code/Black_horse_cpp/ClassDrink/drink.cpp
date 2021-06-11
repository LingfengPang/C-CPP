#include <iostream>
using namespace std;
class AbsDrink
{
private:
    /* data */
public:
    virtual void boil() = 0;//煮水
    virtual void brew() = 0;//冲泡
    virtual void putIntoCup() = 0;//放入杯子中
    virtual void putSomething() = 0;//放点其他东西
    void make(){
        boil();
        brew();
        putIntoCup();
        putSomething();
    }
};

class Coffe:public AbsDrink{
    void boil(){
        cout <<"Boil Water"<<endl;
    }//煮水
    void brew(){
        cout <<"Brew coffee"<<endl;
    }
    void putIntoCup(){
        cout <<"put into cup"<<endl;
    }
    void putSomething(){
        cout <<"put sugar"<<endl;
    }
};

class Tea:public AbsDrink{
    void boil(){
        cout <<"Boil Water"<<endl;
    }//煮水
    void brew(){
        cout <<"Brew Tea"<<endl;
    }
    void putIntoCup(){
        cout <<"put into cup"<<endl;
    }
    void putSomething(){
        cout <<"put none"<<endl;
    }
};

void work(AbsDrink *absdrink){
    absdrink->make();
    delete absdrink;
}

int main(){
    work(new Coffe);
    cout <<"************************"<<endl;
    work(new Tea);
    system("pause");
    return 0;
}
