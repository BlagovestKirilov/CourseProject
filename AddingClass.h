#pragma once
#include "Distributor.h"
#include <vector>
class AddingClass
{
public:
    AddingClass();

    void addTextbook();
    void addDistributor();
    void addOrder();
};


//class Distributor {
//private:
//    std::string name;
//    std::string address;
//    std::string phone;
//
//public:
//    Distributor();
//    Distributor(std::string name_, std::string address_, std::string phone_);
//
//    // Getters
//    std::string getName() const;
//    std::string getAddress() const;
//    std::string getPhoneNumber() const;
//
//    // Setters
//    void setName(const std::string& newName);
//    void setAddress(const std::string& newAddress);
//    void setPhone(const std::string& newPhone);
//
//    friend std::ostream& operator<<(std::ostream& os, const Distributor& obj);
//    friend std::istream& operator>>(std::istream& is, Distributor& obj);
//};
