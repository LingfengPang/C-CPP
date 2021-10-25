template <class Predicate>
class unary_negate:public unary_function<typename Predicate::argument,bool>{
    protected:
    Predicate pred;
    public:
    explicit unary_negate(const Predicate& x):pred(x){}
    bool operator()(const typename Predicate::argument_type& x) const{
        return !pred(x);
    }
};

template <class Predicate>
inline unary_negate<Predicate> not1(const Predicate& pred){
    return unary_negate<Predicate>(pred);
}

template <class Predicate>
class binary_negate:public unary_function<typename Predicate::first_argument_type,typename Predicate::second_argument_type,bool>{
    protected:
    Predicate pred;
    public:
    explicit binary_negate(const Predicate& x):pred(x){}
    bool operator()(const typename Predicate::argument_type& x,const typename Predicate::argument_type& y) const{
        return !pred(x,y);
    }
};

template <class Predicate>
inline binary_negate<Predicate> not2(const Predicate& pred){
    return binary_negate<Predicate>(pred);
}


template <class OPeration>
class binder1st:public unary_function<typename Operation::second_argument_type,typename Operation::result_type>{
    OPeration op;
    typename Operation::first_argument_type value;
    public:
    binder1st(const OPeration& x,const typename Operation::first_argument_type y):op(x),value(y){}
    typename Operation::result_type operator()(const typename Operation::second_argument_type& y) const{
        return op(value,x);
    }
};

template <class OPeration,class T>
inline binder1st<OPeration> bind1st(const  OPeration &op,const T& x){
    typedef typename Operation::first_argument_type arg1_type;
    return binder1st<operation>(op,arg1_type(x));
}

template <class OPeration>
class binder2nd:public unary_function<typename Operation::first_argument_type,typename Operation::result_type>{
    OPeration op;
    typename Operation::second_argument_type value;
    public:
    binder1st(const OPeration& x,const typename Operation::second_argument_type y):op(x),value(y){}
    typename Operation::result_type operator()(const typename Operation::first_argument_type& y) const{
        return op(x,value);
    }
};

template <class OPeration,class T>
inline binder2nd<OPeration> bind1st(const  OPeration &op,const T& x){
    typedef typename Operation::second_argument_type arg2_type;
    return binder2nd<operation>(op,arg2_type(x));
}

template <class Operation1,class Operation2>
class unary_compose:public unary_function<typename Operation2::argument_type.typename Operation1::result_type>{
    protected:
    Operation1 op1;
    Operation2 op2;
    public:
    unary_compose(const Operation1& x,const Operation2& y):op1(x),op2(y){}
    typename Operation1::result_type operator()(const typename Operation2::argument_type& x)const{
        return op1(op2(x));
    }
};

template <class Operation1,class Operation2>
inline unary_compose<Operation1,Operation2>
compose1(const Operation1& op1,const Operation2& op2){
    return unary_compose<Operation1,Operation2>(op1,op2);
}


template <class Operation1,class Operation2,class Operation3>
class binary_compose:public unary_function<typename Operation2::argument_type.typename Operation1::result_type>{
    protected:
    Operation1 op1;
    Operation2 op2;
    Operation3 op3;
    public:
    binary_compose(const Operation1& x,const Operation2& y,const Operation3& z):op1(x),op2(y),op(z){}
    typename Operation1::result_type;
    typename Operation1::result_type operator()(const typename Operation2::argument_type& x)const{
        return op1(op2(x),op3(z));
    }
};

template <class Operation1,class Operation2,class Operation3>
inline binary_compose<Operation1,Operation2,Operation3>
compose2(const Operation1& op1,const Operation2& op2){
    return binary_compose<Operation1,Operation2>(op1,op2,op3);
}

template<class Arg,class Result>
class pointer_to_unary_funtion:public unary_function<Arg,Result>{
    protected:
        Result (*ptr)(Arg);
    public:
        pointer_to_unary_funtion(){};
        explicit pointer_to_unary_funtion(Result (*x)(Arg)):ptr(x){}
        ptr_fun(Result (*x)(Arg)){
        Result pointer_to_unary_funtion<Arg,Result>(x);}
};

template<class Arg1,class Arg2,class Result>
class pointer_to_binary_funtion:public binary_function<Arg1,Arg2,Result>{
    protected:
        Result (*ptr)(Arg1,Arg2);
    public:
        pointer_to_binary_funtion(){};
        explicit pointer_to_binary_funtion(Result (*x)(Arg1,Arg2)):ptr(x){}
        ptr_fun(Result (*x)(Arg1,Arg2)){
        Result pointer_to_binary_funtion<Arg1,Arg2,Result>(x);
        }
};