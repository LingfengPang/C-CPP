#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Mat
{
private:
    /* data */
    int row;
    int col;
    vector<T> matrix;
public:
    Mat(/* args */){
        row = col = 0;
    }
    Mat(vector<vector<T>> v){
        row = v.size();
        col = row == 0?0:v[0].size();
        matrix.resize(row*col,0);
        for(int i = 0;i<row;i++){
            for(int j = 0;j<row;j++)
                matrix[i*row+j] = v[i][j];
        }
    }
    Mat(int row,int col){
        this->row = row;
        this->col = col;
        matrix.resize(row*col);
    }
    void setValue(int i,int j,int value){
        if(i<row&&j<col);
            matrix[i*row+j] = value;
    }
    const T getValue(int i,int j)const{
        if(i<row&&j<row);
        return  matrix[i*row+j];
    }
    
    const int getrow()const {return row;}
    const int getcol()const {return col;}
    Mat operator*(const Mat &b){
        if(this->col == b.row){
            Mat res;
            res.row = this->row;
            res.col = b.col;
            res.matrix.resize(res.row*res.col);
            for(int i = 0;i<this->row;i++){
                for(int j = 0;j<b.col;j++){
                    int value = 0;
                    int minIndex = min(this->row,b.col);
                    for(int k = 0;k<minIndex;k++){
                        value += ((matrix[i*row+k])*(b.matrix[k*b.row+j]));
                    }
                    //res.setValue(i,j,value);
                    res.matrix[i*res.row+j] = value;
                }
            }
            return res;
        } 
        else
            return Mat();
    }
    ~Mat(){}
    void printfMat(){
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++)
                cout << matrix[i*row+j]<<" ";
            cout <<endl;
        }
    }
};


vector<vector<int>> I ={
    {1,0,0},
    {0,1,0},
    {0,0,1}
};

vector<vector<int>> A ={
    {1,2,3},
    {1,2,3},
    {1,2,3}
};
int main(){
    Mat<int> a = Mat<int>(I);
    Mat<int> b = Mat<int>(A);
    Mat<int> c = a*b;
    //a.printfMat();
   // b.printfMat();
    c.printfMat();
    cout << endl;
    Mat<int> d = c*c;
    d.printfMat();
    system("pause");
    return 0;
}