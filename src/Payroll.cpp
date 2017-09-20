#include "Payroll.h"
#include <math.h>

const double ssRate = .062;
const double mediRate = .0145;
const double fitRate = .15;
using namespace std;
float net_s_pay;
float x;
int y;

float getGrossSalaryPay(float salary)
{
	x = salary / 26;
	return x;
}

float getGrossHourlyOTPay(int hoursWorked, float hourlyPay, float overtimePay, int overtimeHours)
{
	y = hoursWorked - overtimeHours;
	x = (y*hourlyPay) + overtimePay;
	return x;

}


float getFIT(float pay)
{
	x = pay*fitRate;
	return x;
}

float getFICASSN(float pay)
{
	x = pay*ssRate;
	return x;
}

float getFICAMED(float pay)
{
	x = pay*mediRate;
	return x;
}

float getNetSPay(float pay)
{
	x = pay - (getFIT(pay) + getFICASSN(pay) + getFICAMED(pay));
	return x;
}
int getOTHours(int hoursWorked)
{
	if (hoursWorked > 40)
	{
		x = hoursWorked - 40;
		return x;
	}
	else
		return 0;
}
float getOTPay(int overtimeHours, float hourlyPay)
{

	x = overtimeHours*(hourlyPay*1.5);
	return x;
}
