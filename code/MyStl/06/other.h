template <class ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first,ForwardIterator last){
    if(first == last) return;
    ForwardIterator next = first;
    while(++next!=last){
        if(*first!=*next) return first;
        first = next;
    }
    return last;
}

template <class ForwardIterator,class BinartPredicate>
ForwardIterator adjacent_find(ForwardIterator first,ForwardIterator last,BinartPredicate binary_pred){
    if(first == last) return;
    ForwardIterator next = first;
    while(++next!=last){
        if(binary_pred(*first,*last)) return first;
        first = next;
    }
    return last;
}

template <class InputIterator,class T,class Size>
void count(InputIterator first,InputIterator last,const T& value,Size &n){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for(;first != last;++first){
        if(*first == value)
            ++n;
        return n;
    }
}

template <class InputIterator,class Predicate>
typename iterator_traits<InputIterator>::difference_type count_if(
    InputIterator first,InputIterator last,Predicate pred
){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for(;first != last;++first){
        if(pred(*first))
            ++n;
        return n;
    }
}

template <class InputIterator,class T>
InputIterator find(InputIterator first,InputIterator last,const T& value){
    while(first != last&&*first != value)
        ++first;
        return first;
}
template <class InputIterator,class T,class Pred>
InputIterator find(InputIterator first,InputIterator last,Pred pred){
    while(first != last&&pred(*first))
        ++first;
        return first;
}

template <class ForwardIterator1,class ForwardIterator2>
inline ForwardIterator1 find_end(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2){

    typedef typename iterator_traits<ForwardIterator1>::iterator_category category1;
    typedef typename iterator_traits<ForwardIterator2>::iterator_category category2;
    return __find_end(first1,last1,first2,last2,category1(),category2());

}
template <class ForwardIterator1,class ForwardIterator2>
ForwardIterator1 __find_end(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2,
forward_iterator_tag,forward_iterator_tag){
    if(first2 == last2)
        return last1;
    else{
        ForwardIterator1 result =last1;
        while(1){
            //查找首次出现的地点
            ForwardIterator1 new_result = search(first1,last1,first2,last2);
            if(new_result == last1)
                return result;
            else{
                result = new_result;
                first1 = new_result;
                ++first1;
            }
        }
    }
}

template <class BidrectionalIterator1,class BidrectionalIterator2>
BidrectionalIterator1 __find_end(BidrectionalIterator1 first1,BidrectionalIterator1 last1,BidrectionalIterator2 first2,BidrectionalIterator2 last2,
bidirectional_iterator_tag,bidirectional_iterator_tag){
    typedef reverse_iterator<BidrectionalIterator1> reviter1;
    typedef reverse_iterator<BidrectionalIterator2> reviter2;

    reviter1 rlast1(first1);
    reviter2 rlast2(first2);

    reviter1 rresult = serach(reviter1(last1),rlast1,reviter2(last2),rlast2);
    if(rresult == rlast1)
        return last1;
    else{
        BidrectionalIterator result = rresult.base();//转回正常的迭代器
        advance(result,-distance(first2,last2));//调整回到子序列的开头
        return result;
    }
}

template <class InputIterator,class ForwardIterator>
InputIterator find_first_of(InputIterator first1,InputIterator last1,ForwardIterator first2,ForwardIterator last2){
    for(;first1 != last1;++first1){
        for(ForwardIterator iter = first2;iter != last2;++iter){
            if(*first1 == *iter)
                return first1;
            
        }
    }
    return last1;
}

template <class InputIterator,class ForwardIterator,class BinaryPredicate>
InputIterator find_first_of(InputIterator first1,InputIterator last1,ForwardIterator first2,ForwardIterator last2，BinaryPredicate pred){
    for(;first1 != last1;++first1){
        for(ForwardIterator iter = first2;iter != last2;++iter){
            if(pred(*first1 , *iter))
                return first1;
            
        }
    }
    return last1;
}

template <class InpuIterator,class Function>
Function for_each(InpuIterator first,InpuIterator last,Function f){
    for (;first!= last;++first)
    {
        /* code */
        f(*first);
    }
    return f;
}

template <class InpuIterator,class Generator>
void generate(InpuIterator first,InpuIterator last,Generator g){
    for (;first!= last;++first)
    {
        /* code */
        *first = g()
    }
    
}

