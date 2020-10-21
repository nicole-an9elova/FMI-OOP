#pragma once
#include "MarketStore.h" 
class Silver: public MarketStore
{
public:
	Silver();
	Silver(const char* owner, double turnover, double purchaseValue);

	double getInitDiscRate() const;

};

