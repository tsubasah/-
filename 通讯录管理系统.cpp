#include<iostream>
using namespace std;
#include<string>
constexpr auto MAX = 1000;

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
};
struct Addressbook
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ�������ϵ�˸���
	int m_Size;
};


void ShowMenu()
{
	cout << "-----1.�����ϵ��-----" << endl;
	cout << "-----2.��ʾ��ϵ��-----" << endl;
	cout << "-----3.ɾ����ϵ��-----" << endl;
	cout << "-----4.������ϵ��-----" << endl;
	cout << "-----5.�޸���ϵ��-----" << endl;
	cout << "-----6.�����ϵ��-----" << endl;
	cout << "-----0.�˳�ϵͳ-----" << endl;
}


void addPerson(Addressbook *abs)
{

	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "������ͨѶ¼�������޷���ӣ�������\n";
	}
	else
	{	//name:
		string name;
		cout << "������������\n";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//sex:
		int sex;
		cout << "1--��\n2--Ů\n";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				if (sex == 1)
					cout << "��������Ա�Ϊ����\n";
				else
					cout << "��������Ա�Ϊ��Ů\n";
				break;
			}
			else
				cout << "�����������������룡" << endl;
		}

		//age
		cout << "���������䣺\n";
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//phone
		cout << "������绰���룺\n";
		string num;
		cin >> num;
		abs->personArray[abs->m_Size].m_Phone = num;
		abs->m_Size++;
		cout << "��ӳɹ���\n";
	}
	
	system("pause");
	system("cls");
}

void showPerson(Addressbook *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��ϵ��Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����\t�Ա�\t����\t�绰����\n" << endl;
		for (int i = 0; i <abs->m_Size; i++)
		{
			cout << abs->personArray[i].m_Name << "\t";
			cout << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << abs->personArray[i].m_Age << "\t";
			cout << abs->personArray[i].m_Phone << "\t";
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExist(Addressbook *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //�ҵ��˷��ر��i
		}
	}
	return -1;		//�Ҳ�������-1
}

//ɾ����ϵ��
void deletePerson(Addressbook *abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�\n";
	string name;
	cin >> name;
	int ret=isExist(abs,name);
	if (ret != -1)
	{
		//�ҵ����ˣ�����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;	//����ͨѶ¼����
		cout << "��ɾ����\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴��ˣ�\n";
		system("pause");
		system("cls");
	}
}


//������ϵ��
void findPerson(Addressbook* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�\n";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "����\t�Ա�\t����\t�绰����\n" << endl;
		cout << abs->personArray[ret].m_Name << "\t";
		cout << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << abs->personArray[ret].m_Age << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴��ˣ�\n";
		system("pause");
		system("cls");
	}
}

//�޸���ϵ��
void modifyPerson(Addressbook* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�\n";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������\n";
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//age
		cout << "���������䣺\n";
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//phone
		cout << "������绰���룺\n";
		string num;
		cin >> num;
		abs->personArray[ret].m_Phone = num;
		cout << "�޸ĳɹ���\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴��ˣ�\n";
		system("pause");
		system("cls");
	}
}

//�����ϵ��
void cleanPerson(Addressbook* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�\n";
	system("pause");
	system("cls");
}

int main()
{
	Addressbook abs;
	abs.m_Size = 0;
	

	int select = 0;
	while (true)
	{
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "�����ϵ��" << endl;
			addPerson(&abs);
			break;
		case 2:
			cout << "��ʾ��ϵ��" << endl;
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			cout << "������ϵ��" << endl;
			findPerson(&abs);
			break;
		case 5:
			cout << "�޸���ϵ��" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			cout << "�����ϵ��" << endl;
			cleanPerson(&abs);
			break;
		case 0:
			cout << "�˳�ϵͳ" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
	return 0;
}