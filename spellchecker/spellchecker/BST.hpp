#ifndef SPELLCHECKER_BST_HPP
#define SPELLCHECKER_BST_HPP

#include <iostream>

template <typename T>
struct Node
{
public:
	Node(T word)
	{
		m_left = nullptr;
		m_right = nullptr;
		m_word = word;
	}
	Node<T>* m_left;
	Node<T>* m_right;
	T m_word;
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
	m_root = nullptr;
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
void BST<T>::remove(T value)
{
	Node<T>* ptrNew = new Node<T>(value);

	remove(m_root, ptrNew);
}

template <typename T>
void BST<T>::remove(Node<T>* node, Node<T>* word)
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
unsigned int BST<T>::numberNodes()
{
	return numberN(m_root)
}

template <typename T>
unsigned int BST<T>::numberN(Node<T>* node)
{
	unsigned int count = 0;
	if (node)
	{
		count++;
		count += numberN(node->left);
		count += numberN(node->right);
	}

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
	if (node)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			count++;
		}
		count += numberLN(node->left);
		count += numberLN(node->right);
	}
	return count;
}

template <typename T>
unsigned int BST<T>::height()
{
	return heightTree(m_root);
}

template <typename T>
unsigned int BST<T>::heightTree(Node<T>* node)
{
	unsigned int height = 0;
	unsigned int tempCount = 0;

	if (node)
	{
		tempCount++;
		if (node->left == nullptr && node->right == nullptr)
		{
			return height + tempCount;
		}
	}

	return height;
}

#endif //SPELLCHECKER_BST_HPP