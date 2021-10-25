template <class Key,class T,class HashFcn = hash<Value>,class EqualKey = equal_tp<Value>,class Alloc = alloc>
class hash_map
{
    typedef hashtable<pair<const Key,T>,Key,HashFcn,select<pair<const Key,T>,EqualKey>,Alloc> ht;
    ht rep;
    public:
    typedef typename ht::key_type key_type;
    typedef T data_type;
    typedef T mapped_type;
    typedef typename ht::value_type value_type;
    typedef typename ht::hasher hasher;
    typedef typename ht::key_equal key_equal;
    //private:
    // template<class T>
    // struct  identity:public unary_function<T,T>
    // {
    //     /* data */
    //     const   T& operator
    // };
    // typedef rb_tree<key_type,value_type,identity<value>,key_compare,Alloc> rep_type;
    // rep_type t;

    public:
    typedef typename ht::const_pointer pointer;
    typedef typename ht::const_pointer const_pointer;
    typedef typename ht::const_reference reference;
    typedef typename ht::const_reference const_reference;
    typedef typename ht::const_iterator iterator;
    typedef typename ht::const_reverse_iterator reverse_iterator;
    typedef typename ht::const_reverse_iterator const_reverse_iterator;
    typedef typename ht::size_type size_type;
    typedef typename ht::difference_iterator difference_type;

    hash hash_funct() const{return rep.hash_funct;}
    key_equal key_eq() const{return rep.key_eq();}
    explicit hash_map(size_type n):rep(n,hasher(),key_equal()){}
    hash_map(size_type n,const hasher& hf):rep(n,hf,key_equal()){}
    hash_map():rep(100,hasher(),key_equal()){}
    hash_map(size_type n,const hasher& hf,const key_equal& eql):rep(n,hf,eql){}



    template<class InputIterator>
    hash_map(InputIterator first,InputIterator last):rep(100,hasher(),key_equal()){
        rep.insert_unique(first,last);
    }
    template<class InputIterator>
    hash_map(InputIterator first,InputIterator last,size_type n):rep(n,hasher(),key_equal()){
        rep.insert_unique(first,last);
    }
//,const key_equal& eql
    template<class InputIterator>
    hash_map(InputIterator first,InputIterator last,size_type n,const hasher& hf):rep(n,hf,key_equal()){
        rep.insert_unique(first,last);
    }

    template<class InputIterator>
    hash_map(InputIterator first,InputIterator last,size_type n,const hasher& hf,const key_equal& eql):rep(n,hf,eql){
        rep.insert_unique(first,last);
    }

    // map(const map<Key,Compare,Alloc>& x):t(x.t){}
    // map<Key,Compare,Alloc>& operator = (const map<Key,Compare,Alloc>& x){
    //     t.xt;
    //     return *this;
    // }

    // key_compare key_comp() const{return t.key_comp();}
    // value_compare value_comp() const{return t.key_comp();}
    iterator begin() const{return rep.begin();}
    iterator end() const{return rep.end();}
    reverse_iterator rbegin() const {return t.rbegin();}
    reverse_iterator rend() const{return t.rend();}
    bool empty(){return rep.empty();}
    size_type size() const{return rep.size();}
    size_type max_size() const{return rep.max_size();}

    friend bool operator==__STL_NULL_TMPL_ARGS(const hash_map&,const hash_map&);
    void swap(hash_map& x){t.swap(x.rep);}

    
    pair<iterator,bool> insert(const value_type& x){
        pair<typename ht::iterator,bool> p = rep.insert_unique(x);
        return pair<iterator,bool>(p.first,p.second);
    }

    // iterator insert(iterator pos,const value_type& x){
    //     typedef typename rep_type::iterator rep_iterator;
    //     return t.insert_unique((rep_iterator&)pos,x);
    // }

    template<class InputIterator>
    void insert(InputIterator first,InputIterator last){
        rep.insert_unique(first,last);
    }

    pair<iterator,bool> insert_noresize(const value_type& x){
      pair<typename ht::iterator,bool> p = rep.insert_unique_noresize(x);
        return pair<iterator,bool>(p.first,p.second);  
    }
    T& operator[](const key_type& key){
        return rep.find_or_insert(value_type(key,T()).second;
    }
    size_type erase(const key_type &key){
        
        return rep.erase(key);
    }



    void erase(iterator it){
         rep.erase(it);
    }

    void erase(iterator first,iterator last){
        rep.erase(first,last);
    }

    void clear(){
        rep.clear();
    }

    iterator find(const key_type& x)const{return rep.find(x);}
    // size_type count(const key_type& x)const{return rep.count(x);}
    // iterator lower_bound(const key)type& x)const{
    //     return t.lower_bound(x);
    // }

    iterator upper_bound(const key_type& x)const{
        return t.upper_bopund(x);
    }

    pair<iterator,iterator> equal_range(const key_type& x)const{
        return rep.equal_range(x);
    }

    public:
    void resize(size_type hint){rep.resize(hint);}
    size_type bucket_count() const {return rep.bucket_count();}
    size_type max_bucket_count() const{return rep.max_bucket_count();}
    size_type elems_in_bucket(size_type n)const{
        return rep.elems_in_bucket(n);    }

    // friend bool operator == __STLNUKK_TMPL_ARGS(const map&,const base&);
    // friend bool operator <  __STLNUKK_TMPL_ARGS(const map&,const base&);   
};
template <class Value,class HashFcn = hash<Value>,class EqualKey = equal_tp<Value>,class Alloc = alloc>
bool operator==__STL_NULL_TMPL_ARGS(const hash_map&,const hash_map&){
    return x.rep == y.rep;
// }
// template <class Key,class Compare = less<Key>,class Alloc = alloc>
// bool operator< __STLNUKK_TMPL_ARGS(const map<Key,Compare,Alloc>& x,const basemap<Key,Compare,Alloc>& y){
//     return x.t <==> y.t;
}