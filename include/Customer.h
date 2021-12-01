//
// Created by helianthus on 2021/11/30.
//

#ifndef TRAIN_TICKET_CUSTOMER_H
#define TRAIN_TICKET_CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
    friend std::istream &operator>>(std::istream &, Customer &);

    friend std::ostream &operator<<(std::ostream &, const Customer &);

public:
    using id_type = unsigned int;
    using name_type = std::string;
    using passwd_type = std::string;

    Customer();

    Customer(id_type id, name_type name, passwd_type password);

    ~Customer();

    inline id_type getId();

    inline void setId(id_type id);

    inline name_type getName();

    inline void setName(name_type &name);

    inline passwd_type getPasswd();

    inline void setPasswd(passwd_type &passwd);

private:
    id_type m_id = 0;
    name_type m_name;
    passwd_type m_passwd;
};

inline Customer::id_type Customer::getId()
{
    return m_id;
}

inline void Customer::setId(id_type id)
{
    m_id = id;
}

inline Customer::name_type Customer::getName()
{
    return m_name;
}

inline void Customer::setName(name_type &name)
{
    m_name = name;
}

inline Customer::passwd_type Customer::getPasswd()
{
    return m_passwd;
}

inline void Customer::setPasswd(passwd_type &passwd)
{
    m_passwd = passwd;
}

#endif //TRAIN_TICKET_CUSTOMER_H
