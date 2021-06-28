#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H
#include "student.h"
class Undergraduate:public student
{
private:
    /* data */
    bool partDS;//是否参加过电赛

public:
    void setPartDS(bool partDS){this->partDS = partDS;}
    bool getPartDS(){return this->partDS;}
    Undergraduate(int id,string name,int age,string sex,int year,int scorce,bool partDS):student(id,name,age,sex,year,scorce){
        this->partDS = partDS;
    }
    void showInfo(){
        printf("Id:%4d,Name:%4s,Age:%3d,Sex:%6s,year:%4d,scorce:%3d,partDS:%2d \n",
        this->getId(),"ss",this->getAge(),this->getSex(),this->getYear(),this->getScorce(),
        this->partDS
        );
    }
    ~Undergraduate();
};



Undergraduate::~Undergraduate()
{
}


#endif