template <class InpuIterator,class Generator>
void generate_n(InpuIterator first,InpuIterator last,Generator g){
    for (;n>0;++first,--n)
    {
        /* code */
        *first = g()
    }
    return first;
}
//S1是否包含S2所有元素
template <class InputIterator1,class InputIterator2>
bool includes(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2){
    while(first1 != last1&& first2 != last2){
        if(*first2 < *first1)
            return false;
        else if(*first1 < *first2)
            ++first1;
        else{
            ++first1;
            ++first2;
        }

    }
    return first2 == last2;
}

template <class InputIterator1,class InputIterator2，class Compare>
bool includes(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,Compare cmp){
    while(first1 != last1&& first2 != last2){
        if(cmp(*first2 , *first1))
            return false;
        else if(cmp(*first1 , *first2))
            ++first1;
        else{
            ++first1;
            ++first2;
        }

    }
    return first2 == last2;
}

template<class ForwardIterator>
ForwardIterator max_element(ForwardIterator first,ForwardIterator last){
    if(first == last) return first;
    ForwardIterator result = first;
    while(++first!=last)
        if(*result < *first) result = first;
    return result;
}

template<class ForwardIterator,class Compare>
ForwardIterator max_element(ForwardIterator first,ForwardIterator last,Compare cmp){
    if(first == last) return first;
    ForwardIterator result = first;
    while(++first!=last)
        if(cmp(*result , *first)) result = first;
    return result;
}

template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator merge(InputIterator1 first1,InputIterator2 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result){
    while(first1!=last1&&first2!=last2){
        if(*first2 < *first1){
        *result = *first2;
        ++first2;
        }
    else{
        *result = *first1;
        ++first1;
        }
    ++result;
}
    return copy(first2,last2,copy(first1，last1,result));
}


template<class InputIterator1,class InputIterator2,class OutputIterator,class Compare>
OutputIterator merge(InputIterator1 first1,InputIterator2 last1,InputIterator2 first2,InputIterator2 last2,OutputIterator result,Compare cmp){
    while(first1!=last1&&first2!=last2){
        if(cmp(*first2 , *first1)){
        *result = *first2;
        ++first2;
        }
    else{
        *result = *first1;
        ++first1;
        }
    ++result;
}
    return copy(first2,last2,copy(first1，last1,result));
}

template<class BidirectionalIterator,class Predicate>
BidirectionalIterator partition(BidirectionalIterator first,BidirectionalIterator last,Predicate pred){
    while(true){
        while(1)
        if(first == last){
            return first;
        }
        else if(pred(*first))
            ++first;
        else
            break;
        --last;
        while (1)
        {
            /* code */
            if(first == last)
                return first;
            else if(!pred(*last))
                --last;
            else
                break;
            }
            iter_swap(first,last);
            ++first;
        
        
    }
}

template <class ForwardIterator,class T>
ForwardIterator remove(ForwardIterator first,ForwardIterator last,const T& value){
    first = find(first,last,value);
    ForwardIterator next = first;
    return first == last?first:remove_copy(++next,last,first,value);
}

template<class InputIterator,class OutputIterator,class T>
OutputIterator remove_copy(InputIterator first,InputIterator last,OutputIterator result,const T& value){
    for(;first!=last;++first)
    if(*first != value){
        *result = *first;
        ++result;
    }
    return result;
}

template <class ForwardIterator,class Pred>
ForwardIterator remove(ForwardIterator first,ForwardIterator last,Pred pred){
    first = find_if(first,last,pred);
    ForwardIterator next = first;
    return first == last?first:remove_copy_if(++next,last,first,pred);
}

template<class InputIterator,class OutputIterator,class T>
OutputIterator remove_copy_if(InputIterator first,InputIterator last,OutputIterator result,T pred){
    for(;first!=last;++first)
    if(!pred(*first )){
        *result = *first;
        ++result;
    }
    return result;
}

template<class ForwardIterator,class T>
void replace(ForwardIterator first,ForwardIterator last,const T& old_value,const T& new_vale){
    for(;first!= last;++first)
        if(*first == old_value) *first = new_vale;
}

template<class ForwardIterator,class OutputIterator,class T>
OutputIterator replace_copy(ForwardIterator first,ForwardIterator last,const T& old_value,const T& new_vale){
    for(;first!= last;++first)
        *result = *first == old_value?new_vale:*first;
    return result;
}

template<class ForwardIterator,class Pred,class T>
void replace_if(ForwardIterator first,ForwardIterator last,Pred pred,const T& new_vale){
    for(;first!= last;++first)
        if(pred(*first))  *first = new_vale;
    return result;
}

