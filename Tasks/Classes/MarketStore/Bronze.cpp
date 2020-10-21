#include "Bronze.h"

Bronze::Bronze():Bronze("Nikol", 0, 0){}

Bronze::Bronze(const char* owner, double turnover, double purchaseValue): MarketStore(owner, turnover, purchaseValue){}

double Bronze::getInitDiscRate() const
{
	double tempDiscRate = 0;
	if (getTurnover() >= 100 && getTurnover() <= 300) tempDiscRate = 1;
	else if (getTurnover() > 300) tempDiscRate = 2.5;
	return tempDiscRate;
}
