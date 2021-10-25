template <class Value>
struct __hashtable_node{
    __hashtable_node* next;
    Value val;
};
template <class Value,class Key,class Hashfcn,class ExtraKey,class EqualKey,class Alloc>
class hashtable{
    public:
    typedef Hashfcn hasher;
    typedef EqualKey key_equal;
    typedef size_t size_type;

    private:
    hasher hash;
    key_equal euqals;
    ExtraKey get_key;

    typedef __hashtable_node<Value> node;
    typedef simple_alloc(node,Alloc) buckets;

    vector<node*,Alloc> buckets;
    size_type nume_elements;

    public:
    pair<iterator,bool> insert_unique(const value_type& obj){
        resize(nume_elements+1);
        return insert_unique_noresize(obj);
    }

    void resize(size_type num_elements_hint){
        const size_type old_n = bucket.size();
        if(num_elements_hint>old_n){
            const size_type n = next_size(num_elements_hint);//找出下一个质数
            if(n>old_n){
                vector<node*,A> tmp(n,(*node) 0);
                __STL_TRY{
                    for(size_type bucket = 0;bucket<old_n;++bucket_count){
                        node *first = buckets[bucket];
                        while(first){
                            size_type new_bucket = bkt_num(first->val,n);
                            buckets[bucket] = first->next;
                            first->next = tmp[new_bucket];
                            tmp[new_bucket] = first;
                            first = buckets[bucket];
                        }
                    }
                    buckets.swap(tmp);
                }
            }
        }
    }

    void insert_unique_noresize(cosnt value_type& obj){
        const size_type n = bkt_num(obj);
        node* first = buckets[n];
        for(node *cur = first;cur;cur = cur->next)
            if(euqals(get_key(cur->val)))
                return pair<iterator,bool>(iterator(cur,this),false);
        node* tmp = new_node(obj);
        tmp->next = first;
        buckets[n] = tmp;
        ++nume_elements;
        return pair<iterator,bool>;
    }
    size_type next_size(size_type n) const{return __stl_next_prime(n);}//下一个质数
    size_type bucket_count()const{return buckets.size();}
    void initialize_buckets(size_type n){
        const size_type n_buckets = next_size(n);
        buckets.reserve(n_buckets);
        buckets.insert(n_buckets.end(),n_buckets,(node*) 0);
        nume_elements = 0;
    }
    hashtable(size_type n,const Hashfcn& hf,const EqualKey& eql):hash(hf),equal(eql),get_key(ExtraKey()),nume_elements(0){
        initialize_buckets(n)
    }
    iterator insert_equal(const value_type& obj){
        resize(nume_elements+1);
        return insert_equal_norsize(obj);
    }

    iterator insert_equal_norsize(const value_type& obj){
        const size_type n = bkt_num(obj);
        node* first = buckets[n];
        for(node* cur = first;cur;cur = cur->next){
            if(equals(get_key(cur->val),get_key(obj))){
                node *tmp = new_node(obj);
                tmp->next = cur->next;
                cur->next = tmp;
                ++nume_elements;
                return iterator(tmp,this);
            }
            node *tmp = new_node(obj);
            tmp->next = first;
            buckets[n] = tmp;
            ++nume_elements;
            return iterator(tmp,this);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        }
    }
    size_type bkt_num_key(const key_type& key,size_t n) const{
        return hash(key)%n;
    }
    size_type bkt_num_key(const key_type& key) const{
        return bkt_num_key(key,buckets.size());
    }
    size_type bkt_num_key(const value_type& obj) const{
        return bkt_num_key(get_key(obj));
    }
    size_type bkt_num(const value_type& obj,size_t n){
        return bkt_num_key(get_key(obj),n);
    }

    void clear(){
        for(size_type i = 0;i<buckets.size();++i){
            node *cur = buckets[i];
            while(cur!=0){
                node* next = cur->next;
                delete_node(cur);
                cur = next;
            }
            buckets[i] = 0;

        }
        nume_elements = 0;
    }

    void copy_from(const hashtable &ht){
        buckets.clear();
        buckets.reserve(ht.buckets.size());//是否扩容
        buckets.insert(buckets.end(),buckets.size(),(node*)0)；
        __STL_TRY{
            for(size_type i = 0;i<ht.buckets.size();i++){
                if(const node*cur = ht.buckets[i]){
                    node *copy = new_node(cur->val);
                    buckets[i] = copy;
                    for(node *next = cur->next;next;cur = next,next = cur->next){
                        copy->next = new_node(next->val);
                        copy = copy->next;
                    }
                }
            }
            nume_elements = ht.num_elements;
        }
        __STL_UNWIND(clear());
    }

    iterator find(const key_type& key){
        size_type n = bkt_num_key(key);
        node *first;
        for(first = buckets[n];first&&!equals(get_key(first->val),key);first = first->next){}
        return iterator(first,this);
    
    }

    size_type count(const key_type& key) const{
        const size_type n = bkt_num_key(key);
        size_type result = 0;
        for(const node* cur = buckets[n];cur;cur = cur->next){
            if(equal(get_key(cur->val),key))
                ++result;
            
        }
        return result;
    }

};



template <class Value,class Key,class Hashfcn,class ExtraKey,class EqualKey,class Alloc>
struct __hashtable_iterator{
    typedef hashtable<Value,Key,Hashfcn,ExtraKey,EqualKey,Alloc> hashtable;
    typedef __hashtable_iterator<Value,Key,Hashfcn,ExtraKey,EqualKey,Alloc> iterator;
    typedef __hashtable_const_iterator<Value,Key,Hashfcn,ExtraKey,EqualKey,Alloc> const_iterator;
    typedef __hashtable_const_node<Value> node;

    typedef forward_iterator_tag iterator_category;
    typedef Value value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef Value& reference;
    typedef Value* pointer;

    node* cur;//迭代器所指节点
    hashtable* ht;

    __hashtable_iterator(node* n,hashtable* tab):cur(n),ht(tab){}
    __hashtable_iterator(){}
    reference operator*() const{return cur->val;}
    pointer operator->() const{return &(operator*());}
    iterator& operator++(){
        const node* old = cur;
        cur = cur->next;
        if(!cur){
            size_type bucket = ht->bkt_num(old->val);
            while(!cur&&++bucket<ht->buckets.size())
                cur = ht->buckets[bucket];
        }
        return *this;
    }
    iterator operator++(int){
        iterator tmp = *this;
        ++*this;
        return tmp;
    }
    bool operator==(const iterator& it) const{return cur == it.cur;}
    bool operator!=(const iterator& it) const{return cur != it.cur;}

    node* new_node(const value_type& obj){
        node* n = node_allocator::allocate();
        n->next = 0;
        __STL_TRY{
            construct(&n->val,obj);
            return n;
        }
        __STL_UNWIND(node_allocator::deallocate(n));
    }

    void delete_node(node* n){
        destroy(&n->val);
        node_allocator::deallocate(n);
    }

};


