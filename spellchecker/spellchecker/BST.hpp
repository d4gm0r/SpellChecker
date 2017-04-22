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
	T* m_words;
	T* m_root;
	T* m_left;
	T* m_right;
};

#endif //SPELLCHECKER_BST_HPP