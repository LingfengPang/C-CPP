#include <iostream>;
#include <string>;
#include <vector>
using namespace std;
class Invectory
{
private:
    /* data */
    int id;
    string name;
    int num;

    
public:
    Invectory(/* args */):id(-1),name("null"),num(0){

    }
    Invectory(int id,string name,int num):id(id),name(name),num(num){}
    ~Invectory();

    int getId(){return id;}
    string getName(){return name;}
    int getNum(){return num;}
};


class Mange
{
private:
    /* data */
    int nums;//文件数量
    vector<Invectory> v;
public:
    //bool isFileEmpty;
    //int nums;//职工人数
    //职工数组指针
     
    void showMenu();
    void insert();
    //void saveFile();
    Mange(/* args */);
    ~Mange(){}
    //int getEmp();
    void search();
    void find();
    void show();
    //void del();
    //void fix();
    //void sort();
    //void clean();
};



