#include "Distributor.h"

// Default constructor
Distributor::Distributor() {}

// Parameterized constructor
Distributor::Distributor(std::string name_, std::string address_, std::string phone_)
    : name(name_), address(address_), phone(phone_)
{}

// Getters
std::string Distributor::getName() const {
    return name;
}

std::string Distributor::getAddress() const {
    return address;
}

std::string Distributor::getPhoneNumber() const {
    return phone;
}

// Setters
void Distributor::setName(const std::string& newName) {
    name = newName;
}

void Distributor::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Distributor::setPhone(const std::string& newPhone) {
    phone = newPhone;
}

// Overloaded << operator to output Distributor object
std::ostream& operator<<(std::ostream& os, const Distributor& obj) {
    os << obj.getName() << '\n' << obj.getAddress() << '\n' << obj.getPhoneNumber() << '\n';
    return os;
}

// Overloaded >> operator to input Distributor object
std::istream& operator>>(std::istream& is, Distributor& obj) {
    std::string name, address, phone;
    std::getline(is, name);
    std::getline(is, address);
    std::getline(is, phone);
    obj.setName(name);
    obj.setAddress(address);
    obj.setPhone(phone);
    return is;
}
