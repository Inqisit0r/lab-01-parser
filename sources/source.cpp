// Copyright 2020 Your Name <your_email>

#include "../include/header.hpp"

using json = nlohmann::json;

bool debt_checker(const json* j)
{
  bool checker = true;
  std::string name;
  json temp;
  for (auto& iter : j->at("items").items())
  {
    temp = iter.value();
    if ((!temp.at("debt").empty()) && (!temp.at("debt").is_array())
    && (!temp.at("debt").is_string()))
    {
      checker = false;
    }
  }
  return checker;
}

bool avg_checker(const json* j)
{
  bool checker = true;
  std::string name;
  json temp;
  for (auto& iter : j->at("items").items())
  {
    temp = iter.value();
    if ((!temp.at("avg").is_string()) && (!temp.at("avg").is_number_integer())
    && (!temp.at("avg").is_number_float()))
    {
      checker = false;
    }
  }
  return checker;
}

bool group_checker(const json* j)
{
  bool checker = true;
  std::string name;
  json temp;
  for (auto& iter : j->at("items").items())
  {
    temp = iter.value();
    if ((!temp.at("group").is_string())
    && (!temp.at("group").is_number_integer()))
    {
      checker = false;
    }
  }
  return checker;
}

bool name_checker(const json* j)
{
  bool checker = true;
  std::string name;
  json temp;
  for (auto& iter : j->at("items").items())
  {
    temp = iter.value();
    if (!temp.at("name").is_string())
    {
      checker = false;
    }
  }
  return checker;
}

void array_checker(const json* j)
{
  if (!j->at("items").is_array()) {
    throw std::runtime_error("Excepted array in json file");
  } else {
    throw std::length_error("Excepted array in json file");
  }
}

bool meta_checker(const json* j)
{
  int counter = 0;
  counter = j->at("items").size();
  if (static_cast<int>(j->at("_meta").at("count")) != counter)
    return false;
  else
    return true;
}

void file_exists(const std::string& name)
{
  bool exist = std::filesystem::exists(name);
  if (!exist)
    throw std::runtime_error("Excepted a path to json file");
}

std::string getName(json* j)
{
    std::string name = "";
  if (j->at("name").is_string())
    {
      name = j->at("name");
      return name;
    } else {
      throw std::invalid_argument("Expected string in name");
    }
}

std::any getGroup(const json* j)
{
  std::any group;
  if (j->at("group").is_string())
  {
    group = (std::string)j->at("group");
    return group;
  } else if (j->at("group").is_number_integer()) {
    group = static_cast<int>(j->at("group"));
    return group;
  } else {
    throw std::invalid_argument("Expected string or unsigned value in group");
  }
}

std::any getAvg(const json* j)
{
  std::any avg;
  if (j->at("avg").is_string())
  {
    avg = (std::string)j->at("avg");
    return avg;
  } else if (j->at("avg").is_number_float()) {
    avg = static_cast<float>(j->at("avg"));
    return avg;
  } else if (j->at("avg").is_number_integer()) {
    avg = static_cast<int>(j->at("avg"));
    return avg;
  } else {
    throw std::invalid_argument(
        "Expected str or double or unsigned value in avg");
  }
}

std::any getDebt(const json* j)
{
  std::any debt;
  if (j->at("debt").empty())
  {
    debt = (std::string)"null";
    return debt;
  } else if (j->at("debt").is_string()) {
    debt = (std::string)j->at("debt");
    return debt;
  } else if (j->at("debt").is_array()) {
    debt = static_cast<int>(j->at("debt").size());
    return debt;
  } else {
    throw std::invalid_argument("Expected string or array of strings in debt");
  }
}

bool formatPrint(const std::string path, std::ostream& os) {
  std::stringstream ss;
  std::ifstream f(path);
  json j = json::parse(f);

  std::string str = "";
  int int_temp = 0;
  float float_temp = 0;
  json temp;
  std::any key;
  if (!meta_checker(&j))
  {
    os << "Meta doesn\'t equal students count" << std::endl;
    return false;
  }

  os << "|" << std::setw(20) << std::left << "         name" << "|"
  << std::setw(10) << std::left << "   group" << "|"
  << std::setw(11) << std::left << "    avg" << "|"
  << std::setw(10) << std::left << "   debt" << "|" << std::endl;
  for (auto& iter : j.at("items").items())
  {
    temp = iter.value();
    os << "|" + std::string(20, '-') + "|" + std::string(10, '-') + "|"
    + std::string(11, '-') + "|" + std::string(10, '-') + "|" << std::endl;

    str = getName(&temp);
    os << "| " << std::setw(19) << std::left << str;

    key = getGroup(&temp);
    if (key.type() == typeid(std::string))
    {
      str = std::any_cast<std::string>(key);
      os << "| " << std::setw(9) << std::left << str;
    } else if (key.type() == typeid(int)) {
      int_temp = std::any_cast<int>(key);
      os << "| " << std::setw(9) << std::left << int_temp;
    }

    key = getAvg(&temp);
    if (key.type() == typeid(std::string))
    {
      str = std::any_cast<std::string>(key);
      os << "| " << std::setw(10) << std::left << str;
    } else if (key.type() == typeid(int)) {
      int_temp = std::any_cast<int>(key);
      os << "| " << std::setw(10) << std::left << int_temp;
    } else if (key.type() == typeid(float)) {
      float_temp = std::any_cast<float>(key);
      os << "| " << std::setw(10) << float_temp;
    }

    key = getDebt(&temp);
    if (key.type() == typeid(std::string))
    {
      str = std::any_cast<std::string>(key);
      os << "| " << std::setw(9) << std::left << str << "|\n";
    } else if (key.type() == typeid(int)) {
      int_temp = std::any_cast<int>(key);
      str = std::to_string(int_temp);
      os << "| " << std::setw(9) << std::left << str + " items" << "|\n";
    }
  }
  os << "|" + std::string(20, '-') + "|" + std::string(10, '-') + "|"
  + std::string(11, '-') + "|" + std::string(10, '-') + "|" << std::endl;
  return true;
}
