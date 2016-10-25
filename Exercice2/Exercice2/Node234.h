#ifndef NODE234_H
#define NODE234_H

#include <vector>

#define KEYS_MAX 3
#define LEAVES_MAX 4

using namespace std;
template<typename T>
class Node234
{
public:
	Node234();
	Node234(vector<T> keys, vector<Node234<T>*> leaves);

	vector<T> & getKeys()				{ return m_keys; };
	T getKey(int i)						{ return m_keys[i]; };
	int getNumberOfKeys()				{ return m_keys.size(); };
	void setKeys(vector<T> keys)		{ m_keys = keys; };
	void addKey(T key);
	void deleteKey(int i);

	vector<Node234<T>*> & getLeaves()			{ return m_leaves; };
	Node234<T>*getLeaf(int i)					{ return m_leaves[i]; };
	int getNumberOfLeaves()					{ return m_leaves.size(); };
	void setLeaves(vector<Node234<T>>leaves)	{ m_leaves = leaves; };
	void addLeaf(Node234<T>*leaf);
	void addLeaf(Node234<T>*leaf, int index);
	void deleteLeaf(int i);

	bool isLeaf() { return m_leaves.size() == 0; };

	int getMedianIndex();

private:
	vector<T> m_keys;
	vector<Node234<T>*> m_leaves;
};

template<typename T>
bool operator==(Node234<T> n1, Node234<T> n2);

template<typename T>
Node234<T>::Node234()
{
	m_keys = vector<T>();
	m_leaves = vector<Node234<T>*>();
}


template<typename T>
Node234<T>::Node234(vector<T> keys, vector<Node234<T>*> leaves)
{
	if (m_keys.size() >= KEYS_MAX)
		throw logic_error("number of keys is greater than KEYS_MAX");
	if (m_leaves.size() >= LEAVES_MAX)
		throw logic_error("number of leaves is greater than LEAVES_MAX");
	m_keys = keys;
	m_leaves = leaves;
}

template<typename T>
void Node234<T>::addKey(T key)
{
	if (m_keys.size() >= KEYS_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_keys.push_back(key);
	sort(m_keys.begin(), m_keys.end());
}

template<typename T>
void Node234<T>::deleteKey(int i)
{
	m_keys.erase(m_keys.begin() + i);
}

template<typename T>
void Node234<T>::addLeaf(Node234<T>*leaf)
{
	if (m_leaves.size() >= LEAVES_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_leaves.push_back(leaf);

}

template<typename T>
void Node234<T>::addLeaf(Node234<T>*leaf, int index)
{
	if (m_leaves.size() >= LEAVES_MAX) {
		throw logic_error("KEYS_MAX already reached");
	}
	m_leaves.insert(m_leaves.begin() + index, leaf);
}

template<typename T>
void Node234<T>::deleteLeaf(int i)
{
	m_leaves.erase(m_leaves.begin() + i);
}


template<typename T>
int Node234<T>::getMedianIndex()
{
	if (m_keys.size() % 2 == 0)
		throw logic_error("no median available");
	return (m_keys.size()) / 2;
}


#endif