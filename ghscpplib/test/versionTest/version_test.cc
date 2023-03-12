#include <gtest/gtest.h>
#include <GhsCppLib/Version.h>

TEST(VersionTest, construction) {

  Version v0, 
          v1("1"),
          v2(2, 0),
          v3(3, 2, 1),
          v4(4, 3, 2, 1);
  EXPECT_STREQ(v0.c_str(), "0.0");
  EXPECT_STREQ(v1.c_str(), "1.0");
  EXPECT_STREQ(v2.c_str(), "2.0");
  EXPECT_STREQ(v3.c_str(), "3.2.1");
  EXPECT_STREQ(v4.c_str(), "4.3.2.1");
}

TEST(VersionTest, equalOperator){
  Version verA(1,2,0), 
          verB("1.2.0.0");
  bool b = verA == verB;
  EXPECT_TRUE(verA == verB) << "Version declared with constructor(int 1, int 2) should be equal to Version declared with constructor(const char* '1.2')";
  EXPECT_STREQ(verA.c_str(), verB.c_str());
}

TEST(VersionTest, graterThanOperator){
  Version verA(1,2), 
          verB("1.3");
  
  EXPECT_TRUE(verB > verA);
}

TEST(VersionTest, lessThanOperator){
  Version verA(1,2), 
          verB(1,3,0);
  
  EXPECT_TRUE(verA < verB);
}

TEST(VersionTest, ComparisonOperators){
  Version verA(1,2), 
          verB(1,3,0);
  
  EXPECT_TRUE(verA < verB);
  EXPECT_FALSE(verA > verB);
  verA.IncrementMinor();
  EXPECT_TRUE(verA == verB);
  verA.IncrementBuild();
  EXPECT_TRUE(verA > verB);
  verB.setBuild(1);
  EXPECT_TRUE(verA == verB);
}