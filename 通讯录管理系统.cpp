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
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前保存的联系人个数
	int m_Size;
};


void ShowMenu()
{
	cout << "-----1.添加联系人-----" << endl;
	cout << "-----2.显示联系人-----" << endl;
	cout << "-----3.删除联系人-----" << endl;
	cout << "-----4.查找联系人-----" << endl;
	cout << "-----5.修改联系人-----" << endl;
	cout << "-----6.清空联系人-----" << endl;
	cout << "-----0.退出系统-----" << endl;
}


void addPerson(Addressbook *abs)
{

	//判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "！！！通讯录已满，无法添加！！！！\n";
	}
	else
	{	//name:
		string name;
		cout << "请输入姓名：\n";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//sex:
		int sex;
		cout << "1--男\n2--女\n";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				if (sex == 1)
					cout << "你输入的性别为：男\n";
				else
					cout << "你输入的性别为：女\n";
				break;
			}
			else
				cout << "输入有误，请重新输入！" << endl;
		}

		//age
		cout << "请输入年龄：\n";
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//phone
		cout << "请输入电话号码：\n";
		string num;
		cin >> num;
		abs->personArray[abs->m_Size].m_Phone = num;
		abs->m_Size++;
		cout << "添加成功！\n";
	}
	
	system("pause");
	system("cls");
}

void showPerson(Addressbook *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前联系人为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "姓名\t性别\t年龄\t电话号码\n" << endl;
		for (int i = 0; i <abs->m_Size; i++)
		{
			cout << abs->personArray[i].m_Name << "\t";
			cout << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << abs->personArray[i].m_Age << "\t";
			cout << abs->personArray[i].m_Phone << "\t";
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int isExist(Addressbook *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i; //找到了返回编号i
		}
	}
	return -1;		//找不到返回-1
}

//删除联系人
void deletePerson(Addressbook *abs)
{
	cout << "请输入你要删除的联系人：\n";
	string name;
	cin >> name;
	int ret=isExist(abs,name);
	if (ret != -1)
	{
		//找到此人，进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;	//更新通讯录人数
		cout << "已删除！\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人！\n";
		system("pause");
		system("cls");
	}
}


//查找联系人
void findPerson(Addressbook* abs)
{
	cout << "请输入你要查找的联系人：\n";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名\t性别\t年龄\t电话号码\n" << endl;
		cout << abs->personArray[ret].m_Name << "\t";
		cout << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << abs->personArray[ret].m_Age << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人！\n";
		system("pause");
		system("cls");
	}
}

//修改联系人
void modifyPerson(Addressbook* abs)
{
	cout << "请输入你要查找的联系人：\n";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：\n";
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//age
		cout << "请输入年龄：\n";
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//phone
		cout << "请输入电话号码：\n";
		string num;
		cin >> num;
		abs->personArray[ret].m_Phone = num;
		cout << "修改成功！\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人！\n";
		system("pause");
		system("cls");
	}
}

//清空联系人
void cleanPerson(Addressbook* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！\n";
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
			cout << "添加联系人" << endl;
			addPerson(&abs);
			break;
		case 2:
			cout << "显示联系人" << endl;
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			cout << "查找联系人" << endl;
			findPerson(&abs);
			break;
		case 5:
			cout << "修改联系人" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			cout << "清空联系人" << endl;
			cleanPerson(&abs);
			break;
		case 0:
			cout << "退出系统" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
	return 0;
}