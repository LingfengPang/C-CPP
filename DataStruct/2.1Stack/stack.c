#include <stdio.h>
#include <windows.h>
#include <stack.h>
#define STACK_SIZE 100
typedef int ElemType;

void init_Stack(Stack *s){
    s->top= 0;
}
int length_Stack(Stack *s){
    return s->top;
}
void make_empty(Stack *s){
    s->top = 0;
}                     
bool is_empty(Stack *s){
    return s->top == 0;
}
bool is_full(Stack *s){
    return s->top == STACK_SIZE;
}
//入栈
bool push(int e,Stack *s){
    if(is_full(s)){
        return false;
    }
    else{ 
        s->content[s->top++]=e;
        return true;
    }
}
//读取栈顶元素
bool GetTop(ElemType *e,Stack *s){
    if(is_empty(s)){
        return false;
    }
    else{
        *e = s->content[s->top-1];
        return true;
    }
}

//出栈
bool pop(ElemType *e,Stack *s){
    if(is_empty(s)){
        return false;
    }
    else{
        (*e) = s->content[--s->top];
        return true;
    }
}

int main(){
    Stack s;
    ElemType e = 0;
    init_Stack(&s);
    for(int i = 0;i<5;i++)
        push(i+1,&s);
    GetTop(&e,&s);
    
    printf("%d\n",e);
    e = length_Stack(&s);
    printf("%d\n",e);
    for(int i = 0;i<5;i++){
        pop(&e,&s);
        printf("%d ",e);
    }
    printf("\n");
       
    system("pause");
    return 0;
}