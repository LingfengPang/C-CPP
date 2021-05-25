#include "addressbook.h"
#include <iostream>
void showMenu(){
    using namespace std;
    cout << "1.Add Person "<<endl;
    cout << "2.Show Person"<<endl;
    cout << "3.Del Person "<<endl;
    cout << "4.Find Person "<<endl;
    cout << "5.Fix Person "<<endl;
    cout << "6.Clear Person "<<endl;
    cout << "0.Exit "<<endl;
}
void addPerson(Ads * ads){
    using namespace std;
    if(ads->size == 1000){
       cout <<"Full"<<endl; 
       return;
    }
    cout <<"Enter name"<<endl;
    cin>>ads->person[ads->size].name;
    cout <<"Enter number"<<endl;
    cin>>ads->person[ads->size].number;
    ads->size++;

}
void showPerson(Ads ads){
    using namespace std;
    if(ads.size == 0){
       cout <<"Empty"<<endl; 
       return;
    }
    for(int i = 0;i<ads.size;i++)
        cout <<"name: "<<ads.person[i].name<<",number: "<<ads.person[i].number<<endl;

}


int findPerson(Ads ads){
    using namespace std;
    std::string name;
    cin >> name;
    for(int i = 0;i<ads.size;i++){
        if(ads.person[i].name == name)
            return ads.size;
    }
    cout << "no person"<<endl;
    return -1;
}

void delPerson(Ads *ads){
    using namespace std;
    int index = findPerson(*ads);
    if(index != -1){
        for(int i = index;i<ads->size;i++){
            ads->person[i-1].name = ads->person[i].name;
            ads->person[i-1].number = ads->person[i].number;
        }
        ads->size--;
        cout << "del ok!"<<endl;
    }

}

void fixPerson(Ads * ads){
    using namespace std;
    std::string name;
    int index = findPerson(*ads);
    if(index != -1){
        cout <<"Enter name"<<endl;
        cin>>ads->person[index-1].name;
        cout <<"Enter number"<<endl;
        cin>>ads->person[index-1].number;
    }
    
}
int main()
{
    using namespace std;
    struct Address ads;
    ads.size = 0;
    int select = 0;
    int id;
    std::string name;
    while(1){
        showMenu();
        cin >> select;
        switch(select){
            case 1:addPerson(&ads);break;
            case 2:showPerson(ads);break;
            case 3:delPerson(&ads);break;
            case 4:{id = findPerson(ads);
                    cout <<ads.person[id-1].name << "  "<<ads.person[id-1].number << "  "<<endl;
            }break;
            case 5:fixPerson(&ads);break;
            case 6:ads.size = 0;break;
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