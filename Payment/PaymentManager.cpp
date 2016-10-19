#include "PaymentManager.h"



PaymentManager::PaymentManager()
{
	LoadData();
}


PaymentManager::~PaymentManager()
{}

void PaymentManager::LoadData()
{
	int num;
	std::string name;
	double salary;
	int year;
	double percent;
	int k;
	int N;
	char buff[1024];
	char *curr, *next;

	std::ifstream fin;
	fin.open("data.txt");
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		if (strlen(buff) > 0)
		{

			curr = strtok_s(buff, ";", &next);
			num = atoi(curr);                     //convert from char to int

			curr = strtok_s(NULL, ";", &next);
			name = curr;						//do not need to convert char to string

			curr = strtok_s(NULL, ";", &next);
			salary = atof(curr);				//convert from char to double

			curr = strtok_s(NULL, ";", &next);
			year = atoi(curr);

			curr = strtok_s(NULL, ";", &next);
			percent = atof(curr);

			curr = strtok_s(NULL, ";", &next);
			k = atoi(curr);

			N = atoi(next);

			Person x(num, name, salary, year, percent, k, N);
			LP.push_back(x);
		}
	}
	fin.close();
}


int PaymentManager::FindByName(std::string name)
{
	return 0;
}

PaymentManager PaymentManager::operator+(const PaymentManager &pm2)
{
	PaymentManager pm3;
	return pm3;
}

PaymentManager PaymentManager::operator*(const PaymentManager &pm2)
{
	PaymentManager pm3;
	return pm3;
}

std::list<Person> PaymentManager::FindByYear(int year)
{
	std::list<Person> XLP;
	return XLP;
}

Person PaymentManager::FindByNum(int num)
{
	Person p;
	return p;
}

TCHAR *PaymentManager::CalcReport()
{
	TCHAR *s = L"";
	return s;
}

TCHAR *PaymentManager::Display()
{
	TCHAR *s = new TCHAR[6000];
	lstrcpy(s, L"");
	for (auto r=LP.begin(); r!=LP.end(); r++)
	{
		lstrcat(s,  r->Display());
		lstrcat(s, L"\r\n");
	}
	return s;
}

void PaymentManager::SaveData()
{
	std::ofstream fout;
	fout.open("data.txt");
	for (auto r = LP.begin(); r != LP.end(); r++)
	{
		fout << r->getnum() << ";";
		fout << r->getName() << ";";
		fout << r->getSalary() << ";";
		fout << r->getYear() << ";";
		fout << r->getPercent() << ";";
		fout << r->getK() << ";";
		fout << r->getN() << std::endl;

	}
	fout.close();
}

void PaymentManager::Add(const Person &x)
{
	LP.push_back(x);
	SaveData();
}

void PaymentManager::Delete(int num)
{
	//1 way
	for (auto pos = LP.begin();pos!=LP.end(); pos++)
		if (pos->getnum() == num)
		{
			LP.erase(pos);
			break;
		}
	SaveData();
}