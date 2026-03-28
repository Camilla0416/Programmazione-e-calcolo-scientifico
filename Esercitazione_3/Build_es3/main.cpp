#include <iostream>
#include "rational.hpp"

int main(void)
{
    rational<int> r1(7,3);
	rational<int> r2(3,6);
	rational<int> r3(2,-3);
	rational<int> r4(0,0);
	rational<int> r5(1,0);
	rational<int> r6(-1,0);
	rational<int> r7(0,1);
	/* Razionali */
    std::cout << r1 << "\n"; /* 7/3 */
	std::cout << r2 << "\n"; /* 1/2 */
	std::cout << r3 << "\n"; /* -2/3 */
	std::cout << r4 << "\n"; /* NaN */
	std::cout << r5 << "\n"; /* +Inf */
	std::cout << r6 << "\n"; /* -Inf */
	std::cout << r7 << "\n"; /* 0 */
	/* Operazioni */
    std::cout << (r1+r2) << "\n"; /* 17/6 */
	std::cout << (r1-r2) << "\n"; /* 11/6 */
	std::cout << (r1*r2) << "\n"; /* 7/6 */
	std::cout << (r1/r2) << "\n"; /* 14/3 */
	std::cout << (r2+r3) << "\n"; /* -1/6 */
	std::cout << (r2-r3) << "\n"; /* 7/6 */
	std::cout << (r2*r3) << "\n"; /* -1/3 */
	std::cout << (r2/r3) << "\n"; /* -3/4 */
	/* Casi Eccezionali */
	std::cout << (r1+r4) << "\n"; /* NaN */
	std::cout << (r1-r4) << "\n"; /* NaN */
	std::cout << (r4*r2) << "\n"; /* NaN */
	std::cout << (r4/r3) << "\n"; /* NaN */
	std::cout << (r5+r6) << "\n"; /* NaN */
	std::cout << (r5-r5) << "\n"; /* NaN */
	std::cout << (r1+r5) << "\n"; /* +Inf */
	std::cout << (r1-r5) << "\n"; /* -Inf */
	std::cout << (r1*r5) << "\n"; /* +Inf */
	std::cout << (r1/r5) << "\n"; /* 0 */
	std::cout << (r5+r5) << "\n"; /* +Inf */
	std::cout << (r6+r6) << "\n"; /* -Inf */
	std::cout << (r5*r5) << "\n"; /* +Inf */
	std::cout << (r6/r6) << "\n"; /* NaN */
	std::cout << (r7*r5) << "\n"; /* NaN */
	return 0;
}