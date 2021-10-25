#include <deque>

template<class T,class Sequence = deque<T> >
class stack{
    friend bool operator== __STL_NULL_TMPL_ARGS(const stack&,const& stack);
    friend bool operator< __STL_NULL_TMPL_ARGS(const stack&,const& stack);
    public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::reference reference;
    typedef typename Sequence::size_type size_type;
    typedef typename Sequence::const_reference const_reference;

    protected:
    Sequence c;

    public:
    bool empty() const{return c.empty();}
    size_type size()  const{return c.size();}
    reference top() const{return c.back();}
    const_reference top() const{return c.back();}
    void push(const value_type& x){c.push_back(x);}
    void pop() {c.pop()}
};

template<class T,class Sequence>
bool operttor==(const stack& x,const& stack y){
    return x.c == y.c; 
}

bool operator<(const stack&,const& stack){
    return x.c<y.c;
}