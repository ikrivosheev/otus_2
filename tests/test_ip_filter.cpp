#include <gtest/gtest.h>
#include "utils.h"

TEST(TestSplit, SplitEmptyString) {
    auto result = split("", '.');
    std::vector<std::string> except{};
    ASSERT_EQ(result, except);
}

TEST(TestSplit, SplitString) {
    auto result = split("test,test", ',');
    std::vector<std::string> except{"test", "test"};
    ASSERT_EQ(result, except);
}

TEST(TestSplit, SplitStringSpecialChar) {
    auto result = split("test\ntest\n", '\n');
    std::vector<std::string> except{"test", "test"};
    ASSERT_EQ(result, except);
}

TEST(TestSplit, SplitStringWithEmptyString) {
    auto result = split(".test", '.');
    std::vector<std::string> except{"", "test"};
    ASSERT_EQ(result, except);
}

TEST(TestSplit, SplitStringEmptyStringResult) {
    auto result = split(".", '.');
    std::vector<std::string> except{""};
    ASSERT_EQ(result, except);
}


TEST(TestIPS, IO_IPS) {
    IPS ips;
    std::string except = "1.1.1.1\n1.1.1.1\n";
    std::stringstream result;
    std::stringstream ss;
    ss << "1.1.1.1\tT1\tT1\n1.1.1.1\tT2\tT2\n";
    ss >> ips;
    result << ips;
    ASSERT_EQ(result.str(), except);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

