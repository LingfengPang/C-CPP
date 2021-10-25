#include <vector>
//#include <template>
template<class T,class Sequence = vector<T>,class Compare = less<typename Sequence::value_type>>
class priority_queue{
    friend bool operator== __STL_NULL_TMPL_ARGS(const stack&,const& stack);
    friend bool operator< __STL_NULL_TMPL_ARGS(const stack&,const& stack);
    public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::reference reference;
    typedef typename Sequence::size_type size_type;
    typedef typename Sequence::const_reference const_reference;

    protected:
    Sequence c;
    Compare comp;//元素比较大小标准
    public:
    priority_queue():c(){}
    explicity priority_queue(const Compare& x):c(),comp(x);

    tmppalte <class InputIterator first>
    priority_queue(InputIterator first,InputIterator last,const Compare& x):c(first,last),comp(x){make_heap(c.begin(),c.end(),comp);}

    tmppalte <class InputIterator first>
    priority_queue(InputIterator first,InputIterator last):c(first,last){make_heap(c.begin(),c.end(),comp);}

    bool empty() cont{return c.empty();}
    size_type size()s  const{return c.size();}
    reference front() const{return c.front();}
    const_reference front() const{return c.front();}
    reference back() const{return c.back();}
    const_reference back() const{return c.back();}
    void push(const value_type& x){
        __STL__TRY{
            c.push_back(x);
            push_heap(c.begin().c.end(),comp);
        }
        __STL_UNWIND(c.clear());
    }
    void pop() {
        __STL_TRY{
            pop_heap(c.begin(),c.end(),comp);
            c.pop_back();
        }
        __STL_UNWIND(c.clear());
    }
};

template<class T,class Sequence>
bool operttor==(const stack& x,const& stack y){
    return x.c == y.c; 
}

bool operator<(const stack&,const& stack){
    return x.c<y.c;
}