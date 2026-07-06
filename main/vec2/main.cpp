#include "vect2.hpp"
#include <iostream>

int main()
{
	vect2 v1; // 0, 0
	vect2 v2(1, 2); // 1, 2
	const vect2 v3(v2); // 1, 2
	vect2 v4 = v2; // 1, 2


	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << "\n" << std::endl;

	std::cout << v4++ << std::endl;
	std::cout << ++v4 << std::endl;
	std::cout << v4-- << std::endl;
	std::cout << --v4 << std::endl;

	
	v2 += v3; // 2, 4
	v1 -= v2; // -2, -4
	v2 = v3 + v3 * 2; // 3, 6
	v2 = 3 * v2; // 9, 18

	std::cout << "v2 = "<<v2<<"\n";
	std::cout << "v3 = "<<v3<<"\n";
	
	v2 += v2 += v3; 	// 20, 40
	std::cout << "v2 = "<<v2<<"\n";
	v1 *= 42; // -84, -168
	
	std::cout << "here\n";
	std::cout << "v1 = "<< v1 <<"\n";
	v1 = v1 - v1 + v1;

	std::cout << "after\n";
	std::cout << "v1: " << v1 << std::endl;

	std::cout << "v2: " << v2 << std::endl;
	std::cout << "-v2: " << -v2 << std::endl;
	std::cout << "v1[1]: " << v1[1] << std::endl;

	v1[1] = 12;

	// std::cout << "v1[1]: " << v1[1] << std::endl;
	// std::cout << "v3[1]: " << v3[1] << std::endl;
	// std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	// std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
	// std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
	// std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}