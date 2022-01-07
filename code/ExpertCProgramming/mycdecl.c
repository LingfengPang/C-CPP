#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag{
    IDENTIFIER,//标识符
    QUALIFIER,//限定符
    TYPE//类型
};

struct token{
    char type;
    char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token that;
#define pop stack[top--]
#define push(s) stack[++top] = s

enum type_tag classify_string(void){
    char *s = that.string;
    if(!strcmp(s,"const")){
        strcpy(s,"read_only");
        return QUALIFIER;
    }
    if(!strcmp(s,"volatile")) return QUALIFIER;
    if(!strcmp(s,"void")) return TYPE;
    if(!strcmp(s,"char")) return TYPE;
    if(!strcmp(s,"signed")) return TYPE;
    if(!strcmp(s,"unsigned")) return TYPE;
    if(!strcmp(s,"short")) return TYPE;
    if(!strcmp(s,"int")) return TYPE;
    if(!strcmp(s,"long")) return TYPE;
    if(!strcmp(s,"float")) return TYPE;
    if(!strcmp(s,"double")) return TYPE;
    if(!strcmp(s,"struct")) return TYPE;
    if(!strcmp(s,"union")) return TYPE;
    if(!strcmp(s,"enum")) return TYPE;

    return IDENTIFIER;

}

void gettoken(void){
    char *p = that.string;
    //略过空白字符
    while((*p = getchar()) == ' ');
    if(isalnum(*p)){//数字，字母
        while(isalnum(*++p = getchar()));
        //把字符 char（一个无符号字符）推入到指定的流 stream 中;
        ungetc(*p,stdin);//推入输入流之中
        *p = '\0';//p指向空
        that.type = classify_string();
        return;
    }

    if(*p == '*'){
        strcpy(that.string,"pointer to");
        that.type = '*';
        return;
    }
    that.string[1] = '\0';
    that.type = *p;//括号 
    return;
}

read_to_first_identifer(){
    gettoken();
    while(that.type != IDENTIFIER){
        push(that);
        gettoken();
    }
    //直到读到标识符
    printf("%s is ",that.string);
    gettoken();//继续读判断是不是数组或函数其他之类的
}

deal_with_arrys(){
    while(that.type == '['){
        printf("array ");
        gettoken();//数字
        if(isdigit(that.string[0])){
            printf("0..%d ",atoi(that.string)-1);
            gettoken();//读取‘]’

        }
        gettoken();//读取一个标记
        printf("of ");
    }
}

deal_with_functions_args(){
    while(that.type != ')'){
        gettoken();
    }
    gettoken();
    printf("function returning " );
}

deal_with_pointers(){
    while(stack[top].type == '*'){
        printf("%s ",pop.string);
    }
}

deal_with_declarator(){
    switch (that.type)
    {
    case '[':deal_with_arrys();break;
    case '(':deal_with_functions_args();break;
    
    default:
        break;
    }

    deal_with_pointers();

    while(top >= 0){
        if(stack[top].type == '('){
            pop;
            gettoken();//读取‘）’之后的符号
            deal_with_declarator();
        }
        else{
            printf("%s ",pop.string);
        }
    }
}

int main(){
    while(1){
    read_to_first_identifer();
    deal_with_declarator();
    printf("\n");
    }
    return 0;
}




