#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string address;


public:
    Customer(const std::string& name, const std::string& address);

    const std::string& getName() const;
    const std::string& getAddress() const;
  
};

#endif // CUSTOMER_H

