#define _CRT_SECURE_NO_WARNINGS  // 消除VS中scanf等函数的安全警告
#include <stdio.h>               // 标准输入输出头文件
#include <stdlib.h>              // 内存管理等函数头文件
#include <time.h>                // 时间相关函数（本代码未使用）
#include <windows.h>            // Windows系统函数（本代码未使用）
#include <string.h>             // 字符串操作函数头文件
#include <math.h>               // 数学函数头文件（如abs、max）
#include <stdbool.h>            // 布尔类型支持头文件

void test(int arr[])        //int arr[] ---> int* arr
{
	arr[0] = 10;            //arr[0] ---> *(arr + 0)
	arr[1] = 20;            //arr[1] ---> *(arr + 1)
}

void print_table(int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d\t", i, j, i * j);
		}
		printf("\n");
	}
}

// 函数：计算10的n次方，返回10^n的结果
int power_of_10(int n)
{
	int tep = 1;
	for (int i = 0; i < n; i++)
	{
		tep = tep * 10;
	}
	return tep;
}

// 函数：计算重复数字项的和（如x=2，y=3时，计算2+22+222的和）
int sum_of_repeated_digit_terms(int x, int y)
{
	int sum = 0;
	int s = 0;
	for (int i = 0; i < y; i++)
	{
		s = x * power_of_10(i) + s;
		sum = sum + s;
	}
	return sum;
}

// 函数：交换两个整数的地址值（功能18使用）
void Swap(int* px, int* py)   //18
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

// 函数：计算位运算（与、或、异或）的最大值且小于k（功能10）
void calculate_the_maximum(int n, int k) {     //10
	//Write your code here.
	int max1 = 0;  // 存储“与”运算的最大值
	int max2 = 0;  // 存储“或”运算的最大值
	int max3 = 0;  // 存储“异或”运算的最大值
	for (int i = 1; i < n; i++)
	{
		// 计算i和j的“与”运算，更新max1
		for (int j = i + 1; j <= n; j++)
		{
			int a = i & j;
			if (a < k && a > max1)
			{
				max1 = a;
			}
		}
		// 计算i和j的“或”运算，更新max2
		for (int j = i + 1; j <= n; j++)
		{
			int a = i | j;
			if (a < k && a > max2)
			{
				max2 = a;
			}
		}
		// 计算i和j的“异或”运算，更新max3
		for (int j = i + 1; j <= n; j++)
		{
			int a = i ^ j;
			if (a < k && a > max3)
			{
				max3 = a;
			}
		}
	}
	printf("%d\n%d\n%d", max1, max2, max3);
}

