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
    Customer();

    ~Customer();

    Customer(unsigned id, const std::string &name, const std::string &password);

private:
    unsigned m_id;
    std::string m_name;
    std::string m_passwd;
};


#endif //TRAIN_TICKET_CUSTOMER_H
