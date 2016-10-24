#ifndef TREE234_H
#define TREE234_H

#include "Node.h"

template <typename T>
class Tree234
{
public:
	Tree234();
	Tree234(vector<T> keys);
	virtual ~Tree234();

	bool isEmpty();
	shared_ptr<Node<T>> search(const T & key);
	void addKey(const T & key);

	void deleteKey(const T & keyToDelete);
private:
	shared_ptr<Node<T>> m_root;
	void _addKey(T key, shared_ptr<Node<T>> startNode, shared_ptr<Node<T>> parentNode);
	void _deleteKey(const T& keyToDelete, shared_ptr<Node<T>> startNode, shared_ptr<Node<T>> nodeToDelete);
	shared_ptr<Node<T>> _search(const T & key, shared_ptr<Node<T>> startNode);
};

template<typename T>
Tree234<T>::Tree234()
{
	m_root = make_shared<Node<T>>();
}

template<typename T>
Tree234<T>::Tree234(vector<T> keys)
{
	try
	{
		m_root = make_shared<Node<T>>(keys);
	}
	catch (logic_error error)
	{
		cout << error.what();
		m_root = make_shared<Node<T>>();
		for (int i; i < keys.size(); i++)
			addKey(keys[i]);
	}
}

template<typename T>
Tree234<T>::~Tree234()
{
}

template<typename T>
bool Tree234<T>::isEmpty()
{
	return (m_root->getNumberOfKeys() == 0);
}

template<typename T>
shared_ptr<Node<T>> Tree234<T>::search(const T & key)
{
	return _search(key, m_root);
}

template<typename T>
shared_ptr<Node<T>> Tree234<T>::_search(const T & key, shared_ptr<Node<T>> startNode)
{
	vector<T> keys = startNode->getKeys();
	if (find(keys.begin(), keys.end(), key) != keys.end())
		return startNode;
	if (startNode->isLeaf())
		return nullptr;

	vector<T> compareKeys;
	compareKeys.push_back(key);
	compareKeys.reserve(compareKeys.size() + startNode->getKeys().size());
	compareKeys.insert(compareKeys.end(), startNode->getKeys().begin(), startNode->getKeys().end());
	sort(compareKeys.begin(), compareKeys.end());
	int leafPos = find(compareKeys.begin(), compareKeys.end(), key) - compareKeys.begin();
	return _search(key, startNode->getLeaf(leafPos));
}

template <typename T>
void Tree234<T>::addKey(const T & key)
{
	_addKey(key, m_root, nullptr);
}

template<typename T>
void Tree234<T>::deleteKey(const T & keyToDelete)
{
	_deleteKey(keyToDelete, m_root, nullptr);
}

