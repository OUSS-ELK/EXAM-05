# pragma once

# include "array_bag.hpp"
# include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag{
	public:
		searchable_array_bag(){};
		searchable_array_bag(const searchable_array_bag& cp) : array_bag(cp){}
		searchable_array_bag& operator=(const searchable_array_bag& ot){
			if (this != &ot)
				array_bag::operator=(ot);
			return *this;
		}
		~searchable_array_bag() {}

		bool has(int value) const {
			for (int i = 0; i < size; i++){
				if (data[i] == value)
					return true;
			}
			return false;
		}
};
