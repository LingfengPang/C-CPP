template <typename T>
class ListItem{
    private:
    T _value;
    ListItem *_next;
    public;
    T value() const{return _value;}
    ListItem* next() const {return _next};
    
};

template <typename T>
class List{
    public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std:cout) const;

    private:
    ListItem<T>* _end;
    ListItem<T>* front;
    long size;
};

template <class Item>
struct ListIter{
    Item *ptr;//保持与容器之间的一个联系
    ListIter(Item *p = 0):ptr(p){}
    Item &operator*() const {return *ptr;}
    Item* operator->() const{return ptr;}
    //前置++
    ListIter& operator++(){
        ptr = ptr->next();
        return *this;
    }
    ListIter operator++(int){
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }
    bool operator==(const ListItem& i)const{
        return ptr == i.ptr;
    } 
    bool operator!=(const ListIter& i)const{
        return ptr != i.ptr;
    }
};