#pragma once
#include <iostream>
class MarketStore
{
public:
	MarketStore();
	MarketStore(const char* owner, double turnover, double purchaseValue);
	MarketStore(const MarketStore& other);
	MarketStore& operator=(const MarketStore& other);
	~MarketStore();


	void setOwner(const char* owner);
	void setTurnover(double turnover);
	void setPurchaseValue(double purchaseValue);

	const char* getOwner() const;
	double getTurnover() const;
	double getPurchaseValue() const;

	virtual double getInitDiscRate() const = 0;

	void print();

	double calcDiscount();

protected:
	char* owner;
	double turnover;
	double purchaseValue;
};

