#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <DoubleStack.h>

void init_Stack(Stack *s){
    s->top1= -1;
    s->top2= STACK_SIZE;
}

// int length_Stack(Stack *s){
//     return s->top;
// }
void make_empty(Stack *s){
    s->top1= -1;
    s->top2= STACK_SIZE;
}                     

// bool is_empty(Stack *s){
//     if()
// }

bool is_full(Stack *s){
    return s->top1+1 == s->top2;
}
//入栈
bool push(int e,Stack *s,int StackNum){
    if(is_full(s)){
        return false;
    }
    else{ 
        if(StackNum == 1)
            s->content[++s->top1] = e;
        else if(StackNum == 2)
            s->content[--s->top2] = e;
        return true;
    }
     return false;
}
//读取栈顶数据
bool GetTop(ElemType *e,Stack *s,int StackNum){
    if(StackNum == 1){
        if(s->top1 == -1)
            return false;
        else{
            *e = s->content[s->top1]; 
            return true;
        }
    }
    else if(StackNum == 2){
        if(s->top2 == STACK_SIZE)
            return false;
        else{
            *e = s->content[s->top2]; 
            return true;
        }
    }
    return false;
}

//出栈
bool pop(ElemType *e,Stack *s,int StackNum){
    if(StackNum == 1){
        if(s->top1 == -1)
            return false;
        else{
            *e = s->content[s->top1--]; 
            return true;
        }
    }
    else if(StackNum == 2){
        if(s->top2 == STACK_SIZE)
            return false;
        else{
            *e = s->content[s->top2++]; 
            return true;
        }
    }
    return false;
}

int main(){
    Stack s;
    ElemType e = 0;
    init_Stack(&s);
    for(int i = 0;i<10;i++){
        push(i+1,&s,1);
        push(i+10,&s,2);
        }
    GetTop(&e,&s,1);
    printf("%d\n",e);
    GetTop(&e,&s,2);
    printf("%d\n",e);
    printf("%d\n",e);
    for(int i = 0;i<10;i++){
        pop(&e,&s,1);
        printf("%d ",e);
        pop(&e,&s,2);
        printf("%d ",e);
    }
    printf("\n");
       
    system("pause");
    return 0;
}