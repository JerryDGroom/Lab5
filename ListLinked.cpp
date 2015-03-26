/*
*******************************************************************

LAB 5 Group
Linked List's
Jerry Groom & Christian Uwimana
3/1/15

*******************************************************************
*/

#include "ListLinked.h"
#include <iostream>


template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
    dataItem = nodeData;
    next = nextPtr;
}
template <typename DataType>
List<DataType>::List(int ignored){
    head = NULL;
    cursor = NULL;
}
// Copy constructor. Creates a list which is equivalent in content
// to the "other" list.
template <typename DataType>
List<DataType>::List(const List& other)
    : head(0), cursor(0)
{
    operator=(other);
}
// Overloaded assignment operator. Reinitializes the list to be
// equivalent in content to the "other" list.
// Note: we include self-assignment protection by checking whether
// "this" object is identical to the "other" object.
template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
    if( this != &other ) {
		clear();
		ListNode *otherPtr = other.head;
		ListNode *holdCursor = 0;
		while( otherPtr != 0 ) {
			insert(otherPtr->dataItem);
			if(otherPtr == other.cursor) {
				holdCursor = cursor;
			}
			otherPtr = otherPtr->next;
		}
		cursor = holdCursor;
    }

    return *this;
}

// Destructor. Frees the memory used by a list.
template <typename DataType>
List<DataType>::~List()
{
    clear();
}
template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){

    if(isEmpty()){
        ListNode* newNode = new ListNode(newDataItem,NULL);
        newNode->dataItem = newDataItem;
        newNode->next = NULL;
        this->head = newNode;
        cursor = newNode;


    //insert new node with a pointer equal to address of previous nodes pointer
    //adjust the previous objects pointer to point to new node.
    //increment cursor by one.
    }else{
        if(cursor->next == NULL){
        ListNode* newNode = new ListNode(newDataItem,NULL);
        newNode->dataItem = newDataItem;
        newNode->next = NULL;
        cursor->next = newNode;
        cursor = newNode;
        }else{
            ListNode* newNode = new ListNode(newDataItem,NULL);
            newNode->dataItem = newDataItem;
            ListNode* temp = cursor->next;
            newNode->next = temp;
            cursor->next = newNode;
            cursor = newNode;
        }
    }
}
template <typename DataType>
void List<DataType>::remove() throw (logic_error){
    if(isEmpty()){
        cout <<"This is an empty list, there is nothing to delete"<< endl;
    }else{
        if (cursor->next != NULL) {
                ListNode *oldcell = cursor->next;
                cursor->next = oldcell->next;
                delete cursor;
                //clear();
        }
    }
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
    if(isEmpty()){
        cout <<"This is an empty list, there is nothing to replace."<< endl;

    }else{
    cursor->dataItem = newDataItem;
    }
}

template <typename DataType>
void List<DataType>::clear(){
    head = NULL;
    cursor = NULL;

}


template <typename DataType>
bool List<DataType>::isEmpty() const{
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

template <typename DataType>
bool List<DataType>::isFull() const{
    return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
    if(head == NULL){
        cout <<"This is an empty list"<< endl;
    }else{
        this->head = head;
        cursor = head;
    }
}
template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error){
    if(cursor->next == NULL){
            cout <<"This is the end of the list"<< endl;
    }else{
        while(cursor->next != NULL){
                cursor = cursor->next;
        }
    }
}


template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error){
    if(head == NULL){
            cout <<"This is an Empty List"<< endl;
    }else{
        cursor = cursor->next;
        return true;
    }
    return false;
}


template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error){
    if(head == NULL){
            cout <<"This is an Empty List"<< endl;
    }else{
        cout<<this->cursor<< endl;
        cout<<cursor<< endl;
        ListNode *prev = head;
        if (cursor != head){
            while(prev->next != cursor) {
                prev = prev->next;
            }
            cursor = prev;
            return true;
        }
        return false;
    }
}
//cellT *cp = start;
//if (cursor != start) {
//while (cp->link != cursor) {
//cp = cp->link;
//}
//cursor = cp;
//}
//}
template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error){
    if(isEmpty()){
            cout <<"This is an empty list"<< endl;
    }else{
        return cursor->dataItem;
}
}


/*
// Programming exercise 2
template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error){
    if(isEmpty()){
            cout <<"This is an empty list"<< endl;
    }else{
}

// Programming exercise 3
template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error){
    if(isEmpty()){
            cout <<"This is an empty list"<< endl;
    }else{
}
*/

template <typename DataType>
void List<DataType>::showStructure() const{

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.


    if ( isEmpty() )
    {
       cout << "Empty list" << endl;
    }
    else
    {
	for (ListNode* temp = head; temp != 0; temp = temp->next) {
	    if (temp == cursor) {
		cout << "[";
	    }

	    // Assumes that dataItem can be printed via << because
	    // is is either primitive or operator<< is overloaded.
	    cout << temp->dataItem;

	    if (temp == cursor) {
		cout << "]";
	    }
	    cout << " ";
	}
	cout << endl;
    }
}

