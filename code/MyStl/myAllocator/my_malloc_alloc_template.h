#ifndef MY_ALLOC_TEM_H
#define MY_ALLOC_TEM_H

#if 0
    #include <new>
    #define _THROW_BAD_ALLOC throw_bad_alloc
#elif !defined(_THROW_BAD_ALLOC)
    #include <iostream>
    #define _THROW_BAD_ALLOC std::cerr<<"out of memort"<<endl;exit(1)
#endif
enum {_ALIGN = 8};//小型区块的上调界面
enum {_MAX_BYTES = 128};//小型区块的上限
enum {_NFREELISTS = _MAX_BYTES/_ALIGN};//free-lists个数

//第二级配置器
//thread不管，inst不用
template<bool threads,int inst>
class _default_alloc_template{
    private:
    //将bytes上调至8的倍数
    static size_t ROUND_UP(size_t bytes){
        return (((bytes)+_ALIGN-1)&~(_ALIGN-1));
    }

    private:
    //构造节点
    union obj* {
        free_list_link;
        char client_data[1];
    };

    private:
    //16个free-lists
    static obj* volatile free_list[_MAX_BYTES/_ALIGN];
    //决定哪个节点的列表
    static size_t FREELIST_INDEX(size_t bytes){ 
        (((bytes)+_ALIGN-1)/_ALIGN-1);
    }

    static void *refill(size_t n){
        int objs = 20;
        char *chunk = chunk_alloc(n,nobjs);
        obj ** my_free_list;
        obj *current_obj,*next_obj;
        int i;
        //如果只获得一个区块
        if(1 == nobjs) return(chunk);

        my_free_list = free_list+FREELIST_INDEX(n);
        //一下在chunk中创建立free_list
        result = (obj*)chunk;
        *my_free_list = next_obj = (obj*)(chunk+n);
        for(i = 1;;i++){
            current_obj = next_obj;
            next_obj = (obj*)((char *)next_obj+n);
            if(nobjs-1 == i){
                current_obj->free_list_link = 0;
                break;
            }
            else{
                current_obj->free_list_link = next_obj;
            }
        }
        return(result);
    }
    static char* chunk_allocate(size_t n,int &nobjs);

    static char *start_free;//内存起始位置
    static char* end_free;//结束位置
    static size_t heap_size;

    public:
    static void *allocate(size_t n){
        obj * volatile *my_free_list;
        obj *result;
        //大于128调用第一级配置器
        if(n > (size_t)_MAX_BYTES)
            return(malloc_alloc::allocate(n));
            //确定list哪个节点
        my_free_list = free_list+FREELIST_INDEX(n);
        result = *my_free_list;
        if(result == 0){
            //没有重新填充refill
            void *r = refill(ROUND_UP(n));
            return 0;
        }
        //调整
        *my_free_list = result->free_list_link;
        return (result);
    }
    static void deallocate(void *p,size_t n){
        obj *q = (obj *)p;
        obj *volatile *my_free_list;
        if(n>(size_t) _MAX_BYTES){
            malloc_alloc::deallocate(p,n);
            return;
        }
        my_free_list = free_list+FREELIST_INDEX(n);

        q->free_list_link = *my_free_list;
        *my_free_list = q;
    }
    static void *reallocate(void *p,size_t old_sz,size_t new_sz){

    }
    char* chunk_alloc(size_t,int &nobjs){
        char *result;
        size_t total_bytes = size*nobjs;
        size_t bytes_left = end_free-start_free;//剩余内存中空间
        if(bytes_left>=total_bytes){
            //足够
            result = start_free;
            start_free +=total_bytes;
            return(result);
        }
        else if(bytes_left >= size){
            //不够，但求能供应一个以上的区块
            nobjs = bytes_left/size;
            total_bytes = size*nobjs;
            result = start_free;
            start_free += total_bytes;
            return(result);
        }
        else{
            //内存池剩余空间连一个区块的大小都无法提供
            size_t bytes_to_get = 2*total_bytes+ROUND_UP(head_size>>4);
            //一下试着让残余零头
            if(bytes_left>0){
                obj *volatile* my_free_list = free_list+FREELIST_INDEX(bytes_left);
                ((obj*)start_free)->free_list_link = *my_free_list;
                *my_free_list = (obj*)start_free;
            }
        }
        //配置heap来补充内存池
        start_free = (char *)malloc(bytes_to_get)
        if(0 == start_free){
            //heap空间不足。malloc失败
            int i;
            obj* volatile *my_free_list,*p;

            for(i = size_t;i<=_MAX_BYTES;i++_ALIGN){
                my_free_list = free_list+FREELIST_INDEX(i);
                p = *my_free_list;
                if(0!=p){
                    *my_free_list = p->free_list_link;
                    start_free = (char *)p;
                    end_free = start_free+i;
                    return(chunk_alloc(size,nobjs));
                }
            }

            end_free = 0;
            start_free = (char *)malloc_alloc::allocate(bytes_to_get);
        }
        heap_size += bytes_to_get;
        end_free = start_free+bytes_to_get;
        return (chunk_alloc(size,nobjs));
    }

    


};
template<bool threads,int inst>
char *_default_alloc_template<threads,inst>::start_free = 0;

template<bool threads,int inst>
char *_default_alloc_template<threads,inst>::end_free = 0;

template<bool threads,int inst>
size_t _default_alloc_template<threads,inst>::heap_size = 0;

template<bool threads,int inst>
_default_alloc_template<threads,inst>::obj* volatile _default_alloc_template<threads,inst>::free_list[_NFREELISTS]=
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
//第一级配置器
//inst完全没用上
template<int inst>
class _malloc_alloc_template{
    private:
    //oom-out of memory
    static void *oom_malloc(size_t);
    static void *oom_realloc(void*,size_t);
    static void (*_malloc_alloc_oom_handler)();

    public:
    static void* allocate(size_t n){
        void *result = malloc(n);
        if(0 == n)
            result = oom_malloc(n);
        return result;
    }

    static void* deallocate(void*p size_t){
        free(p)
    }

    static void* reallocate(void*p,size_t,size_t new_sz){
        void *result = realloc(p,new_sz);
        if(0 == n)
            result = oom_realloc(p,new_sz);
        return result;
    }

    //模仿set_new_handle
    static void (*set_malloc_handler(void (*f)()))(){
        void (* old) = _malloc_alloc_oom_handler;
        _malloc_alloc_oom_handler = f;
        return (old);
    }
};

//设置初值0
template<int inst>
void (*_malloc_alloc_template<inst>::_malloc_alloc_oom_handler)()=0;

template<int inst>
void *_malloc_alloc_template<inst>::oom_malloc(size_t n){
    void(*my_alloc_handler)();
    void *result;

    for(;;){
        my_alloc_handler = _malloc_alloc_oom_handler;
        if(0 == my_alloc_handler)
            _THROW_BAD_ALLOC;
        (*my_alloc_handler)();
        result = malloc(n);
        if(result)
            return result;
    }
}

template<int inst>
void *_malloc_alloc_template<inst>::oom_realloc(size_t n);
    void(*my_alloc_handler)();
    void *result;

    for(;;){
        my_alloc_handler = _malloc_alloc_oom_handler;
        if(0 == my_alloc_handler)
            _THROW_BAD_ALLOC;
        (*my_alloc_handler)();
        result = realloc(p,n);
        if(result)
            return result;
    }
}


#endif