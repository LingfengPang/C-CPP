#include "invectory.h"
#include <iostream>
using namespace std;
Mange::Mange(/* args */){
    this->nums = 0;
}
void Mange::showMenu(){
    cout << "1.Insert"<<endl;
    cout << "2.Search"<<endl;
    cout << "3.Show"<<endl;
    cout << "0.Exit "<<endl;   
}

void Mange::insert(){
    int id,num;
    string name;
    cout <<"Please enter id:";
    cin >> id;
    cout <<"Please enter name:";
    cin.ignore();
    getline(cin, name);
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
            cout << "found!" <<endl;
            return;
        }
    }
    cout << "not found"<<endl;
}


void Mange::show(){
    printf("ID    Name      Num\n");
    for(int i = 0;i<this->nums;i++){
        cout<<this->v[i].getId()<<this->v[i].getName()<<this->v[i].getNum()<<endl
        //printf("%2d    %4s %2d",this->v[i].getId(),this->v[i].getName(),this->v[i].getNum());
    }

}
using namespace std;
int main(){
    Mange mange;

    int select;
    while(1){
        mange.showMenu();
        cin >> select;
        switch(select){
            case 1:
                mange.insert();
            break;
            case 2:
                //JobM.getEmp();
                mange.search();
            break;

            case 3:
                mange.show();
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