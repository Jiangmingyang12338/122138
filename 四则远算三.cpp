#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//������������λ��
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
//չʾ����
void showMenu()
{
	printf("||*********************||\n");
	printf("||   1��������Ŀ����   ||\n");
	printf("||   2��������Ŀ����   ||\n");
	printf("||   3�������������   ||\n");
	printf("||   4�������Ƿ�С��   ||\n");
	printf("||   5��������С����   ||\n");
	printf("||   6������������Ŀ   ||\n");
	printf("||-----0���˳�ϵͳ-----||\n");
	printf("||*********************||\n");
}
//������Ŀ����
int s_L(int n)
{
	cout << "��������Ŀ����" << endl;
	cin >> n;
	system("pause"); 
	system("cls"); 
	return n;
}
//��ѡ�������
char f_H(int s)
{
	char fh;
	cout << "��ѡ���������" << endl;
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
//�������ֵ
double z_Max(double max)
{
	cout << "�������������ֵ" << endl;
	cin >> max;
	system("pause"); 
	system("cls"); 
	return max;
}
//���������
double L_max(double max)
{
	double n; int t;
	t = rand() % 100;
	n = 1.0 * t * (max-0.1) / 100.0+ t / 100.0;
	if(n<10) n+=10;
	return n;
}
//�Ƿ���ҪС��
int x_S()
{
	int xs;
	cout << "�Ƿ���ҪС��" << endl;
	cout << "1.��Ҫ" << endl;
	cout << "2.����Ҫ" << endl;
	cin >> xs;
	system("pause"); 
	system("cls"); 
	return xs;
}
//�Ƿ���Ҫ�������ȼ�
int y_Xj()
{
	int yxj;
	cout << "�Ƿ���Ҫ�������ȼ�" << endl;
	cout << "1.��Ҫ" << endl;
	cout << "2.����Ҫ" << endl;
	cin >> yxj;
	system("pause"); 
	system("cls"); 
	return yxj;
}
//���ɷ�����������Ŀ
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
		cout<<"��Ҫ��ӡ���ļ�����"<<endl;
		cout<<"1.��Ҫ"<<endl;
		cout<<"2.����Ҫ"<<endl;
		int xy;
		cin>>xy;
		fclose(fp);
		if(xy==2) {fp=fopen("D:\\1.txt","w");fclose(fp);}
		else if(xy==1) cout<<"��ӡ�ɹ�!"<<endl;
		else {printf("��������");fp=fopen("D:\\1.txt","w");fclose(fp);}
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

