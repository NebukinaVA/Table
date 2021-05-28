#include <gtest.h>
#include "table.h"


TEST(OrderedTable, can_create_o_table)
{
	ASSERT_NO_THROW(OrderedTable<int> ot);
}

TEST(OrderedTable, can_create_copied_o_table)
{
	OrderedTable<int> ot1;

	ASSERT_NO_THROW(OrderedTable<int> ot2(ot1));
}

TEST(OrderedTable, can_insert_element)
{
	OrderedTable<int> ot;

	ASSERT_NO_THROW(ot.insert(1, 10));
}

TEST(OrderedTable, can_remove_element)
{
	OrderedTable<int> ot;
	ot.insert(1, 10);

	ASSERT_NO_THROW(ot.remove(1));
}

TEST(OrderedTable, can_find_element)
{
	OrderedTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_EQ(ot.find(4), 20);
}

TEST(OrderedTable, can_get_size)
{
	OrderedTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_EQ(ot.get_size(), 3);
}

TEST(OrderedTable, can_check_if_empty)
{
	OrderedTable<int> ot;

	EXPECT_TRUE(ot.empty());
}

TEST(OrderedTable, can_check_if_not_empty)
{
	OrderedTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_FALSE(ot.empty());
}