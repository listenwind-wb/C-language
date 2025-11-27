#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int b = 20;
int Max(int x, int y)
{
    return (x > y) ? x : y;
}

int main() {
    // 1. 打印 "hello world!" 到控制台
    printf("hello world!\n");

    // 2. 打印各数据类型的字节大小
    printf("char       : %zu\n", sizeof(char));
    printf("short      : %zu\n", sizeof(short));
    printf("int        : %zu\n", sizeof(int));
    printf("long       : %zu\n", sizeof(long));
    printf("long long  : %zu\n", sizeof(long long));
    printf("float      : %zu\n", sizeof(float));
    printf("double     : %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));

    // 3. 变量声明
    int age = 18;
    double price = 66.66;
    int high = 180;
    float weight = 60.0f; // 推荐加 f 后缀
    int a = 10;

    // 4. 输入两个整数并输出和
    /*int num1 = 0;
    int num2 = 0;
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    printf("sum = %d\n", sum);*/

    //5. const 常变量
    const int c = 30;

    //6. #define 定义常量
#define MAX 100
    printf("c = %d, MAX = %d\n", c, MAX);
    int d = MAX;
    printf("d = %d\n", d);

    // 7. 枚举类型
    enum Color { RED, GREEN, BLUE };

    // 枚举转字符串输出
    const char* color_names[] = { "RED", "GREEN", "BLUE" };
    enum Color color = RED;
    printf("color = %s\n", color_names[color]);
    color = GREEN;
    printf("color = %s\n", color_names[color]);
    color = BLUE;
    printf("color = %s\n", color_names[color]);

    //8. 字符和字符串
    char ch = 'w';
    char str[] = "hello";
    char arr[] = { 'a', 'b', 'c', 'd', 'e' };
    char arr2[] = { 'a', 'b', 'c', 'd', 'e', '\0' }; // 字符数组最后加 \0
    printf("str = %s\n", str);
    printf("arr = %s\n", arr);
    printf("arr2 = %s\n", arr2);

    //9. 字符串长度
    int len = strlen(str);
    printf("len =%d\n", len);
    printf("arr的长度 = %d\n", strlen(arr));
    printf("arr2的长度 = %d\n", strlen(arr2));
    printf("%d\n", strlen("c:\test\628\test.c")); // 计算字符串长度时，\t \62 \t 都是转义字符

    //10. 转义字符
    // \n 换行， \t 制表符， \\ 反斜杠， \' 单引号， \" 双引号
    //  \ooo 八进制表示的字符， \xhh 十六进制表示的字符
    printf("%c\n", '\'');
    printf("abcd\\0123\n");
    printf("%c\n", '\130');// 八进制
    printf("%c\n", '\x4B');// 十六进制

    //11. 练习题
  //  int input = 0;
  //  printf("要好好学习吗（1/0）？");
  //  scanf("%d", &input);
  //  if (input == 1)
  //  {
  //     printf("好好学习，天天向上！\n");
  //  }
  //  else
  //  {
        //printf("不学，变傻！\n");
  //  }

    //12. 循环打印 "I love China!" 100遍
    int line = 0;
    while (line <= 100)
    {
        printf("I love China!%d\n", line);
        line++;
    }

    //13. 循环打印数组元素
    int arr_1[5] = { 1,2,3,4,5 };
    int i = 0;
    while (i < 5)
    {
        printf("%d\n ", arr_1[i]);
        i++;

    }

    //14. 函数调用
   /* int h = 0;
    int b = 0;
    scanf("%d %d", &h, &b);
    int r = Max(h, b);
    printf("Max = %d\n", r);*/

    //15. if 语句
 //   int x = 0;
 //   int y = 0;
    //scanf("%d", &x);
 //   if (x > 0)
 //       y = -1;
 //   else if (x == 0)
 //       y = 0;
 //   else 
    //	y = 1;
    //printf("y = %d\n", y);























    return 0;
}