// fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//TODO: add list/table to store fibo results;
#include <iostream>

int fibo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    int number;
    std::cout << "number: ";
    std::cin >> number;
    std::cout << "\nFibonacci of " << number << " is " << fibo(number) << "\n";
}

