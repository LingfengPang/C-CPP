#include "cube.h"
#include <iostream>
#include <cmath>
using namespace std;


void Circle::pointAndCircle(Point &point){
    double distance = (point.getX()-center.getX())*(point.getX()-center.getX())+(point.getY()-center.getY())*(point.getY()-center.getY());
    distance = sqrt(distance);
    if(distance > R){
        cout << "out" << endl;
    }
    else if(distance < R)
        cout << "in" << endl;
    else
        cout << "on" << endl;
}
int main(){
    Cube c1,c2;
    c1.setLen(1);
    c2.setLen(1);
    cout << c1.getS() << " "<<c1.getV()<<endl;
    cout << c2.getS() << " "<<c2.getV()<<endl;
    cout << c1.isEqual(c2)<<endl;

    Circle c;
    c.setXY(10,0);
    c.setR(10);
    Point point[3];
    point[0].setXY(8,0);
    point[1].setXY(20,20);
    point[2].setXY(20,0);
    for(int i = 0;i<3;i++)
        c.pointAndCircle(point[i]);
    system("pause");
    return 0;
}