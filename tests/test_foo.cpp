#include "gtest/gtest.h"

#include <demo.h>

 
TEST(SampleTest, AssertionTrue) {
    ASSERT_EQ(3, myadd(1,2));
}

