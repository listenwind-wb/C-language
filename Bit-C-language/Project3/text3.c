#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int test()
{
	int a = 3;
	if (3 == a)
		return 1;
	return 0;
}
int test1()
{
	int a = 3;
	if (3 == a)// if语句只有一条语句时，可以省略大括号
		return 1;
	else
		return 0;
}
struct Student
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
};// 结构体定义, 注意分号结尾
void print(struct Student* pstu)// 结构体变量作为函数参数，传递结构体变量地址
{
	printf("%s %d %s %s\n", pstu->name, pstu->age, pstu->sex, pstu->tele);// 结构体指针访问成员，使用 -> 运算符
}

int main()
{
	//1.指针
	// 指针是一个变量，存储另一个变量的地址，指针变量的类型决定了指针变量所指向的变量的类型
	int a = 10;
	int* p = &a; // & 取地址运算符，获取变量的地址，并赋值给指针变量
	printf("a = %d\n", a);
	printf("*p = %d\n", *p); // * 解引用运算符，获取指针变量所指向的变量的值
	printf("%p\n", &a);// %p 格式化输出指针变量
	printf("%p\n", p);
	printf("%p\n", &p);// 指针变量本身也是一个变量，有自己的地址
	char ch = 'w';
	char* pc = &ch;
	*p = 's';// 通过指针变量修改指针所指向的变量的值
	printf("a = %c\n", a);
	int* p1, * p2, * p3; // 声明多个指针变量

	//2.指针变量的大小
	// 指针变量的大小与平台有关，32位平台指针变量4字节，64位平台指针变量8字节
	printf("int* = %zu\n", sizeof(int*));
	printf("char* = %zu\n", sizeof(char*));
	printf("double* = %zu\n", sizeof(double*));
	printf("short* = %zu\n", sizeof(short*));
	printf("float* = %zu\n", sizeof(float*));
	printf("long* = %zu\n", sizeof(long*));
	printf("long long* = %zu\n", sizeof(long long*));
	printf("void* = %zu\n", sizeof(void*));// void* 通用指针

	//3.结构体
	// 结构体是用户自定义的数据类型，可以包含多个不同类型的成员变量
	// 结构体定义， struct 关键字，结构体标签，成员变量，分号结尾
	struct Student stu = { "张三", 20, "男", "13800138000" };// 结构体变量定义和初始化
	printf("name = %s\n", stu.name);// 结构体成员访问，使用点号 . 运算符
	printf("age = %d\n", stu.age);
	printf("sex = %s\n", stu.sex);
	printf("tele = %s\n", stu.tele);
	printf("%s %d %s %s\n", stu.name, stu.age, stu.sex, stu.tele);
	print(&stu);// 结构体变量作为函数参数，传递结构体变量地址

	//17.if语句
	// if (条件表达式) { 语句体 }
	// if (条件表达式1) { 语句体1 } else if (条件表达式2) { 语句体2 } else { 语句体3 }
	//0表示假，非0表示真
	if (3 == 3)
	{
		printf("条件为真\n");
	}
	else
	{
		printf("条件为假\n");
	}

	int age = 10;
	if (age < 18)
	{
		printf("未成年\n");
		printf("不能喝酒\n");
	}
	else if (age >= 18 && age < 28)
	{
		printf("青年人\n");
	}
	else if (age >= 28 && age < 40)
	{
		printf("中年人\n");
	}
	else if (age >= 40 && age < 60)
	{
		printf("壮年人\n");
	}
	else if (age >= 60 && age < 80)
	{
		printf("老年人\n");
	}
	else
	{
		printf("老寿星\n");
	}

	int b = 0;
	int c = 2;
	if (b == 1)
		if (c == 1)
			printf("b = 0 and c = 1\n");
		else
			printf("b = 0 and c != 1\n");// else 与离它最近的 if 配对
	//不打印结果

	if (b == 0)
	{
		if (c == 2)
			printf("b = 0 and c = 1\n");
	}
	else
	{
		printf("b = 0 and c != 1\n");
	}// 使用大括号明确 else 所属的 if

	//4.变量的命名
	// 1. 只能包含字母、数字、下划线  2. 不能以数字开头  3. 不能使用关键字  4. 区分大小写 5. 有意义，见名知意
	char first_name;
	char FistName;

	//5.if书写
	int d = test();
	int e = test1();
	printf("d = %d e = %d\n", d, e);

	//6.if练习
	int num = 0;
	printf("请输入一个整数：");
	scanf("%d", &num);
	if (num % 2 == 1)
		printf("%d是奇数\n", num);
	else
		printf("%d是偶数\n", num);

	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			printf("%d\n", i);
	}

	while (i <= 100)
	{
		if (i % 2 == 1)
			printf("%d\n", i);
		i++;
	}

	while (i <= 100)
	{
		printf("%d\n", i);
		i += 2;
	}

	//7.switch语句
	// switch (表达式) { case 常量1: 语句体1; break; case 常量2: 语句体2; break; ... default: 语句体n; },常量只能是整型或字符型
	// break 结束当前 case，跳出 switch 语句
	// default 可选，所有 case 都不匹配时执行
	int day = 0;
	printf("请输入一个1-7的整数：");
	scanf("%d", &day);
	if (1 == day)
		printf("Monday\n");
	else if (2 == day)
		printf("Tuesday\n");
	else if (3 == day)
		printf("Wednesday\n");
	else if (4 == day)
		printf("Thursday\n");
	else if (5 == day)
		printf("Friday\n");
	else if (6 == day)
		printf("Saturday\n");
	else if (7 == day)
		printf("Sunday\n");
	else
		printf("输入错误\n");

	switch (day)
	{
	case 1:
		printf("Monday\n");
		break;
	case 2:
		printf("Tuesday\n");
		break;
	case 3:
		printf("Wednesday\n");
		break;
	case 4:
		printf("Thursday\n");
		break;
	case 5:
		printf("Friday\n");
	case 6:
		printf("Saturday\n");
		break;
	case 7:
		printf("Sunday\n");
		break;
	default:
		printf("输入错误\n");
		break;

	}

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:m++;
	case 2:n++;
	case 3:
		switch (n)
		{
		case 1:n++;
		case 2:m++; n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		n++;
		break;
	}
	printf("n = %d m = %d\n", n, m);






































































	return 0;
}