#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int Add(int x, int y)
{
	return x + y;
}
void test()
{
	static int count = 1;  // static 变量只初始化一次，生命周期是整个程序运行期间,只能在定义它的函数内访问
	count++;
	printf("count = %d\n", count);
}
extern int g_val; // 声明一个外部变量，告诉编译器这个变量在其他文件中定义
extern int add(int x, int y); // 声明一个外部函数，告诉编译器这个函数在其他文件中定义
#define NUM 100 // 定义一个宏，宏是一种文本替换机制，在预处理阶段进行文本替换
#define ADD(x,y) ((x)+(y)) // 定义一个带参数的宏,注意宏的参数不要加类型，宏的参数不要加括号,防止优先级错误,如 ADD(1+2,3+4) 会被替换为 (1+2+3+4)
int main() {

	//1. 算术运算符
	int a = 7 / 2;  // 7除以2的商
	int b = 7 % 2; // 7除以2的余数,两端只能用于整数
	printf("%d\n", a);
	printf("%d\n", b);

	//2. 赋值运算符
	int c = 0;//初始化
	c = 20;//赋值

	//3. 复合赋值运算符
	int e = 10;
	int f = e++;//f = e; e = e + 1;
	printf("e = %d\n", e);
	printf("f = %d\n", f);
	e = 10;
	f = ++e;//e = e + 1; f = e;
	printf("e = %d\n", e);
	printf("f = %d\n", f);

	//4. 关系运算符
	int g = (int)3.923;//强制类型转换
	printf("g = %d\n", g);

	//5. 逻辑运算符
	// && 逻辑与， || 逻辑或， ! 逻辑非
	int h = 10;
	int i = 20;
	if (h && i)
	{
		printf("h && i 为真\n");
	}
	h = 0;
	if (h || i)
	{
		printf("h || i 为真\n");
	}
	if (!h)
	{
		printf("!h 为真\n");
	}

	//6.条件操作符
	// 变量 = 条件表达式 ? 表达式1 : 表达式2;
	// 如果条件表达式为真，执行表达式1，否则执行表达式2
	int j = 11;
	int k = 20;
	int max = (j > k) ? j : k;
	printf("max = %d\n", max);

	//7.逗号表达式
	// 逗号表达式从左到右依次计算各个子表达式，整个逗号表达式的值为最后一个子表达式的值
	int n = (a = 10, b = 20, c = a + b, a + b + c);
	printf("n = %d\n", n);

	//8.下标操作符
	// 变量[下标]
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("初始arr[3] = %d\n", arr[3]);
	arr[3] = 20;
	printf("操作后的arr[3] = %d\n", arr[3]);

	//9.函数调用操作符
	// 函数名(实参表)
	// 函数调用操作符用于调用函数
	int sum = Add(10, 20);
	printf("sum = %d\n", sum);

	//10.常见关键字
	// int, return, if, else, while, for, break, continue, switch, case, default
	// void, const, enum, struct, typedef, sizeof, static, extern, goto
	// do, signed, unsigned, long, short, double, float, char
	// auto, register
	// volatile, union, sizeof, inline, restrict
	//关键字不能作为变量名
	//auto int a = 10; // auto 可以省略
	//变量的命名：1. 只能包含字母、数字、下划线  2. 不能以数字开头  3. 不能使用关键字  4. 区分大小写 5. 有意义，见名知意

	//12.typedef	
	// typedef 用于给类型起别名
	// typedef 原类型名 新类型名;
	typedef unsigned int UINT;
	UINT m = 20;
	printf("m = %u\n", m);

	//13.static
	// static 用于定义静态变量，静态变量的生命周期是整个程序运行
	// 静态变量只初始化一次，默认初始化为0
	int p = 1;
	while (p <= 10)
	{
		test(); // 每次调用test函数，count都会加1,但count只初始化一次
		p++;

	}

	int count = 2; // 局部变量，和函数中的静态变量count不是同一个变量
	printf("main中的count = %d\n", count); // 访问的是main函数中的局部变量count

	//14. extern
	// extern 用于声明外部变量，告诉编译器这个变量在其他文件
	printf("g_val = %d\n", g_val);
	int q = 10;
	int r = 20;
	int result = add(q, r);
	printf("result = %d\n", result);

	//15.register
	// register 用于定义寄存器变量，寄存器变量存储在CPU的寄存器中，访问速度快，但寄存器数量有限
	// register 只能修饰局部变量，不能修饰全局变量和函数
	register int s = 10;//建议将变量存储在寄存器中，但不一定会存储在寄存器中，由编译器决定

	//16.#define
	// #define 用于定义宏，宏是一种文本替换机制，在预处理阶段进行文本替换
	// #define 宏名 替换文本
	//宏的
	printf("NUM = %d\n", NUM);
	int t = ADD(10, 20);
	printf("t = %d\n", t);



















	return 0;
}