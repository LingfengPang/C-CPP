#ifndef STMANGE_H
#define STMANGE_H
#include <iostream>
#include "student.h"
#include "undergraduate.h"
#include "master.h"
#include "doctor.h"
using namespace std;
class StMange
{
private:
    /* data */
    int nums;//总共有几人
    student** stuArray;
public:
    void showMenu();
    void add();
    void Show();
    void find();
    void del();
    void fix();
    void sort();
    void clean();
    StMange(/* args */);
    ~StMange();
    
};
void StMange::showMenu(){
    cout << "1.Add Person "<<endl;
    cout << "2.Show Person"<<endl;
    cout << "3.Del Person "<<endl;
    cout << "4.Fix Person "<<endl;
    cout << "5.Find Person "<<endl;
    cout << "6.sort by id "<<endl;
    cout << "7.Clear Person "<<endl;
    cout << "0.Exit "<<endl;    
}
void StMange::add(){
    int num;
    cout  << "Enter num:"<<endl;
    cin >>num;
        if(num>0){
        //计算新添加空间大小
        int newSize = this->nums+num;
        //开辟新空间
        student** newSpace = new student*[newSize];
        //将原来空间数据拷贝新空间下
        if(this->stuArray){
            for(int i = 0;i<this->nums;i++){
                newSpace[i] = this->stuArray[i];
            }
        }
        //添加新数据
        for(int i = 0;i < num;i++){
            int id;
            int age;
            string sex;
            int year;
            int scorce;
            string name;

            int dselect;
            cout <<"Enter id:"<<endl;
            cin >> id;
            cout <<"Enter age"<<endl;
            cin >> age;
            cout <<"Enter sex"<<endl;
            cin >> sex;
            cout <<"Enter year"<<endl;
            cin >> year;
            cout <<"Enter scorce"<<endl;
            cin >> scorce;
            cout <<"Enter name"<<endl;
            cin >> name;
            cout <<"1.undergraduate,2.master,3.doctor"<<endl;
            cin >> dselect;
            // cin >>dselect;
            student* stu = NULL;
            switch (dselect)
            {
            case 1:
                bool partDS;
                cout <<"had part Dian Sai"<<endl;
                cin >> partDS;
                stu = new Undergraduate(id,name,age,sex,year,scorce,partDS);
            break;
            case 2:
                int partPro;
                cout <<"how many parts part"<<endl;
                cin >> partPro;
                stu = new master(id,name,age,sex,year,scorce,partPro);
            break;
            case 3:
                int paper;
                cout <<"how many papers"<<endl;
                cin >> paper;
                stu = new doctor(id,name,age,sex,year,scorce,paper);
            break;
            default:
                break;
            }

            newSpace[this->nums+i] = stu;
        }
        //释放原有的空间
        //delete [] this->jobArray;
        //更改新空间的指 = newSpace;
        this -> stuArray = newSpace;
        this ->nums = newSize;
    }
}
StMange::StMange(/* args */)
{
    this ->nums = 0;
    this ->stuArray = nullptr;
}

StMange::~StMange()
{
}

void StMange::Show(){
    for(int i = 0;i<this->nums;i++){
        this->stuArray[i]->showInfo();
    }
}

void StMange::find(){
    cout <<"Enter id:"<<endl;
    int id;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->stuArray[i]->getId() == id){
            cout <<"exist!"<<endl;
            break;
        }
    }
}

void  StMange::fix(){
    cout <<"Enter id:"<<endl;
    int id;
    int index = -1;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->stuArray[i]->getId() == id){
            index =i;
            break;
        }
    }
    if(index>-1){
        int id;
        int age;
        string sex;
        int year;
        int scorce;
        string name;

        int dselect;
        cout <<"Enter id:"<<endl;
        cin >> id;
        cout <<"Enter age"<<endl;
        cin >> age;
        cout <<"Enter sex"<<endl;
        cin >> sex;
        cout <<"Enter year"<<endl;
        cin >> year;
        cout <<"Enter scorce"<<endl;
        cin >> scorce;
        cout <<"Enter name"<<endl;
        cin >> name;
        cout <<"1.undergraduate,2.master,3.doctor"<<endl;
        cin >> dselect;
        // cin >>dselect;
        student* stu = NULL;
        switch (dselect)
        {
        case 1:
            bool partDS;
            cout <<"had part Dian Sai"<<endl;
            cin >> partDS;
            stu = new Undergraduate(id,name,age,sex,year,scorce,partDS);
        break;
        case 2:
            int partPro;
            cout <<"how many parts part"<<endl;
            cin >> partPro;
            stu = new master(id,name,age,sex,year,scorce,partPro);
        break;
        case 3:
            int paper;
            cout <<"how many papers"<<endl;
            cin >> paper;
            stu = new doctor(id,name,age,sex,year,scorce,paper);
        break;
        default:
            break;
        }
        this->stuArray[index] = stu;
    }    
}

void StMange::del(){
    cout <<"Enter id:"<<endl;
    int id;
    int index = 0;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->stuArray[i]->getId() == id){
            index =i;
            break;
        }
    }
    for(int i = index;i<this->nums-1;i++){
        this->stuArray[i] = this->stuArray[i+1];
    }  
    this->nums--;
}

void StMange::sort(){
    for(int i = 0;i<nums;i++){
        int min = i;
        for(int j = i+1;j<nums;j++){
            if(stuArray[min]->getId() > stuArray[j]->getId())
            min = j;
        }
        if(i!=min){
            student *temp = stuArray[i];
            stuArray[i] = stuArray[min];
            stuArray[min] = temp;
        }
    }

}

void StMange::clean(){
    if(this->stuArray!=nullptr){
        for(int i = 0;i<nums;i++){
            if(stuArray[i]!=nullptr)
                delete stuArray[i];
        }
        nums = 0;
        delete []this->stuArray;
        stuArray = nullptr;

    }
}
#endif