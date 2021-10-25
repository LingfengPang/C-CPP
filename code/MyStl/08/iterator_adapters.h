//插入
template <class Container>
class back_insert_iterator{
    protected:
        Container* container;
    public:
        typedef output_iterator_tag iterator_category;
        typedef void value_type;
        typedef void difference_type;
        typedef void pointer;
        typedef void reference;

        explicit back_insert_iterator(Container& x):container(&x){}
        back_insert_iterator<Container>& operator=(const typename Container::value_type& value){
            container->push_back(value);
            return *this;
        }
};
template <class Container>
inline back_insert_iterator<Container> back_insert(Container& x){
    return back_insert_iterator<Container>(x);
}

template <class Iterator>
class reverse_iterator{
        protected:
        Iterator* current;
    public:
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;

        typedef Iterator iterator_type;
        typedef reverse_iterator<Iterator> self;

    public:
        reverse_iterator(){}
        explicit reverse_iterator(iterator_type x):cuurent(x){}
        reverse_iterator(const selft& x):cuurent(x.current){}
        Iterator_type base() const {return current};
        reference operator*(){
            Iterator tmp = current;
            return --*tmp;
        }
        pointer operator->() const {return &(operator*());}

        self& operator++(){
            --current;
            return *this;
        }

        self operator++(int){
            self tmp = *this;
            --current;
            return tmp;
        }
        
        self& operator--(){
            ++current;
            return *this;
        }

        self operator++(int){
            self tmp = *this;
            ++current;
            return tmp;
        }
        self operator+(difference_type n)const{
            return slef(current-n);
        }
        self operator+=(difference_type n)const{
            current -= n;
            return *this;
        }
        self operator-(difference_type n)const{
            return slef(current+n);
        }
        self operator-=(difference_type n)const{
            current += n;
            return *this;
        }
        reference operator[](difference_type n) const{return *(*this+n);}
        
};

template <class T,class Distance = ptrdiff_t>
class istream_iterator{
    friend bool operator==__STL_NULL_TMP_ARGS(const istream_iterator<T,Distance>& x,const istream_iterator<T,Distance>& y);
        protected:
        istream* stream;
        T value;
        bool end_marker;
        void read{
            end_marker = (*stream)?true:flase;
            if(end_marker) = (*stream)?true:false;
            end_marker = (*stream)?true:false;
        }
    public:
        typedef  input_iterator_category iterator_category;
        typedef  T value_type;
        typedef  Distance difference_type;
        typedef  const T* pointer;
        typedef  const T& reference;


    public:
        istream_iterator():stream(&cin),end_marker(false){}
        istream_iterator(istream& s):stream(&s){read();}


        reference operator*(){
            return value;
        }
        pointer operator->() const {return &(operator*());}

        self& operator++(){
            --current;
            return *this;
        }

        self operator++(int){
            self tmp = *this;
            --current;
            return tmp;
        }
        
        self& operator--(){
            ++current;
            return *this;
        }

        self operator++(int){
            self tmp = *this;
            ++current;
            return tmp;
        }
        self operator+(difference_type n)const{
            return slef(current-n);
        }
        self operator+=(difference_type n)const{
            current -= n;
            return *this;
        }
        self operator-(difference_type n)const{
            return slef(current+n);
        }
        self operator-=(difference_type n)const{
            current += n;
            return *this;
        }
        reference operator[](difference_type n) const{return *(*this+n);}
        
};
