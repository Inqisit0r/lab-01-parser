//Copyright 2021 Enigma

#define TEST_CPP_
#ifdef TEST_CPP_

#include <gtest/gtest.h>
#include "header.hpp"

using namespace std;

using json = nlohmann::json;

TEST(printTest, json)
{
  stringstream ss;
  string path = "../jsonExamples/students.json";
  formatPrint(path, ss);
  ASSERT_EQ("|         name       |   group  |    avg    |   debt   |\n"
      "|--------------------|----------|-----------|----------|\n"
      "| Ivanov Petr        | 1        | 4.25      | null     |\n"
      "|--------------------|----------|-----------|----------|\n"
      "| Sidorov Ivan       | 31       | 4         | C++      |\n"
      "|--------------------|----------|-----------|----------|\n"
      "| Pertov Nikita      | IU8-31   | 3.33      | 3 items  |\n"
      "|--------------------|----------|-----------|----------|\n", ss.str());
}

TEST(existsFile, json)
{
  string path = "..//jsonExamples//students1.json";
  EXPECT_THROW(file_exists(path), std::runtime_error);
}

TEST(arrayChecker, json)
{
  string path = "array.json";
  ifstream f(path);
  json j = json::parse(f);
  EXPECT_THROW(array_checker(&j), std::runtime_error);
}

TEST(ParserTest, wrongName) {
  stringstream ss;
  string path = "name.json";
  EXPECT_THROW( formatPrint(path, ss),std::invalid_argument);
}

TEST(ParserTest, wrongGroup) {
  stringstream ss;
  string path = "group.json";
  EXPECT_THROW( formatPrint(path, ss), std::invalid_argument);
}

TEST(ParserTest, wrongAvg) {
  stringstream ss;
  string path = "avg.json";
  EXPECT_THROW( formatPrint(path, ss), std::invalid_argument);
}

TEST(ParserTest, wrongDebt) {
  stringstream ss;
  string path = "debt.json";
  EXPECT_THROW( formatPrint(path, ss), std::invalid_argument);
}

#endif // TEST_CPP_