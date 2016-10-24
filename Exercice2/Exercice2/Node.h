#ifndef NODE_H
#define NODE_H

#include <vector>
#include <memory>

template<typename T>
class Node
{
public:
	Node();
	~Node();
	Node(vector<T> keys, vector<shared_ptr<Node<T>>> leaves);

	const vector<T> & getKeys()						{ return m_keys;				};
	T getKey(int i)									{ return m_keys[i];				};
	const vector<shared_ptr<Node<T>>> & getLeaves() { return m_leaves;				};
	shared_ptr<Node<T>> getLeaf(int i)				{ return m_leaves[i];			};
	int getNumberOfKeys()							{ return m_keys.size();			};
	int getNumberOfLeaves()							{ return m_leaves.size();		};
	bool isLeaf()									{ return m_leaves.size() == 0;	};

	void setKeys(vector<T> keys)					{ m_keys	= keys;				};
	void setLeaves(vector<Node<T>>leaves)			{ m_leaves	= leaves;			};
	
	void addKey(T key);
	void pushLeaf(shared_ptr<Node<T>> leaf);
	void insertLeafAt(shared_ptr<Node<T>> leaf, int pos);
	void removeLeaf(int i);
	void removeKey(int i);
	int getMedianPos();

	bool operator==(Node<T> node) const;

private:
	vector<T> m_keys;
	vector<shared_ptr<Node<T>>> m_leaves;
	static const int MAX_KEYS = 3;
	static const int MAX_LEAVES = 4;
};

template<typename T>
Node<T>::Node()
{
	m_keys = vector<T>();
	m_leaves = vector<shared_ptr<Node<T>>>();
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
Node<T>::Node(vector<T> keys, vector<shared_ptr<Node<T>>> leaves)
{
	if (m_keys.size() >= MAX_KEYS)
		throw logic_error("number of keys is greater than MAX_KEYS");
	if (m_leaves.size() >= MAX_LEAVES)
		throw logic_error("number of leaves is greater than MAX_LEAVES");
	m_keys = keys;
	m_leaves = leaves;
}



template<typename T>
void Node<T>::addKey(T key)
{
	if (m_keys.size() >= MAX_KEYS) {
		throw logic_error("MAX_KEYS already reached");
	}
	m_keys.push_back(key);
	sort(m_keys.begin(), m_keys.end());
}

template<typename T>
bool Node<T>::pushLeaf(shared_ptr<Node<T>> leaf)
{
	if (m_leaves.size() >= MAX_LEAVES) {
		throw logic_error("MAX_KEYS already reached");
	}
	m_leaves.push_back(leaf);

}

template<typename T>
void Node<T>::insertLeafAt(shared_ptr<Node<T>> leaf, int pos)
{
	if (m_leaves.size() >= MAX_LEAVES) {
		throw logic_error("MAX_KEYS already reached");
	}
	m_leaves.insert(m_leaves.begin() + pos, leaf);
}

template<typename T>
void Node<T>::removeLeaf(int i)
{
	m_leaves.erase(m_leaves.begin() + i);
}

template<typename T>
void Node<T>::removeKey(int i)
{
	m_keys.erase(m_keys.begin() + i);
}
template<typename T>
size_t Node<T>::getMedianPos()
{
	if (m_keys.size() % 2 == 0)
		throw logic_error("The number of keys is even, so there is no median key");
	return (m_keys.size()) / 2;
}

template<typename T>
bool Node<T>::operator==(Node<T> node) const
{
	return (m_keys == node.getKeys() && m_leaves == node.getLeaves());
}

#endif