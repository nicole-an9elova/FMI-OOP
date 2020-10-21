#include "MarketStore.h"
#include "Gold.h"
#include "Silver.h"
#include "Bronze.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <limits>
#include <cmath>
#include <limits>

bool AreSame(double a, double b) {
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

TEST_CASE("Testing initial discount rate of GOLD card ")
{
	Gold card1("Viktor", 1500, 1300);
	Gold card4 = card1;
	card4.setTurnover(452);

	CHECK(AreSame(card1.getInitDiscRate(), 10));
	CHECK(AreSame(card4.getInitDiscRate(), 6));

}
TEST_CASE("Testing initial discount rate of SILVER card ")
{
	Silver card2("Ivan", 600, 850);
	Silver card5 = card2;
	card5.setTurnover(90);

	CHECK(AreSame(card2.getInitDiscRate(), 3.5));
	CHECK(AreSame(card5.getInitDiscRate(), 2));

}
TEST_CASE("Testing initial discount rate of BRONZE card ")
{
	Bronze card1("Petar", 0, 150);
	Bronze card2 = card1;
	Bronze card3 = card1;
	card2.setTurnover(150);
	card3.setTurnover(400);

	CHECK(AreSame(card1.getInitDiscRate(), 0));
	CHECK(AreSame(card2.getInitDiscRate(), 1));
	CHECK(AreSame(card3.getInitDiscRate(), 2.5));
}

TEST_CASE("Testing the calculation method")
{
	Bronze defCard("S", 148, 590);
	
	CHECK(AreSame(defCard.calcDiscount(), 5.9));
}



int main() {

	doctest::Context().run();
	Gold card1("Viktor", 1500, 1300);
	card1.print();
	std::cout << std::endl;
	Silver card2("Ivan", 600, 850);
	card2.print();
	std::cout << std::endl;
	Bronze card3("Petar", 0, 150);
	card3.print();
	std::cout << std::endl;
	Gold card4 = card1;
	card4.setOwner("Simo");
	card4.setTurnover(452);
	card4.print();

	std::cout << std::endl;
	Silver card5 = card2;
	card5.setPurchaseValue(550);
	card5.setTurnover(200);
	card5.print();

	std::cout << std::endl;
	Bronze card6 = card3;
	card6.setTurnover(310);
	card6.print();


	return 0;
}