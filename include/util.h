#pragma once

#include "vex.h"

/// @brief Clamps the input inbetween the min and max value
/// @param input The value being clamped
/// @param min The minimum value that the output can be
/// @param max The maximum value that the output can be
/// @return Returns the input that has been clamped between min and max
float clamp(float input, float min, float max);

/// @brief Gives the accurate value of pi, probably not neccessary but cool :)
/// @return Returns pi
float pi();

template <typename T>
class LinkedList
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			T value;                   	// The value in this node
			struct ListNode *next;  	// To point to the next node
			struct ListNode *previous;	// To point to the previous node
		}; 

		ListNode *head;		// List head pointer
		ListNode *tail;		//List tail pointer

	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (similar to a typical RemoveAll function)
		~LinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		T getNodeValue(int);
		void appendNode(T);
		void insertNode(int, T);
		void deleteNode(T);
};
