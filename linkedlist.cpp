#include <iostream>
#include <cstdlib>

using namespace std;

struct NODE {
	int val;
	NODE* next;
};

void addNodeAtEnd(NODE** list, int val)
{
	NODE* newNode = new NODE;
	newNode->val = val;
	newNode->next = NULL;

	if (*list == NULL) {
		*list = newNode;
		return;
	}
	NODE* temp = *list;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	return;

}

void addNodeAtFront(NODE** list, int val)
{
	NODE* newNode = new NODE;
	newNode->val = val;
	if (*list == NULL) {
		newNode->next = NULL;
		*list = newNode;
		return;
	}
	newNode->next = *list;
	*list = newNode;
	return;
}

int getSize(NODE* list)
{
	int size = 0;
	if (list == NULL)
		return size;
	while (list != NULL) {
		list = list->next;
		size++;
	}
	return size;
}

int getMiddleIndex(NODE* list)
{
	int middleIndex = 0, size = getSize(list);

	if (size == 0)
		return middleIndex;
	if ((size % 2) == 0) {
		while ((middleIndex + 1) != (size - 1)) {
			list = list->next;
			size--;
			middleIndex++;
		}
	}
	else {
		while (middleIndex != (size - 1)) {
			list = list->next;
			size--;
			middleIndex++;
		}
	}
	return middleIndex;
}

void insertNodeAtMiddle(NODE** list, int val)
{
	NODE* newNode = new NODE;
	newNode->val = val;
	int middleIndex = getMiddleIndex(*list);
	if (*list == NULL) {
		newNode->next = NULL;
		*list = newNode;
		return;
	}
	NODE* temp = *list;
	while (middleIndex != 0) {
		temp = temp->next;
		middleIndex--;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;
}

void insertNodeAtK(NODE** list, int val, int k)
{
	NODE* newNode = new NODE;
	newNode->val = val;
	int index = 0;
	if (*list == NULL) {
		newNode->next = NULL;
		*list = newNode;
		return;
	}
	NODE* temp = *list;
	while (index != k) {
		temp = temp->next;
		index++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;

}

//Reversal of Linked List: Iterative Way
void reverseLinkedListIteratively(NODE** list)
{
	NODE* prev = NULL, * curr = *list, * nextNode = NULL;
	if (list == NULL)
		return ;
	while (curr != NULL) {
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	*list = prev;
}

//Reversal of Linked List: Recursive Way
NODE* reverseRecursively(NODE* list)
{
	if (list == NULL || list->next == NULL) {
		return list;
	}
	NODE* restList = reverseRecursively(list->next);
	list->next->next = list;
	list->next = NULL;
	return restList;
}

void deleteNodeFromEnd(NODE** list)
{
	NODE *temp = *list, *prev = NULL;
	if (*list == NULL) {
		return;
	}
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	temp = NULL;
	prev->next = NULL;
	delete temp;
}

void deleteNodeFromFront(NODE** list)
{
	NODE *prev = *list, *temp = *list;
	if (*list == NULL) {
		return;
	}
	temp = temp->next;
	prev->next = NULL;
	*list = temp;
	delete prev;
}

void deleteNodeAtK(NODE** list, int k)
{
	NODE *prev = NULL, *curr = *list;
	int index = 0;
	if (*list == NULL) {
		return;
	}

	while (index != k) {
		index++;
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	curr->next = NULL;
	delete curr;
}

//Delete the given node
NODE* getNode(NODE* list, int val)
{
	while (list->val != val) {
		list = list->next;
	}
	return list;
}

void deleteGivenNode(NODE* nodeToDelete)
{
	nodeToDelete->val = nodeToDelete->next->val;
	nodeToDelete->next = nodeToDelete->next->next;
}

void printList(NODE* list)
{
	if (list == NULL)
		return;
	printf("%d", list->val);
	printList(list->next);
}

int main()
{
	NODE* list = NULL;
	int k, size;
	addNodeAtFront(&list, 0);
	addNodeAtEnd(&list, 1);
	addNodeAtEnd(&list, 2);
	addNodeAtEnd(&list, 3);
	addNodeAtFront(&list, 1);
	insertNodeAtMiddle(&list, 4);
	printList(list);
	cout << endl;
	cin >> k;
	size = getSize(list);
	if (k > size) {
		addNodeAtEnd(&list, 5);
	}
	else if (k < 0) {
		addNodeAtFront(&list, 5);
	}
	else {
		insertNodeAtK(&list, 5, k);
	}
	printList(list);
	cout << endl;
	reverseLinkedListIteratively(&list);
	printList(list);
	cout << endl;
	list = reverseRecursively(list);
	printList(list);
	cout << endl;
	deleteNodeFromEnd(&list);
	printList(list);
	cout << endl;
	deleteNodeFromFront(&list);
	printList(list);
	cout << endl;
	cin >> k;
	deleteNodeAtK(&list, k);
	printList(list);
	cout << endl;
	NODE* nodeToDelete = getNode(list, 4);
	deleteGivenNode(nodeToDelete);
	printList(list);
	return 0;
}
