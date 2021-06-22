#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

typedef struct snode
{
    /* data */
    char data;
    struct snode *next;
}snode ;
typedef struct snode *LiString;

//字符串赋值
void StrAssign(LiString *s,char cstr[]);

//字符串复制
void StrCopy(LiString *s,LiString t);

//字符串长度
int StrLength(LiString s);
//清空字符串
void StrClear(LiString s);
// //字符串是否为空
bool StrEmpty(LiString s);

//字符串比较  s>t 1  s=t 0  s<t -1
int StrCompare(LiString s,LiString t);



//字符串拼接
LiString Concat(LiString s,LiString t);
//求子串，如果没有返回空
LiString SubStr(LiString s,int begin,int len);
//插入字符串
LiString IndStr(LiString s,LiString t,int pos);

//删除字符串
LiString StrDel(LiString s,int begin,int len);
//字符串替代
LiString StrRep(LiString s,LiString t,int begin,int len);

//寻找子串t，并返回其位置
int Index(LiString s,LiString t);
//替换指定字符串 s1中寻找s2并替换s3 
LiString StrRepstr(LiString s1,LiString s2,LiString s3);

void display(LiString s);




