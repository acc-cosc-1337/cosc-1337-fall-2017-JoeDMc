#ifndef _PAYROLL_H
#define _PAYROLL_H

float getGrossSalaryPay(float salary);
float getFIT(float pay);
float getFICASSN(float pay);
float getFICAMED(float pay);
float getNetSPay(float pay);
float getGrossHourlyOTPay(int hoursWorked, float hourlyPay, float overtimePay, int overtimeHours);
float getOTPay(int overtimeHours, float hourlyPay);
int getOTHours(int hoursWorked);


#endif
