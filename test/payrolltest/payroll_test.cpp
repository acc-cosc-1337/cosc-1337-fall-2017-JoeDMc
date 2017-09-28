#include "gtest/gtest.h"
#include "Payroll.h"

TEST(PayrollTests, Test_OT_Hours_when_amount_greater_than_40){
    EXPECT_EQ(10, getOTHours(50));
}
TEST(PayrollTests, Test_OT_Hours_when_amount_less_than_40){
    EXPECT_EQ(0, getOTHours(30));
}
TEST(PayrollTests, Test_OT_Pay_when_hours_less_than_40){
    EXPECT_EQ(0, getOTPay(0, 10));
}
TEST(PayrollTests, Test_OT_Pay_when_hours_greater_than_40){
    EXPECT_EQ(150, getOTPay(10, 10));
}
TEST(PayrollTests, Test_total_pay_without_overtime_hours){
    EXPECT_EQ(100, getGrossHourlyOTPay(10, 10, 0, 0));
}
TEST(PayrollTests, Test_total_pay_with_overtime_hours){
    EXPECT_EQ(550, getGrossHourlyOTPay(50, 10, 150, 10));
}
