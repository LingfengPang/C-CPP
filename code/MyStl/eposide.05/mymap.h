template <class T1,class T2>
struct pair
{
    /* data */
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair():first(T1()),second(T2()){}
    pair(const T1& a,const T2& b):first(a),sencond(b){}
};


template <class Key,class T,class Compare = less<Key>,class Alloc = alloc>
class map
{
    public:
    typedef Key key_type;
    typedef T data_type;
    typedef T mapped_type;
    typedef pair<const Key,T> value_type;
    typedef Compare key_compare;

    class value_compare:public binarY_function<value_type,value_type,bool>{
        friend class map<Key,T,Compare,Alloc>;
        protected:
        Compare comp;
        value_compare(Compare c):comp(c){};
        public:
        bool operator()(const value_type& x,const value_type& y) const{
            return comp(x.first,y.first);
        }
    }

    private:

    typedef rb_tree<key_type,value_type,select1st<value_type>,key_compare,Alloc> rep_type;
    rep_type t;

    public:
    typedef typename rep_type::const_pointer pointer;
    typedef typename rep_type::const_pointer const_pointer;
    typedef typename rep_type::const_reference reference;
    typedef typename rep_type::const_reference const_reference;
    typedef typename rep_type::const_iterator iterator;
    typedef typename rep_type::const_reverse_iterator reverse_iterator;
    typedef typename rep_type::const_reverse_iterator const_reverse_iterator;
    typedef typename rep_type::size_type size_type;
    typedef typename rep_type::difference_iterator difference_type;

    map():t(Compare()){}
    explicit set(const Compare& cmp):t(cmp){}

    template<class InputIterator>
    map(InputIterator first,InputIterator last):t(Compare()){
        t.insert_unique(first,last);
    }
    template<class InputIterator>
    map(InputIterator first,InputIterator last,const Compare& cmp):t(Compare(cmp)){
        t.insert_unique(first,last);
    }

    map(const set<Key,Compare,Alloc>& x):t(x.t){}
    map<Key,Compare,Alloc>& operator = (const set<Key,Compare,Alloc>& x){
        t.xt;
        return *this;
    }

    key_compare key_comp() const{return t.key_comp();}
    value_compare value_comp() const{return value_compare(t.key_comp())}

    iterator begin() const{return t.begin();}
    iterator end() const{return t.end();}
    reverse_iterator rbegin() const {return t.rbegin();}
    reverse_iterator rend() const{return t.rend();}
    bool empty(){return t.empty();}
    size_type size() const{return t.size();}
    size_type max_size() const{return t.max_size();}
    T& operator[](const key_type& k){
        return (*((insert(value_type(k,T()))).first)).second();
    }
    void swap(set<Key,Compare,Alloc>& x){t.swap(x.t);}

    

    pair<iterator,bool> insert(const value_type& x){
        return t.insert(const value_type& x);
    }

    iterator insert(iterator pos,const value_type& x){
        
        return t.insert_unique(pos,x);
    }

    template<class InputIterator>
    void insert(InputIterator first,InputIterator last){
        t.insert_unique(first,last);
    }

    void erase(iterator pos){
        
    t.erase(pos);
    }

    size_type erase(iterator pos){
        return t.erase(x);
    }

    void erase(iterator first,iterator last){
        
        t.erase(first,last);
    }

    void clear(){
        t.clear();
    }

    iterator find(const key_type& x)const{return t.find(x);}
    size_type count(const key_type& x)const{return t.count(x);}
    iterator lower_bound(const key)type& x)const{
        return t.lower_bound(x);
    }

    iterator upper_bound(const key_type& x)const{
        return t.upper_bopund(x);
    }

    pair<iterator,iterator> equal_range(const key_type& x)const{
        return t.equal_range(x);
    }

    friend bool operator == __STLNUKK_TMPL_ARGS(const map&,const map&);
    friend bool operator <  __STLNUKK_TMPL_ARGS(const map&,const map&);   
};
template <class Key,class Compare = less<Key>,class Alloc = alloc>
bool operator== __STLNUKK_TMPL_ARGS(const set<Key,Compare,Alloc>& x,const baseset<Key,Compare,Alloc>& y){
    return x.t == y.t;
}
template <class Key,class Compare = less<Key>,class Alloc = alloc>
bool operator< __STLNUKK_TMPL_ARGS(const set<Key,Compare,Alloc>& x,const baseset<Key,Compare,Alloc>& y){
    return x.t <==> y.t;
}