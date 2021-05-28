#include <iostream>
#include "table.h"

void main()
{
	OrderedTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(10, 1);
	ot.insert(2, 50);
	ot.insert(12, 40);
	std::cout << ot;

}
