#include <iostream>

using namespace std;


//create parent class
class BaseTree
{
public:
	virtual void draw() {};
};


class Tree1 :public BaseTree
{
public:
	void draw()
	{
		cout << " /\\\n";
		cout << "//\\\\\n";
	}
};

class Tree2 :public BaseTree
{
public:
	void draw()
	{
		cout << " /\\\n";
		cout << "/**\\\n";
	}
};

class Tree3 :public BaseTree
{
public:
	void draw()
	{
		cout << " /\\\n";
		cout << "/++\\\n";
	}
};

int main()
{
	BaseTree *trees[3];
	
	Tree1 tree1;
	Tree2 tree2;
	Tree3 tree3;
	trees[0] = &tree1;
	trees[1] = &tree2;
	trees[2] = &tree3;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i + 1 << ": \n";
		trees[i]->draw();
	}
	return 0;
}