template<class ForwardIterator,class OutputIterator,class Pred,class T>
OutputIterator replace_copy_if(ForwardIterator first,ForwardIterator last,const T& old_value,const T& new_vale){
    for(;first!= last;++first)
        *result = pred(*first?new_vale:*first;
    return result;
}

template<class BidirectionalIterator>
inline void reverse(BidirectionalIterator  first,BidirectionalIterator last){
    __reverse(first,last,iterator_category(first));
}

template<class BidirectionalIterator>
void __reverse(BidirectionalIterator  first,BidirectionalIterator last,bidirectional_iterator_tag){
    while(1){
        if(first == last||first == --last)
            return;
        else
            iter_swap(first++,last);
    }
}

template<class andomAccessIterator>
void __reverse(andomAccessIterator  first,andomAccessIterator last,random_access_iterator_tag){
    while(first<last) iter_swap(first++,--last);
}

template<class  BidirectionalIterator,class OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first,BidirectionalIterator last,OutputIterator result){
    while(first != last){
        --last;
        *result = *last;
        ++result;
    }
    return result;
}

template <class ForwardIterator>
inline void rotate(ForwardIterator first,ForwardIterator middle,ForwardIterator last){
    if(first == middle||middle == last) return;
    __rotate(first,middle,last,distance_type(first),iterator_category(first));
}

template <class ForwardIterator,class Distance>
void __rotate(ForwardIterator first,ForwardIterator middle,ForwardIterator last,Distance*, forward_iterator_tag){
    for(ForwardIterator i = middle;;){
        iter_swap(first,i);
        ++first;
        ++i;
        if(first == middle){
            if(i == last)
                return;
            middle = i
        }
        else if(i == last)
            i = middle;
    }
}

template <class Bidirectional,class Distance>
void __rotate(Bidirectional first,Bidirectional middle,Bidirectional last,Distance*, bidirectionIterator_iterator_tag){
  //  for(ForwardIterator i = middle;;){
        reverse(first,middle);
        reverse(middle,last);
        reverse(first,last);
   // }
}

template <class RandomAccessIterator,class Distance>
void __rotate(RandomAccessIterator first,RandomAccessIterator middle,RandomAccessIterator last,Distance*, randow_access_iterator_tag){
    //for(ForwardIterator i = middle;;){
        Distance n = __gcd(last-first,middle - first);
        while(n--)
        __rotete_cycle(first,last,first+n,middle-first,value_type(first));
    //}
}

template<class EuclideanRingElement>
EuclideanRingElement __gcd(EuclideanRingElement m,EuclideanRingElement n){
    while(n!=0){
        EuclideanRingElement t = m%n;
        m = n;
        n = t;
    }
    return m;
}

template <class RandomAccessIterator,class Distance,class T>
void __rotate_cycle(RandomAccessIterator first,RandomAccessIterator last,RandomAccessIterator initial,Distance shift, T*){
    //for(ForwardIterator i = middle;;){
    T value = *initial;
    RandomAccessIterator ptr1 = initial;
    RandomAccessIterator ptr2 = ptr1+shift;
    while(ptr2 != initial){
        *ptr1 = *ptr2;
        ptr1 = ptr2;
        if(last - ptr2>shift)
            ptr2+=shift;
        else
            ptr2 = first+(shift-(last-ptr2));
    }
    *ptr1 = value;
}

template <class ForwardIterator,class OutputIterator>
OutputIterator rotate_copy(ForwardIterator first,ForwardIterator middle,ForwardIterator last,OutputIterator result){
    return copy(first,middle,copy(middle,last,result));
}

template<class ForwardIterator1,class ForwardIterator2>
inline ForwardIterator1 search(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2){
    return __search(first1,last1,first2,last2,distance_type(first1),distance_type(first2));
}
//序列S1查找序列S2首次出现的位置
template<class ForwardIterator1,class ForwardIterator2,class Distance1,class Distance2>
ForwardIterator1 __search(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2,ForwardIterator2 last2,Distance1*,Distance2*){
    Distance1 d1 = 0;
    distance(first1,last1,d1);
    Distance d2 = 0;
    distance(first2,last2,d2);

    if(d1<d2) return last1;

    ForwardIterator1 current1 = first1;
    ForwardIterator2 current2 = first2;

    while(current2 != last2)
    if(*current1 == *current2){
        ++current1;
        ++current2;
    }
    else{
        if(d1 == d2)
            return last1;
        else{
            current1 = ++first1;
            current2 = first2;
            --d1;
        }
    }
    return first1;
}

