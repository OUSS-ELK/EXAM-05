#pragma once

#include <iostream>
#include <vector>
#include <string>


class bigint{

	private:
		std::vector<int>    digits;
		void	trim();
		int		to_int() const;
	
	public:
		bigint();
		bigint(unsigned long long	nb);
		bigint(const std::string& s);
		bigint(const bigint& oth);
		bigint& operator=(const bigint& oth);
		~bigint();

		friend std::ostream&	operator<<(std::ostream& os, const bigint& bg);

};