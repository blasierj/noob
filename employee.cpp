#include "employee.h"
//every employee needs overtime pay, tax amount, net pay 
//program needs to find min and max net pay of all employees as well as sort the employees based on their net pay 




void Employee::calculateOvertimeHours(double[], double[], int)
{
	for (int i = 0; i < n; i++)
	{
		if (hoursWorked[i] > 40) overtimeHours[i] = hoursWorked[i] - 40;
		else overtimeHours[i] = 0;
	}//for
}//findOvertimeHours

void Employee::findOvertimePay(double overtimeHours[], double hourlyRate[], double overtimePay[], int n)
{
	for (int i = 0; i < n; i++)
	{
		overtimePay[i] = overtimeHours[i] * hourlyRate[i] * 1.5;
	}//for
}//findOvertimePay

void Employee::findRegularHours(double hoursWorked[], double regularhours[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (hoursWorked[i] > 40) regularhours[i] = 40;
		else regularhours[i] = hoursWorked[i];
	}//for
}//findRegularHours

void Employee::findRegularPay(double regularhours[], double regularPay[], double hourlyRate[], int n)
{
	for (int i = 0; i < n; i++)
	{
		regularPay[i] = regularhours[i] * hourlyRate[i];
	}//for
}//findRegularPay
void Employee::findGrossPay(double regularPay[], double overtimePay[],
	double grossPay[], int n) {
	for (int i = 0; i < n; i++) {
		grossPay[i] = regularPay[i] + overtimePay[i];
	}//for
}//findGrossPay

void Employee::findTaxRate(double grossPay[], double taxRate[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (grossPay[i] > 500.00) taxRate[i] = 0.30;
		else if (grossPay[i] > 200.00) taxRate[i] = 0.20;
		else taxRate[i] = 0.10;
	}//for
}//findTaxRate

void Employee::findTaxAmount(double grossPay[], double taxAmount[],
	double taxRate[], int n)
{
	for (int i = 0; i < n; i++)
	{
		taxAmount[i] = grossPay[i] * taxRate[i];
	}//FOR
}//findTaxAmount

void Employee::findNetPay(double grossPay[], double netpay[], double taxAmount[], int n)
{
	for (int i = 0; i < n; i++)
	{
		netpay[i] = grossPay[i] - taxAmount[i];
	}//for
}//findNetPay
