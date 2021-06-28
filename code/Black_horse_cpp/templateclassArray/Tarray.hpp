#ifndef TARRAY_HPP
#define TARRAY_HPP
template <class T>
class myArray{
private:
    T *pAddress;
    int cap;//容量
    int size;//大小
public:
    myArray(int cap){
        this->cap = cap;
        this->size = 0;
        this->pAddress = new T[this->cap];
    }
    ~myArray(){
        if(this->pAddress != nullptr)
        {
            delete [] this->pAddress;
            this->pAddress = nullptr;
        }
    }
    myArray(const myArray &arr){
        this->cap = arr.cap;
        this->size = arr.size;
        //this->pAddress = arr.pAddress;
        this->pAddress = new T[arr.cap];
        for(int i = 0;i<this->size;i++){
            this ->pAddress[i] = arr.pAddress[i];
        }
    }

    myArray &operator=(const myArray&arr){
        //先判断堆区是否有数据
        if(this->pAddress!=nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
            this->cap = 0;
            this->size = 0;

        }

        this -> cap = arr.cap;
        this -> size = arr.size;
        this -> pAddress = new T[arr.cap];
        for(int i = 0;i<this->size;i++){
            this ->pAddress[i] = arr.pAddress[i];
        }
    }

    void push_back(const T& val){
        if(this ->cap == this->size)
            return;
        this->pAddress[this->size] = val;
        this->size++;
    }
    void pop_back(){
        if(this->size == 0)
            return;
        this->size--;
    }
    T& operator[](int index){
        return this->pAddress[index];
    }

    int getCap(){return this->cap;}
    int getSize(){return this->size;}
};
#endif