#include "gtest/gtest.h"
#include "Payroll.h"

TEST(PayrollTests, Test_OT_Hours_when_amount_greater_than_40){
    EXPECT_EQ(10, getOTHours(50));
}
TEST(PayrollTests, Test_OT_Hours_when_amount_less_than_40){
    EXPECT_EQ(0, getOTHours(30));
}
