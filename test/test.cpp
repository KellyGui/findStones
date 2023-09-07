#include<gtest/gtest.h>
#include<iostream>
#include "findStonepairs.hpp"

TEST(test1,case1)
{
    Stone<int> s;
    vector<int> nums{1,0,INT_MAX,2,3};
    int D = INT_MAX;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{1,2};
    EXPECT_EQ(res,ans);
}

TEST(test2,case2)
{
    Stone<int> s;
    vector<int> nums{1,2,2,2,3,2};
    int D = 0;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{1,2};
    EXPECT_EQ(res,ans);
}

TEST(test3,case3)
{
    Stone<int> s;
    vector<int> nums{0,12,INT_MAX,2,INT_MIN,2};
    int D = INT_MAX;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{0,2};
    EXPECT_EQ(res,ans);
}

TEST(test4,case4)
{
    Stone<int> s;
    vector<int> nums{0,12,INT_MAX,2,INT_MIN,2};
    int D = 0;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{3,5};
    EXPECT_EQ(res,ans);
}

TEST(test5,case5)
{
    Stone<double> s;
    vector<double> nums{1.2,2.2,5.7,2.2};
    double D = 3.5;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{1,2};
    EXPECT_EQ(res,ans);
}

TEST(test6,case6)
{
    Stone<float> s;
    vector<float> nums{1.0000001,2.000001,3.1,5.1,3.3,3.2};
    float D = 1.0000009;
    vector<int> res = s.find_onepair(nums,D);
    vector<int> ans{0,1};
    EXPECT_EQ(res,ans);
}

TEST(test7,case7)
{
    Stone<int> s;
    vector<int> nums{1,2,2,2,3,2};
    int D = 0;
    vector<pair<int,int>> res = s.find_pairs(nums,D);
    vector<pair<int,int>> ans{{1,2},{1,3},{1,5},{2,3},{2,5},{3,5}};
    EXPECT_EQ(res,ans);
}

TEST(test8,case8)
{
    Stone<double> s;
    vector<double> nums{1.1, 1.1,2.1,2.1,2.1};
    double D = 0;
    vector<pair<int,int>> res = s.find_pairs(nums,D);
    vector<pair<int,int>> ans{{0,1},{2,3},{2,4},{3,4}};
    EXPECT_EQ(res,ans);
}

TEST(test9,case9)
{
    Stone<double> s;
    vector<double> nums{7.1, 8.1,6.1,2.1,3.1};
    double D = 1.0;
    vector<pair<int,int>> res = s.find_pairs(nums,D);
    vector<pair<int,int>> ans{{0,1},{0,2},{3,4}};
    EXPECT_EQ(res,ans);
}