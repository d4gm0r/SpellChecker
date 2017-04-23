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
	Node* ptrNew = new Node(value);
	bool isFound = search(m_root, ptrNew);
	delete ptrNew;
	return isFound;
}

template <typename T>
bool BST::search(Node* node, Node* word)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->data.compare(word->data) == 0)
	{
		return true;
	}
	else if (node->data.compare(word->data) < 0)
	{
		search(node->left, word);
	}
	else if (node->data.compare(word->data) > 0)
	{
		search(node->right, word);
	}
}

template <typename T>
unsigned int BST::numberNodes()
{
	return numberNodes(m_root)
}

template <typename T>
unsigned int BST::numberNodes(Node* node)
{
	unsigned int count = 0;
	if (node)
	{
		count++;
		count += numberNodes(node->left);
		count += numberNodes(node->right);
	}

	return count;
}

template <typename T>
unsigned int BST::numberLeafNodes()
{
	return numberLeafNodes(m_root);
}

template <typename T>
unsigned int BST::numberLeafNodes(Node* node)
{
	unsigned int count = 0;
	if (node)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			count++;
		}
		count += numberLeafNodes(node->left);
		count += numberLeafNodes(node->right);
	}
	return count;
}

template <typename T>
unsigned int BST::height()
{
	return height(m_root);
}

template <typename T>
unsigned int BST::height(Node* node)
{

}