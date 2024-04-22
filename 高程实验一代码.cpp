#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
void Showmenu()
{
	cout << "欢迎使用小型学生成绩管理系统" << endl;
	cout << "按0结束使用" << endl;
	cout << "按1增加学生信息" << endl;
	cout << "按2删除学生信息" << endl;
	cout << "按3修改学生信息" << endl;
	cout << "按4查询学生信息" << endl;
	cout << "按5对学生成绩进行分析" << endl;
}
class Student
{
public:
	//private:
	string m_Name;
	int m_Id = 0;
	string m_Coursename1, m_Coursename2;
	float m_Gread1 = 0, m_Gread2 = 0;
	string m_Classname;
	//public:
	Student() {}
	Student(string name, string coursename1, string coursename2, int id, float gread1, float gread2, string classname)
	{
		m_Name = name;
		m_Coursename1 = coursename1;
		m_Coursename2 = coursename2;
		m_Id = id;
		m_Gread1 = gread1;
		m_Gread2 = gread2;
		m_Classname = classname;
	}
	Student* next = NULL;

};
class Function
{
	int n;//学生个数
	Student* p;//链表头指针
public:
	void begin()
	{
		cout << "输入学生信息" << endl;
		cout << "输入需要录入的学生个数" << endl;
		cin >> n;
		p = func();
	}
	Student* func()
	{
		cout << "请依次输入学生的姓名，学号，班级，课程一名称，课程二名称，课程一成绩，课程二成绩" << endl;
		Student* head = NULL;
		Student* p = NULL;
		Student* p1 = NULL;
		head = new Student;
		p = head;
		p1 = p;
		cin >> head->m_Name >> head->m_Id >> head->m_Classname >> head->m_Coursename1 >> head->m_Coursename2 >> head->m_Gread1 >> head->m_Gread2;
		for (int i = 1;i < n;i++)
		{
			p = new Student;
			cin >> p->m_Name >> p->m_Id >> p->m_Classname >> p->m_Coursename1 >> p->m_Coursename2 >> p->m_Gread1 >> p->m_Gread2;
			p1->next = p;
			p1 = p;
		}
		p1->next = NULL;
		return head;
		cout << "学生信息输入完毕" << endl;
	}

