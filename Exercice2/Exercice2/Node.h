#ifndef NODE_H
#define NODE_H

#include <vector>

#define KEYS_MAX 3
#define LEAVES_MAX 4

using namespace std;
template<typename T>
class Node
{
public:
	Node();
	Node(vector<T> keys, vector<Node<T>*> leaves);

	vector<T> & getKeys()				{ return m_keys; };
	T getKey(int i)						{ return m_keys[i]; };
	int getNumberOfKeys()				{ return m_keys.size(); };
	void setKeys(vector<T> keys)		{ m_keys = keys; };
	void addKey(T key);
	void deleteKey(int i);

	vector<Node<T>*> & getLeaves()			{ return m_leaves; };
	Node<T>*getLeaf(int i)					{ return m_leaves[i]; };
	int getNumberOfLeaves()					{ return m_leaves.size(); };
	void setLeaves(vector<Node<T>>leaves)	{ m_leaves = leaves; };
	void addLeaf(Node<T>*leaf);
	void addLeaf(Node<T>*leaf, int index);
	void deleteLeaf(int i);

	bool isLeaf() { return m_leaves.size() == 0; };

	int getMedianIndex();

private:
	vector<T> m_keys;
	vector<Node<T>*> m_leaves;
};

template<typename T>
bool operator==(Node<T> n1, Node<T> n2);

template<typename T>
Node<T>::Node()
{
	m_keys = vector<T>();
	m_leaves = vector<Node<T>*>();
}


template<typename T>
Node<T>::Node(vector<T> keys, vector<Node<T>*> leaves)
{
	if (m_keys.size() >= KEYS_MAX)
		throw logic_error("number of keys is greater than KEYS_MAX");
	if (m_leaves.size() >= LEAVES_MAX)
		throw logic_error("number of leaves is greater than LEAVES_MAX");
	m_keys = keys;
	m_leaves = leaves;
}

template<typename T>
void Node<T>::addKey(T key)
{
	if (m_keys.size() >= KEYS_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_keys.push_back(key);
	sort(m_keys.begin(), m_keys.end());
}

template<typename T>
void Node<T>::deleteKey(int i)
{
	m_keys.erase(m_keys.begin() + i);
}

template<typename T>
void Node<T>::addLeaf(Node<T>*leaf)
{
	if (m_leaves.size() >= LEAVES_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_leaves.push_back(leaf);

}

template<typename T>
void Node<T>::addLeaf(Node<T>*leaf, int index)
{
	if (m_leaves.size() >= LEAVES_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_leaves.insert(m_leaves.begin() + index, leaf);
}

template<typename T>
void Node<T>::deleteLeaf(int i)
{
	m_leaves.erase(m_leaves.begin() + i);
}


template<typename T>
int Node<T>::getMedianIndex()
{
	if (m_keys.size() % 2 == 0)
		throw logic_error("no median available");
	return (m_keys.size()) / 2;
}


#endif