//Copyright 2021 Enigma

#define TEST_CPP_
#ifdef TEST_CPP_

#include <gtest/gtest.h>
#include "header.hpp"

using namespace std;

using json = nlohmann::json;

TEST(printTest, json)
{
  std::string data = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Ivanov Petr\",\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Sidorov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 4,\n"
      "      \"debt\": \"C++\"\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Pertov Nikita\",\n"
      "      \"group\": \"IU8-31\",\n"
      "      \"avg\": 3.33,\n"
      "      \"debt\": [\n"
      "        \"C++\",\n"
      "        \"Linux\",\n"
      "        \"Network\"\n"
      "      ]\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 3\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  stringstream ss;
  formatPrint(&j, ss);
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
  std::string data = "{\n"
      "  \"items\":\n"
      "    {\n"
      "      \"name\": \"Ivanov Petr\",\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    }\n"
      "  ,\n"
      "  \"_meta\": {\n"
      "    \"count\": 1\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  EXPECT_THROW(array_checker(&j), std::runtime_error);
}

TEST(ParserTest, wrongName) {
  stringstream ss;
  std::string data = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": 35,\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Sidorov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 4,\n"
      "      \"debt\": \"C++\"\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Pertov Nikita\",\n"
      "      \"group\": \"IU8-31\",\n"
      "      \"avg\": 3.33,\n"
      "      \"debt\": [\n"
      "        \"C++\",\n"
      "        \"Linux\",\n"
      "        \"Network\"\n"
      "      ]\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 3\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  EXPECT_THROW( formatPrint(&j, ss),std::invalid_argument);
}

TEST(ParserTest, wrongGroup) {
  stringstream ss;
  std::string data = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Ivanov Petr\",\n"
      "      \"group\": 12.5,\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Sidorov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 4,\n"
      "      \"debt\": \"C++\"\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Pertov Nikita\",\n"
      "      \"group\": \"IU8-31\",\n"
      "      \"avg\": 3.33,\n"
      "      \"debt\": [\n"
      "        \"C++\",\n"
      "        \"Linux\",\n"
      "        \"Network\"\n"
      "      ]\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 3\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  EXPECT_THROW( formatPrint(&j, ss), std::invalid_argument);
}

TEST(ParserTest, wrongAvg) {
  stringstream ss;
  std::string data = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Ivanov Petr\",\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Sidorov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 4,\n"
      "      \"debt\": \"C++\"\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Pertov Nikita\",\n"
      "      \"group\": \"IU8-31\",\n"
      "      \"avg\": [ \"fghds\",\n"
      "      \"dwyjg\"],\n"
      "      \"debt\": [\n"
      "        \"C++\",\n"
      "        \"Linux\",\n"
      "        \"Network\"\n"
      "      ]\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 3\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  EXPECT_THROW( formatPrint(&j, ss), std::invalid_argument);
}

TEST(ParserTest, wrongDebt) {
  stringstream ss;
  std::string data = "{\n"
      "  \"items\": [\n"
      "    {\n"
      "      \"name\": \"Ivanov Petr\",\n"
      "      \"group\": \"1\",\n"
      "      \"avg\": \"4.25\",\n"
      "      \"debt\": null\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Sidorov Ivan\",\n"
      "      \"group\": 31,\n"
      "      \"avg\": 4,\n"
      "      \"debt\": \"C++\"\n"
      "    },\n"
      "    {\n"
      "      \"name\": \"Pertov Nikita\",\n"
      "      \"group\": \"IU8-31\",\n"
      "      \"avg\": 3.33,\n"
      "      \"debt\": 45\n"
      "    }\n"
      "  ],\n"
      "  \"_meta\": {\n"
      "    \"count\": 3\n"
      "  }\n"
      "}";
  json j = json::parse(data);
  EXPECT_THROW( formatPrint(&j, ss), std::invalid_argument);
}

#endif // TEST_CPP_