#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "LinkString.h"


//字符串赋值
void StrAssign(LiString *s,char cstr[]){
    int i;
    LiString r,p;
    (*s) = (LiString)malloc(sizeof(snode));
    r = (*s);
    for(i=0;cstr[i]!='\0';i++){
       p = (LiString)malloc(sizeof(snode));
       p->data = cstr[i];
       r->next = p;
       r = p;
    }
    r->next = NULL;
}

//字符串复制
void StrCopy(LiString *s,LiString t){
    LiString p = t->next;
    LiString q,r;
    (*s) = (LiString)malloc(sizeof(snode));
    r = *s;
    while(p){
        q = (LiString)malloc(sizeof(snode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next; 
    }
   r->next = NULL;
        
}

//字符串长度
int StrLength(LiString s){
    int i = 0;
    LiString p = s->next;
    while(p){
        p = p->next;
        i++;
    }
    return i;
}
//清空字符串
void StrClear(LiString s){
  s->next = NULL ; 
}

// //字符串是否为空
bool StrEmpty(LiString s){
    return s->next == NULL;
}

//字符串比较  s>t 1  s=t 0  s<t -1
int StrCompare(LiString s,LiString t){
    int len,i;
    int flag = 0;
    LiString p,q;
    p = s->next;
    q = t->next;
    if(StrLength(s)>StrLength(t))
        len = StrLength(t);
    else
        len = StrLength(s);
    for(i = 0;i<len;i++){
        if(p->data<q->data)
            return -1;
        else if(p->data>q->data)
            return 1;
        p = p->next;
        q = q->next;
    }
    if(StrLength(s) == StrLength(t))
        return 0;
    else if(StrLength(s)>StrLength(t))
        return 1;
    else
        return -1; 
}



//字符串拼接
LiString Concat(LiString s,LiString t){
    LiString str;
    int i;
    LiString p,q,r;
    str = (LiString)malloc(sizeof(snode));
    p = s->next;
    q = str;
    //str.length =s.length + t.length;
    for(i = 0;i<StrLength(s);i++){
        r = (LiString)malloc(sizeof(snode));
        r->data = p->data;
        q->next = r;
        q = r;
        p = p->next;
    }
    p = t->next;
    for(i = 0;i<StrLength(t);i++){
        r = (LiString)malloc(sizeof(snode));
        r->data = p->data;
        q->next = r;
        q = r;
        p = p->next;
    }
    r->next = NULL;
    return str;
}
//求子串，如果没有返回空
LiString SubStr(LiString s,int begin,int len){
    LiString str,p,q,r;
    str = (LiString)malloc(sizeof(snode));
    p = s;
    r = str;
    int i;
    if(begin<0||begin > StrLength(s) || len<0 || begin+len-1 > StrLength(s))
        return str;
    for(i = 0;i<begin;i++)
        p = p->next;
    for(i = 0;i<len;i++){
        q = (LiString)malloc(sizeof(snode));
        q->data =p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    r->next = NULL;
    return str;
}
//插入字符串
LiString IndStr(LiString s,LiString t,int pos){
    LiString str,p,p1,q,r;
    int i;
    str = (LiString)malloc(sizeof(snode));
    if(pos<0||pos>StrLength(s)+1)//可以加在字符串尾部
        return str;

    p = s->next; 
    r =str;   
    for(i = 0;i<pos;i++){
        if(!p){//如果是结尾插入
            break;
        }
        q = (LiString)malloc(sizeof(snode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
         
    }
    p1 = t->next;
    for(i = 0;i<StrLength(t);i++){
        q = (LiString)malloc(sizeof(snode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    for(i = pos;i<StrLength(s);i++){
        q = (LiString)malloc(sizeof(snode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;     
    return str;
}

//删除字符串
LiString StrDel(LiString s,int begin,int len){
    LiString str,p,q,r;
    int i;
    str = (LiString)malloc(sizeof(snode));
    r = str;
    p = s->next;
    if(begin<0||begin > StrLength(s) || len<0 || begin+len-1>StrLength(s))
        return str;
    for(i = 0;i<begin-1;i++){
        q = (LiString)malloc(sizeof(snode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    for(i = 0;i<len;i++){
        p = p->next;
    }
    while(p){
        q = (LiString)malloc(sizeof(snode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
        
    r->next = NULL; 
    return str;
}
//字符串替代
LiString StrRep(LiString s,LiString t,int begin,int len){
    LiString str;
    str = StrDel(s,begin,len);
    str = IndStr(str,t,begin);
    return str;
}

//寻找子串t，并返回其位置
int Index(LiString s,LiString t){
   int i = 0;
   LiString str,p,q;
   p = s->next;
   q = t->next;
   while(i<StrLength(s) - StrLength(t) +1){
       if(p->data == q->data){
           str = SubStr(s,i+1,StrLength(t) );
           if(StrCompare(t,str) == 0)
                return i+1;
       }
       i++;
       p = p->next;
   }
   return 0;//没有则返回0
}
//替换指定字符串 s1中寻找s2并替换s3 
LiString StrRepstr(LiString s1,LiString s2,LiString s3){
    LiString str;
    int pos;
    if(StrLength(s1) == 0|| StrLength(s2) == 0 || StrLength(s3) == 0)
        return str;
    pos = Index(s1,s2);
    if(pos == 0)//没有字串
        return str;
    else{
        str = StrRep(s1,s3,pos,StrLength(s2));
    }
    return str;
}

void display(LiString s){
    LiString p;
    p = s->next;
    while(p){
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}




int main(){
    //const char c1[] = "happy"; 
    LiString str1,str2,str;
    int flag;
    StrAssign(&str1,"happy");
    StrCopy(&str2,str1);
    display(str1);
    display(str2);
    printf("\n");

    StrAssign(&str1,"happy");
    flag = StrCompare(str1,str2);
    printf("result is %d\n",flag);
    printf("\n");

    flag = StrLength(str1);
    printf("result is %d\n",flag);
    printf("\n");

    StrAssign(&str2,"boy");
    str = Concat(str1,str2);
    display(str);
    printf("\n");

    str = SubStr(str1,1,2);
    display(str);
    printf("\n");

    str = IndStr(str1,str2,2);
    display(str);
    printf("\n");

    str = StrDel(str,3,3);
    display(str);
    printf("\n");

    StrAssign(&str2,"girl");
    StrAssign(&str,"happy");
    str = StrRep(str,str2,3,3);
    display(str);
    printf("\n");

    flag = Index(str,str2);
    printf("result is %d\n",flag);
    printf("\n");

    StrAssign(&str1,"boy");
    str = StrRepstr(str,str2,str1);
    display(str);
    printf("\n");




       
    system("pause");
    return 0;
}