#pragma once
#include <iostream>

template <class T>
struct Node
{
	T value;
	Node<T>* parent = nullptr;
	Node<T>* leftChild = nullptr;
	Node<T>* rightChild = nullptr;
};

template <class T>
class BinaryTree
{
	Node<T>* root;
	int size;

	void AddInside(T value, Node<T>*& nodeTop)
	{
		if (!nodeTop)
		{
			Node<T>* nodeNew = new Node<T>;
			nodeNew->value = value;
			nodeNew->parent = nodeTop;
			nodeTop = nodeNew;
		}
		else
		{
			if (value < nodeTop->value)
				AddInside(value, nodeTop->leftChild);
			else
				AddInside(value, nodeTop->rightChild);
		}
	}
public:
	BinaryTree() : root{ nullptr }, size{ 0 }{}
	
	void AddLoop(T value)
	{
		Node<T>* current{ root };
		Node<T>* nodeParent{ nullptr };

		while (current)
		{
			nodeParent = current;
			if (value <= current->value)
				current = current->leftChild;
			else
				current = current->rightChild;
		}

		Node<T>* nodeNew = new Node<T>;
		nodeNew->value = value;
		nodeNew->parent = nodeParent;

		if (!nodeParent)
		{
			root = nodeNew;
		}
		else
		{
			if (nodeNew->value <= nodeParent->value)
				nodeParent->leftChild = nodeNew;
			else
				nodeParent->rightChild = nodeNew;
		}
	}

	void AddReq(T value)
	{
		AddInside(value, root);
	}

	void PrintReq(Node<T>* nodeTop)
	{
		if (nodeTop)
		{
			PrintReq(nodeTop->leftChild);
			std::cout << nodeTop->value << " ";
			PrintReq(nodeTop->rightChild);
		}
	}

	void Print()
	{
		PrintReq(root);
	}

	Node<T>*& Search(T value)
	{
		Node<T>* current{ root };
		while (current)
		{
			if (current->value == value)
				break;
			if (value < current->value)
				current = current->leftChild;
			else
				current = current->rightChild;
		}

		return current;
	}

	Node<T>*& Min(Node<T>* nodeRoot)
	{
		if (!nodeRoot->leftChild)
			return nodeRoot;
		else
			Min(nodeRoot->leftChild);
	}

	Node<T>*& MinTree()
	{
		return Min(root);
	}

	Node<T>*& Max(Node<T>* nodeRoot)
	{
		if (!nodeRoot->rightChild)
			return nodeRoot;
		else
			Max(nodeRoot->rightChild);
	}

	Node<T>*& MaxTree()
	{
		return Max(root);
	}

	void Delete(Node<T>* nodeDel)
	{
		if (!nodeDel->leftChild && !nodeDel->rightChild)
		{
			if (nodeDel == nodeDel->parent->leftChild)
				nodeDel->parent->leftChild = nullptr;
			else
				nodeDel->parent->rightChild = nullptr;
			/*if(nodeDel->value <= nodeDel->parent->value)
				nodeDel->parent->leftChild = nullptr;
			else
				nodeDel->parent->rightChild = nullptr;*/
			delete nodeDel;
			return;
		}
		if ((nodeDel->leftChild && !nodeDel->rightChild) || (!nodeDel->leftChild && nodeDel->rightChild))
		{
			Node<T>* child;
			if (nodeDel->leftChild)
				child = nodeDel->leftChild;
			else
				child = nodeDel->rightChild;
			if (nodeDel == nodeDel->parent->leftChild)
				nodeDel->parent->leftChild = child;
			else
				nodeDel->parent->rightChild = child;
			delete nodeDel;
			return;
		}
	}
};

