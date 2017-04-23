#ifndef SPELLCHECKER_BST_HPP
#define SPELLCHECKER_BST_HPP

#include <iostream>

template <typename T>
struct Node
{
public:
	Node() 
	{
		m_left = nullptr;
		m_right = nullptr;
	}
	Node(T word)
	{
		m_left = nullptr;
		m_right = nullptr;
		m_data = word;
	}
	Node<T>* m_left;
	Node<T>* m_right;
	T m_data;
};

template <typename T>
class BST
{
public:
	BST();
	~BST();

	bool insert(T value);
	bool insert(Node<T>* node, Node<T>* newWord);
	void remove(T value);
	void remove(Node<T>* node, Node<T>* word);
	bool search(T value);
	bool search(Node<T>* node, Node<T>* word);
	unsigned int numberNodes();
	unsigned int numberN(Node<T>* node);
	unsigned int numberLeafNodes();
	unsigned int numberLN(Node<T>* node);
	unsigned int height();
	unsigned int heightTree(Node<T>* node);

private:

	Node<T>* m_root;
};

template <typename T>
BST<T>::BST()
{
	m_root = new Node<T>();
}

template <typename T>
BST<T>::~BST()
{

}

template <typename T>
bool BST<T>::insert(T value)
{
	Node<T>* ptrNew = new Node<T>(value);
	bool isInserted = insert(m_root, ptrNew);
	delete ptrNew;
	return isInserted;
}

template <typename T>
bool BST<T>::insert(Node<T>* node, Node<T>* newWord)
{
	if (node == nullptr)
	{
		node = newWord;
		return true;
	}
	else if (node->m_data.compare(newWord->m_data) < 0)
	{
		insert(node->m_left, newWord);
	}
	else if (node->m_data.compare(newWord->m_data) > 0)
	{
		insert(node->m_right, newWord);
	}

	return false;
}

template <typename T>
void BST<T>::remove(T value)
{
	Node<T>* ptrNew = new Node<T>(value);

	remove(m_root, ptrNew);
}

template <typename T>
void BST<T>::remove(Node<T>* node, Node<T>* word)//unfinished
{
	if (node == nullptr)
	{
		return;
	}
	if (node->m_data.compare(word->m_data) == 0)
	{
		if (node->m_left)
		{

		}
		if (node->m_right)
		{

		}
		delete node;
		return;
	}
	else if (node->m_data.compare(word->m_data) < 0)
	{
		remove(node->m_left, newWord);
	}
	else if (node->m_data.compare(word->m_data) > 0)
	{
		remove(node->m_right, newWord);
	}

	return false;
}

template <typename T>
bool BST<T>::search(T value)
{
	Node<T>* ptrNew = new Node<T>(value);
	bool isFound = search(m_root, ptrNew);
	delete ptrNew;
	return isFound;
}

template <typename T>
bool BST<T>::search(Node<T>* node, Node<T>* word)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->m_data.compare(word->m_data) == 0)
	{
		return true;
	}
	else if (node->m_data.compare(word->m_data) < 0)
	{
		search(node->m_left, word);
	}
	else if (node->m_data.compare(word->m_data) > 0)
	{
		search(node->m_right, word);
	}
}

template <typename T>
unsigned int BST<T>::numberNodes()
{
	return numberN(m_root);
}

template <typename T>
unsigned int BST<T>::numberN(Node<T>* node)
{
	unsigned int count = 0;

	if (node == nullptr)
	{
		return 0;
	}

	++count;
	count += numberN(node->m_left);
	count += numberN(node->m_right);

	return count;
}

template <typename T>
unsigned int BST<T>::numberLeafNodes()
{
	return numberLN(m_root);
}

template <typename T>
unsigned int BST<T>::numberLN(Node<T>* node)
{
	unsigned int count = 0;

	if (node == nullptr)
	{
		return 0;
	}
	if (node->m_left == nullptr && node->m_right == nullptr)
	{
		++count;
	}

	count += numberLN(node->m_left);
	count += numberLN(node->m_right);

	return count;
}

template <typename T>
unsigned int BST<T>::height()
{
	return heightTree(m_root);
}

template <typename T>
unsigned int BST<T>::heightTree(Node<T>* node)//unfinished
{
	unsigned int height = 0;
	unsigned int tempCount = 0;

	if (node)
	{
		tempCount++;
		if (node->m_left == nullptr && node->m_right == nullptr)
		{
			return height + tempCount;
		}
	}

	return height;
}

#endif //SPELLCHECKER_BST_HPP