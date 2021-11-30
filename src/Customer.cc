//
// Created by helianthus on 2021/11/30.
//

#include "include/Customer.h"

std::istream &operator>>(std::istream &in, Customer &customer)
{
    in >> customer.m_id >> customer.m_name >> customer.m_passwd;
    if (!in)
        customer = Customer();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Customer &customer)
{
    out << "Your id: " << customer.m_id
        << ", name: " << customer.m_name
        << ", password: " << customer.m_passwd;
    return out;
}


Customer::Customer()
{

}

Customer::~Customer()
{

}

Customer::Customer(unsigned int id, const std::string &name, const std::string &password)
        : m_id(id),
          m_name(std::move(name)),
          m_passwd(std::move(password))
{
}

