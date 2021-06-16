#include "job.h"
#include <iostream>
using namespace std;
JobMange::JobMange(/* args */)
{
}

JobMange::~JobMange()
{
}


Employee::Employee(int id,int partId){
    this->id = id;
    this->partId = partId;
}

void Employee::showInfo(){
    cout <<"id:"<<id<<" part:"<<partId<<" job:"<<this->getPart()<<endl;
}

string Employee::getPart(){
    string str = "Employee,work work!";
    return str;
}


Mange::Mange(int id,int partId){
    this->id = id;
    this->partId = partId;
}
void Mange::showInfo(){
    cout <<"id:"<<id<<" part:"<<partId<<" job:"<<this->getPart()<<endl;
}
string Mange::getPart(){
    string str = "Manger,kill employee!";
    return str;    
}



Boss::Boss(int id,int partId){
    this->id = id;
    this->partId = partId;
}
void Boss::showInfo(){
    cout <<"id:"<<id<<" part:"<<partId<<" job:"<<this->getPart()<<endl;
}
string Boss::getPart(){
    string str = "Boss,kill manger and employee!";
    return str;    
}

void JobMange::showMenu(){
    cout << "1.Add Person "<<endl;
    cout << "2.Show Person"<<endl;
    cout << "3.Del Person "<<endl;
    cout << "4.Fix Person "<<endl;
    cout << "5.Find Person "<<endl;
    cout << "6.sort by id "<<endl;
    cout << "6.Clear Person "<<endl;
    cout << "0.Exit "<<endl;
}
int main(){
    Job *job = new Employee(1,1);
    job->showInfo();
    delete job;

    job = new Mange(2,2);
    job->showInfo();
    delete job;

    job = new Boss(3,3);
    job->showInfo();
    delete job;

    int select;
    while(1){
        JobMange::showMenu();
        cin >> select;
        switch(select){
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            case 5:break;
            case 6:break;
            case 0:
                cout <<"goodbye!"<<endl;
                system("pause");
                return 0;
                break;
            default:break;
        }
        system("pause");//按任意键继续
        system("cls");
}

system("pause");
return 0;
}