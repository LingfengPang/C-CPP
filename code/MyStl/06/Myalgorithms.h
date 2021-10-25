template<class T>
T* find(T* begin,T* end,const T& value){
    while(begin != end&& *begin!=value){
        ++begin;
    }
    return begin;
}

template<class Iterator ,class T>
Iterator find(Iterator begin,Iterator end,const T& value){
    while(begin != end&& *begin!=value){
        ++begin;
    }
    return begin;
}

//数值算法
//头文件在<numeric>
template<class InputIterator,class T>
T accumulate(InputIterator first,InputIterator last,T init){
    for(;first!=last;first++){
        init = init+*first;
    }
    return init;
}

//执行一个二元caozuo
template<class InputIterator,class T,class BinartOperation>
T accumulate(InputIterator first,InputIterator last,T init,BinartOperation binory_op){
    for(;first!=last;first++){
        init = binory_op(init,*first);
    }
    return init;
}

template<class InputIterator,class OutputIterator>
OutputIterator adjacent_difference(InputIterator first,InputIterator last,OutputIterator result){
    if(first == last) return result;
    *result = *first;
    return __adjacent_difference(first,last,result,value_type(first))
}

template<class InputIterator,class OutputIterator,class T>
OutputIterator __adjacent_difference(InputIterator first,InputIterator last,OutputIterator result,T* value){
    T value = *first;
    while(++first != last){
        T tmp = *first;
        *++result = tmp - value;
        value = tmp;
    }
    return ++result;
}


template<class InputIterator,class OutputIterator,class BinartOperation>
OutputIterator adjacent_difference(InputIterator first,InputIterator last,OutputIterator result,BinartOperation binary_op){
    if(first == last) return result;
    *result = *first;
    return __adjacent_difference(first,last,result,value_type(first),BinartOperation binary_op);
}

template<class InputIterator,class OutputIterator,class T,class BinartOperation>
OutputIterator __adjacent_difference(InputIterator first,InputIterator last,OutputIterator result,T* value,BinartOperation binary_op){
    T value = *first;
    while(++first != last){
        T tmp = *first;
        *++result = binary_op(tmp,value);
        value = tmp;
    }
    return ++result;
}


template<class InputIterator1,class InputIterator2,class T>
T inner_product(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,T init){
    for(;first1 != last1; ++first1,++first2){
        init = init +(*first1 * *first2);
    }
    return init;
}

template<class InputIterator1,class InputIterator2,class T,class BinaryOperation1,class BinaryOperation2>
T inner_product(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,T init,BinaryOperation1 binary_op1,BinaryOperation1 binaty_op2){
    for(;first1 != last1; ++first1,++first2){
        init = binary_op1(init,  binary_op1(*first1,*first2));
    }
    return init;
}

template <class InputIterator,class OutputIterator>
OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result){
    if(first == last) return result;
    return __partial_sum(first,last,result,value_type(first));
}

template <class InputIterator,class OutputIterator,class T>
OutputIterator __partial_sum(InputIterator first,InputIterator last,OutputIterator result,T*){
    T value = *first;
    while(++first!=last){
        value = value+*first;
        *++result = value;
    }
    return ++result;
}


template <class InputIterator,class OutputIterator,class BinartOperation>
OutputIterator partial_sum(InputIterator first,InputIterator last,OutputIterator result,BinartOperation op){
    if(first == last) return result;
    return __partial_sum(first,last,result,value_type(first),op);
}

template <class InputIterator,class OutputIterator,class T,class BinartOperation>
OutputIterator __partial_sum(InputIterator first,InputIterator last,OutputIterator result,T*,BinartOperation op){
    T value = *first;
    while(++first!=last){
        value = op(value,*first);
        *++result = value;
    }
    return ++result;
}

template<class T,class Integer>
inline T power(T x,Integer n){
    return power(x,n,multiplies<T>());
}

template<class T,class Integer,class OP>
T power(T x,Integer n,OP op){
    if(n == 0)
        return identity_element(op);
    else{
        while((n&1)==0){
            n>>=1;
            x = op(x,x);
        }
        T result = x;
        n >>= 1;
        while(n!=0){
            x = op(x,x);
            if((n&1)!=0)
                result = op(result,x);
            n >>= 1;
        }
        return result; 
    }
}

template<class ForwardIterator,class T>
void iota(ForwardIterator first,ForwardIterator last,T value){
    while(first != last) *first++ = value++
}

//<stl_algobase.h> <stl_alog.h>

template<class InputIterator1,class InputIterator2>
inline bool equal(InputIterator1 first1,InputIterator2 last1,InputIterator2 first2){
    for(;first1 != last1;++first1,++first2){
        if(*first1!=first2)
        return false;
    }
    return true;
}

template<class InputIterator1,class InputIterator2,class Pre>
inline bool equal(InputIterator1 first1,InputIterator2 last1,InputIterator2 first2,Pre pred){
    for(;first1 != last;++first1,++first2){
        if(pred(*first1,*first2))
        return false;
    }
    return true;
}

template<class ForwardIterator,class T>
void fill(ForwardIterator first,ForwardIterator last,const T& value){
    for(;first!=last;++first)
        *first = value;
}

