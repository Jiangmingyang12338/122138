#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
void Showmenu()
{
	cout << "��ӭʹ��С��ѧ���ɼ�����ϵͳ" << endl;
	cout << "��0����ʹ��" << endl;
	cout << "��1����ѧ����Ϣ" << endl;
	cout << "��2ɾ��ѧ����Ϣ" << endl;
	cout << "��3�޸�ѧ����Ϣ" << endl;
	cout << "��4��ѯѧ����Ϣ" << endl;
	cout << "��5��ѧ���ɼ����з���" << endl;
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
	int n;//ѧ������
	Student* p;//����ͷָ��
public:
	void begin()
	{
		cout << "����ѧ����Ϣ" << endl;
		cout << "������Ҫ¼���ѧ������" << endl;
		cin >> n;
		p = func();
	}
	Student* func()
	{
		cout << "����������ѧ����������ѧ�ţ��༶���γ�һ���ƣ��γ̶����ƣ��γ�һ�ɼ����γ̶��ɼ�" << endl;
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
		cout << "ѧ����Ϣ�������" << endl;
	}

	void Addition()
	{
		cout << "������Ҫ���ӵ���Ϣ" << endl;
		Student* m1_p = p;
		Student* m2_p = new Student;
		m2_p->next = m1_p;
		cin >> m2_p->m_Name >> m2_p->m_Id >> m2_p->m_Classname >> m2_p->m_Coursename1 >> m2_p->m_Coursename2 >> m2_p->m_Gread1 >> m2_p->m_Gread2;
		cout << "�������" << endl;
		n++;
		cout << "��ʾ���Ӻ��ѧ����Ϣ" << endl;
		Student* m3_p = m2_p;
		for (int i = 0;i < n;i++)
		{
			cout << "������" << m3_p->m_Name << "ѧ�ţ�" << m3_p->m_Id << "�༶��" << m3_p->m_Classname << "�γ�һ���ƣ�" << m3_p->m_Coursename1 << "�γ̶����ƣ�" << m3_p->m_Coursename2 << "�γ�һ�ɼ���" << m3_p->m_Gread1 << "�γ̶��ɼ���" << m3_p->m_Gread2 << endl;
			m3_p = m3_p->next;
		}
	}
	void Delete()
	{
		cout << "������Ҫɾ��ѧ��������" << endl;
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
		cout << "ɾ�����" << endl;
		n--;
		cout << "��ʾɾ�����ѧ����Ϣ" << endl;
		if (flag == 0)
		{
			Student* m3_p = m2_p;
			for (int i = 0;i < n;i++)
			{
				cout << "������" << m3_p->m_Name << "ѧ�ţ�" << m3_p->m_Id << "�༶��" << m3_p->m_Classname << "�γ�һ���ƣ�" << m3_p->m_Coursename1 << "�γ̶����ƣ�" << m3_p->m_Coursename2 << "�γ�һ�ɼ���" << m3_p->m_Gread1 << "�γ̶��ɼ���" << m3_p->m_Gread2 << endl;
				m3_p = m3_p->next;
			}

		}
		if (flag == 1)
		{
			Student* m3_p = m1_p;
			for (int i = 0;i < n;i++)
			{
				cout << "������" << m3_p->m_Name << "ѧ�ţ�" << m3_p->m_Id << "�༶��" << m3_p->m_Classname << "�γ�һ���ƣ�" << m3_p->m_Coursename1 << "�γ̶����ƣ�" << m3_p->m_Coursename2 << "�γ�һ�ɼ���" << m3_p->m_Gread1 << "�γ̶��ɼ���" << m3_p->m_Gread2 << endl;
				m3_p = m3_p->next;
			}
		}
	}
	void Modification()
	{
		cout << "������Ҫ�޸�ѧ��������" << endl;
		string name;
		cin >> name;
		cout << "�������ѧ���޸ĺ����Ϣ" << endl;
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
		cout << "�޸����" << endl;
		Student* m3_p = m1_p;
		for (int i = 0;i < n;i++)
		{
			cout << "������" << m3_p->m_Name << "ѧ�ţ�" << m3_p->m_Id << "�༶��" << m3_p->m_Classname << "�γ�һ���ƣ�" << m3_p->m_Coursename1 << "�γ̶����ƣ�" << m3_p->m_Coursename2 << "�γ�һ�ɼ���" << m3_p->m_Gread1 << "�γ̶��ɼ���" << m3_p->m_Gread2 << endl;
			m3_p = m3_p->next;
		}
	}
	void Average()//�꼶ƽ���ɼ�
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
		cout << "�γ�һƽ���ɼ���" << ave1 << endl;
		cout << "�γ̶�ƽ���ɼ���" << ave2 << endl;
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
		cout << "�γ�һ����߳ɼ�Ϊ��" << bestgread1 << endl;
		cout << "�γ̶�����߳ɼ�Ϊ��" << bestgread2 << endl;

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
		cout << "�γ�һ����ͳɼ�Ϊ��" << badgread1 << endl;
		cout << "�γ̶�����ͳɼ�Ϊ��" << badgread2 << endl;

	}
	void Showinformation()//��ѯѧ����Ϣ
	{
		cout << "��ѯѧ����Ϣ" << endl;
		//int a = 0;
		//cin >> a;
		/*if (a == 1)
		{
			Student* m1_p = p;
			for (int i = 0;i < n;i++)
			{
				cout << "������" << m1_p->m_Name << "ѧ�ţ�" << m1_p->m_Id << "�༶��" << m1_p->m_Classname << "�γ�һ���ƣ�" << m1_p->m_Coursename1 << "�γ̶����ƣ�" << m1_p->m_Coursename2 << "�γ�һ�ɼ���" << m1_p->m_Gread1 << "�γ̶��ɼ���" << m1_p->m_Gread2 << endl;
				m1_p = m1_p->next;
			}
		}*/
		//else
		{
			cout << "������Ҫ��ѯ��ѧ������" << endl;
			string name;
			cin >> name;
			Student* m1_p = p;
			for (int i = 0;i < n;i++)
			{
				if (m1_p->m_Name == name)
				{
					cout << "������" << m1_p->m_Name << "ѧ�ţ�" << m1_p->m_Id << "�༶��" << m1_p->m_Classname << "�γ�һ���ƣ�" << m1_p->m_Coursename1 << "�γ̶����ƣ�" << m1_p->m_Coursename2 << "�γ�һ�ɼ���" << m1_p->m_Gread1 << "�γ̶��ɼ���" << m1_p->m_Gread2 << endl;
					break;
				}
				m1_p = m1_p->next;

			}
		}
	}
	void Showaveage()//��ѯƽ���ɼ�
	{
		Average();
	}
	void Showbestgread()//��ѯ��߳ɼ�
	{
		Bestgread();
	}
	void Showbadgread()//��ѯ��ͳɼ�
	{
		Badgread();
	}
	void Analyze()
	{
		cout << "�����������ѯ�ĳɼ�����" << endl;
		cout << "1��ȫ��ѧ�����ſγ�ƽ���ɼ���2���γ�һ���γ̶���߳ɼ���3���γ�һ���γ̶���ͳɼ�" << endl;
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
		cout << "��лʹ��!" << endl;
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


