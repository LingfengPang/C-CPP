#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int main(){
    int n;
    std::cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    //首先把数1放在0行的中间
    //v[0][n/2] = 1;
    //剩下2，3，到n*n依次向上移动一格
    int x = 0;
    int y = n/2;
    for(int i = 1;i<=n*n;i++){
        v[x][y] = i;
        if(i%n!=0)
        {   
            x--;
           
        }
            y++;
        if(y>=n)
            y = 0;
       
        if(x < 0)
            x = n-1;
        
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout <<v[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}