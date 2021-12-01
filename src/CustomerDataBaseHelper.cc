//
// Created by helianthus on 2021/11/30.
//

#include "include/CustomerDataBaseHelper.h"

void CustomerDataBaseHelper::line_to_customer(const std::string &line, std::shared_ptr<Customer> &customer)
{
    Customer::id_type id;
    Customer::name_type name;
    Customer::passwd_type passwd;
    id = (stoi(line.substr(CUSTOMER_ID_OFFSET, CUSTOMER_ID_STRIDE)));
    name = (line.substr(CUSTOMER_NAME_OFFSET, CUSTOMER_NAME_STRIDE));
    passwd = (line.substr(CUSTOMER_PASSWD_OFFSET, CUSTOMER_PASSWD_STRIDE));
    customer = std::make_shared<Customer>(id, name, passwd);
}

std::string CustomerDataBaseHelper::customer_to_line(std::shared_ptr<Customer> &customer)
{
    Customer::id_type id = customer->getId();
    Customer::name_type name = customer->getName();
    Customer::passwd_type passwd = customer->getPasswd();
    return std::to_string(id)
           + " "
           + name + " "
           + passwd;
}

CustomerDataBaseHelper::CustomerDataBaseHelper() : m_file(nullptr), m_customers()
{
}

CustomerDataBaseHelper::CustomerDataBaseHelper(std::string filePath)
        : m_file(filePath),
          m_customers()
{
    if (m_file.is_open()) {
        std::shared_ptr<Customer> customer;
        std::string line;
        while (std::getline(m_file, line)) {
            line_to_customer(line, customer);
            m_customers.push_back(customer);
        }
        fprintf(stdout, "<train ticket> Customer data base init success\n");
    } else {
        fprintf(stderr, "<train ticket> Customer data base open failed\n");
    }
}

CustomerDataBaseHelper::~CustomerDataBaseHelper()
{
    for (auto &item: m_customers) {
        std::string line(customer_to_line(item) + '\n');
        std::cout << line << std::endl;
        m_file.write(line.c_str(), line.size());
    }
    if (m_file.is_open()) {
        m_file.close();
    }
    m_customers.clear();
    fprintf(stdout, "<train ticket> Customer data base exit success\n");
}
