#include<iostream>
#include<time.h>
#pragma warning( disable : 4996 )
using namespace std;

void User()
{
	cout << "**************************" << endl;
	cout << "*****3.查询个人资料  *****" << endl;
	cout << "*****4.查询车辆资料  *****" << endl;
	cout << "*****6.增加车辆      *****" << endl;
	cout << "*****7.删除车辆      *****" << endl;
	cout << "*****8.进入停车场    *****" << endl;
	cout << "*****9.离开停车场    *****" << endl;
	cout << "*****0.退出系统      *****" << endl;
	cout << "**************************" << endl;
}

void Manage()
{
	cout << "*************************************" << endl;
	cout << "*****3.查询剩余车位             *****" << endl;
	cout << "*****4.查询在停车辆及其车主信息 *****" << endl;
	cout << "*****5.准许进入                 *****" << endl;
	cout << "*****6.准许离开                 *****" << endl;
	cout << "*****0.退出系统                 *****" << endl;
	cout << "*************************************" << endl;
}

class Car
{
public:
	string licensePlate;
	string color;
	string name;
	int age;
	int numble;
	double price;
	string time3;
	int n = 0;
	int Time()
	{
		time_t nowtime;
		struct tm* p;
		time(&nowtime);
		p = localtime(&nowtime);
		return ("%02d:%02d:%02d\n", p->tm_hour, p->tm_min);
	}
};

class AddressCar
{
	friend class Car;
public:
	Car a[100];
	int size;
};

class ParkingLot
{
	friend class Car;
public:
	Car b[100];
	int size1=0;

};

void findPerson(AddressCar* abs,ParkingLot* abt)
{
	system("cls");
	cout << "名字：" << "草象" << "\t";
	cout << "年龄：" << "18" << "\t";
	cout << "拥有" << abs->size << "辆车" << "\t";
	cout << "已缴费" << abt->b->n * 30 << "元" << endl;
	system("pause");
	system("cls");
}

void AddCar(AddressCar* abs)
{
	system("cls");
	string licensePlate1;
	string color;
	cout << "请输入您要添加车辆的车牌号码：";
	cin >> licensePlate1;
	abs->a[abs->size].licensePlate = licensePlate1;
	cout << "请输入您要添加的车辆的颜色：";
	cin >> color;
	abs->a[abs->size].color = color;
	abs->size++;
	cout << "您已添加成功！" << endl;
	system("pause");
	system("cls");
}

int isExist(AddressCar* abs)
{
	string ElicensePlate;
	cin >> ElicensePlate;
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->a[i].licensePlate == ElicensePlate)
		{
			return i;
		}
	}
	return -1;
}

void findCar(AddressCar* abs,ParkingLot* abt)
{
	system("cls");
	cout << "您一共有" << abs->size << "辆车" << endl;
	for (int i = 0; i <abs->size; i++)
	{
		cout << "车牌号：" << abs->a[i].licensePlate << "\t"
			<< "颜色：" << abs->a[i].color << "\t" << "进入时间：" << abt->b[i].time3 << "\t";
		cout << "离开时间：" << abt->b[i+1].time3 << endl;

	}

	//time_t nowtime;
	//struct tm* p;
	//time(&nowtime);
	//p = localtime(&nowtime);
	//printf("进入时间：%02d:%02d:%02d\n", p->tm_hour, p->tm_min);

	system("pause");
	system("cls");
}

