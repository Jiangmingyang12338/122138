#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//计算整数部分位数
int ws(double n)
{
	n = (int)n;
	int c = 0;
	if (n == 0) c = 1;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return c;
}
//展示界面
void showMenu()
{
	printf("||*********************||\n");
	printf("||   1、设置题目数量   ||\n");
	printf("||   2、设置题目符号   ||\n");
	printf("||   3、设置最大限制   ||\n");
	printf("||   4、设置是否小数   ||\n");
	printf("||   5、设置有小括号   ||\n");
	printf("||   6、生成运算题目   ||\n");
	printf("||-----0、退出系统-----||\n");
	printf("||*********************||\n");
}
//限制题目数量
int s_L(int n)
{
	cout << "请输入题目数量" << endl;
	cin >> n;
	system("pause"); 
	system("cls"); 
	return n;
}
//自选运算符号
char f_H(int s)
{
	char fh;
	cout << "请选择运算符号" << endl;
	cout << "1.+" << endl;
	cout << "2.-" << endl;
	cout << "3.*" << endl;
	cout << "4./" << endl;
	cin >> s;
	switch (s)
	{
	case 1: fh = '+'; break;
	case 2: fh = '-'; break;
	case 3: fh = '*'; break;
	case 4: fh = '/'; break;
	}
	system("pause"); 
	system("cls"); 
	return fh;
}
//限制最大值
double z_Max(double max)
{
	cout << "请输入最大限制值" << endl;
	cin >> max;
	system("pause"); 
	system("cls"); 
	return max;
}
//随机数返回
double L_max(double max)
{
	double n; int t;
	t = rand() % 100;
	n = 1.0 * t * (max-0.1) / 100.0+ t / 100.0;
	if(n<10) n+=10;
	return n;
}
//是否需要小数
int x_S()
{
	int xs;
	cout << "是否需要小数" << endl;
	cout << "1.需要" << endl;
	cout << "2.不需要" << endl;
	cin >> xs;
	system("pause"); 
	system("cls"); 
	return xs;
}
//是否需要括号优先级
int y_Xj()
{
	int yxj;
	cout << "是否需要括号优先级" << endl;
	cout << "1.需要" << endl;
	cout << "2.不需要" << endl;
	cin >> yxj;
	system("pause"); 
	system("cls"); 
	return yxj;
}
//生成符合条件的题目
void f_S(double a, double b, double c, double max, char fh, int n, int xs, int x,char dy[])
{
	FILE *fp;
	if((fp=fopen("D:\\1.txt","w"))==NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	int i = 0;
	while (i != n)
	{
		a = L_max(max);
		b = L_max(max);
		c = L_max(max);
		int q = ws(a);
		int w = ws(b);
		int e = ws(c);
		switch (x)
		{
		case 1: if (xs == 2 && (q%2==1)) 
				{ 
					printf("%d %c ( %d %c %d )=	", (int)a, fh, (int)b, fh, (int)c);
					printf("\t");
					fprintf(fp,"%d %c ( %d %c %d )=	", (int)a, fh, (int)b, fh, (int)c);
				}
				else if(xs==2 && (q%2==0)) 
				{ 
					printf("( %d %c %d ) %c %d =	", (int)a, fh, (int)b, fh, (int)c);
					printf("\t");
					fprintf(fp,"( %d %c %d ) %c %d =	", (int)a, fh, (int)b, fh, (int)c); 
				}
				else if(xs == 1 && (q%2==1)) 
				{  
					printf("%.1f %c ( %.1f %c %.1f) =	", a, fh, b, fh, c);
					printf("\t");
					fprintf(fp,"%.1f %c ( %.1f %c %.1f) =	", a, fh, b, fh, c); 
				}
				else if(xs == 1 && (q%2==0)) 
				{  
					printf("(%.1f %c %.1f ) %c %.1f =	", a, fh, b, fh, c);
					printf("\t");
					fprintf(fp,"(%.1f %c %.1f ) %c %.1f =	", a, fh, b, fh, c); 
				}
			  break;
		case 2: if (xs == 2) 
				{
					printf("%d %c %d %c %d =	", (int)a, fh, (int)b, fh, (int)c);
					printf("\t");
					fprintf(fp,"%d %c %d %c %d =	", (int)a, fh, (int)b, fh, (int)c);
				}
			  else 
				{ 
				  printf("%.1f %c %.1f %c %.1f =	", a, fh, b, fh, c);
				  printf("\t"); 
				  fprintf(fp,"%.1f %c %.1f %c %.1f =	", a, fh, b, fh, c);
				}
			  break;
		}
		i++;
		if (i % 5 == 0) {cout << endl; fprintf(fp,"\n");}
	}
		cout<<"需要打印到文件上吗？"<<endl;
		cout<<"1.需要"<<endl;
		cout<<"2.不需要"<<endl;
		int xy;
		cin>>xy;
		fclose(fp);
		if(xy==2) {fp=fopen("D:\\1.txt","w");fclose(fp);}
		else if(xy==1) cout<<"打印成功!"<<endl;
		else {printf("输入有误！");fp=fopen("D:\\1.txt","w");fclose(fp);}
	system("pause"); 
	system("cls"); 
}


int main()
{
	char fh = '+'; int s=0, n = 50, xs = 2, x = 2; double max, a=0, b=0, c=0; max = 100;
	char dy[1000];
	while (1)
	{
		showMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			n = s_L(n);
			break;
		case 2:
			fh= f_H(s);
			break;
		case 3:
			max = z_Max(max);
			break;
		case 4:
			xs = x_S();
			break;
		case 5:
			x = y_Xj();
			break;
		case 6:
			f_S(a, b, c, max, fh, n, xs, x,dy);
			break;
		case 7:

			break;
		case 0:
			return 0;
		}
	}	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 return 0;
}

