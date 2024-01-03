#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    virtual double calculatePrice() const = 0;
    virtual std::string getDescription() const = 0;
};

class Electronics : public Product {
private:
    double price;
    std::string model;

public:
    Electronics(double price, const std::string& model)
        : price(price), model(model) {}

    double calculatePrice() const override {
        // Custom logic for calculating electronics price
        return price * 1.1; // Example calculation
    }

    std::string getDescription() const override {
        return "Electronics - Model: " + model;
    }
};

class Clothing : public Product {
private:
    double price;
    std::string size;

public:
    Clothing(double price, const std::string& size)
        : price(price), size(size) {}

    double calculatePrice() const override {
        // Custom logic for calculating clothing price
        return price * 1.2; // Example calculation
    }

    std::string getDescription() const override {
        return "Clothing - Size: " + size;
    }
};

class Groceries : public Product {
private:
    double price;
    std::string type;

public:
    Groceries(double price, const std::string& type)
        : price(price), type(type) {}

    double calculatePrice() const override {
        // Custom logic for calculating groceries price
        return price * 1.05; // Example calculation
    }

    std::string getDescription() const override {
        return "Groceries - Type: " + type;
    }
};

#endif // PRODUCT_H

