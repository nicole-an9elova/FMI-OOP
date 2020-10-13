#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

//7.1
char* strduplicate(char* original) {
    char* copy = new char[strlen(original) + 1];
    strcpy(copy, original);

    return copy;
}

//7.2
char* transformIntToString(int number) {
    int count = 1;
    int copyOfNum = number;
    int num;
    while (number > 10) {
        number /= 10;
        count++;
    }
    char* result = new char[count + 1];
    for (int i = count - 1; i >= 0; i--) {
        num = copyOfNum % 10;
        copyOfNum /= 10;

        result[i] = '0' + num;
    }
    result[count] = '\0';
    return result;
}

//7.3
char* combiningStringsAndRemovingTheDuplicates(const char* s1, const char* s2)
{
    char* result = new char[strlen(s1) + strlen(s2) + 1];
    strcpy(result, s1);
    strcat(result, s2);

    size_t pos = 0;
    for (size_t i = 0; i < strlen(result); i++) {
        size_t j;
        for (j = 0; j < i; j++) {
            if (result[i] == result[j])
                break;
        }
        if (i == j)
            result[pos++] = result[i];
    }
    char* resultWithNewSize = new char[pos + 1];
    for (int i = 0; i < pos; i++) {
        resultWithNewSize[i] =  result[i]; 
    }
    resultWithNewSize[pos] = '\0';
    return resultWithNewSize;
}

//7.4
//returns the first char from a string
char car(const char* x)
{
    char first = x[0];
    return first;
}
//returns the string without its first element
char* cdr(char* x)
{
    char* result = new char[strlen(x) + 1];
    for (size_t i = 0, j = 1; i < strlen(x); i++, j++) {
        result[i] = x[j];
    }
    return result;
}
//concatenates a char with a string
char* cons(char x, const char* y)
{
    char* result = new char[strlen(y) + 2];

    result[0] = x;
    for (size_t i = 1, j = 0; i < strlen(result); i++, j++) {
        result[i] = y[j];
    }
    return result;
}
//checks if the strings are equal
bool eq(const char* x, const char* y) 
{
    return strcmp(x, y) == 0;
}

char* reverse(char* x) 
{
    char* result = new char[strlen(x)];

    for (size_t i = strlen(x) - 1, j = 0; j < strlen(x); i--, j++) {
        result[j] = x[i];
    }
    result[strlen(x)] = '\0';
    return result;
}

//returns a string with just the first n elements from string x
char* car_n(char* x, int n)
{
    char* result = new char[n + 1];

    for (size_t i = 0; i < n; i++) {
        result[i] = x[i];
    }
    result[n] = '\0';
    return result;
}
//returns a string without the first n elements
char* cdr_n(char* x, int n)
{
    char* result = new char[strlen(x)];
    for (size_t j = 0, i = n; i < strlen(x); i++, j++) {
        result[j] = x[i];
    }
    result[strlen(x) - n] = '\0';
    return result;
}

//returns how many times ch appears in the x string
int number_of_char(char* x, char ch) 
{
    int count = 0;
    for (size_t i = 0; i < strlen(x); i++) {
        if (x[i] == ch)
            count++;
    }
    return count;
}

//returns how many times the string y appears in string x
int number_of_substr(char* x, char* y)
{
    int count = 0;
    int length_x = strlen(x);
    int length_y = strlen(y);

    for (size_t i = 0; i < length_x; i++) {
        if (eq(car_n(x, length_y), y)) {
            count++;
        }
        x = cdr(x);
    }
    return count;
}

//returns the x string, but if a part of it equals the y string, it will be deleted
char* delete_substr(char* x, char* y)
{
    
    int length_x = strlen(x);
    int length_y = strlen(y);

    int count = number_of_substr(x, y);
    char* result = new char[length_x - (count * length_y) + 1];
    
    int j = 0;
    for (size_t i = 0; i < length_x; i++) {
        if (!eq(car_n(x, length_y), y)) {
            result[j] = car(x);
            j++;
        }
        else {
            x = cdr_n(x, length_y - 1);
            i += length_y - 1;
        }
        x = cdr(x);
    }
    
    result[j] = '\0';
    return result;
}

int main()
{
    //testing 7.1
    char original[] = "Nikol";
    std::cout << strduplicate(original) << std::endl;
    //testing 7.2
    int num = 58941;
    std::cout << transformIntToString(num) << std::endl;
    //testing 7.3
    char removing[] = "aaa";
    char remo[] = "abb";
    std::cout << combiningStringsAndRemovingTheDuplicates(removing, remo) << std::endl;
    //testing 7.4 
    char testSevenFour[] = "Nikoliol";
    char testSevenFour2[] = "heeybe";
    char test[] = "ol";
    std::cout << car(testSevenFour) << std::endl;
    std::cout << cdr(testSevenFour) << std::endl;
    std::cout << cons('a', testSevenFour) << std::endl;
    std::cout << std::boolalpha << eq(testSevenFour2, testSevenFour) << std::endl;

    std::cout << reverse(testSevenFour) << std::endl;
    std::cout << car_n(testSevenFour, 3) << std::endl;
    std::cout << cdr_n(testSevenFour, 3) << std::endl;
    std::cout << number_of_char(testSevenFour, 'N') << std::endl;
    std::cout << number_of_substr(testSevenFour, test) << std::endl;
    std::cout << delete_substr(testSevenFour, test) << std::endl;
    


    return 0;
}
