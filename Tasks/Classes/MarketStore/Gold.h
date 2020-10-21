#pragma once
#include "MarketStore.h"
class Gold: public MarketStore
{
public:
	Gold();
	Gold(const char* owner, double turnover, double purchaseValue);

	double getInitDiscRate() const;
};

