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
    if(isalnum(*p)){
        while(isalnum(*++p = getchar()));
        //把字符 char（一个无符号字符）推入到指定的流 stream 中;
        ungetc(*p,stdin);//推入输入流之中
        *p = '\0';//p指向空
        that.type = classify_string();
        return;
    }
    that.string[1] = '\0';
    that.type = *p;
    return;
    // if(*p == '*'){
    //     strcpy(that.string,"pointer to");
    //     that.type = '*';
    //     return;
    // }
    // that.string[1] = '\0';
    // that.type = *p;
    // return;
}

void initialize(),get_array(),get_params(),get_lparen(),get_ptr_part(),get_type();
void (*nextstate)(void) = initialize;


int main(){

    while(nextstate != NULL)
        nextstate();
    system("pause");
    return 0;
}

void initialize(){
    gettoken();
    while(that.type!=IDENTIFIER){
        push(that);
        gettoken();
    }
    printf("%s is ",that.string);
    gettoken();
    nextstate = get_array;
}

void get_array(){
    nextstate = get_params;
    while (that.type == '[')
    {
        /* code */
        gettoken();
        if(isdigit(that.string[0])){
            printf("0..%d ",atoi(that.string)-1);
            gettoken();//读取‘]’
        }
        gettoken();
        printf("of ");
        nextstate = get_lparen;
    }
    
}

void get_params(){
    nextstate = get_lparen;
    if(that.type == '('){
        while(that.type!=')')
            gettoken();
        printf("function returnning");
    }
}

void get_lparen(){
    nextstate = get_ptr_part;
    if(top >= 0){
        if(stack[top].type == '('){
            pop;
            gettoken();
            nextstate = get_array;
        }
    }
}

void get_ptr_part(){
    nextstate = get_type;
    if(stack[top].type == '*'){
        printf("pointer to");
        pop;
        nextstate = get_lparen;
    }
    else if(stack[top].type == QUALIFIER){
        printf("%s ",pop.string);
        nextstate = get_lparen;
    }
}

void get_type(){
    nextstate = NULL;
    while(top >= 0){
        printf("%s",pop.string);
    }
    printf("\n");
}