int main()
{
	//1.计算球的体积
	double r1 = 0.0;  // 球的半径
	double v1 = 0.0;  // 球的体积
	scanf("%lf", &r1);
	v1 = 4 / 3.0 * 3.145926 * r1 * r1 * r1;  // 球体积公式：(4/3)πr³
	printf("%.3lf\n", v1);

	//2.计算BMI指数
	int weight2 = 0;  // 体重（kg）
	int high2 = 0;    // 身高（cm）
	scanf("%d %d", &weight2, &high2);
	float bmi2 = weight2 / (high2 / 100.0) / (high2 / 100.0);  // BMI计算公式
	printf("%.2f\n", bmi2);  // 补充换行，避免输出粘连

	//3.体重正常吗
	int height3, weight3;
	// 循环读取输入，直到文件结束（EOF）
	while (scanf("%d %d", &height3, &weight3) != EOF) {
		// 计算BMI：身高转换为米（除以100），再计算平方
		float bmi3 = weight3 / ((height3 / 100.0) * (height3 / 100.0));
		// 输出BMI（保留2位小数）
		printf("%.2f ", bmi3);
		// 根据BMI范围判断体重状况
		if (bmi3 < 19) {
			printf("lower\n");
		}
		else if (bmi3 < 25) {
			printf("health\n");
		}
		else if (bmi3 < 30) {
			printf("heavy\n");
		}
		else if (bmi3 < 40) {
			printf("super heavy\n");
		}
		else {
			printf("extra heavy\n");
		}
	}
	while (getchar() != '\n');  // 吸收EOF前的换行，避免影响后续输入

	//5.打印字母菱形图案（版本1）
	int n5;
	scanf("%d", &n5);
	int mid5 = (n5 + 1) / 2;
	// 打印上半部分
	for (int i5 = 1; i5 <= mid5; i5++) {
		// 输出前导空格
		for (int j5 = 0; j5 < mid5 - i5; j5++) {
			printf(" ");
		}
		// 输出字母序列
		char ch5 = 'A' + i5 - 1;
		for (int j5 = 0; j5 < 2 * i5 - 1; j5++) {
			printf("%c", ch5 + j5);
		}
		printf("\n");
	}

	// 打印下半部分
	for (int i5 = mid5 - 1; i5 >= 1; i5--) {
		// 输出前导空格
		for (int j5 = 0; j5 < mid5 - i5; j5++) {
			printf(" ");
		}
		// 输出字母序列
		char ch5 = 'A' + i5 - 1;
		for (int j5 = 0; j5 < 2 * i5 - 1; j5++) {
			printf("%c", ch5 + j5);
		}
		printf("\n");
	}

	//5.打印字母菱形图案（版本2）
	int n6 = 0;
	scanf("%d", &n6);
	int mid6 = (n6 + 1) / 2;
	for (int i6 = 1; i6 <= mid6; i6++)
	{
		for (int j6 = 0; j6 < mid6 - i6; j6++)
		{
			printf(" ");
		}
		int ch6 = 'A' + i6 - 1;
		for (int j6 = 0; j6 < 2 * i6 - 1; j6++)
		{
			printf("%c", ch6 + j6);
		}
		printf("\n");
	}
	for (int i6 = 1; i6 <= mid6 - 1; i6++)
	{
		for (int j6 = 0; j6 < i6; j6++)
		{
			printf(" ");
		}
		int ch6 = 'A' + mid6 - i6 - 1;
		for (int j6 = 0; j6 < 2 * (mid6 - i6) - 1; j6++)
		{
			printf("%c", ch6 + j6);
		}
		printf("\n");
	}

	//6.字符输入输出（单个字符、无空格字符串、含空格字符串）
	char a6;
	char b6[100] = { 0 };  // 存储无空格字符串
	char c6[100] = { 0 };  // 存储含空格字符串
	getchar();  // 吸收前序输入的换行
	scanf("%c", &a6);
	scanf("%s", b6);  // 数组名本身是地址，无需&
	getchar();        // 吸收%s后的换行符
	scanf("%[^\n]", c6);  // 读取整行（含空格），数组名无需&
	printf("%c\n%s\n%s\n", a6, b6, c6);

	//7.整数与浮点数运算
	int a7, b7;
	float c7, d7;
	scanf("%d %d", &a7, &b7);
	while (getchar() != '\n');  // 清空输入缓冲区
	scanf("%f %f", &c7, &d7);
	printf("%d %d\n", a7 + b7, a7 - b7);
	printf("%.1f %.1f\n", c7 + d7, c7 - d7);

	//8.数字转英文（1-9）和奇偶判断（≥10）
	int a8, b8;
	scanf("%d %d", &a8, &b8);
	for (int n8 = a8; n8 <= b8; n8++)
	{
		if (n8 == 1) { printf("one\n"); }
		else if (n8 == 2) { printf("two\n"); }
		else if (n8 == 3) { printf("three\n"); }
		else if (n8 == 4) { printf("four\n"); }
		else if (n8 == 5) { printf("five\n"); }
		else if (n8 == 6) { printf("six\n"); }
		else if (n8 == 7) { printf("seven\n"); }
		else if (n8 == 8) { printf("eight\n"); }
		else if (n8 == 9) { printf("nine\n"); }
		else if (n8 > 9)
		{
			printf("%s\n", n8 % 2 == 0 ? "even" : "odd");
		}
	}

	//9.五位数各位和
	int n9;
	scanf("%d", &n9);
	int a9 = n9 % 10;      // 个位
	int b9 = n9 / 10 % 10; // 十位
	int c9 = n9 / 100 % 10;// 百位
	int d9 = n9 / 1000 % 10;// 千位
	int e9 = n9 / 10000;   // 万位
	int sum9 = a9 + b9 + c9 + d9 + e9;
	printf("%d\n", sum9);

	//10.调用位运算最大值函数
	int n10, k10;
	scanf("%d %d", &n10, &k10);
	calculate_the_maximum(n10, k10);

	//11.Print a pattern of numbers 
	int n11 = 0;
	scanf("%d", &n11);
	int i11, j11;
	int size11 = 2 * n11 - 1;
	for (i11 = -(n11 - 1); i11 <= n11 - 1; i11++)
	{
		for (j11 = -(n11 - 1); j11 <= n11 - 1; j11++)
		{
			int d11 = max(abs(i11), abs(j11));
			printf("%d ", d11 + 1);
		}
		printf("\n");
	}

	//12.动态数组求和
	int n12;
	int sum12 = 0;
	scanf("%d", &n12);
	int* arr12 = (int*)malloc(n12 * sizeof(int));
	for (int i12 = 0; i12 < n12; i12++)
	{
		scanf("%d", &arr12[i12]);
		sum12 = sum12 + arr12[i12];
	}
	printf("%d\n", sum12);
	free(arr12);
	arr12 = NULL;

	//13.税率计算
	int i13 = 0;
	float m13 = 0;
	scanf("%d", &i13);
	if (i13 <= 100000)
	{
		m13 = i13 * 0.1;
	}
	else if (i13 <= 200000)
	{
		m13 = 10000 + (i13 - 100000) * 0.075;
	}
	else if (i13 <= 400000)
	{
		m13 = 10000 + 7500 + (i13 - 200000) * 0.05;
	}
	else if (i13 <= 600000)
	{
		m13 = 10000 + 7500 + 10000 + (i13 - 400000) * 0.03;
	}
	else if (i13 <= 1000000)
	{
		m13 = 10000 + 7500 + 10000 + 6000 + (i13 - 600000) * 0.015;
	}
	else
	{
		m13 = 10000 + 7500 + 10000 + 6000 + 6000 + (i13 - 1000000) * 0.01;
	}
	printf("%d\n", (int)m13);

	//14.求最大公约数和最小公倍数（枚举法）
	int m14, n14, gcd14, lcm14;
	scanf("%d %d", &m14, &n14);
	int max14 = m14 >= n14 ? m14 : n14;
	int min14 = m14 <= n14 ? m14 : n14;
	// 求最大公约数
	for (int i14 = min14; i14 > 0; i14--)
	{
		if (m14 % i14 == 0 && n14 % i14 == 0)
		{
			gcd14 = i14;
			break;
		}
	}
	// 求最小公倍数
	for (int j14 = max14; j14 <= m14 * n14; j14++)
	{
		if (j14 % m14 == 0 && j14 % n14 == 0)
		{
			lcm14 = j14;
			break;
		}
	}
	printf("最大公约数: %d 最小公倍数: %d\n", gcd14, lcm14);

	//15.字符分类统计（字母、数字、空格、其他）
	char c15[200];
	scanf("%[^\n]", &c15);
	int letter15 = 0, digit15 = 0, space15 = 0, other15 = 0;
	int i15 = 0;
	for (i15 = 0; c15[i15] != '\0'; i15++)
	{
		if ((c15[i15] >= 'a' && c15[i15] <= 'z') || (c15[i15] >= 'A' && c15[i15] <= 'Z'))
		{
			letter15++;
		}
		else if (c15[i15] >= '0' && c15[i15] <= '9')
		{
			digit15++;
		}
		else if (c15[i15] == ' ')
		{
			space15++;
		}
		else
		{
			other15++;
		}
	}
	printf("%d %d %d %d\n", letter15, digit15, space15, other15);

	//16.注意赋值和比较的区别（此段会导致死循环，建议注释或理解后使用）
	int i16 = 0;
	for (i16 = 0; i16 < 10; i16++)
	{
		if (i16 = 5)                 // 注意：这里是赋值不是比较，会导致死循环
		{
			printf("i = %d\n", i16);
		}
	}

	//17.switch语句
	int n17 = 0;
	scanf("%d", &n17);
	switch (n17)
	{
	default:
		printf("呵呵\n");
		break;
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	}

	//18.排序三个数（降序）
	int a18 = 0, b18 = 0, c18 = 0;
	scanf("%d %d %d", &a18, &b18, &c18);

	int tmp18 = 0;
	if (a18 < b18)
	{
		Swap(&a18, &b18);
	}
	if (a18 < c18)
	{
		Swap(&a18, &c18);
	}
	if (b18 < c18)
	{
		Swap(&b18, &c18);
	}
	printf("%d %d %d\n", a18, b18, c18);

	//19.重复数字项求和（如2+22+222...）
	int n19 = 0;
	scanf("%d", &n19);
	int Sn19 = sum_of_repeated_digit_terms(2, n19);
	printf("%d\n", Sn19);

	//20.最大公约数（辗转相除法）
	int a20 = 0, b20 = 0, c20 = 0;
	scanf("%d %d", &a20, &b20);
	while ((c20 = a20 % b20) != 0)
	{
		a20 = b20;
		b20 = c20;
	}
	printf("%d\n", b20);

	//21.计算1到100之间9的个数
	int i21 = 0;
	int count21 = 0;
	for (i21 = 1; i21 <= 100; i21++)
	{
		if (i21 % 10 == 9)
			count21++;
		if (i21 / 10 == 9)
			count21++;
	}
	printf("count = %d\n", count21);

	//22.计算 100 项交替调和级数的和
	int i22 = 0;
	double sum22 = 0;
	int flag22 = 1;
	for (i22 = 1; i22 <= 100; i22++)
	{
		sum22 = sum22 + flag22 * (1.0 / i22);
		flag22 = -flag22;
	}
	printf("%lf\n", sum22);

	//23.找出数组 arr 中的最大值
	int arr23[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int max23 = arr23[0];
	int i23 = 0;
	for (i23 = 1; i23 < 10; i23++)
	{
		if (arr23[i23] > max23)
		{
			max23 = arr23[i23];
		}
	}
	printf("max = %d\n", max23);

	//24.打印乘法口诀表
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d\t", i, j, i * j);
		}
		printf("\n");
	}

	//25.自行决定打印乘法口诀表的行数
	int n = 0;
	scanf("%d", &n);
	print_table(n);

	//26.数组越界访问
	int arr[2] = { 0 };
	test(arr);
	printf("%d %d\n", arr[10], arr[1]);

	//27.计算阶乘之和
	int n = 0;
	int i = 0;
	long long Sn = 0;               //注意这里Sn 和 tep要用long long类型，否则会溢出
	long long tep = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		tep = tep * i;
		Sn = Sn + tep;
	}
	printf("%lld\n", Sn);

	return 0;
}