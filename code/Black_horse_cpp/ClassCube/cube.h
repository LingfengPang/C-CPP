#ifndef CUBE_H
#define CUBE_H

class Cube
{
private:
    /* data */
    int len;//变成
public:
    void setLen(int len){this->len = len;}
    int getS(){return len*len*6;}
    int getV(){return len*len*len;}
    int getLen(){return len;}
    bool isEqual(Cube &c){
        if(c.getLen()  == len)
            return true;
        return false;
    }
};

class Point
{
private:
    /* data */
    double x;//变成
    double y;
public:
    void setXY(double x = 0,double y = 0){this->x = x,this->y = y;}
    double getX(){return x;}
    double getY(){return y;}
};

class Circle{
private:
    /* data */
    Point center;
    double R;
public:
    void setXY(double x = 0,double y = 0){center.setXY(x,y);}   
    void setR(double R = 1){this->R = R;} 
    void pointAndCircle(Point &point);
};
#endif