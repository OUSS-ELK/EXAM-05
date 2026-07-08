# pragma once

#include "searchable_bag.hpp"

class set{
	private:
		searchable_bag	&bag;
	public:
		set(searchable_bag &oth) : bag(oth) {}
		
		void	insert(int value){
			if (!bag.has(value))
				bag.insert(value);
		}
		void	insert(int *arr, int size){
			int i = 0;
			while (i < size){
				if (!bag.has(arr[i]))
					bag.insert(arr[i]);
				i++;
			}
		}

		void	print() const{
			bag.print();
		}
		void	clear(){
			bag.clear();
		}
		bool	has(int value) const{
			return bag.has(value);
		}
		
		searchable_bag&		get_bag() const{
			return bag;
		}

		~set(){
			bag.clear();
		}
};