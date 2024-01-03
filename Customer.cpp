#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& address)
    : name(name), address(address){
    // Additional initialization if needed
}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getAddress() const {
    return address;
}



