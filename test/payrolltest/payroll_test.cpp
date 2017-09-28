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