template<class ForwardIterator1,class Integer,class T>
ForwardIterator1 __search_n(ForwardIterator1 first,ForwardIterator1 last,Integer count,const T& value){
    if(count<=0)
        return first;
    else{
        first = find(first,last,value);
        while(first!=last){
            Integer n = count-1;
            ForwardIterator i = first;
            ++i;
            while(i!=last&&n!=0&&*i == value){
                ++i;
                --n;
            }
            if(n == 0)
                return first;
            else
                first = find(i,last,value);
        }
        return last;
    }
}

template<class ForwardIterator1,class Integer,class T,class BinaryPredicate>
ForwardIterator1 __search_n(ForwardIterator1 first,ForwardIterator1 last,Integer count,const T& value,BinaryPredicate pred){
    if(count<=0)
        return first;
    else{
        while(first != last){
            if(pred(*first,value))
                break;
            first1++;
        }
        while(first!=last){
            Integer n = count-1;
            ForwardIterator i = first;
            ++i;
            while(i!=last&&n!=0&&pred(*i , value)){
                ++i;
                --n;
            }
            if(n == 0)
                return first;
            else{
                while(i!=last){
                    if(pred(*i,value)) break;
                    ++i;
                }
                first = i;
            }
               // first = find(i,last,value);
        }
        return last;
    }
}

template <class ForwardIterator1,class ForwardIterator2>
ForwardIterator2 swap_range(ForwardIterator1 first1,ForwardIterator1 last1,ForwardIterator2 first2){
    for(;first1 != last1;++first1,++first2)
        iter_swap(first1,first2)
    return first2;
}

template <class InputIterator,class OutputIterator,class UnaryOperation>
OutputIterator transform(InputIterator first,InputIterator last,OutputIterator result,UnaryOperation op){
    for(;first != last;++first,++result){
        *result = op(*first);
    }
    return result;
}

template <class InputIterator,class InputIterator2,class OutputIterator,class BinaryOperation>
OutputIterator transform(InputIterator first1,InputIterator last1,InputIterator2 first2,OutputIterator result,BinaryOperation op){
    for(;first1 != last1;++first1,++result,++first2){
        *result = op(*first1,*first2);
    }
    return result;
}

//移除相邻元素的相同值
template <class ForwardIterator>
ForwardIterator unique(ForwardIterator first,ForwardIterator last){
    first = adjacent_find(first,last);
    return unique_copy(first,last,first);
}

template <class ForwardIterator,class OutputIterator>
ForwardIterator unique_copy(ForwardIterator first,ForwardIterator last,OutputIterator result){
    if(first == last) return result;
    first = adjacent_find(first,last);
    return __unique_copy(first,last,first,iterator_category);
}

template<class InputIterator,class ForwardIterator>
ForwardIterator __unique_copy(InputIterator first,InputIterator last,ForwardIterator result,forward_iterator_tag){
    *result = *first;
    while(++first!=last)
        if(*result != *first) *++result = *first;
    return ++result;
}

template<class InputIterator,class OutputIterator>
OutputIterator __unique_copy(InputIterator first,InputIterator last,OutputIterator result,outiterator_iterator_tag){
    return __unique_copy(first,last,result,value_type(first));
}

template<class InputIterator,class OutputIterator,class T>
OutputIterator __unique_copy(InputIterator first,InputIterator last,OutputIterator result,T*){
    T value = *first;
    *result = value;
    while(++first!= last)
        if(value!=*first){
            value = *first;
            *++result = value;
        }
        return ++result;
}

template<class ForwardIterator,class T>
inline ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T& value){
    return __lower_bound(first,last,value,distance_type(first),iterator_category(first));
}

template<class ForwardIterator,class T,class Compare>
inline ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T& value,Compare cmp){
    return __lower_bound(first,last,value,cmp,distance_type(first),iterator_category(first));
}

