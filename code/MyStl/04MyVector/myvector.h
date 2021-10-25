template<class T,class Alloc *alloc>
class vector{
    public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    protected:
    //配置去
    typedef simple_alloc<value_type,Alloc> data_allocator;
    iterator start;//目前使用空间的头
    iterator finish;//目前使用空间的尾巴
    iterator end_of_storage;//目前可用空间的尾巴

    void insert_aux(iterator position,const T& x){
        if(finish != end_of_storage){
            construct(finish,*(finish-1));
            ++finish;
            T x_copy = x;
            copy_backward(position,finish-2,finish-1);
            *position = x_copy;
        }
        else{
            const size_type old_size = size();
            const size_type len = old_size!=0?2*old_size:1;

            iterator new_start = data_allocator::allocate(len);
            iterator new_finish = new_start;

            try{
                new_finish = uninitialized_copy(start,position,new_start);
                construct(new_finish,x);
                ++new_finish;
                new_finish = uninitialized_copy(position,finish,new_finish);
            }
            catch(...){
                destroy(new_start,new_finish);
                data_allocator::deallocate(new_start,len);
                throw;
            }
            destroy(begin(),end());
            deallocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start+len;
        }
    }


    void dellocate(){
        if(start){
            data_allocator::deallocate(start,end_of_storage-start);
        }
    }

    void fill_initialize(size_type n,const T& value){
        start = allocate_end_fill(n,value);
        finish += n;
        end_of_storage = finish;
    }

    public:
    iterator begin(){return start;}
    iterator end(){return finish;}
    size_type size(){return size_type(end()-begin());}
    size_type capcaity() const{return size_type(end_of_storage-begin());}
    bool empty() const{return begin() == end();}
    reference operator[](size_type n){return *(begin()+n);}

    vector():start(0),finish(0),end_of_storage(0){}
    vector(size_type n,const T& value){fill_initialize(n,value);}
    vector(int n,const T& value){fill_initialize(n,value);}
    vector(long n,const T& value){fill_initialize(n,value);}
    explicit vector(size_type n){fill_initialize(n,T());}

    ~vector(){
        destroy(start,finish);//这是一个全局函数
        dellocate();//vector的一个成员函数
    }

    reference front(){return *begin()};
    reference back(){return *(end()-1);}

    void push_back(const T&x){
        if(finish != end_of_storage){
            construct(finish,x);//全局函数
            ++finish;
        }
        else{
            insert_aux(end(),x);
        }
    }

    void pop_back(){
        --finish;
        destroy(finish);
    }

    iterator erase(iterator pos){
        if(pos+1 != end())
            copy(pos+1,finish,pos);
        --finish;
        destroy(finish);
        return pos;
    }

    void resize(size_type new_size,const T& x){
        if(new_size<size())
            erase(begin()+new_size,end());
        else
            insert(end(),new_size-size(),x);
    }

    void resize(size_type new_size){resize(new_size,T());}
    void clear(){erase(begin(),end());}
    void insert(iterator pos,size_type n,const T& x){
        if(n!=0){
            if(size_type(end_of_storage-finish)>=n){
                T x_copy = x;
                const size_type elems_after = finish - pos;
                iterator old_finish = finish;
                if(elems_after > n){
                    uninitialized_copy(finish-n,finish,finish);
                    finish+=n;
                    copy_backward(pos,old_finish-n,old_finish);
                    fill(pos,pos+n,x_copy);
                }
                else{
                    uninitialized_fill_n(finish,n-elems_after,x_copy);
                    finish +=n-elems_after;
                    uninitialized_copy(pos,old_finish,finish);
                    finish+=elems_after;
                    fill(pos,pos+n,x_copy);
                }
            }
            else{
                const size_type old_size = size();
                const size_type len = old_size+max(old_size,n);
                iterator new_start = data_allocator::allocate(len);
                iterator new_finish = new_start;
                _STL_TRY{
                    new_finish = uninitialized_copy(star,pos,new_start);
                    new_finish = uninitialized_fill_n(new_finish,n,x);
                    new_finish = uninitialized_copy(pos,finish,new_finish);
                }
            #ifdef _STL_USE_EXCEPTIONS
                catch(...){
                    destroy(new_start,new_finish);
                    data_allocator::deallocate(new_start,len);
                    throw;
                }
            #endif
            destroy(start,finish);
            dellocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start+len;
            }
    }
}
    protected:
    iterator allocate_and_fill(size_type n,const T&x){
        iterator result = data_allocator::allocate(n);
        uinitialized_fill_n(result,n,x);
        return result;
    }
};