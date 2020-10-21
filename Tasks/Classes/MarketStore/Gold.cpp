#include "Gold.h"

Gold::Gold(): Gold("Nikol", 0, 0){}

Gold::Gold(const char* owner, double turnover, double purchaseValue) : MarketStore(owner, turnover, purchaseValue){}

double Gold::getInitDiscRate() const
{
	double tempDiscRate = 2;
	double tempTurnover = getTurnover();
	while (tempTurnover >= 100) {
		tempDiscRate++;
		tempTurnover -= 100;
	}
	return tempDiscRate >= 10 ? tempDiscRate = 10: tempDiscRate;
}


