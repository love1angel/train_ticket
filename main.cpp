#include <iostream>
#include <memory>
#include <string>

#include "CustomerDataBaseHelper.h"

std::string db("/home/ts/CLionProjects/CppProject/train_ticket/resources/custom_data");

int main()
{
    CustomerDataBaseHelper customerDataBaseHelper(db);
    return 0;
}
