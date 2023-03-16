#pragma once

#include "Distributor.h"
#include "Textbook.h"
#include <fstream>
#include <iomanip>
#include <vector>

class Order {
private:
	Distributor distributor;
	std::vector<Textbook> textbooks;
public:
	Order(Distributor d);
	void addTextbook(Textbook t);
	double getTotalCost() const;
	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

