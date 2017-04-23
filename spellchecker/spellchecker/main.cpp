#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

/*
void testTree()
{
BinaryTree<std::string> tree;
//
// Add a bunch of values to the tree
tree.insert("Olga");
tree.insert("Tomeka");
tree.insert("Benjamin");
tree.insert("Ulysses");
tree.insert("Tanesha");
tree.insert("Judie");
tree.insert("Tisa");
tree.insert("Santiago");
tree.insert("Chia");
tree.insert("Arden");

//
// Make sure it displays in sorted order
tree.display();

//
// Try to add a duplicate
std::cout << std::endl << "---- adding a duplicate ----" << std::endl;
if (tree.insert("Tomeka"))
{
std::cout << "oops, shouldn't have returned true from the insert" << std::endl;
}
tree.display();

//
// Remove an existing value from the tree
std::cout << std::endl << "---- removing an existing value ----" << std::endl;
tree.remove("Olga");
tree.display();

//
// Remove a value that was never in the tree, hope it doesn't crash!
tree.remove("Karl");

//
// Check the tree stats
std::cout << std::endl << "---- checking the tree stats ----" << std::endl;
std::cout << "Expecting 9 nodes, found " << tree.numberNodes() << std::endl;
std::cout << "Expecting 4 leaf nodes, found " << tree.numberLeafNodes() << std::endl;
std::cout << "Expecting height of 6, found " << tree.height() << std::endl;
}
*/

std::vector<std::string> readFile(std::string file) 
{
	std::string word = "";
	std::vector<std::string> words;

	std::ifstream fi(file);

	if (file.compare("Letter.txt") == 0)
	{
		while (fi >> word)
		{
			for (unsigned int i = 0, size = word.size(); i < size; i++)
			{
				if (ispunct(word[i]))
				{
					//char punct = static_cast<char> (word[i]);
					//if (punct != "a") {}
					word.erase(i--, 1);
					size = word.size();
				}
			}
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			words.push_back(word);
		}
	}
	else
	{
		while (fi >> word)
		{
			words.push_back(word);
		}
	}

	fi.close();

	return words;
}

int main()
{
	std::vector<std::string> words = readFile("Letter.txt");

	for (unsigned int i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << std::endl;
	}
	return 0;
}