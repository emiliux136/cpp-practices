#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

static void test_default_array()
{
    std::cout << "\n[TEST] Default constructor and empty array behavior" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    try
    {
        empty[0] = 42;
        std::cerr << "Expected exception for empty[0], but none was thrown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
}

static void test_assignment_and_self_assignment()
{
    std::cout << "\n[TEST] Assignment and self-assignment" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i * 10);

    Array<int> b;
    b = a;
    bool same = true;
    for (unsigned int i = 0; i < b.size(); ++i)
    {
        if (a[i] != b[i])
        {
            same = false;
            break;
        }
    }
    std::cout << "Assignment preserved values: " << (same ? "OK" : "FAIL") << std::endl;

    a = a;
    same = true;
    for (unsigned int i = 0; i < a.size(); ++i)
    {
        if (a[i] != static_cast<int>(i * 10))
        {
            same = false;
            break;
        }
    }
    std::cout << "Self-assignment preserved values: " << (same ? "OK" : "FAIL") << std::endl;
}

static void test_bounds(Array<int> &numbers)
{
    std::cout << "\n[TEST] Bounds checks" << std::endl;
    try
    {
        numbers[-2] = 0;
        std::cerr << "Expected exception for numbers[-2], but none was thrown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception for numbers[-2]: " << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
        std::cerr << "Expected exception for numbers[MAX_VAL], but none was thrown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception for numbers[MAX_VAL]: " << e.what() << std::endl;
    }
}

int main(int, char**)
{
    test_default_array();

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    test_bounds(numbers);
    test_assignment_and_self_assignment();

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}