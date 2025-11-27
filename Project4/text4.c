#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int sum(int g)
{
	int s = 0;
	static int i = 1;
	s += 1;
	i += 2;
	return (g + s + i);
}
int main()
{
	//1.while循环
	// while (条件表达式) { 语句体 }， 条件为真时执行语句体， 条件为假时跳出循环
	// 注意避免死循环
	//break 的作⽤是⽤于终⽌循环的，在 while 循环中，只要有机会执⾏到 break ，不管后续还可能有多少次循环，循环都会终⽌
	//continue是继续的意思，在循环中的作⽤就是跳过本次循环中continue下⼀次循环的判断
	int i = 1;
	while (i <= 10)
	{
		printf("i = %d\n", i);
		i++;
	}
	i = 1;
	while (i <= 10)
	{
		if (5 == i)
			break;                // break 结束整个循环
		printf("i = %d\n", i);
		i++;
	}
	i = 0;
	while (i <= 9)
	{
		i++;
		if (5 == i)
			continue;             // continue 跳过本次循环，进入下一次循环        
		printf("i = %d\n", i);

	}

	//2.使用getchar()和putchar()实现一个简单的文本过滤程序
	//int ch = 0;
	//while ((ch = getchar()) != EOF)       // EOF 是一个宏，表示文件结束符
	//{
	//	if (ch == '\n')                   // 如果输入的是换行符，则跳过本次循环
	//		continue;                     // continue 跳过本次循环，进入下一次循环
	//	putchar(ch);                      // putchar() 函数将字符输出到标准输出流
	//}                                     // 注意：EOF 是一个宏，表示文件结束符，通常是 -1

	//int Ch = 0;
	//while ((Ch = getchar()) != EOF)
	//{
	//	if (Ch < '0' || Ch > '9')
	//		continue;
	//	putchar(Ch);
	//}                                     // 过滤掉非数字字符

	//3.使用while循环遍历数组,打印字符
	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };   // ASCII 码对应 "I can do it!"
	i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]); // 计算数组元素个数
	while (i < sz)
	{
		printf("%c", arr[i]);
		i++;
	}

	//4.使用scanf()格式化输入年月日，要求用户输入8位整数表示年月日，如20230615，分别提取出年、月、日并打印
	/*int year = 0;
	int month = 0;
	int date = 0;
	scanf("%4d%2d%2d", &year, &month, &date);
	printf("year=%d\n", year);
	printf("month=%02d\n", month);
	printf("date=%02d\n", date);*/

	//5.使用scanf()格式化输入学生的学号和各科成绩，要求用户输入格式如：1;95,88,92，分别提取出学号、C语言成绩、数学成绩、英语成绩并打印
	//int id = 0;
	//float C = 0.0f;
	//float math = 0.0f;
	//float eng = 0.0f;
	//scanf("%d;%f,%f,%f", &id, &C, &math, &eng);
	//printf("The each subject score of No. %d is %.2f, %.2f, %.2f.\n", id, C, math, eng);

	//6.printf()函数的返回值
	int n = printf("Hello World!");   // printf() 函数返回值是输出的字符个数
	printf("\nn = %d\n", n);

	//7.函数中static变量的使用
	int l;
	int m = 2;
	for (l = 1; l <= 5; l++)
	{
		printf("sum = %d\n", sum(m));
	}

	//8.C和C++中打印“Hello world!”的区别
	printf("\nprintf(\"Hello world!\\n\");\n");
	printf("cout << \"Hello world!\" << endl;\n");

	//9.使用while循环找出4个整数中的最大值
	//(1)
	/*int arr1[4] = { 0 };
	int g = 0;
	while (g < 4)
	{
		scanf("%d", &arr1[g]);
		g++;
	}
	int max = arr1[0];
	g = 1;
	while (g < 4)
	{
		if (arr1[g] > max)
		{
			max = arr1[g];
		}
		g++;
	}
	printf("max = %d", max);*/

	//(2)
	int g = 1;
	int k = 0;
	int max = 0;
	scanf("%d", &max);
	while (g < 4)
	{
		scanf("%d", &k);
		if (k > max)
			max = k;
		g++;
	}
	printf("max=%d", max);

	//10.for循环
	// for (初始化表达式; 条件表达式; 更新表达式) { 语句体 }
	// 初始化表达式：在循环开始前执行一次，用于初始化循环变量
	// 条件表达式：在每次循环开始前进行判断，条件为真
	// 更新表达式：在每次循环体执行完后执行，用于更新循环变量
	//1.不可在for 循环体内修改循环变量，防止 for  循环失去控制。
	//2. 建议for语句的循环控制变量的取值采用“前闭后开区间”写法。
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("i = %d\n", i);
		printf("hehe\n");
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 5)
			break;                // break 结束整个循环
		printf("%d ", i);

	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 5)
			continue;            // continue 跳过本次循环，进入下一次循环
		printf("%d ", i);

	}

	for (;;)                    // 无限循环
	{
		printf("hehe");

	}

	int i = 0;
	int j = 0;
	for (; i < 10; i++)
	{
		for (; j < 5; j++)
		{
			printf("i = %d, j = %d\n", i, j);
		}// 内层循环结束后，j 的值已经是5，再次进入内层循环时，条件 j < 5 不成立，内层循环不会执行
	}

	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		for (; j < 5; j++)
		{
			printf("i = %d, j = %d\n", i, j);
		}// 内层循环结束后，j 的值已经是5，再次进入内层循环时，条件 j < 5 不成立，内层循环不会执行


	}

	int x, y;
	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
	{
		printf("hehe\n");
	}

	//11.do while
	int i = 1;
	do
	{
		i++;
		if (i == 5)
			break;
		printf("%d ", i);

	} while (i <= 10);

	int i = 1;
	do
	{
		i++;
		if (i == 5)
			continue;
		printf("%d ", i);

	} while (i <= 10);

	//11

	int i = 1;
	int n = 0;
	int ret = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		ret = ret * i;
	}
	printf("%d\n", ret);



	int i = 1;
	int n = 0;
	int ret = 1;
	int sum = 0;
	for (n = 1; n <= 10; n++)
	{
		ret = 1;
		for (i = 1; i <= n; i++)
		{
			ret = ret * i;
		}
		sum = sum + ret;

	}
	printf("%d\n", sum);


	int n = 0;
	int ret = 1;
	int sum = 0;
	for (n = 1; n <= 10; n++)
	{
		ret = ret * n;
		sum = sum + ret;

	}
	printf("%d\n", sum);

	//12
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == k)
		{
			printf("找到了，下标是：%d\n", i);
			break;
		}

	}
	if (i == sz)
		printf("找不到");


	//有序数组，折半查找
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (left - right) / 2;    //防止相加数据溢出
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
			printf("找到了，下标是：%d\n", mid);
			break;

		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}


















































	return 0;
}