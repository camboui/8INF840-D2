#ifndef RED_BLACK_NODE_H
#define RED_BLACK_NODE_H

#define RED 0
#define BLACK 1

template <typename T>
class RedBlackNode
{
public:
	RedBlackNode();
	RedBlackNode(int color, T key);
	RedBlackNode(int color, T key, RedBlackNode<T>* parent, RedBlackNode<T>* left, RedBlackNode<T>* right);
	RedBlackNode<T>& operator=(const RedBlackNode<T> &copy);
	int					getColor()				{ return m_color;	};
	RedBlackNode<T>*	getLeftNode()			{ return m_left;	};
	RedBlackNode<T>*	getRightNode()			{ return m_right;	};
	RedBlackNode<T>*	getParentNode()			{ return m_parent;	};
	RedBlackNode<T>*	getUncleNode() {
		if (getGrandParentNode() == nullptr) return nullptr;
		else if (getGrandParentNode()->getLeftNode() == m_parent) return getGrandParentNode()->getRightNode();
		else return getGrandParentNode()->getLeftNode();
	};
	RedBlackNode<T>*	getBrotherNode() {
		if (getParent() == nullptr) return nullptr;
		else if (getParentNode()->getLeftNode() == this) return getParentNode()->getRightNode();
		else return getParentNode()->getLeftNode();
	};
	RedBlackNode<T>*	getGrandParentNode()	{ if (m_parent) return m_parent->getParentNode(); else return nullptr; };
	T					getKey()				{ return m_key;		};

	void setColor(int color)					{ m_color = color;			};
	void changeColor()							{ m_color = 1 - m_color;	};
	void setLeftNode(RedBlackNode<T>* left)		{ m_left = left;			};
	void setRightNode(RedBlackNode<T>* right)	{ m_right = right;			};
	void setParentNode(RedBlackNode<T>* parent) { m_parent = parent;		};
	void setKey(T key)							{ m_key = key;				};

private:
	int					m_color;
	RedBlackNode<T>*	m_left;
	RedBlackNode<T>*	m_right;
	RedBlackNode<T>*	m_parent;
	T					m_key;
};


template<typename T>
RedBlackNode<T>::RedBlackNode():
	RedBlackNode(BLACK, T())
{
}

template<typename T>
RedBlackNode<T>::RedBlackNode(int color, T key):
	m_color(color),
	m_key(key)
{
	m_left   = nullptr;
	m_right  = nullptr;
	m_parent = nullptr;
}

template<typename T>
RedBlackNode<T>::RedBlackNode(int color, T key, RedBlackNode<T>* parent, RedBlackNode<T>* left, RedBlackNode<T>* right):
	m_color(color),
	m_key(key),
	m_left(left),
	m_right(right),
	m_parent(parent)
{
	if (left != nullptr) {
		left->m_parent = this;
	}
	if (right != nullptr) {
		right->m_parent = this;
	}
	if (parent != nullptr)
		if (parent->m_key > key) {
			parent->m_left = this;
		}
		else {
			parent->m_right = this;
		}
}

template<typename T>
RedBlackNode<T>& RedBlackNode<T>::operator=(const RedBlackNode<T> &copy)
{
	this->m_color = n2->m_color;
	this->m_left = n2->m_left;
	this->m_right = n2->m_right;
	this->m_parent = n2->m_parent;
	this->m_key = n2->m_key;
	return *this;
}

template<typename T>
bool operator==(RedBlackNode<T> n1, RedBlackNode<T> n2);


#endif
