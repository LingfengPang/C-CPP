template<class T,class Ref,class Ptr,size_t BufSize>
struct __dequee_iterator{
    typedef __deque_iterator<T,T&,T*,BufSize> iterator;
    typedef __list_iterator<T,Ref,PtrBufSize> self;

    //缓冲区大小
    static size_t buffer_size(){return __deque_buf_size(BufeSize,sizeof(T));}//调用一个全局函数


    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T** map_pointer;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    T* cur;//指向缓存区的现行
    T* first;//头
    T* last;//尾巴

    map_pointer node;//指向控制中枢

    void set_node(map_pointer new_node){
        node = first;
        first = *new_node;
        last = first + difference_type(buffer_size());
    }

    __list_iterator(link_type x):node(x){}
    __list_iterator(){}
    __list_iterator(const iterator& x):node(x.node){}

    bool operator==(const self& x)const{return node == x.node;}
    bool operator!=(const self& x)const{return node != x.node;}
    
    reference operator*() const{return *cur;}
    pointer operator->() const{return &(operator*());}
    difference_type operator-(const self& x) const{
        return difference_type(buffer_size())*(node-x.node-1)+(cur-first)+(x.last-x.cur);
    }
    self& operator++(){
        ++cur;
        if(cur == last){
            set_node(node+1);
            cur = first;
        }
        return *this;
    }

    self operator++(int){
        selft tmp = *this;
        ++*this;
        return temp;
    }

    self& operator--(){
        if(cur == first){
            set_node(node-1);
            cur = last;
        }
        --cur;
        return *this;
    }
    self operator--(int){
        self tmp = *this;
        --*this;
        return tmp;
    }

    self& operator+=(difference_type n){
        difference_type offset = n+(cur-first);
        if(offset>=0 && offset<difference_type(buffer_size()))
            cur+=n;
        else{
            difference_type node_offset = offset>0?offset/difference_type(buffer_size()):-difference_type((-offset-1)/buffer_size())-1;
            set_node(node+node_offset);
            cur = first+(offset-node_offset*difference_type(buffer_size()));
        }
        return *this;
    }

    self operator+(difference_type n) const{
        self tmp = *this;
        return tmp+=n;
    }

    self& operator=(difference_type n){return *this += -n;}

    self operator-(difference_type n) const{
        self tmp =*this;
        return tmp -= n;
    }

    reference operator[](difference_type n)const{return *(*this+n);}

    bool operator==(const self&x) const{return cur == x.cur;}

    bool operator!=(const self& x) const{return!(*this == x);}
    bool operator<(const self& x)const{return (node==x.node)?(cur<x.cur):(node<x.node);}
};

template<class T,class Alloc = alloc,size_t BufSiz = 0>
class deque{
    public:
    typedef T value_type;
    typedef value_type * pointer;
    typedef size_t size_type;

    typedef __dequee_iterator<T,T&,T*,BufSiz> iterator;

    typedef simple_alloc<value_type,Alloc> data_allocator;//每次配备一个元素的大小
    typedef simple_alloc<pointer,Alloc> map_allocator;//每次配备一个指针的大小
    protected:
    typedef pointer* map_pointer;

    iterator start;
    iterator finish;
    map_pointer map;
    size_type map_size;

