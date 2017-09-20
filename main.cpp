#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "string"
#include "Payroll.h"
#include "sstream"
using namespace std;
int hoursWorked, overtimeHours;
float biWeeklyPay, netSPay, mediS, ssS, fitS, mediH, ssH, fitH, salary, hourlyPay, weeklyPay, netHPay, overtimePay;
stringstream string1, string2, string3, string4, string5, string6;
string output1, output2, output3, output4, output5, output6, name;
char yesNo;
bool validate;
int main()
{
	for (int loopCount = 0; loopCount < 3; loopCount++)
	{

		validate = false;

		cout << "Please enter the name of employee " << loopCount + 1 << ":\n";
		cin.ignore(cin.rdbuf()->in_avail(), '\n'); //Makes the getline work in all loops besides the first
		getline(cin, name);

		cout << "Are they a salaried employee?(y/n): \n";
		cin >> yesNo;

		while (validate == false)
		{
			if (yesNo == 'y' || yesNo == 'n')
				validate = true;
			else {
				validate = false;
				cout << "Invalid input, please enter y/n: \n";
				cin >> yesNo;
			}
		}
		switch (yesNo)
		{
		case 'y':

			cout << "How much is their yearly salary?:\n";
			cin >> salary;
			while (salary < 20000 || salary > 100000)
			{
				cout << "Invalid input, re-enter your salary: \n";
				cin >> salary;
			}
			biWeeklyPay = getGrossSalaryPay(salary);
			fitS = getFIT(biWeeklyPay);
			ssS = getFICASSN(biWeeklyPay);
			mediS = getFICAMED(biWeeklyPay);
			netSPay = getNetSPay(biWeeklyPay);
			if (loopCount == 0)
			{
				string1 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << "" << right << setw(12) << "" << right << setw(9) << "" << right << setw(12) << "" << right << setw(12) << biWeeklyPay << right << setw(12) << "" <<
					right << setw(14) << biWeeklyPay << right << setw(12) << ssS << right << setw(12) << mediS << right << setw(12) << fitS << right << setw(12) << netSPay;
				output1 = string1.str();
			}
			if (loopCount == 1)
			{
				string2 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << "" << right << setw(12) << "" << right << setw(9) << "" << right << setw(12) << "" << right << setw(12) << biWeeklyPay << right << setw(12) << "" <<
					right << setw(14) << biWeeklyPay << right << setw(12) << ssS << right << setw(12) << mediS << right << setw(12) << fitS << right << setw(12) << netSPay;
				output2 = string2.str();
			}
			if (loopCount == 2)
			{
				string3 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << "" << right << setw(12) << "" << right << setw(9) << "" << right << setw(12) << "" << right << setw(12) << biWeeklyPay << right << setw(12) << "" <<
					right << setw(14) << biWeeklyPay << right << setw(12) << ssS << right << setw(12) << mediS << right << setw(12) << fitS << right << setw(12) << netSPay;
				output3 = string3.str();
			}
			break;


		case 'n':
			validate = false;

			cout << "Enter the hourly pay of the employee:\n";
			cin >> hourlyPay;
			while (validate == false)
			{
				if (hourlyPay > 0 && hourlyPay <= 50)
					validate = true;
				else {
					validate = false;
					cout << "Invalid input, please enter the correct payrate: \n";
					cin >> hourlyPay;
				}
			}

			validate = false;
			cout << "How many hours did they work this week?:\n";
			cin >> hoursWorked;
			while (validate == false)
			{
				if (hoursWorked > 0 && hoursWorked <= 60)
					validate = true;
				else {
					validate = false;
					cout << "Invalid input, please enter the correct amount of hours: \n";
					cin >> hoursWorked;
				}
			}

			overtimeHours = getOTHours(hoursWorked);
			overtimePay = getOTPay(overtimeHours, hourlyPay);
			weeklyPay = getGrossHourlyOTPay(hoursWorked, hourlyPay, overtimePay, overtimeHours);
			fitH = getFIT(weeklyPay);
			ssH = getFICASSN(weeklyPay);
			mediH = getFICAMED(weeklyPay);
			netHPay = getNetSPay(weeklyPay);


			if (loopCount == 0)
			{
				string4 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << hoursWorked << right << setw(12) << overtimeHours << right << setw(9) << hourlyPay << right << setw(12) << hourlyPay*1.5 << right << setw(12) << weeklyPay - overtimePay << right << setw(12) << overtimePay <<
					right << setw(14) << weeklyPay << right << setw(12) << ssH << right << setw(12) << mediH << right << setw(12) << fitH << right << setw(12) << netHPay;
				output1 = string4.str();
			}
			if (loopCount == 1)
			{
				string5 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << hoursWorked << right << setw(12) << overtimeHours << right << setw(9) << hourlyPay << right << setw(12) << hourlyPay*1.5 << right << setw(12) << weeklyPay - overtimePay << right << setw(12) << overtimePay <<
					right << setw(14) << weeklyPay << right << setw(12) << ssH << right << setw(12) << mediH << right << setw(12) << fitH << right << setw(12) << netHPay;
				output2 = string5.str();
			}
			if (loopCount == 2)
			{
				string6 << fixed << showpoint << setprecision(2) << left << setw(20) << name << right << setw(6) << hoursWorked << right << setw(12) << overtimeHours << right << setw(9) << hourlyPay << right << setw(12) << hourlyPay*1.5 << right << setw(12) << weeklyPay - overtimePay << right << setw(12) << overtimePay <<
					right << setw(14) << weeklyPay << right << setw(12) << ssH << right << setw(12) << mediH << right << setw(12) << fitH << right << setw(12) << netHPay;
				output3 = string6.str();
			}
			break;

		}
	}
	cout << left << setw(20) << "Name" << right << setw(6) << "Hours" << right << setw(12) << "OT Hours" << right << setw(9) << "Rate" << right << setw(12) << "OT Rate" << right << setw(12) << "Reg. Pay" << right << setw(12) << "OT Pay" <<
		right << setw(14) << "Gross Pay" << right << setw(12) << "FICA SSN" << right << setw(12) << "FICA Med" << right << setw(12) << "FIT" << right << setw(12) << "Net Pay" << endl;
	cout << output1 << endl << output2 << endl << output3 << endl;
	return 0;
}
