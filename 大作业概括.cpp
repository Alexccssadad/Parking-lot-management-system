#include<iostream>
#include<time.h>
#pragma warning( disable : 4996 )
using namespace std;

void User()
{
	cout << "**************************" << endl;
	cout << "*****3.��ѯ��������  *****" << endl;
	cout << "*****4.��ѯ��������  *****" << endl;
	cout << "*****6.���ӳ���      *****" << endl;
	cout << "*****7.ɾ������      *****" << endl;
	cout << "*****8.����ͣ����    *****" << endl;
	cout << "*****9.�뿪ͣ����    *****" << endl;
	cout << "*****0.�˳�ϵͳ      *****" << endl;
	cout << "**************************" << endl;
}

void Manage()
{
	cout << "*************************************" << endl;
	cout << "*****3.��ѯʣ�೵λ             *****" << endl;
	cout << "*****4.��ѯ��ͣ�������䳵����Ϣ *****" << endl;
	cout << "*****5.׼�����                 *****" << endl;
	cout << "*****6.׼���뿪                 *****" << endl;
	cout << "*****0.�˳�ϵͳ                 *****" << endl;
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
	cout << "���֣�" << "����" << "\t";
	cout << "���䣺" << "18" << "\t";
	cout << "ӵ��" << abs->size << "����" << "\t";
	cout << "�ѽɷ�" << abt->b->n * 30 << "Ԫ" << endl;
	system("pause");
	system("cls");
}

void AddCar(AddressCar* abs)
{
	system("cls");
	string licensePlate1;
	string color;
	cout << "��������Ҫ��ӳ����ĳ��ƺ��룺";
	cin >> licensePlate1;
	abs->a[abs->size].licensePlate = licensePlate1;
	cout << "��������Ҫ��ӵĳ�������ɫ��";
	cin >> color;
	abs->a[abs->size].color = color;
	abs->size++;
	cout << "������ӳɹ���" << endl;
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
	cout << "��һ����" << abs->size << "����" << endl;
	for (int i = 0; i <abs->size; i++)
	{
		cout << "���ƺţ�" << abs->a[i].licensePlate << "\t"
			<< "��ɫ��" << abs->a[i].color << "\t" << "����ʱ�䣺" << abt->b[i].time3 << "\t";
		cout << "�뿪ʱ�䣺" << abt->b[i+1].time3 << endl;

	}

	//time_t nowtime;
	//struct tm* p;
	//time(&nowtime);
	//p = localtime(&nowtime);
	//printf("����ʱ�䣺%02d:%02d:%02d\n", p->tm_hour, p->tm_min);

	system("pause");
	system("cls");
}

void DeleteCar(AddressCar* abs)
{
	cout << "����������Ҫɾ���ĳ����ĳ��ƺţ�" << endl;
	int i = isExist(abs);
	if (i != -1)
	{
		for (int j = 0; j < i; j++)
		{
			abs->a[i] = abs->a[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "δ�ҵ�������" << endl;
	}
	system("pause");
	system("cls");
}

void Enter(AddressCar* abs, ParkingLot* abt)
{
	int time1;
	system("cls");
	string color;
	cout << "��ӭͣ����" << endl;
	if (abt->size1 == 100)
	{
		cout << "�Բ���ͣ������λ������" << endl;
	}
	else
	{
		//����
		cout << "�����복�ƺţ�";
		int ret = isExist(abs);
		if (ret != -1)
		{
			//����ʱ��
			string time3;
			cout << "���������Ľ���ʱ�䣺";
			cin >> time3;
			abt->b[abt->size1].time3 = time3;
			abt->size1++;
		}
		else
		{
			cout << "δ�ҵ��˳�����Ϣ��������ӳ�����ͣ����" << endl;
		}
		system("pause");
		system("cls");
	}
}

void Leave(AddressCar* abs, ParkingLot* abt)
{
	system("cls");
	string licensePlate1;
	cout << "��������Ҫ�뿪ͣ���������ĳ��ƺ��룺" ;
	int ret = isExist(abs);
	if (ret != -1)
	{
		string time4;
		cout << "�����������뿪ʱ�䣺";
		cin >> time4;
		abt->b[abt->size1].time3 = time4;
		cout << "һ·˳�磡 \t";
		cout << "����Ҫ���ɵķ����ǣ�30Ԫ" << endl;
		abt->size1--;
		abt->b->n++;
	}
	else
	{
		cout << "δ��ͣ�������ҵ��ó�����Ϣ��" << endl;
	}
	system("pause");
	system("cls");
}

void Left(ParkingLot* abt)
{
	system("cls");
	cout << "��ǰͣ������ʣ�� " << 100-abt->size1 << "����λ��" << endl;
	system("pause");
	system("cls");
}
 
void FindAll(AddressCar* abs,ParkingLot* abt)
{
	system("cls");
	cout << "Ŀǰ��ͣ�������䳵����ϢΪ��" << endl;
	for (int i = 0; i < abt->size1; i++)
	{
		cout << "������" << abs->a[abs->size].name << "\t";
		cout << "���䣺" << abs->a[abs->size].age << "\t";
		cout << "���ƺţ�" << abs->a[abs->size].licensePlate << "\t";
		cout << "������ɫ��" << abs->a[abs->size].color << endl;
	}
	system("pause");
	system("cls");
}

void allowEnter(ParkingLot* abt)
{
	system("cls");
	cout << "׼����룡" << endl;
	system("pause");
	system("cls");
}

void allowLeave(ParkingLot* abt)
{
	system("cls");
	cout << "׼���뿪��" << endl;
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
		cout << "��ӭ����ͣ��������ϵͳ��" << endl;
		cout << "�������˺ţ�";
		cin >> ID;
		cout << "���������룺";
		cin >> Password;
		if (ID == ID1 && Password == Password1)
		{
			cout << "��ӭ����ͣ�����û�����ϵͳ��" << endl;
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
			cout << "��ӭ����ͣ��������Ա����ϵͳ��" << endl;
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
			cout << "�˺Ż��������\t ����������" << endl;
			system("pause");
			system("cls");
		}
	}

}


int main()
{
	Login();
}