	void Addition()
	{
		cout << "请输入要增加的信息" << endl;
		Student* m1_p = p;
		Student* m2_p = new Student;
		m2_p->next = m1_p;
		cin >> m2_p->m_Name >> m2_p->m_Id >> m2_p->m_Classname >> m2_p->m_Coursename1 >> m2_p->m_Coursename2 >> m2_p->m_Gread1 >> m2_p->m_Gread2;
		cout << "增加完成" << endl;
		n++;
		cout << "显示增加后的学生信息" << endl;
		Student* m3_p = m2_p;
		for (int i = 0;i < n;i++)
		{
			cout << "姓名：" << m3_p->m_Name << "学号：" << m3_p->m_Id << "班级：" << m3_p->m_Classname << "课程一名称：" << m3_p->m_Coursename1 << "课程二名称：" << m3_p->m_Coursename2 << "课程一成绩：" << m3_p->m_Gread1 << "课程二成绩：" << m3_p->m_Gread2 << endl;
			m3_p = m3_p->next;
		}
	}
	void Delete()
	{
		cout << "请输入要删除学生的姓名" << endl;
		string name;
		cin >> name;
		int flag = 0;
		Student* m1_p = p;
		Student* m2_p = m1_p->next;
		if (m1_p->m_Name == name)
		{
			m2_p = m1_p->next;
			delete m1_p;
			flag = 0;
		}
		else
		{
			for (int i = 0;i < n;i++)
			{
				if (m2_p->m_Name == name)
				{
					m1_p->next = m2_p->next;
					delete m2_p;
					break;
				}
				else
				{
					m1_p = m1_p->next;
					m2_p = m1_p->next;
				}
				if (m1_p->next == NULL)
				{
					break;
				}
			}
			flag = 1;
		}
		cout << "删除完成" << endl;
		n--;
		cout << "显示删除后的学生信息" << endl;
		if (flag == 0)
		{
			Student* m3_p = m2_p;
			for (int i = 0;i < n;i++)
			{
				cout << "姓名：" << m3_p->m_Name << "学号：" << m3_p->m_Id << "班级：" << m3_p->m_Classname << "课程一名称：" << m3_p->m_Coursename1 << "课程二名称：" << m3_p->m_Coursename2 << "课程一成绩：" << m3_p->m_Gread1 << "课程二成绩：" << m3_p->m_Gread2 << endl;
				m3_p = m3_p->next;
			}

		}
		if (flag == 1)
		{
			Student* m3_p = m1_p;
			for (int i = 0;i < n;i++)
			{
				cout << "姓名：" << m3_p->m_Name << "学号：" << m3_p->m_Id << "班级：" << m3_p->m_Classname << "课程一名称：" << m3_p->m_Coursename1 << "课程二名称：" << m3_p->m_Coursename2 << "课程一成绩：" << m3_p->m_Gread1 << "课程二成绩：" << m3_p->m_Gread2 << endl;
				m3_p = m3_p->next;
			}
		}
	}
	void Modification()
	{
		cout << "请输入要修改学生的姓名" << endl;
		string name;
		cin >> name;
		cout << "请输入该学生修改后的信息" << endl;
		Student* m1_p = p;
		for (int i = 0;i < n;i++)
		{
			if (m1_p->m_Name == name)
			{
				cin >> m1_p->m_Name >> m1_p->m_Id >> m1_p->m_Classname >> m1_p->m_Coursename1 >> m1_p->m_Coursename2 >> m1_p->m_Gread1 >> m1_p->m_Gread2;

			}
			else
			{
				m1_p = m1_p->next;
			}
		}
		cout << "修改完成" << endl;
		Student* m3_p = m1_p;
		for (int i = 0;i < n;i++)
		{
			cout << "姓名：" << m3_p->m_Name << "学号：" << m3_p->m_Id << "班级：" << m3_p->m_Classname << "课程一名称：" << m3_p->m_Coursename1 << "课程二名称：" << m3_p->m_Coursename2 << "课程一成绩：" << m3_p->m_Gread1 << "课程二成绩：" << m3_p->m_Gread2 << endl;
			m3_p = m3_p->next;
		}
	}
	void Average()//年级平均成绩
	{
		Student* m1_p = p;
		float sum1 = 0, sum2 = 0, ave1, ave2;
		for (int i = 0;i < n;i++)
		{
			sum1 = m1_p->m_Gread1 + sum1;
			sum2 = m1_p->m_Gread2 + sum2;
			m1_p = m1_p->next;
		}
		ave1 = sum1 / n;
		ave2 = sum2 / n;
		cout << "课程一平均成绩：" << ave1 << endl;
		cout << "课程二平均成绩：" << ave2 << endl;
	}
	void Bestgread()
	{
		Student* m1_p = p;
		float bestgread1 = 0;
		float bestgread2 = 0;
		for (int i = 0;i < n;i++)
		{
			if (m1_p->m_Gread1 >= bestgread1)
			{
				bestgread1 = m1_p->m_Gread1;
			}
			if (m1_p->m_Gread2 >= bestgread2)
			{
				bestgread2 = m1_p->m_Gread2;
			}
			m1_p = m1_p->next;
		}
		cout << "课程一的最高成绩为：" << bestgread1 << endl;
		cout << "课程二的最高成绩为：" << bestgread2 << endl;

	}
	void Badgread()
	{
		Student* m1_p = p;
		float badgread1 = m1_p->m_Gread1;
		float badgread2 = m1_p->m_Gread2;
		for (int i = 0;i < n;i++)
		{
			if (m1_p->m_Gread1 <= badgread1)
			{
				badgread1 = m1_p->m_Gread1;
			}
			if (m1_p->m_Gread2 <= badgread2)
			{
				badgread2 = m1_p->m_Gread2;
			}
			m1_p = m1_p->next;
		}
		cout << "课程一的最低成绩为：" << badgread1 << endl;
		cout << "课程二的最低成绩为：" << badgread2 << endl;

	}
	void Showinformation()//查询学生信息
	{
		cout << "查询学生信息" << endl;
		//int a = 0;
		//cin >> a;
		/*if (a == 1)
		{
			Student* m1_p = p;
			for (int i = 0;i < n;i++)
			{
				cout << "姓名：" << m1_p->m_Name << "学号：" << m1_p->m_Id << "班级：" << m1_p->m_Classname << "课程一名称：" << m1_p->m_Coursename1 << "课程二名称：" << m1_p->m_Coursename2 << "课程一成绩：" << m1_p->m_Gread1 << "课程二成绩：" << m1_p->m_Gread2 << endl;
				m1_p = m1_p->next;
			}
		}*/
		//else
		{
			cout << "输入您要查询的学生姓名" << endl;
			string name;
			cin >> name;
			Student* m1_p = p;
			for (int i = 0;i < n;i++)
			{
				if (m1_p->m_Name == name)
				{
					cout << "姓名：" << m1_p->m_Name << "学号：" << m1_p->m_Id << "班级：" << m1_p->m_Classname << "课程一名称：" << m1_p->m_Coursename1 << "课程二名称：" << m1_p->m_Coursename2 << "课程一成绩：" << m1_p->m_Gread1 << "课程二成绩：" << m1_p->m_Gread2 << endl;
					break;
				}
				m1_p = m1_p->next;

			}
		}
	}
	void Showaveage()//查询平均成绩
	{
		Average();
	}
	void Showbestgread()//查询最高成绩
	{
		Bestgread();
	}
	void Showbadgread()//查询最低成绩
	{
		Badgread();
	}
	void Analyze()
	{
		cout << "请输入你想查询的成绩类型" << endl;
		cout << "1：全部学生两门课程平均成绩。2：课程一，课程二最高成绩。3：课程一，课程二最低成绩" << endl;
		int a = 0;
		cin >> a;
		switch (a)
		{
		case 1:
			Showaveage();
			break;
		case 2:
			Showbestgread();
			break;
		case 3:
			Showbadgread();
			break;
		}
	}
	void Out()
	{
		Student* m1_p = p;
		for (int i = 0;i < n;i++)
		{
			p = p->next;
			delete m1_p;
			m1_p = p;
		}
	}

};
int main()
{
	Function f;
	f.begin();
end:
	int number = 0;
	Showmenu();
	cin >> number;
	switch (number)
	{
	case(0):
		cout << "感谢使用!" << endl;
		system("pause");
		return 0;
	case(1):
		f.Addition();
		system("pause");
		goto end;
	case(2):
		f.Delete();
		system("pause");
		goto end;
	case(3):
		f.Modification();
		system("pause");
		goto end;
	case(4):
		f.Showinformation();
		system("pause");
		goto end;
	case(5):
		f.Analyze();
		system("pause");
		goto end;
	}
	f.Out();
	system("pause");
	return 0;

};


