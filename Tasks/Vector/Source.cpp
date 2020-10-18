#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <string>

//add more tests
TEST_CASE("Copying test")
{
    Vector<int> v;
    v.push(0);
    v.push(1);
    Vector<int> copied = v;

    copied[0] = 100;
    CHECK(copied[0] == 100);
    CHECK(v[0] == 1);

    v[1] = 100;
    CHECK(v[1] == 100);
    CHECK(copied[1] == 0);
}
TEST_CASE("Test push_back")
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push(4);//4 1 2 3 

    CHECK(v[2] == 2);

}

TEST_CASE("Test constructor with def values")
{
    Vector<int> v (5, 0);
    
    CHECK(v[0] == 0);
    CHECK(v[1] == 0);
    CHECK(v[2] == 0);
    CHECK(v[3] == 0);
    CHECK(v[4] == 0);
}
int main()
{
    doctest::Context().run();
    Vector<int> iv;
    iv.push(0);
    iv.push(1);
    iv.push(2);
    iv.push(3);
    iv.push(4);
    iv.push(5);
    //iv.print();

    //iv.resizeDecrease();
    //iv.resizeIncrease();
    //iv.print();
    Vector<int> a;
    a.push(12);
    a.push(11);
    a.push(10);
    a.push(9);
    a.push(8);
    a.push(7);
    a.push(6);
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);

    a.print();
    a.slice(3);


	return 0;
}

