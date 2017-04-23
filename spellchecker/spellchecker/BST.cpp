#include "BST.hpp"

template <typename T>
BST::BST()
{
	m_root = nullptr;
}

template <typename T>
BST::~BST()
{
	
}

template <typename T>
bool BST::insert(T value)
{
	Node* ptrNew = new Node(value);
	bool isInserted = insert(m_root, ptrNew);
	delete ptrNew;
	return isInserted;
}

template <typename T>
bool BST::insert(Node* node, Node* newWord)
{
	if(node == nullptr)
	{
		node = newWord;
		delete newWord;
		return true;
	}
	else if (node->data.compare(newWord->data) < 0)
	{
		insert(node->left, newWord);
	}
	else if (node->data.compare(newWord->data) > 0)
	{
		insert(node->right, newWord);
	}

	delete newWord;
	return false;
}

template <typename T>
void BST::remove(T value)
{
	Node* ptrNew = new Node(value);

	remove(m_root, ptrNew);
}

template <typename T>
void BST::remove(Node* node, Node* word)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->data.compare(word->data) == 0)
	{
		if (node->left)
		{

		}
		if (node->right)
		{

		}
		delete node;
		return;
	}
	else if (node->data.compare(word->data) < 0)
	{
		remove(node->left, newWord);
	}
	else if (node->data.compare(word->data) > 0)
	{
		remove(node->right, newWord);
	}

	return false;
}

template <typename T>
bool BST::search(T value)
{

}

template <typename T>
bool BST::search(Node* node, Node* word)
{

}

template <typename T>
unsigned int BST::numberNodes()
{

}

template <typename T>
unsigned int BST::numberLeafNodes()
{

}

template <typename T>
unsigned int BST::height()
{

}