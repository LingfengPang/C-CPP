struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag{};
struct bidirectional_iterator_tag{};
struct random_access_iterator_tag{};

template<class Category,class T,class Distance /*= ptrdiff_t*/,class Point = T*,class Reference = T&>
struct iterator
{
    /* data */
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

//traits
template<class Iterator>
struct iterator_traits
{
    /* data */
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::Distance difference_type difference_type;
    typedef typename Iterator::Pointer pointer pointer;
    typedef typename Iterator::Reference reference reference;
};

//争对原生指针的偏特化版本
template<class T>
struct iterator_traits<T*>{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type difference_type;
    typedef T* pointer pointer;
    typedef T& Iterator::Reference reference reference;
};
//争对原生pointer-to-const
template<class T>
struct iterator_traits<const T*>{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type difference_type;
    typedef const T* pointer pointer;
    typedef const T& Iterator::Reference reference reference;
};


//确定迭代器的类型
template<class Iterator>
inline typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator){
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}

template<class Iterator>
inline typename iterator_traits<Iterator>::difference_type* distance_type(const Iterator){
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    return category();
}

template<class Iterator>
inline typename iterator_traits<Iterator>::value_type value_type(const Iterator){
    typedef typename iterator_traits<Iterator>::value_type value_type;
    return category();
}


//distance函数
template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type _distance(InputIterator firts,
    InputIterator last,input_iterator_tag){
        iterator_traits<InputIterator>::difference_type n = 0;
        while(first != last){
            ++first;
            ++n;
        }
    return n;
}


template<class RandomAccessIterator>
inline typename iterator_traits<RandomAccessIterator>::difference_type _distance(RandomAccessIterator firts,
    RandomAccessIterator last,random_access_iterator_tag){
        return last-first;
}


template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type _distance(InputIterator firts,
    InputIterator last){
        typedef typename iterator_traits<InputIterator>::iterator_category category;
    return _distance(first,last,category());
}

//advance函数
template<class InputIterator,class Distance>
inline void _advance(InputIterator &i,Distance n,input_iterator_tag){
    while(n--)
        ++i;
}

template<class BidirectionalIterator,class Distance>
inline void _advance(InputIterator &i,Distance n,bidirectional_iterator_tag){
    if(n>=0)
        while(n--) i++;
    else
        while(n++) i--;
}

template<class RandomAccessIterator &i,class Distance>
inline void_type(random_access_iterator_tag &i,Distance n,random_access_iterator_tag){
    i+=5;
}

template<class InputIterator,class Distance>
inline void advace(input_iterator_tag &i,Distance n){
    _advance(i,n,iterator_category(i));
}


