#include "invectory.h"
#include <iostream>
using namespace std;
Mange::Mange(/* args */){
    this->nums = 0;
}
void Mange::showMenu(){
    cout << "i.Insert"<<endl;
    cout << "s.Search"<<endl;
    cout << "p.Show"<<endl;
    cout << "0.Exit "<<endl;   
}

void Mange::insert(){
    int id,num;
    string name;
    cout <<"Please enter id:";
    cin >> id;
    cout <<"Please enter name:";
    cin >>name;
    cout << "Please enter num:";
    cin >>num;
    v.push_back(Invectory(id,name,num));
    this->nums++;
}
void Mange::search(){
    int id;
    cout <<"Please enter id:";
    cin >> id;
    for(int i = 0;i<this->nums;i++){
        if(v[i].getId() == id){
            cout << "found!"<<end;
            return;
        }
    }
    cout << "not found"<<endl;
}

void Mange::show(){
    printf("ID    Name      Num")
    for(int i = 0;i<this->nums;i++){
        printf("%2d    %s%d",this->v[i].getId(),this->v[i].getName(),this->v[i].getNum())
    }

}
using namespace std;
int main(){
    Mange mange;

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