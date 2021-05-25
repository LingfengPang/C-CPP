#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H
#include <string>

//联系人结构体
struct Person
{
    std::string name;
    long number;
    /* data */
};

struct Address
{
    struct Person person[1000];
    int size;
    /* data */
};
typedef struct Address Ads;

void showMenu();
void addPerson(Ads * ads);
void showPerson(Ads ads);
int findPerson(Ads ads);
void delPerson(Ads * ads);
void fixPerson(Ads * ads);
#endif