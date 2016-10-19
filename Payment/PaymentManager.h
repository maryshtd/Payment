#pragma once
#include "Header.h"
#include "Person.h"
class PaymentManager
{
	std::list<Person> LP;
	std::string path;
	std::multimap<std::string, Person> m1;
	std::map<int, Person> m2;
	void LoadData();
	void SaveData();
public:
	PaymentManager();
	~PaymentManager();
	int FindByName(std::string name);
	PaymentManager operator+(const PaymentManager &pm2);
	PaymentManager operator*(const PaymentManager &pm2);
	std::list<Person> FindByYear(int year);
	Person FindByNum(int num);
	TCHAR *CalcReport();
	TCHAR *Display();
	
	void Add(const Person &x);
	void Delete(int num);
};

