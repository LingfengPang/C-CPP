template<class RandomAccessIterator,class Distance,class T>
inline void __push_heap(RandomAccessIterator first,Distance holeIndex,Distance topIndex, T value){
    Distance parent = (holeIndex-1)/2;//找出父亲节点
    while(holeIndex > topIndex &&*(first+parent)<value){
        Distance parent = (holeIndex-1)/2;
            *(first+holeIndex) = *(first+parent);
            holeIndex = parent;
            parent = (holeIndex-1)/2;
    }
    *(first+holeIndex) = value;
}

template<class RandomAccessIterator,class Distance,class T>
inline void __push_heap_aux(RandomAccessIterator first,RandomAccessIterator last,Distance*,T*){
    __push_heap(first,Distance((last-first)-1),Distance(0),T(*last-1));
}

template<class RandomAccessIterator>
inline void push_heap(RandomAccessIterator first,RandomAccessIterator last){
    __push_heap_aux(first,last,distance_type(first),value_type(first));
}

template<class RandomAccessIterator>
inline void pop_heap(RandomAccessIterator first,RandomAccessIterator last){
    __pop_heap_aux(first,last,value_type(first));
}

template<class RandomAccessIterator,class Distance,class T>
inline void __pop_heap_aux(RandomAccessIterator first,RandomAccessIterator last,Distance*,T*){
    __pop_heap(first,last-1,last-1,T(*(last-1)),distance_type(first));
}


template<class RandomAccessIterator,class Distance,class T>
inline void __push_heap(RandomAccessIterator first,RandomAccessIterator last,RandomAccessIterator reslut,T value,Distance*){
    *reslut = *first;
    __adjust_heap(first,Distance(0),Distance(last-first),Distance holeIndex);
}

template<class RandomAccessIterator,class Distance,class T>
void __adjust_heap(first,Distance(0),Distance(last-first),Distance holeIndex){
    Distance topIndex = holeIndex;
    Distance secondChild = 2*holeIndex;
    while(second < len){
        if(*(first+secondChild)<*(first+(secondChild-1)))
            second--;
        *(first+holeIndex) = *(first+secondChild);
        holeIndex = secondChild;
        secondChild = 2*(secondChild+1);
    }
    if(sencondChild == len){
        *(first+holeIndex) = *(first+holeIndex) = value;
        holeIndex = secondChild - 1;
    }
    __push_heap(first,holeIndex,topIndex,value);
}

template <class RandomAccessIterator>
void sort_heap(RandomAccessIterator first,RandomAccessIterator last){
    while(last-first >1)
        pop_heap(first,last--);
}
template <class RandomAccessIterator>
void __make_heap(RandomAccessIterator first,RandomAccessIterator last,T*,Distance*){
    if(last-first <2) return;
    Distance len = last - first;
    Distance parent = (len-2)/2;
    while(true){
        __adjust_heap(first,parent,len,T(*(first+parent)));
        if(parent == 0)
            return;
        parent--;
    }
}
template <class RandomAccessIterator>
void make_heap(RandomAccessIterator first,RandomAccessIterator last){
    __make_heap(first,last,value_type(first),distace_type(first));

}


