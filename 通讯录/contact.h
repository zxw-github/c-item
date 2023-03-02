// contact.h -- 类型的定义，函数的声明
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_IDDR 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2
// 联系人信息
typedef struct PerInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_IDDR];
} perInfo;

// // 通讯录 -- 静态版本
// typedef struct Contact
// {
//     perInfo data[MAX]; // 存放联系人的信息
//     int sz;            // 当前通讯录的联系人的个数
// } contact;
// 通讯录 -- 动态版本
typedef struct Contact
{
    perInfo *data; // 存放联系人的信息
    int sz;        // 当前通讯录的联系人的个数
    int capacity;  // 通讯录可存放的最大容量
} contact;

// 初始化通讯录
void InitConst(contact *pc);
// 增加联系人
void AddContact(contact *pc);
// 打印联系人
void PrintContact(const contact *pc);
// 删除联系人
void DelContact(contact *pc);
// 查找联系人
void SearchContact(const contact *pc);
// 修改联系人
void ModifyContact(contact *pc);
// 销毁通讯录
void DestoryContact(contact *pc);
// 保存通讯录到文件
void SaveContact(contact *pc);
// 加载文件
void LoadContact(contact *pc);
// 通讯录增容的问题
void CheckContact(contact *pc);