template<class ForwardIterator,class T,class Distance>
ForwardIterator __lower_bound(ForwardIterator first,ForwardIterator last,const T& value,Distance* forward_iterator_tag){
    Distance len = 0;
    distance(first,last,len);
    Distance half;
    ForwardIterator middle;

    while(len>0){
        half = len >> 1;
        middle = first;
        advance(middle,half);
        if(*middle < value){
            first = middle;
            ++first;
            len = len - half - 1;
        }
        else{
            len = half;
        }
    }
    return first;
}
//查找第一个不小于value的值
template<class ForwardIterator,class T,class Distance>
ForwardIterator __lower_bound(ForwardIterator first,ForwardIterator last,const T& value,Distance* random_access_iterator_tag){
    Distance len = last-first;
    //distance(first,last,len);
    Distance half;
    ForwardIterator middle;

    while(len>0){
        half = len >> 1;
        //middle = first;
        middle = first + half;
        if(*middle < value){
            first = middle+1;
            ++first;
            len = len - half - 1;
        }
        else{
            len = half;
        }
    }
    return first;
}

//upper_bound懒得写了
//最后一个适合插入的位置
template<class ForwarIterator ,class T>
bool binary(ForwarIterator first,ForwarIterator last,const T& value){
    ForwarIterator i = lower_bound(first,last,value);
    return i!=last &&!(value<*i);
}

template <class BidirectionIterator>
bool next_permutation(BidirectionIterator first,BidirectionIterator last){
    if(first == last) return;
    BidirectionIterator i = first;
    ++i;
    if(i == last) return false;
    i = last;
    --i;
    for(;;){
        BidirectionIterator ii = i;
        --i;
        if(*i < *ii){
            BidirectionIteratorIterator j = last;
            while(!(*i < *--j));
            iter_swap(i,j);
            reverse(ii,last);
            return true;
        }
        if(i == last){
            reverse(first,last);
            return false;
        }
    }
}


template <class BidirectionIterator>
bool next_permutation(BidirectionIterator first,BidirectionIterator last){
    if(first == last) return;
    BidirectionIterator i = first;
    ++i;
    if(i == last) return false;
    i = last;
    --i;
    for(;;){
        BidirectionIterator ii = i;
        --i;
        if(*i < *ii){
            BidirectionIteratorIterator j = last;
            while(!(*i > *--j));
            iter_swap(i,j);
            reverse(ii,last);
            return true;
        }
        if(i == last){
            reverse(first,last);
            return false;
        }
    }
}

template <class RandomAccessIterator>
inline void random_shuffle(RandomAccessIterator first,RandomAccessIterator last){
    __random_shuffle(first,last,distance_type(first));
}

template <class RandomAccessIterator,class Distance>
inline void __random_shuffle(RandomAccessIterator first,RandomAccessIterator last,Distance*){
    //__random_shuffle(first,last,distance_type(first));
    if(first == last) return;
    for(RandomAccessIterator i = first+1;i!=last;++i){
        #ifdef __STL_NO_DRAND48
        iter_swap(i,first+Distance(rand()%((i-first)+1)));
        #else
        iter_swap(i,first+Distance(lrand48()%((i-first)+1)));
        #endif
    }
}

template <class RandomAccessIterator,class RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first,RandomAccessIterator last,RandomAccessIterator& rand){
    if(first == last) return;
    for(RandomAccessIterator i =first+1;i!=last;++i){
        iter_swap(i,first+rand((i-first)+1));
    }
    
}

template<class RandomAccessIterator>
inline void partial_sort(RandomAccessIterator first,RandomAccessIterator middle,RandomAccessIterator last){
    __partial_sort(first,middle,last,value_type(first));
}

template<class RandomAccessIterator,class T>
void __partial_sort(RandomAccessIterator first,RandomAccessIterator middle,RandomAccessIterator last,T*){
    make_heap(first,middle);
    for(RandomAccessIterator i = middle;i<last;++i)
    if(*i < *first)
        __pop_heap(first,middle,i,T(*i),distance_type(first));
    sort_heap(first,middle);
}

template <class RandomAccessIterator>
void __inline_sort(RandomAccessIterator first,RandomAccessIterator last){
    if(first == last) return;
    for(RandomAccessIterator i = first+1;i!=last;++i){
        __liner_insert(first,i,value_type(first));
    }
}

template<class RandomAccessIterator,class T>
inline void __linear_insert(RandomAccessIterator first,RandomAccessIterator last,T*){
    T value = *last;
    if(value < *first){
        copy_backward(first,last,last+1);
        *first = value;
    }
    else
        __ungurded_linear_insert(last,value);
}

