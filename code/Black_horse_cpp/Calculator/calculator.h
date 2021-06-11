#ifndef CALCILATOR_H
#define CALCILATOR_H
//用多态实现加减乘除
class Calculator
{
private:
    /* data */
public:
    int A;
    int B;
    virtual int getResult(){
        return 0;
    }    
};

class Add:public Calculator
{
private:
    /* data */
public:
   virtual int getResult(){
        return A+B;
    }    
};

class Sub:public Calculator
{
private:
    /* data */
public:
   virtual int getResult(){
        return A-B;
    }    
};

class Mul:public Calculator
{
private:
    /* data */
public:
   virtual int getResult(){
        return A*B;
    }    
};

class Div:public Calculator
{
private:
    /* data */
public:
   virtual int getResult(){
        return A/B;
    }    
};





#endif