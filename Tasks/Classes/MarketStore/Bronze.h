#pragma once
#include "MarketStore.h"
class Bronze: public MarketStore
{
public:
	Bronze();
	Bronze(const char* owner, double turnover, double purchaseValue);

	double getInitDiscRate() const;
};

