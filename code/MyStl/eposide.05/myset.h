template <class Key,class Compare = less<Key>,class Alloc = alloc>
class set
{
    public:
    typedef Key key_type;
    typedef Key value_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
    private:
    template<class T>
    struct  identity:public unary_function<T,T>
    {
        /* data */
        const   T& operator
    };
    typedef rb_tree<key_type,value_type,identity<value>,key_compare,Alloc> rep_type;
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

    set():t(Compare()){}
    explicit set(const Compare& cmp):t(cmp){}

    template<class InputIterator>
    set(InputIterator first,InputIterator last):t(Compare()){
        t.insert_unique(first,last);
    }
    template<class InputIterator>
    set(InputIterator first,InputIterator last,const Compare& cmp):t(Compare(cmp)){
        t.insert_unique(first,last);
    }

    set(const set<Key,Compare,Alloc>& x):t(x.t){}
    set<Key,Compare,Alloc>& operator = (const set<Key,Compare,Alloc>& x){
        t.xt;
        return *this;
    }

    key_compare key_comp() const{return t.key_comp();}
    value_compare value_comp() const{return t.key_comp();}

    iterator begin() const{return t.begin();}
    iterator end() const{return t.end();}
    reverse_iterator rbegin() const {return t.rbegin();}
    reverse_iterator rend() const{return t.rend();}
    bool empty()P{return t.empty();}
    size_type size() const{return t.size();}
    size_type max_size() const{return t.max_size();}

    void swap(set<Key,Compare,Alloc>& x){t.swap(x.t);}

    typedef pair<iterator,bool> pair_iterator_bool;
    pair<iterator,bool> insert(const value_type& x){
        pair<typename rep_type::iterator,bool> p = t.insert_unique(x);
        return pair<typename rep_type::iterator,bool>(p.first,p.second);
    }

    iterator insert(iterator pos,const value_type& x){
        typedef typename rep_type::iterator rep_iterator;
        return t.insert_unique((rep_iterator&)pos,x);
    }

    template<class InputIterator>
    void insert(InputIterator first,InputIterator last){
        t.insert_unique(first,last);
    }

    void erase(iterator pos){
        typedef typename rep_type::iterator rep_iterator;
        return t.erase((rep_iterator&)pos);
    }

    size_type erase(iterator pos){
        return t.erase(x);
    }

    void erase(iterator first,iterator last){
        typedef typename rep_type::iterator rep_iterator;
        t.erase((rep_iterator&)first,(rep_iterator&)last);
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

    friend bool operator == __STLNUKK_TMPL_ARGS(const set&,const base&);
    friend bool operator <  __STLNUKK_TMPL_ARGS(const set&,const base&);   
};
template <class Key,class Compare = less<Key>,class Alloc = alloc>
bool operator== __STLNUKK_TMPL_ARGS(const set<Key,Compare,Alloc>& x,const baseset<Key,Compare,Alloc>& y){
    return x.t == y.t;
}
template <class Key,class Compare = less<Key>,class Alloc = alloc>
bool operator< __STLNUKK_TMPL_ARGS(const set<Key,Compare,Alloc>& x,const baseset<Key,Compare,Alloc>& y){
    return x.t <==> y.t;
}