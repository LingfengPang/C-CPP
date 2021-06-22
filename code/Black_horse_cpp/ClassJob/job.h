#ifndef JOB_H
#define JOB_H
#include <string>
#include <fstream>
#define FILEPATH "save.txt"
class Job;
class JobMange
{
private:
    /* data */

public:
    bool isFileEmpty;
    int nums;//职工人数
    //职工数组指针
    Job **jobArray;  
    void showMenu();
    void add();
    void saveFile();
    JobMange(/* args */);
    ~JobMange();
    int getEmp();
    void Show();
    void find();
    void del();
    void fix();
    void sort();
    void clean();
};

class Job
{
private:
public:
    int id;//个人id
    int partId;//部门id
    virtual void showInfo() = 0;//显示个人信息
    virtual std::string getPart() = 0;//获取个人id

};

//普通员工类
class Employee:public Job{
    private:
    public:
        Employee(int id,int partId);
        void showInfo();//显示个人信息
        std::string getPart();//获取个人id

};

class Mange:public Job{
    private:
    public:
        Mange(int id,int partId);
        void showInfo();//显示个人信息
        std::string getPart();//获取个人id
};

class Boss:public Job{
    private:
    public:
        Boss(int id,int partId);
        void showInfo();//显示个人信息
        std::string getPart();//获取个人id
};
#endif