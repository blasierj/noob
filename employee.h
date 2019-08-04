#ifndef employee_h
#define employee_h
#include <iostream>
#pragma once
const int SIZE = 20;
int n;


class Employee
{
public:
		double overtimePay[SIZE];
		double overtimeHours[SIZE];
		long int SSN[SIZE];
		int employeeId[SIZE];
		std::string firstName[SIZE];
		std::string lastName[SIZE];
		double hoursWorked[SIZE];
		double grossPay[SIZE];
		double netPay[SIZE];
		double taxRate[SIZE];
		double taxAmount[SIZE];
		double regularPay[SIZE];
		double regularHours[SIZE];


	void calculateOvertimeHours(double[], double[], int);
	void findOvertimePay(double[], double[], double[], int);
	void findRegularHours(double[], double[], int);
	void findRegularPay(double[], double[], double[], int);
	void findGrossPay(double[], double[], double[], int);
	void findTaxRate(double[], double[], int);
	void findTaxAmount(double[], double[], double[], int);
	void findNetPay(double[], double[], double[], int);


};
#endif