template<class ForwardIterator,class T,class Size>
ForwardIterator fill_n(ForwardIterator first,ForwardIterator last,const T& value,Size n){
    for(;n>0;n--,++first)
        *first = value;
    return first;
}

template<class ForwardIterator1,class ForwardIterator2>
inline void iter_swap(ForwardIterator1 a,ForwardIterator2 b){
    __iter_swap(a,b,value_type(a));
}

template<class ForwardIterator1,class ForwardIterator2,class T>
inline void __iter_swap(ForwardIterator1 a,ForwardIterator2 b,T*){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class InputIterator1,class InputIterator2>
bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2){
    for(;first1!=last1 && first2!= last2;++first1,++first2){
        for(*first1 < *first2)
            return true;
        for(*first2<*first1)
            return false;
    }
    return first1 == last1 && first2!=last2
}

template <class InputIterator1,class InputIterator2,class Compare>
bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,Compare cmp){
    for(;first1!=last1 && first2!= last2;++first1,++first2){
        for(cmp(*first1,*first2))
            return true;
        for(cmp(*first2,*first1))
            return false;
    }
    return first1 == last1 && first2!=last2
}
//争对原生指针的特化版本
bool lexicographical_compare(const unsigned char* first1,const unsigned char* last1,const unsigned char* first2,const unsigned char* last2){
    const size_t len1 = last1-first1;
    const size_t len2 = last2-first1;
    const int result = memcmp(first1,first2,min(len1,len2));
    return result != 0?result<0:len1<len2;
}

template <class T>
inline const T& max(const T &a,const T &b){
    return a<b?b:a;
}

template <class T,class Compare>
inline const T& max(const T &a,const T &b,Compare cmp){
    return cmp(a,b)?b:a;
}

//min差不多不写了
template <class InputIterator1,class InputIterator2>
pair<InputIterator1,InputIterator2> mismatch(InputIterator1 first1,
                                            InputIterator1 last1,InputIterator2 last2){
    while(*first1!=*last1&&*first1 == *first2){
        ++first1;
        ++first2;
    }
    return pair<InputIterator1,InputIterator2>(first1,first2);
                                            }                                            

template <class InputIterator1,class InputIterator2,class BinaryPredicate>
pair<InputIterator1,InputIterator2> mismatch(InputIterator1 first1,
                                            InputIterator1 last1,InputIterator2 last2,BinaryPredicate binary_pred){
    while(*first1!=*last1&&binary_pred(*first1,*first2)){
        ++first1;
        ++first2;
    }
    return pair<InputIterator1,InputIterator2>(first1,first2);
                                            }   

template <class T>
inline void swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

//copy函数
template <class InputIterator,class OutputIterator>
inline OutputIterator copy(InputIterator first1,InputIterator last1,OutputIterator result){
    return __copy_dispatch<InputIterator,OutputIterator>()(first1,last1,result);
}

//特化版本
inline char* copy(const char* first,const char* last,char *result){
    memmove(result,first,last-first);
    return result+(last-first);
}
//特化版本
inline wchar_t* copy(const char* first,const char* last,char *result){
    memmove(result,first,sizeof(wchar_t)*(last-first));
    return result+(last-first);
}

template <class InputIterator,class OutputIterator>
struct __copy_dispatch
{
    /* data */
        OutputIterator operator()(InputIterator first,InputIterator last,OutputIterator result){
            return __copy(first,last,result,iterator_category(first));
        }
};
//偏特化版本
template <class T>
struct __copy_dispatch<T*,T*>
{
    /* data */
        OutputIterator operator()(T* first,T* last,T* result){
            typedef typename __type_traits<T>::has_trivial_assignment_operator t;
            return __copy_t(first,last,result,t());
        }
};

template <class T>
struct __copy_dispatch<const T*,T*>
{
    /* data */
        OutputIterator operator()(T* first,T* last,T* result){
            typedef typename __type_traits<T>::has_trivial_assignment_operator t;
            return __copy_t(first,last,result,t());
        }
};

template <class InputIterator,class OutputIterator>
inline OutputIterator __copy(InputIterator first,InputIterator last,OutputIterator result,input_iterator_tag){
    for(;first!=last;++result,++first)
        *result = *first;
    return result;
}

template <class RandomAcessIterator,class OutputIterator>
inline OutputIterator __copy(RandomAcessIterator first,RandomAcessIterator last,OutputIterator result,random_access_iterator_tag){
    return __copy_d(first,last,result,distance_type(first));
}

template <class RandomAcessIteratorr,class OutputIterator>
inline OutputIterator __copy_d(RandomAcessIterator first,RandomAcessIterator last,OutputIterator result,Distance*){
    for(Distance n = last - first;n>0;--n,++result,++first)
        *result = *first;
    return result;
}


template <class T>
inline T* __copy_t(const T *first,const T *last,T *result,__true_type){
    memmove(result,first,sizeof(T)*(last-first));
    return result + (last-first);
}

template <class T>
inline T* __copy_t(const T *first,const T *last,T *result,__false_type){
    return __copy_d(first,last,result,(ptrdiff_t*)0);
}

