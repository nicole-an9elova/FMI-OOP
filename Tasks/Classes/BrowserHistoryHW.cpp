#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

//add resize function!

//10.3 + 10.4
struct HistoryEntry {
    size_t month;
    char url[150];
};

class BrowserHistory {
private:
    HistoryEntry* visitedWebs;
    size_t numOfVisited;
public:
    BrowserHistory();
    BrowserHistory(size_t numOfVisited);
    BrowserHistory(const BrowserHistory& other);
    BrowserHistory& operator= (const BrowserHistory& other);
    ~BrowserHistory();

    void addNewEntry();
    void removeEntry();
    void print();
    //how many sites have been visited this month
    size_t numOfMonths(size_t month);
    //finding the month when the user was most active
    size_t whichMonth();
    BrowserHistory& operator+= (HistoryEntry newEntry);

    
    BrowserHistory operator+ (BrowserHistory& other);
    BrowserHistory& operator+= (BrowserHistory& other);
};

int main()
{
    BrowserHistory brH = { 6 };
    HistoryEntry h1 = { 3, "https://www.github.com" };
    HistoryEntry h2 = { 5, "https://www.youtube.com" };
    HistoryEntry h3 = { 5, "https://www.facebook.com" };
    HistoryEntry h4 = { 3, "https://www.ye.com" };
    //brH.addNewEntry();
    //brH.addNewEntry();
    brH += h1;
    brH += h2;
    BrowserHistory brH2 = { 2 };
    brH2 += h3;
    brH2 += h4;
    
    BrowserHistory brCopy = brH;
    brH.removeEntry();
    brH.print();
    std::cout << "This is copy " << std::endl;
    brCopy.print();
    //brCopy.addNewEntry();
    //brCopy.print();
    brH += h3;
    std::cout << "This is BrH before COMBINATION" << std::endl;
    brH.print();

    //BrowserHistory brM = brH;
    //brM.addNewEntry();
    //brH.print();
    //std::cout << brH.numOfMonths(3) << std::endl;
    //std::cout << brH.whichMonth() << std::endl;
    //brH2.print();
    BrowserHistory combined = brH + brH2;
    //(brH + brH2).print();
    brH += brCopy;
    std::cout << "This is BrH after COMBINATION" << std::endl;

    brH.print();
    return 0;
}

BrowserHistory::BrowserHistory()
{    
    this->visitedWebs = new HistoryEntry[1];
    this->numOfVisited = 0;
}

BrowserHistory::BrowserHistory(size_t numOfVisited)
{
    this->visitedWebs = new HistoryEntry[numOfVisited];
    this->numOfVisited = 0;
}

BrowserHistory::BrowserHistory(const BrowserHistory& other)
{
    this->numOfVisited = other.numOfVisited;
    this->visitedWebs = new HistoryEntry[other.numOfVisited];
    for (size_t i = 0; i < numOfVisited; i++) {
        this->visitedWebs[i] = other.visitedWebs[i];
    }
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& other)
{
    if (this != &other) {
        delete[] visitedWebs;

        this->numOfVisited = other.numOfVisited;
        this->visitedWebs = new HistoryEntry[other.numOfVisited];
        for (size_t i = 0; i < numOfVisited; i++) {
            this->visitedWebs[i] = other.visitedWebs[i];
        }

    }
    return *this;

}

BrowserHistory::~BrowserHistory()
{
    delete[] visitedWebs;
}

void BrowserHistory::addNewEntry()
{
    HistoryEntry* biggerBuffer = new HistoryEntry[numOfVisited + 1];
    HistoryEntry entry;
    for (size_t i = 0; i < numOfVisited; i++) {
        biggerBuffer[i] = visitedWebs[i];
    }
    std::cout << "Enter the MONTH when the website was visited \n -> ";
    std::cin >> entry.month;
    std::cin.ignore();
    std::cout << "Enter the URL of the website \n -> ";
    std::cin.getline(entry.url, 150);
    biggerBuffer[numOfVisited] = entry;
    ++numOfVisited;
    delete[] visitedWebs;
    visitedWebs = biggerBuffer;
}

void BrowserHistory::removeEntry()
{
    visitedWebs[numOfVisited - 1].month = 0;
    visitedWebs[numOfVisited - 1].url[0] = '\0';
    numOfVisited--;

}

void BrowserHistory::print()
{
    std::cout << "---HISTORY---" << std::endl;
    for (size_t i = 0; i < numOfVisited; i++) {
        std::cout << "Month: " << visitedWebs[i].month <<
            "  " << "URL: " << visitedWebs[i].url << std::endl;
    }
}

size_t BrowserHistory::numOfMonths(size_t month)
{
    size_t count = 0;
    for (size_t i = 0; i < numOfVisited; i++) {
        if (visitedWebs[i].month == month) {
            count++;
        }
    }
    return count;
}

size_t BrowserHistory::whichMonth()
{
    size_t maxMonth = visitedWebs[0].month;
    size_t maxCount = 1;
    for (size_t i = 0; i < numOfVisited; i++) {
        size_t countCurr = 1;
        for (size_t j = i + 1; j < numOfVisited; j++) {
            if (visitedWebs[i].month == visitedWebs[j].month) {
                countCurr++;
            }
        }
        if (countCurr > maxCount) {
            maxCount = countCurr;
            maxMonth = visitedWebs[i].month;
        }
    }
    return maxMonth;
}

BrowserHistory& BrowserHistory::operator+=(HistoryEntry newEntry)
{
    visitedWebs[numOfVisited++] = newEntry;
    return *this;
}

BrowserHistory BrowserHistory::operator+(BrowserHistory& other)
{
    BrowserHistory newBr;
    newBr.visitedWebs = new HistoryEntry[numOfVisited + other.numOfVisited];
    size_t i;
    for (i = 0; i < numOfVisited; i++) {
        newBr.visitedWebs[i] = visitedWebs[i];
    }
    for (size_t j = 0; j < other.numOfVisited; j++) {
        newBr.visitedWebs[i++] = other.visitedWebs[j];
    }
    newBr.numOfVisited = numOfVisited + other.numOfVisited;
    return newBr;
}

BrowserHistory& BrowserHistory::operator+=(BrowserHistory& other)
{
    HistoryEntry *newBuffer = new HistoryEntry[this->numOfVisited + other.numOfVisited];
    for (size_t i = 0; i < this->numOfVisited; i++) {
        newBuffer[i] = this->visitedWebs[i];
    }
    for (size_t i = 0; i < other.numOfVisited; i++) {
        newBuffer[this->numOfVisited + i] = other.visitedWebs[i];
    }
    delete[] this->visitedWebs;
    this->visitedWebs = newBuffer;
    this->numOfVisited = this->numOfVisited + other.numOfVisited;
    return *this;
}

