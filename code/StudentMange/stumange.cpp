#include "stmange.h"

int main(){
    StMange JobM;
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