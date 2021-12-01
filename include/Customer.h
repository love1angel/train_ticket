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

    id_type getId();

    inline void setId(id_type id);

    const name_type getName();

    void setName(name_type &name);

    const passwd_type getPasswd();

    void setPasswd(passwd_type &passwd);

private:
    id_type m_id = 0;
    name_type m_name;
    passwd_type m_passwd;
};

#endif //TRAIN_TICKET_CUSTOMER_H
