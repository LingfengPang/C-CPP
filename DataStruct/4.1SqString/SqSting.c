#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
//这个队列有缺陷
#include "SqSting.h"

//字符串赋值
void StrAssign(SqString *s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++){
        s->data[i] = cstr[i];
    }
    s->length=i;
}

//字符串复制
void StrCopy(SqString *s,SqString t){
    int i;
    for(i = 0;i<t.length;i++)
        s->data[i] = t.data[i];
    s->length=t.length;
}
//清空字符串
void StrClear(SqString *s){
    if(s->length>0)
        s->length = 0;
}

//字符串是否为空
bool StrEmpty(SqString *s){
    return s->length == 0;
}

//字符串比较  s>t 1  s=t 0  s<t -1
int StrCompare(SqString s,SqString t){
    int len,i;
    int flag = 0;
    if(s.length>t.length)
        len = t.length;
    else
        len = s.length;
    for(i = 0;i<len;i++){
        if(s.data[i]<t.data[i])
            return -1;
        else if(s.data[i]>t.data[i])
            return 1;
    }
    if(s.length == t.length)
        return 0;
    else if(s.length>t.length)
        return 1;
    else
        return -1; 
}

//字符串长度
int StrLength(SqString s){
    return s.length;
}

//字符串拼接
SqString Concat(SqString s,SqString t){
    SqString str;
    int i;
    str.length =s.length + t.length;
    for(i = 0;i<s.length;i++){
        str.data[i] = s.data[i];
    }
    for(i = 0;i<t.length;i++){
        str.data[s.length+i] = t.data[i];
    }
    return str;
}
//求子串，如果没有返回空
SqString SubStr(SqString s,int begin,int len){
    SqString str;
    int i;
    str.length = 0;
    if(begin<0||begin > s.length || len<0 || begin+len-1>s.length)
        return str;
    for(i = begin - 1;i<begin+len-1;i++)
        str.data[i-begin+1] = s.data[i];
    str.length = len;
    return str;
}
//插入字符串
SqString IndStr(SqString s,SqString t,int pos){
    SqString str;
    int i;
    str.length = 0;
    if(pos<0||pos>s.length+1)//可以加在字符串尾部
        return str;
    for(i = 0;i<pos-1;i++){

        str.data[i] = s.data[i];
    }
    for(i = 0;i<t.length;i++)
        str.data[pos-1+i] = t.data[i];
    for(i = pos-1;i<s.length;i++)
        str.data[t.length+i] = s.data[i];
    str.length = s.length + t.length;
    return str;
}

//删除字符串
SqString StrDel(SqString s,int begin,int len){
    SqString str;
    int i;
    str.length = 0;
    if(begin<0||begin > s.length || len<0 || begin+len-1>s.length)
        return str;
    for(i = 0;i<begin-1;i++)
        str.data[i] = s.data[i];
    for(i = begin+len-1;i<s.length;i++)
        str.data[i - len] = s.data[i];
    str.length = s.length - len; 
    return str;
}
//字符串替代
SqString StrRep(SqString s,SqString t,int begin,int len){
    SqString str;
    str = StrDel(s,begin,len);
    str = IndStr(str,t,begin);
    return str;
}

//寻找子串t，并返回其位置
int Index(SqString s,SqString t){
   int i = 0;
   SqString str;
   while(i<s.length - t.length +1){
       if(s.data[i] == t.data[0]){
           str = SubStr(s,i+1,t.length );
           if(StrCompare(t,str) == 0)
                return i+1;
       }
       i++;
   }
   return 0;//没有则返回0
}
//替换指定字符串 s1中寻找s2并替换s3 
SqString StrRepstr(SqString s1,SqString s2,SqString s3){
    SqString str;
    int pos;
    str.length = 0;
    if(s1.length == 0|| s2.length == 0 || s3.length == 0)
        return str;
    pos = Index(s1,s2);
    if(pos == 0)//没有字串
        return str;
    else{
        str = StrRep(s1,s3,pos,s2.length);
    }
    return str;
}

void display(SqString s1){
    for(int i = 0;i < s1.length ;i++)
        printf("%c",s1.data[i]);
    printf("\n");
}
//aba ba 01123  -10012 01123
void GetNextVal(SqString t,int *nextval){
    int j,k;
    j = 0;
    k = -1;
    nextval[0] = -1;
    while(j<t.length){
        if(k == -1||t.data[j] == t.data[k]){
            j++;
            k++;
            if(t.data[j]!=t.data[k])
                nextval[j] = k;
            else 
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
    
}

//aba  a abab  abab -1012
int KMPIndex(SqString s ,SqString t){
    int next[MAXSIZE],i=0,j=0;
    GetNextVal(t,next);
    while(i<s.length&&j<t.length){
        if(j == -1||s.data[i] == t.data[j]){
            i++;//5
            j++;//3
        }
        else
            j = next[j];//-1
    }
    if(j>=t.length)
        return (i-t.length+1);
    else
    {
        return -1;
    }
    
}


int main(){
    SqString str1,str2,str;
    int flag;
    str1.length = 0;
    str2.length = 0;
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

    flag = KMPIndex(str,str2);
    printf("result is %d\n",flag);
    printf("\n");

    StrAssign(&str1,"boy");
    str = StrRepstr(str,str2,str1);
    display(str);
    printf("\n");

    {
        int next[5];
        StrAssign(&str1,"ababa");
        GetNext(str1,next);
        for(int i = 0;i<5;i++){
            printf("%d",next[i]);
        }

    }



       
    system("pause");
    return 0;
}