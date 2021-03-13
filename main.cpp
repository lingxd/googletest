#include <iostream>
#include <gtest/gtest.h>
#include <eigen3/Eigen/Dense>
#include <numeric>

TEST(Vector3d, Dense)
{
    Eigen::Vector3d v1, v2;
    v1 << 1, 2, 3;
    v2 << 4, 5, 6;
    std::cout << v1 << "\n";
    std::cout << v2 << "\n";
    std::cout << v1.cross(v2) << "\n";
}

// 测试集为 MyTest，测试案例为 Sum
TEST(MyTestSum, Sum)
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    EXPECT_EQ(sum, 15);
}

/**
 * @brief Construct a new TEST object
 * 那么这两种断言有什么区别呢？如果ASSERT_*执行失败了，会导致当前的测试函数立即返回。而EXPECT_*如果执行失败了，并不会导致测试函数返回。
　　gtest 提供了 8 个ASSERT_*断言，分别是ASSERT_TRUE()、ASSERT_FALSE()、ASSERT_EQ()、ASSERT_NE()、ASSERT_LT()、ASSERT_LE()、ASSERT_GT()和ASSERT_GE()。
　　EXPECT_*的断言同样也有 8 个，分别是ASSERT_TRUE()、ASSERT_FALSE()、EXPECT_EQ()、EXPECT_NE()、EXPECT_LT()、EXPECT_LE()、EXPECT_GT()和EXPECT_GE()。
 */
TEST(MyTest, Add)
{
    EXPECT_EQ(1 + 1, 2);
    ASSERT_EQ(1 + 1, 2);
}

TEST(MyTest, Sum)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    EXPECT_EQ(3, std::accumulate(vec.begin(), vec.end(), 0));
}
TEST(MyTest, Size)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    EXPECT_EQ(2, vec.size());
}

class VectorTest : public testing::Test
{
protected:
    virtual void SetUp() override
    {
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
    }
    std::vector<int> vec;

private:
    /* data */
public:
    VectorTest(/* args */);
    ~VectorTest();
};

VectorTest::VectorTest(/* args */)
{
}

VectorTest::~VectorTest()
{
}

TEST_F(VectorTest, PushBack)
{
    vec.push_back(4);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec.size(), 4);
}

TEST_F(VectorTest, Size)
{
    EXPECT_EQ(vec.size(), 3);
}

class SomeTest
{
private:
    /* data */
public:
    SomeTest(/* args */);
    ~SomeTest();
};

SomeTest::SomeTest(/* args */)
{
}

SomeTest::~SomeTest()
{
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}