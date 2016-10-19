#pragma once
#include "Header.h"
class Person
{
	int num;
	std::string name;
	double salary;
	int year;
	double percent;
	double tax;
	int k;
	int N;
	
public:
	Person();
	~Person();
	Person(int num,	std::string name, double salary,	int year,	double percent,
	int k,	int N);
	int getnum();
	std::string getName();
	double getSalary();
	int getYear();
	double getPercent();
	double getTax();
	int getK();
	int getN();
		
	double CalcSum();
	double calcHold();
	double calcClear();
	int calcExperience();
	
	TCHAR *Display(); //для юникода
	char *Display2(); //для анси

};