void DeleteCar(AddressCar* abs)
{
	cout << "请输入您想要删除的车辆的车牌号：" << endl;
	int i = isExist(abs);
	if (i != -1)
	{
		for (int j = 0; j < i; j++)
		{
			abs->a[i] = abs->a[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "未找到这辆车" << endl;
	}
	system("pause");
	system("cls");
}

void Enter(AddressCar* abs, ParkingLot* abt)
{
	int time1;
	system("cls");
	string color;
	cout << "欢迎停车！" << endl;
	if (abt->size1 == 100)
	{
		cout << "对不起，停车场车位已满！" << endl;
	}
	else
	{
		//车牌
		cout << "请输入车牌号：";
		int ret = isExist(abs);
		if (ret != -1)
		{
			//进入时间
			string time3;
			cout << "请输入您的进入时间：";
			cin >> time3;
			abt->b[abt->size1].time3 = time3;
			abt->size1++;
		}
		else
		{
			cout << "未找到此车辆信息，请先添加车辆再停车！" << endl;
		}
		system("pause");
		system("cls");
	}
}

void Leave(AddressCar* abs, ParkingLot* abt)
{
	system("cls");
	string licensePlate1;
	cout << "请输入您要离开停车场车辆的车牌号码：" ;
	int ret = isExist(abs);
	if (ret != -1)
	{
		string time4;
		cout << "请输入您的离开时间：";
		cin >> time4;
		abt->b[abt->size1].time3 = time4;
		cout << "一路顺风！ \t";
		cout << "您需要缴纳的费用是：30元" << endl;
		abt->size1--;
		abt->b->n++;
	}
	else
	{
		cout << "未在停车场中找到该车辆信息！" << endl;
	}
	system("pause");
	system("cls");
}

void Left(ParkingLot* abt)
{
	system("cls");
	cout << "当前停车场还剩下 " << 100-abt->size1 << "个车位！" << endl;
	system("pause");
	system("cls");
}
 
void FindAll(AddressCar* abs,ParkingLot* abt)
{
	system("cls");
	cout << "目前在停车辆及其车主信息为：" << endl;
	for (int i = 0; i < abt->size1; i++)
	{
		cout << "车主：" << abs->a[abs->size].name << "\t";
		cout << "年龄：" << abs->a[abs->size].age << "\t";
		cout << "车牌号：" << abs->a[abs->size].licensePlate << "\t";
		cout << "车辆颜色：" << abs->a[abs->size].color << endl;
	}
	system("pause");
	system("cls");
}

void allowEnter(ParkingLot* abt)
{
	system("cls");
	cout << "准许进入！" << endl;
	system("pause");
	system("cls");
}

void allowLeave(ParkingLot* abt)
{
	system("cls");
	cout << "准许离开！" << endl;
	system("pause");
	system("cls");
}

void Login()
{
	string ID1 = "abc";
	string Password1 = "abc";
	string ID2 = "admin";
	string Password2 = "admin";
	string ID;
	string Password;
	AddressCar abs;
	ParkingLot abt;
	abs.size = 0;
	while (true)
	{
		cout << "欢迎进入停车场管理系统！" << endl;
		cout << "请输入账号：";
		cin >> ID;
		cout << "请输入密码：";
		cin >> Password;
		if (ID == ID1 && Password == Password1)
		{
			cout << "欢迎进入停车场用户管理系统！" << endl;
			system("pause");
			system("cls");
			while (true)
			{
				User();
				int select1 = 0;
				cin >> select1;
				switch (select1)
				{
				case 0:
				{
					system("pause");
					exit(0);
				}
				case 3:
					findPerson(&abs,&abt);
					break;

				case 4:
					findCar(&abs,&abt);
					break;

				case 6:
					AddCar(&abs);
					break;

				case 7:
					DeleteCar(&abs);
					break;

				case 8:
					Enter(&abs, &abt);
					break;
				case 9:
					Leave(&abs, &abt);
					break;
				}

			}
		}
		if (ID == ID2 && Password == Password2)
		{
			cout << "欢迎进入停车场管理员管理系统！" << endl;
			system("pause");
			system("cls");
			while (true)
			{
				Manage();
				int select2 = 0;
				cin >> select2;
				switch (select2)
				{
				case 3:
					Left(&abt);
					break;
				case 4:
					FindAll(&abs, &abt);
					break;
				case 5:
					allowEnter(&abt);
					break;
				case 6:
					allowLeave(&abt);
					break;
				case 0:
					system("pause");
					exit(0);
					break;
				}
			}
		}
		else
		{
			cout << "账号或密码错误！\t 请重新输入" << endl;
			system("pause");
			system("cls");
		}
	}

}


int main()
{
	Login();
}


