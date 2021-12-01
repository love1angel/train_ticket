//
// Created by helianthus on 2021/11/30.
//

#ifndef TRAIN_TICKET_CUSTOMERDATABASEHELPER_H
#define TRAIN_TICKET_CUSTOMERDATABASEHELPER_H

#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "Customer.h"

#define CUSTOMER_ID_OFFSET 0
#define CUSTOMER_ID_STRIDE 2
#define CUSTOMER_NAME_OFFSET (CUSTOMER_ID_OFFSET + CUSTOMER_ID_STRIDE + 1)
#define CUSTOMER_NAME_STRIDE 5
#define CUSTOMER_PASSWD_OFFSET (CUSTOMER_NAME_OFFSET + CUSTOMER_NAME_STRIDE + 1)
#define CUSTOMER_PASSWD_STRIDE 5

class CustomerDataBaseHelper {
public:
    CustomerDataBaseHelper();

    CustomerDataBaseHelper(std::string filePath);

    ~CustomerDataBaseHelper();


private:
    static void line_to_customer(const std::string &line, std::shared_ptr<Customer>&);

    static std::string customer_to_line(std::shared_ptr<Customer> &customer);

    std::fstream m_file;
    std::vector<std::shared_ptr<Customer>> m_customers;
};


#endif //TRAIN_TICKET_CUSTOMERDATABASEHELPER_H
