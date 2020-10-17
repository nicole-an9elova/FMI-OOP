#pragma warning(disable : 4996)
#include <iostream>
#include <string>

//check again
//9.3 + 10.5 + 10.6
const size_t SIZE_W = 100;
const size_t SIZE_D = 500;


struct Description {
    char word[SIZE_W];
    char definition[SIZE_D];
};

class Dictionary {
public:
    Description *words;
    size_t size;

    Dictionary();
    Dictionary(size_t size);
    Dictionary(const Dictionary& other);
    Dictionary& operator= (const Dictionary& other);
    ~Dictionary();

    void copy(const Dictionary& other);

    void swap(Description& desc1, Description& desc2);
    void addWord();

    void removeWord();
    void searchDefinition();
    void printDictionary();
    void sortAlphabetically();

    Dictionary operator+ (Dictionary other);

    
};



int main()
{
    Dictionary dict2 = Dictionary();
    //Dictionary dict3 = Dictionary(3);
    //dict3.addWord();
    dict2.addWord();
    dict2.addWord();
    dict2.addWord();
    dict2.sortAlphabetically();

    Dictionary dict1 = dict2;
    //dict1.addWord();
    //dict2.removeWord();
    std::cout << "DICTIONARY 1111" << std::endl;
    dict1.printDictionary();
    std::cout << "DICTIONARY 2222" << std::endl;
    dict2.printDictionary();
    //dict2.searchDefinition();
    std::cout << "THIS IS COMBINED" << std::endl;
    (dict1 + dict2).printDictionary();


    return 0;
}

Dictionary::Dictionary()
{
    this->words = new Description[1];
    this->size = 0;
}
Dictionary::Dictionary(size_t size)
{
    words = new Description[size];
    this->size = 0;
}
Dictionary::Dictionary(const Dictionary& other)
{
    copy(other);
}
Dictionary& Dictionary::operator=(const Dictionary& other)
{
    if (this != &other)
    {
        delete[] words;
        copy(other);
    }
    return *this;
}
Dictionary::~Dictionary()
{
    delete[] words;
}
void Dictionary::copy(const Dictionary& other)
{
    this->size = other.size;
    this->words = new Description[other.size];
    for (size_t i = 0; i < other.size; i++) {
        this->words[i] = other.words[i];
    }
}
void Dictionary::swap(Description& desc1, Description& desc2)
{
    Description temp = desc1;
    desc1 = desc2;
    desc2 = temp;
}
void Dictionary::addWord()
{
    Description *biggerBuffer = new Description[this->size + 1];
    Description entry;
    for (size_t i = 0; i < this->size; i++) {
        biggerBuffer[i] = words[i];
    }
    std::cout << "Enter new word: ";
    std::cin.getline(entry.word, 100);
    std::cout << "Enter the definition of the word: ";
    std::cin.getline(entry.definition, 500);
    biggerBuffer[size] = entry;
    ++size;
    delete[] words;
    words = biggerBuffer;
}

void Dictionary::removeWord()
{
    std::cout << "Which word would you like to delete? \n ->";
    char toBeDeleted[100];
    std::cin.getline(toBeDeleted, 100);
    for (size_t i = 0; i < size; i++) {
        if (strcmp(words[i].word, toBeDeleted) == 0) {
            for (size_t j = i + 1; j < size; j++) {
                words[j - 1] = words[j];
            }
            size--;
        }
    }
}

void Dictionary::searchDefinition()
{
    std::cout << "Which word are you looking for? \n ->";
    char toBeSearched[100];
    std::cin.getline(toBeSearched, 100);
    for (size_t i = 0; i < size; i++) {
        if (strcmp(words[i].word, toBeSearched) == 0) {
            std::cout << "Definition: " << words[i].definition << std::endl;
           
        }
    }
}

void Dictionary::printDictionary()
{
    std::cout << "**DICTIONARY**" << std::endl;
    for (size_t i = 0; i < size; i++) {
        std::cout << i + 1 << ".  " << words[i].word << " - "
            << words[i].definition << std::endl;
    }
}

void Dictionary::sortAlphabetically()
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if(strcmp(words[i].word, words[j].word)> 0){
                swap(words[i], words[j]);
            }
        }
    }
}

Dictionary Dictionary::operator+(Dictionary other)
{
    //check!!!
    Dictionary dict;
    dict.words = new Description[this->size + other.size];
    size_t i;
    for (i = 0; i < this->size; i++) {
        dict.words[i] = this->words[i];
    }
    dict.size = i;
    if ((this->size + other.size) > SIZE_D) {
        for (size_t j = 0; j < (SIZE_D - this->size); j++) {
            bool flag = true;
            for (size_t k = 0; k < (dict.size) && flag; k++) {
                if (strcmp(dict.words[k].word, other.words[j].word) == 0) {
                    flag = false;
                }
            }
            if (flag) {
                dict.words[i++] = other.words[i];
                dict.size = i;
            }
        }
    }
    else {
        for (size_t j = 0; j < other.size; j++) {
            bool flag = true;
            for (size_t k = 0; k < (dict.size) && flag; k++) {
                if (strcmp(dict.words[k].word, other.words[j].word) == 0) {
                    flag = false;
                }
            }
            if (flag) {
                dict.words[i++] = other.words[i];
                dict.size = i;
            }
        }
    }
    return dict;
}
