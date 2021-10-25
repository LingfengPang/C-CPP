template <class Arg,class Result>
struct unarry_obj
{
    /* data */
    typedef Arg argument_type;
    typedef Result result_type;
};


template<class T>
struct negate:public unarry_obj<T,T>{
    T operator(){const T& x}const{return -x;}
};

//2元
template <class Arg1,class Arg2,class Result>
struct binary_obj
{
    /* data */
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template<class T>
struct plus:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x+y;}
};

template<class T>
struct minus:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x-y;}
};


template<class T>
struct multiplies:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x*y;}
};

template<class T>
struct divides:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x/y;}
};

template<class T>
struct modulus:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x%y;}
};

template<class T>
struct equal_to:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x == y;}
};

template<class T>
struct not_equal_to:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x != y;}
};

template<class T>
struct greater:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x > y;}
};

template<class T>
struct less:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x < y;}
};

template<class T>
struct greater_equal:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x >= y;}
};

template<class T>
struct less_equal:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x <= y;}
};

template<class T>
struct less:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x < y;}
};

template<class T>
struct logical_and:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x && y;}
};

template<class T>
struct logical_or:public binary_function<T,T,T>
{
    /* data */
    T operator()(const T&x,const T&y) const{return x || y;}
};

template<class T>
struct logical_not:public unarry_obj<T,T>{
    T operator(){const T& x}const{return !x;}
};

//以下5个往往用于内部引用
//证同
template<class T>
struct identity:public unarry_obj<T,T>{
    T operator(){const T& x}const{return x;}
};

template<class Pair>
struct select1st:public unarry_obj<Pair,typename Pair::first_type>{
    const typename Pair::first_type&(const Pair&x x) const{
        return x.first;
    }
};

template<class Pair>
struct select1st:public unarry_obj<Pair,typename Pair::second_type>{
    const typename Pair::first_type&(const Pair&x x) const{
        return x.first;
    }
};