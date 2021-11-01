#include "../include/header.hpp"

using namespace std;

using json = nlohmann::json;

int main(int argc, char* argv[])
{
  string filePath = "asd";
  //a
  if (argc <= 1)
  {
    cout << "Invalid params" << endl;
    return SSP_STATUS_EMPTY_PARAMETR;
  }
  else
  {
    filePath = (string)argv[1];
    if (!std::filesystem::exists(filePath))
    {
      cout << "File does not exists" << endl;
      return SSP_STATUS_ERROR;
    }
  }
}
