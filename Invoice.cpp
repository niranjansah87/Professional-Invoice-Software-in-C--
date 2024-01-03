#include "Invoice.h"
#include <iostream>

Invoice::Invoice(int invoiceNumber, const std::string& date, const Customer& customer)
    : invoiceNumber(invoiceNumber), date(date), customer(customer) {
    // Additional initialization if needed
}

void Invoice::addProduct(Product* product) {
    products.push_back(product);
}

double Invoice::calculateTotalAmount() {
    double totalAmount = 0.0;
    // Using iterators instead of range-based for loop
    std::vector<Product*>::iterator it;
    for (it = products.begin(); it != products.end(); ++it) {
        totalAmount += (*it)->calculatePrice(); // Dereference the iterator to access the pointer
    }
    return totalAmount;
}

void Invoice::generateInvoice() {
    // Printing invoice details using C++98 style
    std::cout << "Invoice Number: " << invoiceNumber << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Customer Details:\n";
    std::cout << "Name: " << customer.getName() << "\n";
    std::cout << "Address: " << customer.getAddress() << "\n";

    std::cout << "Products:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << "Product " << i + 1 << ":\n";
        // Assuming products have a method to describe themselves
        std::cout << "Description: Not available\n";
        std::cout << "Price: $" << products[i]->calculatePrice() << "\n\n";
    }

    std::cout << "Total Amount: $" << calculateTotalAmount() << "\n";
}