    public:
    void create_map_and_nodes(size_type num){
        size_type num_nodes = num/buffer_size()+1;

        map_size = max(initial_map_size(),num_nodes+2);
        map = map_allocator::allocate(map_size);

        map_pointer nstart = map+(map_size-num_nodes)/2;
        map_pointer nfinish = nstart+num_nodes-1;

        map_pointer cur;

        __STL_TRY{
            for(cur = nstart;cur<=finish;++cur){
                *cur = allocate_node();
            }
        }
        catch(...){}
        start.set_node(nstart);
        finish.set_node(nfinish);
        start.cur = start.first;
        finish.cur = finish.first+num%buffer_size();
    }
    void fill_initialize(size_type n,const value_type& value){
        create_map_and_nodes(n);
        map_pointer cur;
        __STL_TRY{
            for(cur = start.node;cur<finish.node;++cur){
                uninitialized_fill(*cur,*cur+buffer_size(),value);
            }
            uninitialized_fill(finish.first,finish.cur,value);
        }
        catch(...){
            `
        }
    }
    deque(int n,const value_type& value):start(),finish(),map(0),map_size(0){
        fill_initialize(n,value);
    }

    iterator begin(){return *start;}
    iterator end(){return finish;}

    reference operator[](size_type n){
        return start[difference_type(n)];//调用__deque_iterator<>::operator[]
    }

    reference front(){return *start;}
    reference back(){
        iterator tmp = finish;
        --tmp;
        return *tmp;
    }

    size_type size() const{ return finish-start;}
    size_type max_size() const{return size_type(-1);}

    void reallocate_map(size_type nodes_to_add,bool add_front){
        size_type old_num_nodes = finish.node - start.node + 1;
        size_type new_num_nodes = old_num_nodes+nodes_to_add;

        map_pointer new_nstart;

        if(map_size > 2*new_num_nodes){
            new_nstart = map + (map_size - new_num_nodes)/2+(add_front?nodes_to_add:0);
            if(new_nstart<start.node)
                copy(start.node,finish.node+1,new_nstart);
            else
                copy_backward(start.node,finish.node+1,new_nstart+old_num_nodes);
        }
        else{
            size_type new_map_size = map_size+max(map_size,nodes_to_add)+2;
            map_pointer new_map = map_allocator::allocate(new_map_size);
            new_nstart = new_map +(new_map_size-new_num_nodes)/2+(add_front?nodes_to_add:0);
            copy(start.node,finish.node+1,new_nstart);
            map_allocator::deallocate(map,map_size);
            map = new_map;
            map_size = new_map_size;
        }

        start.set_node(new_nstart);
        finish.set_node(new_nstart+old_num_nodes-1);

    }

    void reserve_map_at_back(size_type nodes_to_add = 1){
        //如果空间不够则要重新分配空间
        if(nodes_to_add + 1>map_size - (finish.node - map))
            reallocate_map(nodes_to_add,false);
    }

    void reserve_map_at_front(ize_type nodes_to_add = 1){
        if(nodes_to_add > start.node-map);
            reallocate_map(nodes_to_add,false);
    }
    bool empty() cosnt{return start == finish;}
    void  push_back_aux(const value_type& t){
        value_type t_copy = t;
        reserve_map_at_back();//符合某种条件则重换一个
        *(finish.node+1) = allocate_node();
        __STL_TRY{
            construct(finish.cur,t_copy);
            finish.set_node(finish.node+1);
            finish.cur = finish.first;
        }
        __STL_UNWIND(deallocate_node(*(finish.node+1)));
    }
    void push_back(const value_type& t){
        if(finish.cur!=finish.last-1){
            construct(finish.cur,t);
            ++finish.cur;
        }
        else{
            push_back_aux(t);
        }
    }
    void push_front_aux(const value_type& t){
        value_type t_copy = t;
        reserve_map_at_front();//符合某种条件则必须换一个map
        *(start.node-1) = allocate_node();
        __STL_TRY{
            start.set_node(start.node-1);
            start.cur = start.last-1;
            construct(start.cur,t_copy);
        }
        catch(...){
            //若非全部成功，则一个不留
            start.set_node(start.node+1);
            start.cur = start.first;
            deallocate_node(*(start.node-1));
            throw;
        }
    }
    void push_front(const value_type& t){
        if(start.cur != start.first){//第一缓存区还有空间
            construct(start.cur-1,t);
            start.cur--;
        }
        else
            push_front_aux(t);
    }
    void pop_back_aux(){
        deallocate_node(finish.first);
        finish.set_node(finish.node-1);
        finish.cur = finish.last-1;
        destroy(finish.cur);
    }

    void pop_front_aux(){
        destroy(start.cur);
        deallocate_node(start.first);
        start.set_node(start.node+1);
        start.cur = start.first;
        //destroy(start.cur);
    }
    void pop_back(){
        if(finish.cur!=finish.first){
            --finish.cur;
            destory(finish.cur);
        }
        else
            pop_back_aux();
    }

    void pop_front(){
        if(start.cur!=start.last-1){
            destory(start.cur);//嗯？？？
            ++start.cur;
        }
        else
            pop_front_aux();
    }

    void clear(){
        for(map_point node = start.node+1;node<finish.node;++node){
            //将缓存区元素析构
            destroy(*node,*node+buffer_size());
            //释放缓存区内存
            data_allocatot::dellocate(*node,buffer_size());
        }
        if(start.node!=finish.node){
            destroy(start.cur,start.last);
            destroy(finish.first,finish.last);
            data_allocator::deallocate(finish.first,buffer_size());
        }
        else
            destroy(start.cur,finish.cur);
        finish = start;//调整状态
    }

    iterator erase(iterator pos){
        iterator next = pos;
        ++next;
        difference_type index = pos-start;
        if(index<(size()>>1)){//判断哪边移动的元素少
            copy_backward(start,pos,next);
            pop_front();
        }
        else{
            copy(next,finish,pos);
            pop_back();
        }
        return start+index;
    }
    //左闭右开
    void erase(iterator first,iterator last){
        if(first == start&&last == finish){
            clear();
            return finish;
        }
        else{
            difference_type n = last - first;
            difference_type elems_before = first-start;
            if(elems_befoe<(size()-n)/2){
                copy_backward(start,first,next);
                iterator new_start = start+n;
                destroy(start,new_start);
                for(map_pointer cur = start.node;cur<new_start.node;++cur){
                    data_allocator::deallocate(*cur,buffer_size());
                }
                start = new_start;
            }
            else{
                copy(last,finish,first);
                iterator new_finish = finish-n;
                destroy(new_finish,finish);
                for(map_pointer cur = new_finish.node+1;cur<=finish.node;++cur)
                    data_allocator::deallocate(*cur,buffer_size());
                finish = new_finish;
            }
            return start+elems_before;
        }
    }

    iterator insert_aux(iterator pos,const value_type& x){
        difference_type index = pos-start;
        value_type x_copy = x;
        if(index < size()/2){
            push_front(front());//在前端加入一个一样的值
            iterator front1= start;
            ++front1;
            iterator front2 = front1;
            ++front2;
            pos = start+index;
            iterator pos1 = pos;
            ++pos1;
            copy(front2,pos1,front1);
        }
        else{
            push_back(back());//在前端加入一个一样的值
            iterator back1= finish;
            --back1;
            iterator back2 = back1;
            --back2;
            pos = start+index;
            iterator pos1 = pos;
            //++pos1;
            copy_backward(pos,back2,back1);
        }
        *pos = x_copy;
        return pos;
    }

    //在pos之前插入
    iterator insert(iterator pos,const value_type& x){
        if(pos.cur == start.cur){
            push_fornt(x);
            return start;
        }
        else if(pos.cur == finish.cur){
            push_back(x);
            iterator tmp = finish;
            --temp
            return temp;
        }
        else
            return insert_aux(pos,x);
    }
};