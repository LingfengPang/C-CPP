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


//��׺����ʽ
// int Count1(char *str){
//     LinkStack s;
//     ElemType e = 0;
//     char strnum[20];
//     int num1,num2;
//     int i =0;
//     int j = 0;
//     int num = 0;
//     // int e;
//     int result = 0;
//     bool flag = false;//是否入栈标志
//     init_Stack(&s);
//     while(str[i] != '\0'){
//         if(str[i] == '+'){
//             pop(&num1,&s);
//             pop(&num2,&s);
//             result = num2+num1;
//             push(result,&s);
//         }
//         else if(str[i] == '-'){
//             pop(&num1,&s);
//             pop(&num2,&s);
//             result = num2-num1;
//             push(result,&s);
//         }
//         else if(str[i] == '*'){
//             pop(&num1,&s);
//             pop(&num2,&s);
//             result = num2*num1;
//             push(result,&s);
//         }
//         else if(str[i] == '/'){
//             pop(&num1,&s);
//             pop(&num2,&s);
//             if(num1 == 0){
//                 printf("���ܳ���0\n");
//                 return  0;
//             }
//             else{
//                 result = num2/num1;
//                 push(result,&s);
//                 }
//         }
//         else if(str[i] == ' '){
//             if(flag){
//                 strnum[j] = '\0';
//                 num = atoi(strnum);
//                 push(num,&s);
//                 flag = false;
//                 j = 0;
//             }
//         }
//         else{
//             if(isdigit(str[i]))
//                 strnum[j++]=str[i];

//             flag = true;
//             if(j == 20){
//                 printf("����̫��\n");
//                 return 0;
//             }
//         }
//         i++;   
//     }
//     if(length_Stack(&s) != 1){
//         printf("ջδ��\n");
//     }
//     pop(&result,&s);
//     return result;
// }

//后缀表达式求值
static int RPN(char *str){
    int i = 0;
    int res = 0;
    int num = 0;
    int a = 0,b = 0;
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

//栈的应用
int main(){
    char rpn[] = "9 3 1 - 3 * + 10 2 / +";
    printf("%d\n",RPN(rpn));
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