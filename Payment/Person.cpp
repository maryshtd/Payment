#include "Person.h"



Person::Person()
{
	this->num=000000;
	this->name="";
	this->salary = 0;
	this->year=0;
	this->percent=0;
	this->tax=0;
	this->k=0;
	this->N=0;
	
}


Person::~Person()
{}

Person::Person(int num, std::string name, double salary, int year, double percent,
	int k, int N)
{
	this->num = num;
	this->name = name;
	this->salary = salary;
	this->year = year;
	this->percent = percent;
	this->k = k;
	this->tax = 0.13;
	this->N = N;

}

TCHAR *Person::Display()
{
	setlocale(LC_ALL, "Russian");
	TCHAR buff[1024];
	swprintf_s(buff, L"%d. %S - %2.f uah; %d; %.2f; %.2f; %d / %d : %2.f / %.2f",
		num, name.c_str(), salary, year, percent, tax, k, N, CalcSum(), calcHold());
	return buff;
	//c_str() преобразовывает string to ANSI
}

char *Person::Display2()
{
	char buff[1024];
	sprintf_s(buff, "%d. - %f uah; %d; %f; %f, %d / %d : %f / %f",
		num, salary, year, percent, tax, k, N, CalcSum(), calcHold());
	return buff;
}


int Person::getnum()
{
	return num;
}

std::string Person::getName()
{
	return name;
}

double Person::getSalary()
{
	return salary;
}

int Person::getYear()
{
	return year;
}

double Person::getPercent()
{
	return percent;
}

double Person::getTax()
{
	return tax;
}

int Person::getK()
{
	return k;
}

int Person::getN()
{
	return N;
}


double Person::CalcSum()
{
	return (salary / N*k*(percent + 1));
}

double Person::calcHold()
{
	return CalcSum()*0.01 + CalcSum()*tax;
}

double Person::calcClear()
{
	return CalcSum() - calcHold();
}

int Person::calcExperience()
{
	//работа с датой - временем
	time_t data_sec;

	time(&data_sec);
	tm* timestruct = nullptr; //структура tm
	localtime_s(timestruct, &data_sec);

	return timestruct->tm_year - year;

}
