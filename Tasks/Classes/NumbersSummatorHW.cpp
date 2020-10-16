#include <iostream>

//10.2
class NumbersSummator {
private:
    size_t summ;
    size_t countChanges;
    size_t startSumm;
public:
    NumbersSummator(size_t summ);

    size_t sum();
    void add(size_t number);
    void sub(size_t number);
    //returns how many times the sum has been changed
    size_t num();
    //average of the numbers with which the initial sum was changed
    double average();
};


int main()
{
    NumbersSummator seq1(10);
    std::cout << seq1.sum() << std::endl;
    seq1.add(10);
    seq1.add(5);
    seq1.sub(4);
    std::cout << seq1.sum() << std::endl;
    std::cout << seq1.num() << std::endl;
    std::cout << seq1.average() << std::endl;

    return 0;
}

NumbersSummator::NumbersSummator(size_t summ)
{
    startSumm = summ;
    this->summ = summ;
    countChanges = 0;
}

size_t NumbersSummator::sum()
{
    return this->summ;
}

void NumbersSummator::add(size_t number)
{
    countChanges++;
    summ += number;
}

void NumbersSummator::sub(size_t number)
{
    countChanges++;
    summ -= number;
}

size_t NumbersSummator::num()
{
    return countChanges;
}

double NumbersSummator::average()
{
    return (summ - startSumm) / countChanges;
}
