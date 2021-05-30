#include <gtest.h>
#include "hash_table.h"


TEST(HashTable, can_create_table)
{
	ASSERT_NO_THROW(HashTable<int> ot);
}

TEST(HashTable, can_create_copied_table)
{
	HashTable<int> ot1;

	ASSERT_NO_THROW(HashTable<int> ot2(ot1));
}

TEST(HashTable, can_insert_element)
{
	HashTable<int> ot;

	ASSERT_NO_THROW(ot.insert(1, 10));
}

TEST(HashTable, can_remove_element)
{
	HashTable<int> ot;
	ot.insert(1, 10);

	ASSERT_NO_THROW(ot.remove(1));
}

TEST(HashTable, can_find_element)
{
	HashTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_EQ(ot.find(4), 20);
}

TEST(HashTable, can_get_size)
{
	HashTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_EQ(ot.get_size(), 3);
}

TEST(HashTable, can_check_if_empty)
{
	HashTable<int> ot;

	EXPECT_TRUE(ot.empty());
}

TEST(HashTable, can_check_if_not_empty)
{
	HashTable<int> ot;
	ot.insert(1, 10);
	ot.insert(4, 20);
	ot.insert(2, 50);

	EXPECT_FALSE(ot.empty());
}