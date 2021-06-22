#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
//这个队列有缺陷
#define MAXSIZE 100

typedef struct 
{
    /* data */
    char data[MAXSIZE];
    int length;
}SqString;
//字符串赋值
void StrAssign(SqString *s,char cstr[]);
//字符串复制
void StrCopy(SqString *s,SqString t);
//清空字符串
void StrClear(SqString *s);
//字符串是否为空
bool StrEmpty(SqString *s);
//字符串比较  s>t 1  s=t 0  s<t -1
int StrCompare(SqString s,SqString t);
//字符串长度
int StrLength(SqString s);
//字符串拼接
SqString Concat(SqString s,SqString t);
//求子串，如果没有返回空
SqString SubStr(SqString s,int begin,int len);//插入字符串
SqString IndStr(SqString s,SqString t,int pos);
//删除字符串
SqString StrDel(SqString s,int begin,int len);
//字符串替代
SqString StrRep(SqString s,SqString t,int begin,int len);
//寻找子串t，并返回其位置
int Index(SqString s,SqString t);
//替换指定字符串 s1中寻找s2并替换s3 
SqString StrRepstr(SqString s1,SqString s2,SqString s3);

void display(SqString s1);
//aba ba 01123  -10012 01123
void GetNext(SqString t,int *next);
//aba  a abab  abab -1012
int KMPIndex(SqString s ,SqString t);