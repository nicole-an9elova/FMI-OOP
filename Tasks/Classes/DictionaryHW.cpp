#pragma warning(disable : 4996)
#include <iostream>
#include <string>


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

    void swap(Description desc1, Description desc2);
    void addWord();
    void removeWord();
    void searchDefinition();
    void printDictionary();
    void sortAlphabetically();
    
};



int main()
{
    //Dictionary dict1 = Dictionary();
    Dictionary dict2 = Dictionary(3);
    dict2.addWord();
    dict2.addWord();
    dict2.addWord();
    dict2.sortAlphabetically();
    //dict2.removeWord();
    dict2.printDictionary();
    //dict2.searchDefinition();

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
void Dictionary::swap(Description desc1, Description desc2)
{
    Description temp = desc1;
    desc1 = desc2;
    desc2 = temp;
}
void Dictionary::addWord()
{
    Description descript;
    std::cout << "Enter new word: ";
    std::cin.getline(descript.word, 100);
    std::cout << "Enter the definition of the word: ";
    std::cin.getline(descript.definition, 500);
    words[size++] = descript;
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
    //not finished!!!
    bool swapped = true;

    for (size_t i = 0, j = 1; j < size; i++, j++) {
        if (int(words[i].word[0]) > int(words[j].word[0])) {
            swap(words[i], words[j]);
            swapped = true;
        }
    }
}
