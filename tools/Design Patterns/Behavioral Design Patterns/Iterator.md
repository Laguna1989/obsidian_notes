---
tags:
  - design-patterns
links: "[[Behavioral Design Patterns]]"
---
# Overview

> [!quote] How traversal of data structure happens and who makes it happen

> [!quote] An object that facilitates the traversal of a particular data structure

- Iterator (traversal) is a core functionality of various data structures
- An *iterator* is a class that facilitates the traversal
	- Keeps a reference to the current element
	- Knows how to move to a different element
- Can be used implcitly
	- range-based for
	- [[C++ Coroutines]]

# Iterators in the C++ Standard Library

## Create Iterators

How do iterators work in the stl?

```cpp
std::vector<std::string> names {"john", "jane", "jill", "jack"};

std::vector<std::string>::iterator it = names.begin();
//alternative
std::vector<std::string>::iterator it = std::begin(names);

```

> [!check] Benefit of global `std::begin()`
> Also works for arrays (which do not have a `.begin()` function).

## Accessing Iterators

> [!hint] A iterator behaves like a pointer

```cpp
std::cout << *it << std::endl;
```

## Follow Iterators

```cpp
++it; // it points to "jane" now
```

## Modify Elements via Iterators

```cpp
it->append(std::string{" goodall"});
```

> [!warning] Modification is only possible because `it` is not a `const_iterator`

## Print All Elements

```cpp
while(++it != names.end())
{
	std::cout << *it << std::endl;
}
```

> [!note] `.end()` points to one after the last element

## Reverse order

> [!warning] Not possible for all stl containers (e.g. for singly linked lists)

```cpp
for(auto ri = std::rbegin(names); ri != rend(names); ++ri)
{
	std::cout << *ri << std::endl;
}
```

> [!note] `.rend()` points to one befor the first element

> [!note] `ri++` advances the iterator

## Range Based for Loop

```cpp
for(auto&& name : names)
	std::cout << "name: " << name << std::endl;
```

> [!note] This uses iterators internaly by calling `std::begin()` and `std::end()` for the container

# Binary Tree Iterator

How to implement a fully fledged Iterator

## Building a [[Binary Tree]]

Start by defining a node of a binary tree

```cpp
// fwd declaration
template <typename T> struct BinaryTree;


template <typename T>
struct Node
{
	T value = T();
	Node<T>* left{nullptr};
	Node<T>* right{nullptr};
	Node<T>* parent{nullptr};
	BinaryTree<T>* tree{nullptr};

	// constructors
	Node(T value) : value{value} {}
	Node(T value, Node<T>* left, Node<T>* right) : value{value}, left{left}, right{right} 
	{
		this->left->tree = this->right->tree = tree;
		this->left->parent = this->right->parent = this;
		
	}

	// setting the tree ptr
	void set_tree(BinaryTree<T>* t)
	{
		tree = t;
		if(left) left->set_tree(t);
		if(right) right->set_tree(t);
	}

	// destructor assumes that the node owns the children
	~Node()
	{
		if(left) delete left;
		if(right) delete right;
	}
};
```

Continue with `BinaryTree`

```cpp
template <typename T> BinaryTree
{
	Node<T>* root{nullptr};

	BinaryTree(Node<T>* root) : root{root}
	{
		root->set_tree(this);
	}

	~BinaryTree() 
	{
		if(root) delete root;
	}
};
```

## Iterator

> [!hint] This is a *preorder* iterator

Now we can build the iterator
> [!note] This goes inside the `BinaryTree` class

```cpp
template <typename T>
struct BinaryTree
{
	// stuff from above
	
	template <typename U> struct PreorderIterator
	{
		Node<U>* current;
		PreorderIterator(Node<U>* current) : current{current} {}
		
		bool operator!=(PreorderIterator<U> const& other)
		{
			return current != other.current;
		}
		
		// complicated piece of code, but works
		PreorderIterator<U>& operator++()
		{
			if(current->right)
			{
				current = current->right;
				while(current->left)
					current = current.left;
			}
			else
			{
				Node<T>* p = current->parent;
				while(p && current == p->right)
				{
					current = p;
					p = p->parent;
				}
				current = p;
			}
			return *this;
		}
		
		Node<U>& operator*()
		{
			return *current;
		}
	}; // PreorderIterator

	typedef PreorderIterator<T> iterator;
	
	// start at the leftmost element
	iterator begin()
	{
		Node<T>* n = root;
		if(n)
			while(n->left)
				n = n->left;
		return iterator{n};
	}
	
	// there is no "one-after" in a tree
	iterator end()
	{
		return iterator{nullptr};
	}
};
```

## Iterate a Family Tree

```cpp
int main()
{
//            me
//           /  \
//     mother   father
//    /      \
// m'm       m'f  
	BinaryTree<std::string> family{
		new Node<std::string>{"me"
			new Node<std::string>{"mother",
				new Node<std::string>{"mother's mother"},
				new Node<std::string>{"mother's father}
			new Node<std::string>{"father"}
		}
	};

	for(auto it = family.begin(); it != family.end(); ++it)
	{
		std::Cout << (*it).value << "\n";
	}
}
```

> [!hint] If we want a different iterator type, define it as another inner class of `BinaryTree`

# Tree Iterator with [[C++ Coroutines]]
