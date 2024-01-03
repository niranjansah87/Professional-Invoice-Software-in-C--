#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Invoice.h"

int main() {
    // User input for customer details
    std::string customerName, customerAddress, customerEmail;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, customerAddress);

    // Creating a customer object
    Customer customer(customerName, customerAddress);

    // User input for invoice details
    int invoiceNumber;
    std::string invoiceDate;
    std::cout << "Enter invoice number: ";
    std::cin >> invoiceNumber;
    std::cin.ignore(); // Ignore newline character in buffer
    std::cout << "Enter invoice date (YYYY-MM-DD): ";
    std::getline(std::cin, invoiceDate);

    // Creating an invoice object
    Invoice invoice(invoiceNumber, invoiceDate, customer);

    char addMoreProducts = 'y';
    while (addMoreProducts == 'y' || addMoreProducts == 'Y') {
        // Product input logic
        int productType;
        std::cout << "Enter product type (1 - Electronics, 2 - Clothing, 3 - Groceries): ";
        std::cin >> productType;
        std::cin.ignore(); // Ignore newline character in buffer

        double price;
        std::string details;

        switch (productType) {
            case 1:
                std::cout << "Enter electronics price: $";
                std::cin >> price;
                std::cin.ignore(); // Ignore newline character in buffer
                std::cout << "Enter electronics model: ";
                std::getline(std::cin, details);
                invoice.addProduct(new Electronics(price, details));
                break;
            case 2:
                std::cout << "Enter clothing price: $";
                std::cin >> price;
                std::cin.ignore(); // Ignore newline character in buffer
                std::cout << "Enter clothing size: ";
                std::getline(std::cin, details);
                invoice.addProduct(new Clothing(price, details));
                break;
            case 3:
                std::cout << "Enter groceries price: $";
                std::cin >> price;
                std::cin.ignore(); // Ignore newline character in buffer
                std::cout << "Enter groceries type: ";
                std::getline(std::cin, details);
                invoice.addProduct(new Groceries(price, details));
                break;
            default:
                std::cout << "Invalid product type!\n";
                break;
        }

        std::cout << "Add another product? (y/n): ";
        std::cin >> addMoreProducts;
        std::cin.ignore(); // Ignore newline character in buffer
    }

    // Generate and display the invoice
    invoice.generateInvoice();

    return 0;
}