template<typename T>
void Tree234<T>::_deleteKey(const T & keyToDelete, shared_ptr<Node<T>> startNode, shared_ptr<Node<T>> nodeToDelete)
{
	int keyPosition = find(startNode->getKeys().begin(), startNode->getKeys().end(), keyToDelete) - startNode->getKeys().begin();

	if (keyPosition != startNode->getNumberOfKeys())
		nodeToDelete = startNode;

	if (startNode->isLeaf())
	{
		if (startNode == nodeToDelete)
		{
			if (keyPosition != startNode->getNumberOfKeys())
			{
				startNode->removeKey(keyPosition);
				return;
			}
		}
		if (nodeToDelete != nullptr)
		{
			keyPosition = find(nodeToDelete->getKeys().begin(), nodeToDelete->getKeys().end(), keyToDelete) - nodeToDelete->getKeys().begin();
			if (keyPosition != nodeToDelete->getNumberOfKeys())
				nodeToDelete->removeKey(keyPosition);
			nodeToDelete->addKey(startNode->getKey(0));
			startNode->removeKey(0);
			return;

		}
		throw logic_error("Key not found in the tree");

	}
	shared_ptr<Node<T>> leftNeighbourNode;
	shared_ptr<Node<T>> rightNeighbourNode;
	shared_ptr<Node<T>> mergedNode;
	shared_ptr<Node<T>> nextNode;

	int nextLeafPos;
	if (nodeToDelete == nullptr)
	{
		vector<T> sumKeys;
		sumKeys.push_back(keyToDelete);
		sumKeys.reserve(sumKeys.size() + startNode->getKeys().size());
		sumKeys.insert(sumKeys.end(), startNode->getKeys().begin(), startNode->getKeys().end());
		sort(sumKeys.begin(), sumKeys.end());
		nextLeafPos = find(sumKeys.begin(), sumKeys.end(), keyToDelete) - sumKeys.begin();
		nextNode = startNode->getLeaf(nextLeafPos);
	}
	else
	{
		vector<T> sumKeys;
		sumKeys.push_back(keyToDelete);
		sumKeys.reserve(sumKeys.size() + startNode->getKeys().size());
		sumKeys.insert(sumKeys.end(), startNode->getKeys().begin(), startNode->getKeys().end());
		sort(sumKeys.begin(), sumKeys.end());
		nextLeafPos = find(sumKeys.begin(), sumKeys.end(), keyToDelete) - sumKeys.begin() + 1;
		nextNode = startNode->getLeaf(nextLeafPos);
	}


	if (nextNode->getNumberOfKeys() == 1)
	{
		if (nextLeafPos > 0)
			leftNeighbourNode = startNode->getLeaf(nextLeafPos - 1);
		if (nextLeafPos < startNode->getNumberOfLeaves() - 1)
			rightNeighbourNode = startNode->getLeaf(nextLeafPos + 1);

		if (leftNeighbourNode != nullptr && leftNeighbourNode->getNumberOfKeys() != 1)
		{
			mergedNode = leftNeighbourNode;
			nextNode->addKey(startNode->getKey(nextLeafPos - 1));
			if (!mergedNode->isLeaf())
			{
				nextNode->pushLeaf(mergedNode->getLeaf(mergedNode->getNumberOfLeaves() - 1));
				mergedNode->removeLeaf(mergedNode->getNumberOfLeaves() - 1);
			}

			startNode->removeKey(nextLeafPos - 1);
			startNode->addKey(mergedNode->getKey(mergedNode->getNumberOfLeaves() - 1));
			mergedNode->removeKey(mergedNode->getNumberOfLeaves() - 1);
		}
		else if (rightNeighbourNode != nullptr && rightNeighbourNode->getNumberOfLeaves() != 1)
		{
			mergedNode = rightNeighbourNode;
			nextNode->addKey(startNode->getKey(nextLeafPos));
			if (!mergedNode->isLeaf())
			{
				nextNode->pushLeaf(mergedNode->getLeaf(0));
				mergedNode->removeLeaf(0);
			}

			startNode->removeKey(nextLeafPos);
			startNode->addKey(mergedNode->getKey(0));
			mergedNode->removeKey(0);
		}
		else
		{
			mergedNode = make_shared<Node<T>>();

			if (leftNeighbourNode != nullptr)
			{
				if (!nextNode->isLeaf())
				{
					for (size_t i = 0; i < leftNeighbourNode->getNumberOfLeaves(); i++)
						mergedNode->pushLeaf(leftNeighbourNode->getLeaf(i));
					for (size_t i = 0; i < nextNode->getNumberOfLeaves(); i++)
						mergedNode->pushLeaf(nextNode->getLeaf(i));
				}

				mergedNode->addKey(leftNeighbourNode->getKey(0));
				mergedNode->addKey(startNode->getKey(nextLeafPos - 1));
				mergedNode->addKey(nextNode->getKey(0));

				startNode->removeLeaf(nextLeafPos);
				startNode->removeLeaf(nextLeafPos - 1);

				startNode->removeKey(nextLeafPos - 1);

				startNode->insertLeafAt(mergedNode, nextLeafPos - 1);
			}

			else if (rightNeighbourNode != nullptr)
			{
				if (!nextNode->isLeaf())
				{
					for (size_t i = 0; i < nextNode->getNumberOfLeaves(); i++)
						mergedNode->pushLeaf(nextNode->getLeaf(i));
					for (size_t i = 0; i < rightNeighbourNode->getNumberOfLeaves(); i++)
						mergedNode->pushLeaf(rightNeighbourNode->getLeaf(i));
				}

				mergedNode->addKey(nextNode->getKey(0));
				mergedNode->addKey(startNode->getKey(nextLeafPos));
				mergedNode->addKey(rightNeighbourNode->getKey(0));

				startNode->removeLeaf(nextLeafPos + 1);
				startNode->removeLeaf(nextLeafPos);

				startNode->removeKey(nextLeafPos);

				startNode->insertLeafAt(mergedNode, nextLeafPos);
			}
			nextNode = mergedNode;
		}
	}

	_deleteKey(keyToDelete, nextNode, nodeToDelete);

}

template<typename T>
void Tree234<T>::_addKey(T key, shared_ptr<Node<T>> startNode, shared_ptr<Node<T>> parentNode)
{

	if (startNode->getNumberOfKeys() >= 3)
	{
		size_t medianPos = startNode->getMedianPos();
		shared_ptr<Node<T>> leftNewNode(new Node<T>());
		shared_ptr<Node<T>> rightNewNode(new Node<T>());

		for (size_t i = 0; i < medianPos; i++)
			leftNewNode->addKey(startNode->getKey(i));
		for (size_t i = medianPos + 1; i < startNode->getKeys().size(); i++)
			rightNewNode->addKey(startNode->getKey(i));

		int leafPos = 0;

		if (!startNode->isLeaf())
		{
			for (size_t i = 0; i <= medianPos; i++)
				leftNewNode->pushLeaf(startNode->getLeaf(i));
			for (size_t i = medianPos + 1; i < startNode->getLeaves().size(); i++)
				rightNewNode->pushLeaf(startNode->getLeaf(i));

		}

		if (startNode == m_root)
		{
			parentNode.reset(new Node<T>());
			m_root = parentNode;
		}
		else
		{
			leafPos = find(parentNode->getLeaves().begin(), parentNode->getLeaves().end(), startNode) - parentNode->getLeaves().begin();
			parentNode->removeLeaf(leafPos);
		}

		T medianKey = startNode->getKey(medianPos);
		parentNode->addKey(medianKey);

		parentNode->insertLeafAt(leftNewNode, leafPos);
		parentNode->insertLeafAt(rightNewNode, leafPos + 1);

		startNode = parentNode;
	}

	if (startNode->isLeaf()) {
		try {
			startNode->addKey(key);
		}
		catch (logic_error error) {
			cout << error.what();
		}
			
	}
	else
	{
		vector<T> sumKeys;
		sumKeys.push_back(key);
		sumKeys.reserve(sumKeys.size() + startNode->getKeys().size());
		sumKeys.insert(sumKeys.end(), startNode->getKeys().begin(), startNode->getKeys().end());
		sort(sumKeys.begin(), sumKeys.end());
		int nextleafPos = find(sumKeys.begin(), sumKeys.end(), key) - sumKeys.begin();
		_addKey(key, startNode->getLeaf(nextleafPos), startNode);
	}
}

#endif