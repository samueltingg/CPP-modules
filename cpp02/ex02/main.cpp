#include <iostream>
#include "Fixed.hpp"


void subjectPdfTest() 
{
    std::cout << CYAN << BOLD << "== Subject PDF Tests ==" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( 10 ); 

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

}

void testConstructors() {
    std::cout << CYAN << BOLD << "== Testing Constructors ==" << RESET << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(3.14f);
    Fixed d = c;

    std::cout << "a (default): " << a.toFloat() << std::endl;
    std::cout << "b (int 10): " << b.toFloat() << std::endl;
    std::cout << "c (float 3.14): " << c.toFloat() << std::endl;
    std::cout << "d (copy of c): " << d.toFloat() << std::endl;
}

void testAssignmentOperator() {
    std::cout << CYAN << BOLD << "\n== Testing Assignment Operator ==" << RESET << std::endl;
    Fixed a(42);
    Fixed b;

    std::cout << "Initial a: " << a.toFloat() << std::endl;
    std::cout << "Initial b: " << b.toFloat() << std::endl;

    b = a;

    std::cout << "b (after assignment from a): " << b.toFloat() << std::endl;
}

void testComparisonOperators() {
    std::cout << CYAN << BOLD << "\n== Testing Comparison Operators ==" << RESET << std::endl;
    Fixed a(5);
    Fixed b(10);

    std::cout << "Initial a: " << a.toFloat() << std::endl;
    std::cout << "Initial b: " << b.toFloat() << std::endl;

    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
}

void testArithmeticOperators() {
    std::cout << CYAN << BOLD << "\n== Testing Arithmetic Operators ==" << RESET << std::endl;
    Fixed a(3);
    Fixed b(2);

    std::cout << "Initial a: " << a.toFloat() << std::endl;
    std::cout << "Initial b: " << b.toFloat() << std::endl;

    std::cout << "a + b: " << (a + b).toFloat() << std::endl;
    std::cout << "a - b: " << (a - b).toFloat() << std::endl;
    std::cout << "a * b: " << (a * b).toFloat() << std::endl;
    std::cout << "a / b: " << (a / b).toFloat() << std::endl;
}

void testIncrementDecrement() {
    std::cout << CYAN << BOLD << "\n== Testing Increment/Decrement ==" << RESET << std::endl;
    Fixed a(1);

    std::cout << "Initial a: " << a.toFloat() << std::endl;

    std::cout << "++a: " << (++a).toFloat() << std::endl;
    std::cout << "a++: " << (a++).toFloat() << " (before post-increment)" << std::endl;
    std::cout << "a (after post-increment): " << a.toFloat() << std::endl;

    std::cout << "--a: " << (--a).toFloat() << std::endl;
    std::cout << "a--: " << (a--).toFloat() << " (before post-decrement)" << std::endl;
    std::cout << "a (after post-decrement): " << a.toFloat() << std::endl;
}

void testMinMax() {
    std::cout << CYAN << BOLD << "\n== Testing Min/Max Functions ==" << RESET << std::endl;
    Fixed a(7);
    Fixed b(3);

    std::cout << "Initial a: " << a.toFloat() << std::endl;
    std::cout << "Initial b: " << b.toFloat() << std::endl;

    std::cout << "Min of a and b: " << Fixed::min(a, b).toFloat() << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b).toFloat() << std::endl;
}


int main() {
	subjectPdfTest();
    testConstructors();
    testAssignmentOperator();
    testComparisonOperators();
    testArithmeticOperators();
    testIncrementDecrement();
    testMinMax();

    return 0;
}
