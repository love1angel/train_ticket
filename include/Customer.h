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

    inline const id_type &getId() const;

    inline void setId(const id_type &id);

    inline const name_type &getName() const;

    inline void setName(const name_type &name);

    inline const passwd_type &getPasswd() const;

    inline void setPasswd(const passwd_type &passwd);

private:
    id_type m_id = 0;
    name_type m_name;
    passwd_type m_passwd;
};

std::istream &operator>>(std::istream &, Customer &);

std::ostream &operator<<(std::ostream &, const Customer &);

inline const Customer::id_type &Customer::getId() const
{
    return m_id;
}

inline void Customer::setId(const id_type &id)
{
    m_id = id;
}

inline const Customer::name_type &Customer::getName() const
{
    return m_name;
}

inline void Customer::setName(const name_type &name)
{
    m_name = name;
}

inline const Customer::passwd_type &Customer::getPasswd() const
{
    return m_passwd;
}

inline void Customer::setPasswd(const passwd_type &passwd)
{
    m_passwd = passwd;
}

#endif //TRAIN_TICKET_CUSTOMER_H
