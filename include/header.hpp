// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <string>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <any>
#include <nlohmann/json.hpp>

typedef enum sspStatus_t
{
  SSP_STATUS_OK\
  = 0x0000,
  SSP_STATUS_ERROR\
  = 0x8000,
  SSP_STATUS_INVALID_PARAMETR\
  = 0x8001,
  SSP_STATUS_EMPTY_PARAMETR\
  = 0x8002
} sspStatus;

bool debt_checker(const nlohmann::json* j);

bool avg_checker(const nlohmann::json* j);

bool group_checker(const nlohmann::json* j);

bool name_checker(const nlohmann::json* j);

void array_checker(const nlohmann::json* j);

bool meta_checker(const nlohmann::json* j);

void file_exists(const std::string& name);

std::string getName(nlohmann::json* j);

std::any getGroup(const nlohmann::json* j);

std::any getAvg(const nlohmann::json* j);

std::any getDebt(const nlohmann::json* j);

bool formatPrint(const std::string path, std::ostream& os);

#endif // INCLUDE_HEADER_HPP_
