#pragma warning(disable: 4996)
#include "MarketStore.h"

MarketStore::MarketStore() :MarketStore("Nikol", 0, 0) {}

MarketStore::MarketStore(const char* owner, double turnover, double purchaseValue)
{
	setOwner(owner);
	setTurnover(turnover);
	setPurchaseValue(purchaseValue);
}

MarketStore::MarketStore(const MarketStore& other) :MarketStore(other.owner, other.turnover, other.purchaseValue) {}

MarketStore& MarketStore::operator=(const MarketStore& other)
{
	if (this != &other) {
		delete[] owner;
		setOwner(other.owner);
		setTurnover(other.turnover);
		setPurchaseValue(other.purchaseValue);
	}
	return *this;
}

MarketStore::~MarketStore()
{
	delete[] owner;
}

void MarketStore::setOwner(const char* owner)
{
	if (owner == nullptr) {
		owner = " ";
	}
	this->owner = new char[strlen(owner) + 1];
	strcpy(this->owner, owner);
}

void MarketStore::setTurnover(double turnover)
{
	if (turnover >= 0) this->turnover = turnover;
	else this->turnover = 0;
}

void MarketStore::setPurchaseValue(double purchaseValue)
{
	if (purchaseValue >= 0) this->purchaseValue = purchaseValue;
	else this->purchaseValue = 0;
}

const char* MarketStore::getOwner() const
{
	return owner;
}

double MarketStore::getTurnover() const
{
	return turnover;
}

double MarketStore::getPurchaseValue() const
{
	return purchaseValue;
}

void MarketStore::print() 
{
	std::cout << "Owner of the card: " << getOwner() << std::endl;
	std::cout << "Purchase value: " << getPurchaseValue() << std::endl;
	std::cout << "Discount rate: " << getInitDiscRate() << std::endl;
	std::cout << "Discount: " << calcDiscount() << std::endl;
	std::cout << "Total: " << getPurchaseValue() - calcDiscount() << std::endl;
}

double MarketStore::calcDiscount()
{
	double discRate = getInitDiscRate() / 100;
	return discRate * getPurchaseValue();
}
