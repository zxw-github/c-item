// main.c -- 测试通讯录的模块

// 通讯录
/*
要求：
1，通讯录可以存放1000个人的信息
2，每个人的信息：名字+年龄+性别+电话+住址
3，增加通讯录的信息
4，删除
5，查询
6，修改
7，排序
*/
#include "contact.h"

void menu()
{
    printf("**********************************\n");
    printf("*****  1. add     2. del *********\n");
    printf("*****  3. search  4. modify ******\n");
    printf("*****  5. sort    6. print *******\n");
    printf("*****        0. exit     *********\n");
    printf("************************************\n");
}
enum option
{
    EXIT,
    add,
    del,
    search,
    modify,
    sort,
    print
};
int main(void)
{
    // 创建通讯录
    contact con; // 通讯录
    // 初始化通讯录
    InitConst(&con);
    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case add:
            // 增加联系人
            AddContact(&con);
            break;
        case del:
            // 删除联系人
            DelContact(&con);
            break;
        case search:
            // 查找联系人
            SearchContact(&con);
            break;
        case modify:
            // 修改联系人
            ModifyContact(&con);
            break;
        case sort:
            // 排序
            break;
        case print:
            // 打印联系人
            PrintContact(&con);
            break;
        case EXIT:
            // 销毁通讯录
            DestoryContact(&con);
            printf("程序退出!\n");
            break;
        default:
            printf("输入错误,请重新输入!\n");
        }
    } while (input);

    return 0;
}