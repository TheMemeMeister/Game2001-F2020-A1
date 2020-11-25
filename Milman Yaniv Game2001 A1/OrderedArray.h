#pragma once
#include <cassert>
#include "BaseArray.h"

template <class T>
class OrderedArray : public BaseArray <T>
{
public:
	//Constructor
	OrderedArray(int size, int growBy = 1) :
		BaseArray<T>(size, growBy)
	{

	}
	// Destructor
	~OrderedArray()
	{
		if (BaseArray<T>::m_array != NULL)
		{
			delete[] BaseArray<T>::m_array;
			BaseArray<T>::m_array = NULL;		// Good programming practice to set unused pointers to NULL
		}
	}
	// Insertion - Big O = O(N)
	int push(T val)
	{

		assert(BaseArray<T>::m_array != NULL);

		if (BaseArray<T>::m_numElements >= BaseArray<T>::m_maxSize)
		{
			BaseArray<T>::Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < BaseArray<T>::m_numElements; i++)
		{
			if (BaseArray<T>::m_array[i] == val)
			{
				return -1;
			}

			if (BaseArray<T>::m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = BaseArray<T>::m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			BaseArray<T>::m_array[k] = BaseArray<T>::m_array[k - 1];
		}

		// Step 3 Insert val into index
		BaseArray<T>::m_array[i] = val;

		BaseArray<T>::m_numElements++;

		return i;
	}

	// Searching -- Binary Search -- Big O = O(log N)
	//int search(T searchKey)
	//{
	//	assert(m_array != NULL);

	//	 Helper variables
	//	int lowerBound = 0;
	//	int upperBound = m_numElements - 1;
	//	int current = 0;

	//	while (1)	// <-- Replaced with recursion
	//	{
	//		current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations. Divides by 2

	//		 Binary search steps:
	//		 Step 1: Check if the middle is the value we are looking for
	//		if (m_array[current] == searchKey)
	//		{
	//			 Found the item in the middle of the array. Return the index
	//			return current;
	//		}
	//		 Step 2: Check that we've exhausted all options. Can't find the item
	//		else if (lowerBound > upperBound)
	//		{
	//			return -1;
	//		}
	//		else
	//		{
	//			 Step 3: Check which half of the array the value is in
	//			if (m_array[current] < searchKey)
	//			{
	//				lowerBound = current + 1;
	//			}
	//			else
	//			{
	//				upperBound = current - 1;
	//			}
	//		}
	//	}

	//	return -1;
	//}
	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(BaseArray<T>::m_array != NULL && index < BaseArray<T>::m_numElements);
		return BaseArray<T>::m_array[index];
	}
	// Clear
	void clear()
	{
		BaseArray<T>::m_numElements = 0;
	}
	// Gets and Sets
	int GetSize()
	{
		return BaseArray<T>::m_numElements;
	}
	int GetMaxSize()
	{
		return BaseArray<T>::m_maxSize;
	}
	int GetGrowSize()
	{
		return BaseArray<T>::m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(BaseArray<T>::val >= 0);
		BaseArray<T>::m_growSize = val;
	}
private:
	int search(T searchKey)
	{
		assert(BaseArray<T>::m_array != NULL);

		// Helper variables
		int lowerBound = 0;
		int upperBound = BaseArray<T>::m_numElements - 1;
		int current = 0;

		while (1)    // <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for
			if (BaseArray<T>::m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				// Step 3: Check which half of the array the value is in
				if (BaseArray<T>::m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}

};