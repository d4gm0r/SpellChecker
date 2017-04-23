#ifndef SPELLCHECKER_BST_HPP
#define SPELLCHECKER_BST_HPP

#include <iostream>

template <typename T>
class BST
{
public:
	BST();
	~BST();

	bool insert(T value);
	void remove(T value);
	unsigned int numberNodes();
	unsigned int numberLeafNodes();
	unsigned int height();

private:
	class Node
	{
	public:
		Node(T word)
		{
			m_left = nullptr;
			m_right = nullptr;
			m_word = word;
		}
		Node* m_left;
		Node* m_right;
		T* m_word;
	};

	Node* m_root;
};

#endif //SPELLCHECKER_BST_HPP