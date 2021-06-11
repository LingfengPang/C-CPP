#ifndef COMPUTER_H
#define COMPUTER_H


class CPU
{
private:
    /* data */
public:
    virtual void calculate() = 0;
};

class Intel:public CPU{
    void calculate();
};

class Amd:public CPU{
    void calculate();
};

class Computer
{
private:
    CPU *cpu;
public:
    void work(){cpu->calculate();}
    Computer(CPU *cpu){this->cpu = cpu;};
    ~Computer();
};



#endif