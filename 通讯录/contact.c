#include "contact.h"

// 初始化通讯录 -- 静态版本
// void InitConst(contact *pc)
// {
//     pc->sz = 0;
//     memset(pc->data, 0, sizeof(pc->data));
// }
// 初始化通讯录 -- 动态版本

// 加载文件到通讯录
void LoadContact(contact *pc)
{
    // 打开文件
    FILE *pf = fopen("contact.md", "r");
    if (pf == NULL)
    {
        perror("LoadContact");
        return;
    }
    // 读取文件
    perInfo temp = {0};
    while (fread(&temp, sizeof(perInfo), 1, pf))
    {
        // 通讯录增容的问题
        CheckContact(pc);
        pc->data[pc->sz++] = temp;
    }
    // 关闭文件
    fclose(pf);
    pf = NULL;
}

void InitConst(contact *pc)
{
    pc->data = (perInfo *)malloc(DEFAULT_SZ * sizeof(perInfo));
    if (pc->data == NULL)
    {
        perror("InitConst");
    }
    pc->sz = 0;
    pc->capacity = DEFAULT_SZ;
    // 加载文件
    LoadContact(pc);
}

// 增加联系人 -- 静态
// void AddContact(contact *pc)
// {
//     // 判断通讯录是否已满
//     if (pc->sz == MAX)
//     {
//         printf("通讯录已满,添加失败!\n");
//         return;
//     }
//     printf("请输入名字:>");
//     scanf("%s", pc->data[pc->sz].name);
//     printf("请输入年龄:>");
//     scanf("%d", &(pc->data[pc->sz].age));
//     printf("请输入性别:>");
//     scanf("%s", pc->data[pc->sz].sex);
//     printf("请输入电话:>");
//     scanf("%s", pc->data[pc->sz].tele);
//     printf("请输入地址:>");
//     scanf("%s", pc->data[pc->sz].addr);
//     pc->sz++;
//     printf("添加成功!\n");
// }

// 通讯录增容
void CheckContact(contact *pc)
{
    // 判断通讯录是否已满
    if (pc->sz == pc->capacity)
    {
        perInfo *ptr = (perInfo *)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(perInfo));
        if (ptr != NULL)
        {
            pc->data = ptr;
            pc->capacity += INC_SZ;
            printf("增加成功\n");
        }
        else
        {
            perror("AddContact");
            printf("增加失败\n");
            return;
        }
    }
}

// 增加联系人 -- 动态
void AddContact(contact *pc)
{
    CheckContact(pc);
    printf("请输入名字:>");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入年龄:>");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pc->sz].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pc->sz].addr);
    pc->sz++;
    printf("添加成功!\n");
}

// 打印联系人
void PrintContact(const contact *pc)
{
    // 打印标题
    printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");

    // 打印通讯录
    for (int i = 0; i < pc->sz; i++)
    {
        printf("%-15s\t%-5d\t%-5s\t%-12s\t%-15s\n",
               pc->data[i].name,
               pc->data[i].age,
               pc->data[i].sex,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

// 按名字查找联系人
int FindContact(contact *pc, char name[])
{
    for (int i = 0; i < pc->sz; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}
// 删除联系人
void DelContact(contact *pc)
{
    char name[MAX_NAME];
    // 判断通讯录是否为空
    if (pc->sz == 0)
    {
        printf("通讯录为空。无需删除\n");
        return;
    }
    // 按名字查找联系人,返回所在下标
    printf("请输入需要删除的联系人名字:");
    scanf("%s", name);
    int pos = FindContact(pc, name);
    if (-1 == pos)
    {
        printf("查找失败,没有此联系人!\n");
    }
    // 打印查找到的联系人
    printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");
    printf("%-15s\t%-5d\t%-5s\t%-12s\t%-15s\n",
           pc->data[pos].name,
           pc->data[pos].age,
           pc->data[pos].sex,
           pc->data[pos].tele,
           pc->data[pos].addr);

    // 删除联系人
    for (int i = pos; i < pc->sz - 1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->sz--;
    printf("删除成功\n");
}

// 查找联系人
void SearchContact(const contact *pc)
{
    contact *p = (contact *)pc;
    char name[MAX_NAME];
    // 判断通讯录是否为空
    if (pc->sz == 0)
    {
        printf("通讯录为空。无法查找\n");
        return;
    }
    // 按名字查找联系人,返回所在下标
    printf("请输入需要查找的联系人名字:");
    scanf("%s", name);
    int pos = FindContact(p, name);
    if (-1 == pos)
    {
        printf("查找失败,没有此联系人!\n");
    }
    // 打印查找到的联系人
    printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");
    printf("%-15s\t%-5d\t%-5s\t%-12s\t%-15s\n",
           pc->data[pos].name,
           pc->data[pos].age,
           pc->data[pos].sex,
           pc->data[pos].tele,
           pc->data[pos].addr);
}

// 修改联系人
void ModifyContact(contact *pc)
{

    char name[MAX_NAME];
    // 判断通讯录是否为空
    if (pc->sz == 0)
    {
        printf("通讯录为空。无法修改\n");
        return;
    }
    // 按名字查找联系人,返回所在下标
    printf("请输入需要修改的联系人名字:");
    scanf("%s", name);
    int pos = FindContact(pc, name);
    if (-1 == pos)
    {
        printf("查找失败,没有此联系人!\n");
    }
    // 打印查找到的联系人
    printf("%-15s\t%-5s\t%-5s\t%-12s\t%-15s\n", "名字", "年龄", "性别", "电话", "地址");
    printf("%-15s\t%-5d\t%-5s\t%-12s\t%-15s\n",
           pc->data[pos].name,
           pc->data[pos].age,
           pc->data[pos].sex,
           pc->data[pos].tele,
           pc->data[pos].addr);
    printf("请输入名字:>");
    scanf("%s", pc->data[pos].name);
    printf("请输入年龄:>");
    scanf("%d", &(pc->data[pos].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pos].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pos].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pos].addr);

    printf("修改成功!\n");
}
// 销毁通讯录
void DestoryContact(contact *pc)
{
    free(pc->data);
    pc->data = NULL;
    pc->sz = 0;
    pc->capacity = 0;
}
// 保存通讯录到文件
void SaveContact(contact *pc)
{
    // 打开文件
    // 退出时保存通讯录到文件contact.md
    FILE *pf = fopen("contact.md", "w");
    if (pf == NULL)
    {
        perror("SaveContact");
        return;
    }
    for (int i = 0; i < pc->sz; i++)
    {
        fwrite(pc->data + i, sizeof(perInfo), 1, pf);
    }
}