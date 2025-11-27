#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void Add1(int* p)
{
    (*p)++;
}

int binary_search(int arr[], int k, int sz) //这里arr是指针变量，数组传参实际上传递是数组首元素的地址
{
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            return mid;//找到了，返回下标
        }
    }
    return -1;//找不到
}

int is_leap_year(int y)
{
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        return 1;
    else
        return 0;
}

int is_prime(int n)
{
    int j = 0;
    for (j = 2; j <= sqrt(n); j++)
    {
        if (n % j == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Add(int x, int y)
{
    return x + y;
}

void Swap(int* x, int* y)
{
    int z = 0;
    z = *x;
    *x = *y;
    *y = z;
}

int get_max(int x, int y)
{
    return (x > y ? x : y);

}

void menu()
{
    printf("*************************\n");
    printf("*******  1.play  ********\n");
    printf("*******  0.exit  ********\n");
}

void game()
{

    int ret = rand() % 100 + 1;
    int guess = 0;
    while (1)
    {
        printf("请猜数字:>");
        scanf("%d", &guess);
        if (guess < ret)
        {
            printf("猜小了\n");
        }
        else if (guess > ret)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你，猜对了");
            break;
        }
    }

}

int main()
{
    //01.字符串逐步替换
    char arr1[] = "welcome to bit!!!!";
    char arr2[] = "##################";

    int left = 0;
    int right = strlen(arr2) - 1;//int right = sizeof(arr1) / sizeof(arr1[0]) - 1;

    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\n", arr2);
        Sleep(1000);
        system("cls");//system() 函数用于执行操作系统的命令，而括号中的 "cls" 是 Windows 系统命令行中的清屏指令，执行后会清除当前控制台（命令提示符窗口）中显示的所有内容，使光标回到屏幕左上角。
        left++;
        right--;
    }
    printf("%s\n", arr2);

    //02.有限次简单的密码验证功能
    int i = 0;
    char password[20] = { 0 };
    for (i = 0; i < 3; i++)
    {
        printf("请输入密码:>");
        scanf("%s", password);
        if (strcmp(password, "abcdef") == 0) //strcmp是 C 语言标准库中的字符串比较函数，用于比较两个字符串的内容
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
        }

    }
    if (i == 3)
    {
        printf("三次密码输入错误，退出程序\n");
    }

    //03
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏");
            break;
        default:
            printf("出错了");
            break;
        }
        break;
    } while (input);

    //04.
    char input[20] = { 0 };
    system("shutdown -s -t 60");
again:
    printf("请注意，你的电脑将在60秒内关机，如果输入：我是猪咪，就会取消关机哦\n");
    scanf("%s", &input);
    if (strcmp(input, "我是猪咪") == 0)
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }

    //05
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int m = get_max(a, b);
    printf("%d", m);

    //06
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int c = Add(a, b);
    int e = Add(a - b, b);
    int d = Add(Add(a, b), b);
    printf("c=%d,e=%d,d=%d\n", c, e, d);
    printf("交换前：a=%d ,b=%d\n", a, b);
    Swap(&a, &b);
    printf("交换后：a=%d ,b=%d\n", a, b);


    //07
    int i = 0;
    int count = 0;
    for (i = 100; i <= 200; i++)
    {
        int flag = 1;//flag是1，表示是素数
        for (int j = 2; j <= i - 1; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
            printf("%d ", i);
        }

    }
    printf("\ncount = %d", count);

    //优化：
    int i = 0;
    int count = 0;
    for (i = 101; i <= 200; i += 2)
    {
        int flag = 1;//flag是1，表示是素数
        for (int j = 2; j <= sqrt(i); j++)//sqrt()开平方
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
            printf("%d ", i);
        }

    }
    printf("\ncount = %d", count);

    //自定义函数
    int i = 0;
    int count = 0;
    for (i = 101; i <= 200; i += 2)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\ncount = %d", count);

    //08
    int year = 0;
    for (year = 1000; year <= 2000; year++)
    {
        if (year % 4 == 0)
        {
            if (year % 100 != 0)
            {
                printf("%d ", year);
            }

        }
        if (year % 400 == 0)
        {
            printf("%d ", year);
        }
    }


    int year = 0;
    for (year = 1000; year <= 2000; year++)
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            printf("%d ", year);
        }
    }

    int year = 0;
    for (year = 1000; year <= 2000; year++)
    {
        if (is_leap_year(year))
        {
            printf("%d ", year);
        }
    }

    //09
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int k = 7;
    int sz = sizeof(arr) / sizeof(arr[0]);
    //找到了，返回下标
    //找不到，返回-1
    int ret = binary_search(arr, k, sz);
    if (ret == -1)
        printf("找不到\n");
    else
        printf("找到了，下标是：%d\n", ret);

    //10
    int num = 0;
    Add1(&num);
    printf("%d\n", num);
    Add1(&num);
    printf("%d\n", num);


































    return 0;
}