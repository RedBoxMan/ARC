#include "util.h"

using namespace vex;

/// @brief Clamps the input inbetween the min and max value
/// @param input The value being clamped
/// @param min The minimum value that the output can be
/// @param max The maximum value that the output can be
/// @return Returns the input that has been clamped between min and max
float clamp(float input, float min, float max)
{
    if(input < min)
        return min;
    if(input > max)
        return max;
    return input;
}

/// @brief Gives the accurate value of pi, probably not neccessary but cool :)
/// @return Returns pi
float pi()
{
    return atan(1.0) * 4.0;
}


//**************************************************
// Linked List                                     *
//**************************************************

// isEmpty returns true if the list has no nodes and false if it does
template <typename T>
bool LinkedList<T>::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

template <typename T>
int LinkedList<T>::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	//list traversal
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

//returns the node value at a given integer position
template <typename T>
T LinkedList<T>::getNodeValue(int position)
{
	ListNode *nodePtr;
	if(!head)
		return -1;
	else
	{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		
		//list traversal
		while(nodePtr != NULL && position >= currentPos)
		{
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;				
		}
	}
	return -1;
}

//**************************************************
// appendNode appends a node containing the        *
// value passed into object, to the end of the list.   *
//**************************************************
template <typename T>
void LinkedList<T>::appendNode(T object)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store object there.
	newNode = new ListNode;
	newNode->value = object;
	newNode->next = NULL;
	newNode->previous = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		newNode->previous = tail;
		
		//now the tail is the new node
		tail = newNode;
	}
}

//insert a new node at the integer position passed to this function
template <typename T>
void LinkedList<T>::insertNode(int position, T object)
{
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->value = object;
	
	if(!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		while(nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}
		
		//now nodePtr is positioned 1 node BEFORE the node we want to insert
		if(nodePtr->next == NULL) //we are appending this node to the end
			tail = newNode;
			
		//set up newNode's links
		newNode->next = nodePtr->next;
		newNode->previous = nodePtr;
		
		//change the node on the left
		nodePtr->next = newNode;
		
		//change the node on the right (if there is a node on the right)
		if(newNode->next)
		{
			nodePtr = newNode->next; 
			nodePtr->previous = newNode;
		}
	}
	
}


//**************************************************
// The deleteNode function searches for a node     *
// with object as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************
template <typename T>
void LinkedList<T>::deleteNode(T object)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == object)
	{
		nodePtr = head->next;
		delete head;
		if(nodePtr != NULL)
		{
			head = nodePtr;
			head->previous = NULL;
		}
		else
			head = NULL;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to object.
		while (nodePtr && nodePtr->value != object)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
			if(previousNode != tail)
			{
				nodePtr = previousNode->next;
				nodePtr->previous = previousNode;
			}
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}