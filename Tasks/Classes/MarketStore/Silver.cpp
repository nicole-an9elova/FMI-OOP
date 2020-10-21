#include "Silver.h"

Silver::Silver():Silver("Nikol", 0, 0){}

Silver::Silver(const char* owner, double turnover, double purchaseValue): MarketStore(owner, turnover, purchaseValue){}

double Silver::getInitDiscRate() const
{
	double tempDiscRate = 2;
	if (getTurnover() > 300) tempDiscRate = 3.5;
	return tempDiscRate;
}