template<class RandomAccessIterator,class T>
void ungurded__linear_insert(RandomAccessIterator last,T*){
    RandomAccessIterator next = last;
    --next;
    while(value < *next){
        *last = *next;
        last = next;
        --next;
    }
    *last = value;
}
//三个数的中值
template<class T>
inline const T& __median(const T& a,const T&b,const T& c){
    if(a < b)
        if(b < c)
            return b;
        else if(a < c)
            return c;
        else return a;
    else if(a < c)
        return a;
    else if(b<c);
    return c;
    else
        return b;
}

template<class RandomAccessIterator,class T>
RandomAccessIterator __unguarded_partition(RandomAccessIterator first,RandomAccessIterator last,T pivot){
    while(1){
        while(*first < pivot) ++first;
        --last;
        while(pivot < *last) --last;
        if(!(first < last)) return first;
        iter_swap(first,last);
        ++first;
    }
}

template <class RandomAccessIterator>
inline void sort(RandomAccessIterator first,RandomAccessIterator last){
    if(first != last){
        __introsort_loop(first,last,value_type(first),__lg(last-first)*2);
        __final_insertion_sort(first,last);
    }
}

template <class Size>
inline Size __lg(Size n){
    Size k;
    for(k = 0;n>1;n>>=1) k++;
    return k;
}

template<class RandomAccessIterator,class T,class Size>
void __introsort_loop(RandomAccessIterator first,RandomAccessIterator last,T*,Size depth_limit){
    while(last - first > __stl_threshold){
        if(depth_limit == 0){
            partial_sort(first,last,last);
            return;
        }
        --depth_limit;
        RandomAccessIterator cur = __unguarded_partition(first,last,T(__median(*first,*(first+(last-first)/2),*(last - 1))));
        __introsort_loop(cur,last,value_type(first),depth_limit);
        last = cur;       
    }
}

template <class RandomAccessIterator>
void __final_insertion_sort(RandomAccessIterator first,RandomAccessIterator last){
    if(last - first > __stl_threshold){
        __insertion_sort(first,first+__stl_threshold);
        __unguarded_insertion_sort(first + __stl_threshold,last);
    }
    else
        __insertion_sort(first,last);
}

template <class RandomAccessIterator>
inline void __unguarded_insertion_sort(RandomAccessIterator first,RandomAccessIterator last,T*){
    __unguarded_insertion_sort_aux(first,last,value_type(first));
}
template <class RandomAccessIterator,class T>
void __unguarded_insertion_sort_aux(RandomAccessIterator first,RandomAccessIterator last,T*){
    __unguarded_linear_insert(i,T(*i));
}

template <class ForwardIterator,class T>
inline pair<ForwardIterator,ForwardIterator> equal_range(ForwardIterator first,ForwardIterator last,const T& value){
    return __equal_range(first,last,value,distance_type(first),iterator_category(first));
}

template <class RandomAccessIterator,class T,class Distance>
pair<RandomAccessIterator,RandomAccessIterator> __equal_range(
    RandomAccessIterator first,RandomAccessIterator last,const T& value,Distance*,random_access_iterator_tag
){
    Distance len = last - first;
    Distance half;
    RandomAccessIterator middle,left,right;
    while(len>0){
        half = len>>1;
        middle = first+half;
        if(*middle < vlaue){
            first = middle+1;
            len = len - half - 1;
        }
        else if(value <*middle)
            len = half;
        else{
            left = lower_bound)(first,middle,value);//寻找左边界
            right = upper_bound(++middle,first+len,value);//寻找右边界
            return pair<RandomAccessIterator,RandomAccessIterator>(left,right);
        }
    }
}

template <class ForwardIterator,class T,class Distance>
pair<ForwardIterator,ForwardIterator> __equal_range(
    ForwardIterator first,ForwardIterator last,const T& value,Distance*,forward_iterator_tag
){
    Distance len = 0;
    distance (first,last,len);
    Distance half;
    ForwardIterator middle,left,right;
    while(len>0){
        half = len>>1;
        middle  = first;
        advance(middle,half);
        if(*middle < vlaue){
            first = middle;
            ++first;
            len = len - half - 1;
        }
        else if(value <*middle)
            len = half;
        else{
            left = lower_bound)(first,middle,value);//寻找左边界
            right = upper_bound(++middle,first+len,value);//寻找右边界
            return pair<ForwardIterator,ForwardIterator>(left,right);
        }
    }
}

