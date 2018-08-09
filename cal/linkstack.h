#pragma once
template<class T>
class  LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void push(T data);//入栈
	void pop(void);  //出栈
	T top(void);
	bool isEmpty(void);
	void clear(void);
	int size(void);

private:
	int NodeNum;
	struct Node  //栈的节点
	{
		T data;
		struct Node *next;
	};
	struct Node *pTop;//栈顶
};
template<class T>
LinkStack<T>::LinkStack()
{
	this->NodeNum = 0;
	this->pTop = NULL;
}
template<class T>
LinkStack<T>::~LinkStack()
{
	this->clear();
}

template<class T>
int LinkStack<T>::size(void)
{
	return NodeNum;
}
template<class T>
bool LinkStack<T>::isEmpty(void)
{
	return pTop == NULL;
}
template<class T>
void LinkStack<T>::clear(void)
{
	struct Node *pTmp;
	while (pTop != NULL)
	{
		pTmp = pTop;
		pTop = pTop->next;
		delete pTmp; //释放内存
	}
	NodeNum = 0;
	pTop = NULL;
}
template<class T>
void LinkStack<T>::push(T data)
{
	struct Node *node = new Node;
	node->data = data;
	node->next = NULL;
	if (pTop == NULL)
	{
		pTop = node;
	}
	else
	{
		node->next = pTop;
		pTop = node;
	}
	NodeNum++;
}

template<class T>
void LinkStack<T>::pop(void)
{
	struct Node *pTmp;
	if (pTop == NULL)
	{
		return;
	}
	else
	{
		pTmp = pTop;
		pTop = pTop->next;
		delete pTmp; //释放内存
		NodeNum--;
	}
}

template<class T>
T LinkStack<T>::top(void)
{
	if (NodeNum == 0)
		return T();
	else
		return pTop->data;
}