#include <set>
//并集
template <class Inputerator1,class Inputerator2,class OutputIterator>
OutputIterator set_union(Inputerator1 first1,Inputerator1 last1,Inputerator2 first2,Inputerator2 last2,OutputIterator result){
    while(first1!=last1&&first2!=last2){
        if(*first1 < *first2){
            *result = *first1;
            ++first1;
        }
        else if(*first1 > *first2){
            *result = *first2;
            ++first2;
        }
        else{
            *result = *first1;
            ++first1;
            ++first2;
        }
        ++result;
    }
    return copy(first2,last2,copy(first1,last1,result));
}

//交
template <class Inputerator1,class Inputerator2,class OutputIterator>
OutputIterator set_intersection(Inputerator1 first1,Inputerator1 last1,Inputerator2 first2,Inputerator2 last2,OutputIterator result){
    while(first1!=last1&&first2!=last2){
        if(*first1 < *first2){
            //*result = *first1;
            ++first1;
        }
        else if(*first1 > *first2){
            //*result = *first2;
            ++first2;
        }
        else{
            *result = *first1;
            ++first1;
            ++first2;
            ++result;
        }
        
    }
    return result;
}

//差
//出现于S1但不出现于S2 
template <class Inputerator1,class Inputerator2,class OutputIterator>
OutputIterator set_difference(Inputerator1 first1,Inputerator1 last1,Inputerator2 first2,Inputerator2 last2,OutputIterator result){
    while(first1!=last1&&first2!=last2){
        if(*first1 < *first2){
            *result = *first1;
            ++first1;
            ++first2;
        }
        else if(*first1 > *first2){
            //*result = *first2;
            ++first2;
        }
        else{
           // *result = *first1;
            ++first1;
            ++first2;
           // ++result;
        }
        
    }
    return copy(first1,last1,result);
}

//出现于S1但不出现于S2 ,出现于S2但不出现于S1 的并集
//那是不是就是去除S1,S2相同的元素
template <class Inputerator1,class Inputerator2,class OutputIterator>
OutputIterator set_symmetric_difference(Inputerator1 first1,Inputerator1 last1,Inputerator2 first2,Inputerator2 last2,OutputIterator result){
    while(first1!=last1&&first2!=last2){
        if(*first1 < *first2){
            *result = *first1;
            ++first1;
            ++first2;
        }
        else if(*first1 > *first2){
            *result = *first2;
            ++first1;
            ++first2;
        }
        else{
           // *result = *first1;
            ++first1;
            ++first2;
           // ++result;
        }
        
    }
    return copy(first1,last1,result);
}