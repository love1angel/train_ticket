//
// Created by helianthus on 2021/11/30.
//

#include "include/Customer.h"

#include <utility>

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

Customer::Customer() = default;

Customer::Customer(id_type id, name_type name, passwd_type password)
        : m_id(id),
          m_name(std::move(name)),
          m_passwd(std::move(password))
{
}

Customer::~Customer() = default;

Customer::id_type Customer::getId()
{
    return m_id;
}

 void Customer::setId(id_type id)
{
    m_id = id;
}

 const Customer::name_type Customer::getName()
{
    return m_name;
}

 void Customer::setName(name_type &name)
{
    m_name = name;
}

 const Customer::passwd_type Customer::getPasswd()
{
    return m_passwd;
}

 void Customer::setPasswd(passwd_type &passwd)
{
    m_passwd = passwd;
}
