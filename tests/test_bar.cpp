#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Return;

class Bar{
public:
	virtual ~Bar(){}
	virtual int add(int a, int b){ return a+b;}
};

class MockBar : public Bar{
public:
	MOCK_METHOD2(add, int(int a, int b));
};
 
TEST(SampleTest, AssertionTrue) {
    MockBar mockbar;
    EXPECT_CALL(mockbar, add(2,2))
     .Times(1)
     .WillOnce(Return(4));
    ASSERT_EQ(4, mockbar.add(2,2));
}

