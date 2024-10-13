#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(Add, Commutative) {
    ASSERT_EQ(add(1, 2), add(2, 1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
