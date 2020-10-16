#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

//if the word has more than 20 symbols don't do anything
class Word {
private:
	char* word;
public:
	Word();
	Word(const char* word);
	Word(const Word& other);

	void setWord(const char* word);
	char* getWord();

	char operator[] (size_t i);
	Word operator+ (char c);
	Word& operator+= (char c);

	bool operator< (Word word);
	bool operator== (Word word);
};

std::ostream& operator<< (std::ostream& out, Word word) {
	out << word.getWord();
	return out;
}


int main()
{
	Word word1 = "Adrenocorticotropic";
	std::cout << word1 << std::endl;
	Word word2 =  word1 + 'a' + 'b';
	std::cout << word2 << std::endl;
	Word word3 = word2;	
	char lett = 'x';
	word3 += lett;
	std::cout << word3 + 'm' << std::endl;


	return 0;
}

Word::Word()
{
	setWord("");
}

Word::Word(const char* word)
{
	setWord(word);
}

Word::Word(const Word& other)
{
	setWord(other.word);
}

void Word::setWord(const char* w)
{
	word = new char[strlen(w) + 1];
	strcpy(word, w);
}

char* Word::getWord()
{
	return word;
}

char Word::operator[](size_t i)
{
	return word[i];
}

Word Word::operator+(char c)
{
	Word newWord;
	newWord.word = new char[strlen(this->word) + 1 + 1];
	if (strlen(this->word) < 20) {
		strcpy(newWord.word, this->word);
		newWord.word[strlen(this->word)] = c;
		newWord.word[strlen(this->word) + 1] = 0;
		return newWord;
	}
	return *this;
	
}

Word& Word::operator+= (char c)
{
	Word newWord;
	newWord.word = new char[strlen(this->word) + 1 + 1];

	if (strlen(this->word) == 20)
		return *this;

	strcpy(newWord.word, this->word);
	newWord.word[strlen(this->word)] = c;
	newWord.word[strlen(this->word) + 1] = 0;

	*this = newWord;
	return *this;
}

bool Word::operator<(Word word)
{
	return strcmp(this->word, word.word) < 0;
}

bool Word::operator==(Word word)
{
	return strcmp(this->word, word.word) == 0;
}