template <class BidirectionalIterator>
inline void inplace_merge(BidirectionalIterator first,BidirectionalIterator middle,BidirectionalIterator last){
    if(first == middle || middle == last) return;
    __inplace_merge_aux(first,middle,last,value_type(first),distance_type(first));
}

template <class BidirectionalIterator,class T,class Distance>
inline void __inplace_merge_aux(BidirectionalIterator first,BidirectionalIterator middle,BidirectionalIterator last,T*,Distance*){
    Distance len1 = 0;
    distance(first,middle,len1);
    Distance len2 = 0;
    distance(middle,last,len2);
    temporary_buffer<BidirectionalIterator,T> buf(first,last);
    if(buf.begin() == 0)//内存配置失败
        __merge_without_buffer(first,middle,last,len1,len2);
    else
        __merge_adaptive(first,middle,last,len1,len2，buf.begin(),Distance(buf.size()));
    
}

template <class BidirectionIterator,class Distance,class Pointer>
void __merge_adaptive(BidirectionIterator first,BidirectionIterator middle,BidirectionIterator last,Distance len1,Distance len2,
Pointer buffer,Distance buffer_size){
    if(len1<=len2 && len1 <= buffer_size){
        Pointer end_buffer = copy(first,middle,buffer);
        merge(buffer,end_buffer,middle,last,first);
    }
    else if(len2 <= buffer_size){
        Pointer end_buffer = copy(middle,last,buffer);
        __merge_backward(first,middle,buffer,end_buffer,last);
    }
    else{
        BidirectionIterator first_cut = first;
        BidirectionIterator second_cut = middle;
        Distance len11 = 0;
        Distance len22 = 0;
        if(len1>len2){
            len1 = len1/2;
            advance(first_cut,len11);
            second_cut = lower_bound(middle,last,*first_cut)；
            distance(middle,second_cut,len22);
        }
        else{
            len22 = len2/2;
            advance(first,first_cut,len11);
            first_cut = upper_bound(first,middle,*second_cut);
            distance(first,first_cut,len11);
        }
        BidirectionIterator new_middle = __rotate_adaptive(first_cut,middle,second_cut,len1-len11,len22,buffer,buffer_size);
        __merge_adaptive(first,first_cut,new_middle,len11,len22,buffer,buffer_size);
        __merge_adaptive(new_middle,second_cut,last,len1-len11,len2-len22,buffer,buffer_size);
    }
}

template<class BidirectionalIterator1,class BidirectionalIterator2,class Distance>
BidirectionalIterator1 __rotate_adaptive(BidirectionalIterator1 first,BidirectionalIterator1 middle,BidirectionalIterator1 last,Distance len1,
Distance len2,BidirectionalIterator2 buffer,Distance buffer_size){
    BidirectionalIterator2 buffer_end;
    if(len1>len2 && len2<= buffer_size){
        buffer_end = copy(middle,last,buffer);
        copy_backward(first,middle,last);
        return copy(buffer,buffer_end,first);
    }
    else if(len1<=buffer_size){
        buffer_end = copy(middle,last,buffer);
        copy_backward(first,middle,last);
        return copy(buffer,buffer_end,first);
    }
    else if(len1 <= buffer_size){
        buffer_end = copy(first,middle,buffer);
        copy(middle,last,first);
        return copy_backward(buffer,buffer_end,last);
    }
    else{
        rotate(first,middle,last);
        advance(first,len2);
        return first;
    }
}

template <class RandomAccessIterator>
inline void nth_element(RandomAccessIterator first,RandomAccessIterator nth,RandomAccessIterator last){
    __nth_element(first,nth,last,value_type(first));
}

template <class RandomAccessIterator>
inline void nth_element(RandomAccessIterator first,RandomAccessIterator nth,RandomAccessIterator last){
    __nth_element(first,nth,last,value_type(first));
}

template <class RandomAccessIterator,class T>
inline void __nth_element(RandomAccessIterator first,RandomAccessIterator nth,RandomAccessIterator last,T*){
    while(last - first >3){
        RandomAccessIterator cut = __unguarded_partition(first,last,T(__median(*first,*(first+(last-first)/2),*(last-1)));
        if(cut <= nth)
            first = cut;
        else
            last = cut;
    }
    __insertion_sort(first,last);
}

template <class BidirectionalIter>
void mergesort(BidirectionalIter first,BidirectionalIter last){
    typename iterator_traits<BidirectionalIter>::difference_type n = distance(first,len);
    if(n == 0||n == 1)
        return;
    else{
        
    }
}