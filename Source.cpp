#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <functional>
#include <algorithm>
#include <array>
#include "employee_hourly.cpp"
#include "employee_salary.cpp"
#include "employee.cpp"
#include "employee.h"

int input(int employeeId[], long int SSN[], std::string firstName[], std::string lastName[], double hoursWorked[], double hourlyRate[], int i);
void print(int employeeId[], long int SSN[], std::string firstN[], std::string lastN[], double hoursWorked[], double hourlyRate[],
	double overtimePay[], double grossPay[], double taxAmount[],
	double netpay[], int n);



int main()
{
	double sum = 0.0;
	int counter = 0;
	Employee employee;
	EmployeeHourly hourlyEmployee;


	n = input(employee.employeeId, employee.SSN, employee.firstName, employee.lastName, employee.hoursWorked, hourlyEmployee.hourlyRate, SIZE);
	employee.calculateOvertimeHours(employee.hoursWorked, employee.overtimeHours, n);
	employee.findOvertimePay(employee.overtimeHours, hourlyEmployee.hourlyRate, employee.overtimePay, n);
	employee.findRegularHours(employee.hoursWorked, employee.regularHours, n);
	employee.findRegularPay(employee.regularHours, employee.regularPay, hourlyEmployee.hourlyRate, n);
	employee.findGrossPay(employee.regularPay, employee.overtimePay, employee.grossPay, n);
	employee.findTaxRate(employee.grossPay, employee.taxRate, n);
	employee.findTaxAmount(employee.grossPay, employee.taxAmount, employee.taxRate, n);
	employee.findNetPay(employee.grossPay, employee.netPay, employee.taxAmount, n);
	print(employee.employeeId, employee.SSN, employee.firstName, employee.lastName, employee.hoursWorked, hourlyEmployee.hourlyRate, employee.overtimePay, employee.grossPay, employee.taxAmount, employee.netPay, n);
	return 0;

} //main

//int input();


int input(int employeeId[], long int SSN[], std::string firstName[], std::string lastName[], double hoursWorked[], double hourlyRate[], int n) {
	n = 0;
	std::cout << "Enter Employee ID, SSN, FNAME, LNAME, HOURS WORKED, HOURLY RATE, CTRL Z TO END.";
	while (std::cin >> employeeId[n] >> SSN[n] >> firstName[n] >> lastName[n] >> hoursWorked[n] >> hourlyRate[n])
		n++;

	return n;
}//read


void print(int employeeId[], long int SSN[], std::string firstName[], std::string lastName[], double hoursWorked[], double hourlyRate[],
	double overtimePay[], double grossPay[], double taxAmount[], double netpay[], int n)
{
	double totalNetPay = 0;
	int i = 0;
	std::ofstream employeeRecords("txt.txt");
	std::cout << std::setw(62) << "JUSTIN BLASIER'S PAYROLL INSTITUTE" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "================================================================== " << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "EMPLOY ID" << std::setw(13)
		<< "SSN" << std::setw(12)
		<< "FIRST NAME" << std::setw(12)
		<< "LAST NAME" << std::setw(7)
		<< "HOURS" << std::setw(6)
		<< "RATE" << std::setw(10)
		<< "OVERPAY" << std::setw(11)
		<< "GROSSPAY" << std::setw(8)
		<< "TAX" << std::setw(11)
		<< "NETPAY" << std::endl;

	employeeRecords << std::setw(62) << "JUSTIN BLASIER'S PAYROLL INSTITUTE" << std::endl;
	employeeRecords << " " << std::endl;
	employeeRecords << "================================================================== " << std::endl;
	employeeRecords << std::fixed << std::setprecision(2);
	employeeRecords << "EMPLOY ID" << std::setw(13)
		<< "SSN" << std::setw(12)
		<< "FIRST NAME" << std::setw(12)
		<< "LAST NAME" << std::setw(7)
		<< "HOURS" << std::setw(6)
		<< "RATE" << std::setw(10)
		<< "OVERPAY" << std::setw(11)
		<< "GROSSPAY" << std::setw(8)
		<< "TAX" << std::setw(11)
		<< "NETPAY" << std::endl;

	for (i; i < n; i++) {
		totalNetPay += netpay[i];
		std::cout << "" << employeeId[i] << std::setw(11)
			<< SSN[i] << std::setw(11)
			<< firstName[i] << std::setw(13)
			<< lastName[i] << std::setw(7)
			<< hoursWorked[i] << std::setw(9)
			<< hourlyRate[i] << std::setw(7)
			<< overtimePay[i] << std::setw(12)
			<< grossPay[i] << std::setw(10)
			<< taxAmount[i] << std::setw(10)
			<< netpay[i] << std::endl;
		employeeRecords << "" << employeeId[i] << std::setw(11)
			<< SSN[i] << std::setw(11)
			<< firstName[i] << std::setw(13)
			<< lastName[i] << std::setw(7)
			<< hoursWorked[i] << std::setw(9)
			<< hourlyRate[i] << std::setw(7)
			<< overtimePay[i] << std::setw(12)
			<< grossPay[i] << std::setw(10)
			<< taxAmount[i] << std::setw(10)
			<< netpay[i] << std::endl;
	}//for



	//for (i; i < n; i++) {
	//	totalNetPay += netpay[i];

	//}//for

	std::cout << "==================================================================== " << std::endl;
	std::cout << "AVERAGE NETPAY FOR ALL EMPLOYEES IS:" << std::setw(7) << totalNetPay / i << std::endl;
	std::cout << std::endl;

	employeeRecords << "==================================================================== " << std::endl;
	employeeRecords << "AVERAGE NETPAY FOR ALL EMPLOYEES IS:" << std::setw(7) << totalNetPay / i << std::endl;
	employeeRecords << std::endl;

}//print

