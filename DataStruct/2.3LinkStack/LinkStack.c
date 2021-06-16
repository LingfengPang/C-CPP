#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "LinkStack.h"


void init_Stack(LinkStackPtr *S){
    *S = (LinkStackPtr)malloc(sizeof(StackNode));
    (*S)->next = NULL;
}

// int length_Stack(LinkStack *S){
//     return S->count;
// }
// void make_empty(LinkStack *S){
//     S->top = NULL;
//     S->count = 0;
// }                     

bool is_empty(LinkStackPtr *S){
    return (*S)->next == NULL;
}

//入栈,相当于尾插法
bool push(ElemType e,LinkStackPtr *S){
        LinkStackPtr p;
        p= (LinkStackPtr)malloc(sizeof(StackNode));
        p->data = e;
        p->next = (*S)->next;
        ( *S)->next = p;
        return true;
}
//读取栈顶数据
bool GetTop(ElemType *e,LinkStackPtr *S){
    
    if(is_empty(S)){
        *e = -1;
        return false;
    }
    else{
        (*e) = (*S)->next->data;
        return true;
    }
}

//出栈
bool pop(ElemType *e,LinkStackPtr *S){
    if(is_empty(S)){
        *e = -1;
        return false;
    }
    else{
        LinkStackPtr p;
        p= (LinkStackPtr)malloc(sizeof(StackNode));
        *e = (*S)->next->data;
        p = (*S) -> next;
        (*S)->next = p->next; 
        free(p);
        return true;
    }
    return false;
}




//后缀表达式求值
static int RPN(char *str){
    int i = 0;
    int res = 0;
    int num = 0;
    char a = 0,b = 0;
    int flag = 0;
    LinkStackPtr s;
    init_Stack(&s);
    while(str[i]!='\0'){
        if(str[i] == '+'){
            pop(&b,&s);
            pop(&a,&s); 
            push(a+b,&s); 
            //flag = 0;
        }
        else if(str[i] == '-'){
            pop(&b,&s);
            pop(&a,&s); 
            push(a-b,&s);  
           // flag = 0;   
        }
        else if(str[i] == '*'){
            pop(&b,&s);
            pop(&a,&s);  
            push(a*b,&s);     
            //flag = 0;          
        }
        else if(str[i] == '/'){
            pop(&b,&s);
            pop(&a,&s);    
            push(a/b,&s); 
           // flag = 0;               
        }
        else if(str[i] == ' '&&flag == 1){
            push(num,&s);
            num = 0;
            flag = 0;
        }
        else if(str[i] != ' '){
            flag = 1;
            num = num*10 + str[i]-'0';
        }
        i++;
    }
    return s->next->data;
    
}
//中缀转后缀
int toRPN(char *s){
    LinkStackPtr S;
    init_Stack(&S);
    char c;
    char str[30];
    int j = 0;
    int i = 0;
    bool has_num = 0;
    while(s[i]!='\0'){
        if(s[i] == '+'||s[i] == '-'){
            if(has_num){
                str[j++] = ' ';
                has_num = 0; 
                }
            if(GetTop(&c,&S)&&c!='('){
                //如果由那么一定时符号
                    while(GetTop(&c,&S)&&(c!='('||c!='*'||c!=' /')){
                        pop(&c,&S);
                        str[j++] = c;
                        str[j++] = ' ';
                    }  
            }
            push(s[i],&S);    
        }
        else if(s[i] == '*'||s[i] == '/'){
            if(has_num){
                str[j++] = ' ';
                has_num = 0; 
            }
            if(GetTop(&c,&S)&&c!='('&&c!='+'&c!='-'){
                //如果由那么一定时符号
                    while(GetTop(&c,&S)&&c!='('){
                        pop(&c,&S);
                        str[j++] = c;
                        str[j++] = ' ';
                    }
             
            }
            push(s[i],&S);  
        }
        else if(s[i] == '('){
            if(has_num){
                str[j++] = ' ';
                has_num = 0;    
            }
            push(s[i],&S);         
        }   
        else if(s[i] == ')'){
            if(has_num){
                str[j++] = ' ';
                has_num = 0; 
            }
            while(GetTop(&c,&S)&&c!='('){
                pop(&c,&S);
                str[j++] = c;
                str[j++] = ' ';
            }
            pop(&c,&S);//把括号排出来
        } 
        else{//数字
            str[j++] = s[i];
            has_num = 1;
        } 
        i++;        
    }
    while(GetTop(&c,&S)){
        pop(&c,&S);
        str[j++] = c;
        str[j++] = ' ';
    }
    str[j] = '\0';

    return RPN(str);
}
//栈的应用
int main(){
    char rpn[] = "9 3 1 - 3 * + 10 2 / +";
    char rpn2[] = "9+(3-1)*3+10/2";
    printf("%d\n",RPN(rpn));
    printf("%d\n",toRPN(rpn2));
    LinkStackPtr *s;
    ElemType e = 0;
    init_Stack(s);
    for(int i = 0;i<5;i++){
        push(i,s);
        GetTop(&e,s);
        printf("%d ",e);
    }
    printf("\n ");
    for(int i = 0;i<5;i++){
        pop(&e,s);
        printf("%d ",e);
    }
    printf("\n ");
    system("pause");
    return 0;
}