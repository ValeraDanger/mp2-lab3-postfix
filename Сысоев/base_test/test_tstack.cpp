#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-5));
}

TEST(Stack, cant_pop_empty_stack)
{
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, cant_top_empty_stack)
{
	Stack<int> st;
	ASSERT_ANY_THROW(st.top());
}

TEST(Stack, can_push_element)
{
	Stack<int> st;
	ASSERT_NO_THROW(st.push(-1));
}

TEST(Stack, can_push_many_elements)
{
	Stack<int> st;
	ASSERT_NO_THROW(st.push(1));
	ASSERT_NO_THROW(st.push(2));
	ASSERT_NO_THROW(st.push(3));
	ASSERT_NO_THROW(st.push(4));
	ASSERT_NO_THROW(st.push(5));
	ASSERT_NO_THROW(st.push(6));
	ASSERT_NO_THROW(st.push(7));
	ASSERT_NO_THROW(st.push(8));
}

TEST(Stack, is_pushed_elements_correct)
{
	Stack<int> st;
	st.push(10);
	EXPECT_EQ(10, st.top());

	st.push(100);
	EXPECT_EQ(100, st.top());

	st.push(1000);
	EXPECT_EQ(1000, st.top());
}

TEST(Stack, can_stack_copy)
{
	Stack<int> st;
	st.push(10);
	st.push(100);
	st.push(1000);
	ASSERT_NO_THROW(Stack<int> st2(st));
}

TEST(Stack, is_stack_copy_correct)
{
	Stack<int> st;
	st.push(10);
	st.push(100);
	st.push(1000);
	Stack<int> st2(st);
	EXPECT_TRUE(st == st2);
}
