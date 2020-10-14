#include <iostream>

//8.1
template <class ArrayType>
void input(ArrayType array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        std::cout << "Enter el[" << i << "]: ";
        std::cin >> array[i];
    }
}

//8.2
template <class ArrayType>
bool ordered(ArrayType array, size_t size)
{
    int j = 0;
    for (size_t i = 1; i < size; i++) {
        if (array[j] > array[i]) {
            return false;
            break;
        }
        j++;
    }
    return true;
}

//8.3
template <class ElementType>
bool member(ElementType array[], size_t size, ElementType x)
{
    for (size_t i = 0; i < size; i++) {
        if (array[i] == x) {
            return true;
        }
    }
    return false;
}

//8.4
using typeFunc = double (*) (double);
double f1(double a1) { return a1; };
double f2(double a2) { return 2.1; };
double f3(double a3) { return 4.7; };
double f4(double a4) { return 9.1; };
double f5(double a5) { return 5.3; };

double testingTypeFunc(typeFunc* funct, double x) 
{
    double max = 0;
    for (size_t i = 0; i < 5; i++) {
        if (max < (*funct[i])(x)) {
            max = i;
        }        
    }
    return max;
}

//8.5
using typeOfFunction = double(*)(double);
double fmax(typeOfFunction f, typeOfFunction g, double x)
{
    if ((*f)(x) < (*g)(x)) {
        return (*g)(x);
    }
    else {
        return (*f)(x);
    }
}
double func1(double p1) { return p1; };
double func2(double p2) { return 7.1; };

//8.6
double maxarray(typeOfFunction array[], int n, double x)
{
    double maxf = 0;
    for (size_t i = 0, j = 1; j < n; i++, j++) {
        if ((*array[i])(x) > (*array[j])(x)) {
            maxf =  (*array[i])(x);
        }
    }
    return maxf;
}

//8.7
struct S {
    int a;
    int b;
    int c;
};

template<class T>
void swap(T *a, T *b) {
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
template<class T>
using typeOfSort = bool (*)(T, T);


bool sortByComparingAs(S a1, S a2) {
    return a1.a > a2.a;
}
bool sortByComparingBs(S b1, S b2) {
    return b1.b > b2.b;
}
bool sortInLexicographicalOrder(S s1, S s2) {
    if (s1.a != s2.a) return s1.a < s2.a;
    else if (s1.b != s2.b) return s1.b < s2.b;
    else if (s1.c != s2.c) return s1.c < s2.c;
    else return 0;
}

template<class T>
void sort(T array[], int n, typeOfSort<T> compare) {
    int minIndex;
    for (size_t i = 0, j = 1; j < n; i++, j++) {
        minIndex = i;
        if ((*compare)(array[i], array[j])) {
            minIndex = j;
        }
        swap(&array[i], &array[minIndex]);
    }
}

int main()
{
    //testing 8.1
    char testArr[5];
    //input(testArr, 5);

    //testing 8.2
    int a[] = { 1, 2, 3, 3, 3 };
    int b[] = { 5, 2, 4, 1, 9 };
    int c[] = { 3, 4, 7, 9 };
    std::cout << std::boolalpha << ordered(a, 5) << std::endl;

    //testing 8.3
    std::cout << std::boolalpha << member(b, 5, 7) << std::endl;

    //testing 8.4
    typeFunc functions[5] = { f1, f2, f3, f4, f5 };
    std::cout << testingTypeFunc(functions, 4.5) << std::endl;

    //testing 8.5
    std::cout << fmax(func1, func2, 4.5) << std::endl;

    //testing 8.6
    typeOfFunction funcs[5] = { f1, f2, f3, f4, f5 };
    std::cout << maxarray(funcs, 5, 0.9) << std::endl;

    //testing 8.7
    S first = {4, 2, 3}, 
      second = { 1, 4, 5 },
      third = { 2, 7, 8 },
      fourth = { 3, 9, 1 },
      fifth = { 4, 8, 2 };

    S arr[] = { first, second, third};
    sort<S>(arr, 3, sortInLexicographicalOrder);
    std::cout << "HEREEE" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << std::endl;
    }
    

    return 0;
}
