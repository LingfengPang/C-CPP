#include "job.h"
#include <iostream>
using namespace std;
JobMange::JobMange(/* args */)
{
    char ch;
    // this->nums = 0;
    // this->jobArray = NULL;
    ifstream ifs;
    ifs.open(FILEPATH,ios::in);
    //文件不存在的情况
    if(!ifs.is_open())
    {
        this->nums = 0;
        this->jobArray = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }
    //文件存在内容为空
    ifs >> ch;
    if(ifs.eof()){//是否结尾了
        this->nums = 0;
        this->jobArray = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }
    else{
        this->isFileEmpty = false;
        ifs.close();
        this->getEmp();
    }
        
}
int JobMange::getEmp(){
    ifstream ifs;
    ifs.open(FILEPATH,ios::in);
    int id;
    int partId;
    string msg;
    int num = 0;
    while(ifs>>id&&ifs>>partId&&ifs>>msg){
        num++;
    }
    ifs.close();
    ifs.open(FILEPATH,ios::in);
    this->nums = num;
    this->jobArray = new Job*[this->nums];//开辟空间
    num = 0;
    while(ifs>>id&&ifs>>partId&&ifs>>msg){
        //num++;//
        Job* job = nullptr;
        if(msg == "1"){
            job = new Employee(id,partId);
        }
        else if(msg == "2"){
            job = new Mange(id,partId);
        }
        else if(msg == "3"){
            job = new Boss(id,partId);
        }
        this->jobArray[num++] = job; 
    }
    this->nums = num;
     ifs.close();
    return num;
    
    
}
void JobMange::Show(){
    if(this->isFileEmpty){
        return;
    }
    else{
        for(int i = 0;i<this->nums;i++){
            this->jobArray[i]->showInfo();
        }
    }
}

void JobMange::find(){
    cout <<"Enter id:"<<endl;
    int id;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->jobArray[i]->id == id){
            cout <<"exist!"<<endl;
            break;;
        }
    }
}
void  JobMange::fix(){
    cout <<"Enter id:"<<endl;
    int id;
    int index = -1;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->jobArray[i]->id == id){
            index =i;
            break;
        }
    }
    if(index>-1){
        int newId,newPartId,newSel;
        delete this->jobArray[index];
            cout <<"Enter id:"<<endl;
            cin >> newId;
            cout <<"Enter PartId"<<endl;
            cin >> newPartId;
            cout <<"job:1.employee,2.mange,3.boss"<<endl;
            cin >>newSel;
            Job *job = NULL;
            switch (newSel)
            {
            case 1:
                job = new Employee(newId,newPartId);
            break;
            case 2:
                job = new Mange(newId,newPartId);
            break;
            case 3:
                job = new Boss(newId,newPartId);
            break;
            default:
                break;
            }
            this->jobArray[index] = job;
    }    
}
void JobMange::del(){
    cout <<"Enter id:"<<endl;
    int id;
    int index = 0;
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(this->jobArray[i]->id == id){
            index =i;
            break;
        }
    }
    for(int i = index;i<this->nums-1;i++){
        this->jobArray[i] = this->jobArray[i+1];
    }  
    this->nums--;
    this->saveFile();
}
JobMange::~JobMange()
{
}
void JobMange::add(){
    int num;
    cout <<"Enter num: "<<endl;
    cin >> num;
    if(num>0){
        //计算新添加空间大小
        int newSize = this->nums+num;
        //开辟新空间
        Job** newSpace = new Job*[newSize];
        //将原来空间数据拷贝新空间下
        if(this->jobArray){
            for(int i = 0;i<this->nums;i++){
                newSpace[i] = this->jobArray[i];
            }
        }
        //添加新数据
        for(int i = 0;i < num;i++){
            int id;
            int partId;
            int dselect;
            cout <<"Enter id:"<<endl;
            cin >> id;
            cout <<"Enter PartId"<<endl;
            cin >> partId;
            cout <<"job:1.employee,2.mange,3.boss"<<endl;
            cin >>dselect;
            Job *job = NULL;
            switch (dselect)
            {
            case 1:
                job = new Employee(id,partId);
            break;
            case 2:
                job = new Mange(id,partId);
            break;
            case 3:
                job = new Boss(id,partId);
            break;
            default:
                break;
            }

            newSpace[this->nums+i] = job;
        }
        //释放原有的空间
        //delete [] this->jobArray;
        //更改新空间的指 = newSpace;
        this -> jobArray = newSpace;
        this ->nums = newSize;
        this->saveFile();
    }
}
void JobMange::saveFile(){
    ofstream ofs;
    ofs.open(FILEPATH,ios::out);
    //写入数据for
    for(int i = 0;i<this->nums;i++){
        ofs<<this->jobArray[i]->id<<" "
        <<this->jobArray[i]->partId<<" "
        <<this->jobArray[i]->getPart()<<endl;
    }
    ofs.close();
}
Employee::Employee(int id,int partId){
    this->id = id;
    this->partId = partId;
}

void Employee::showInfo(){
    cout <<"id:"<<id<<" part:"<<partId<<" job:"<<this->getPart()<<endl;
}

string Employee::getPart(){
    string str = "1";
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
    string str = "2";
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
    string str = "3";
    return str;    
}

void JobMange::showMenu(){
    cout << "1.Add Person "<<endl;
    cout << "2.Show Person"<<endl;
    cout << "3.Del Person "<<endl;
    cout << "4.Fix Person "<<endl;
    cout << "5.Find Person "<<endl;
    cout << "6.sort by id "<<endl;
    cout << "7.Clear Person "<<endl;
    cout << "0.Exit "<<endl;
}

void JobMange::sort(){
    if(this->isFileEmpty){
        return;
    }
    for(int i = 0;i<nums;i++){
        int min = i;
        for(int j = i+1;j<nums;j++){
            if(jobArray[min]->id > jobArray[j]->id)
            min = j;
        }
        if(i!=min){
            Job *temp = jobArray[i];
            jobArray[i] = jobArray[min];
            jobArray[min] = temp;
        }
    }

}

void JobMange::clean(){
    ofstream ofs(FILEPATH,ios::trunc);//如果存在,删除文件并重新创建
    ofs.close();
    if(this->jobArray!=nullptr){
        for(int i = 0;i<nums;i++){
            if(jobArray[i]!=nullptr)
                delete jobArray[i];
        }
        nums = 0;
        delete []this->jobArray;
        jobArray = nullptr;
        this->isFileEmpty = true;
    }
}
int main(){
    JobMange JobM;
    // job->showInfo();
    // delete job;

    // job = new Mange(2,2);
    // job->showInfo();
    // delete job;

    // job = new Boss(3,3);
    // job->showInfo();
    // delete job;

    int select;
    while(1){
        JobM.showMenu();
        cin >> select;
        switch(select){
            case 1:
                JobM.add();
            break;
            case 2:
                //JobM.getEmp();
                JobM.Show();
            break;

            case 3:
                JobM.del();
            break;
            case 4:
                JobM.fix();
                break;
            case 5:
                JobM.find();
            break;
            case 6:
                JobM.sort();
            break;
            case 7:
                JobM.clean();
            break;
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