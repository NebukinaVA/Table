#include <gtest.h>
#include "table.h"


TEST(UnorderedTable, can_create_uo_table) 
{
	ASSERT_NO_THROW(UnorderedTable<int> ut);
}

TEST(UnorderedTable, can_create_copied_uo_table)
{
	UnorderedTable<int> ut1;

	ASSERT_NO_THROW(UnorderedTable<int> ut2(ut1));
}

TEST(UnorderedTable, can_insert_element)
{
	UnorderedTable<int> ut;

	ASSERT_NO_THROW(ut.insert(1, 10));
}

TEST(UnorderedTable, can_remove_element)
{
	UnorderedTable<int> ut;
	ut.insert(1, 10);

	ASSERT_NO_THROW(ut.remove(1));
}

TEST(UnorderedTable, can_find_element)
{
	UnorderedTable<int> ut;
	ut.insert(1, 10);
	ut.insert(4, 20);
	ut.insert(2, 50);

	EXPECT_EQ(ut.find(4), 20);
}

TEST(UnorderedTable, can_get_size)
{
	UnorderedTable<int> ut;
	ut.insert(1, 10);
	ut.insert(4, 20);
	ut.insert(2, 50);

	EXPECT_EQ(ut.get_size(), 3);
}

TEST(UnorderedTable, can_check_if_empty)
{
	UnorderedTable<int> ut;
	
	EXPECT_TRUE(ut.empty());
}

TEST(UnorderedTable, can_check_if_not_empty)
{
	UnorderedTable<int> ut;
	ut.insert(1, 10);
	ut.insert(4, 20);
	ut.insert(2, 50);

	EXPECT_FALSE(ut.empty());
}