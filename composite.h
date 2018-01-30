#ifndef COMPOSITE_H
#define COMPOSITE_H
/*
*	组合模式
*/
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;
namespace composite
{


class Graphic
{
public:
	Graphic(){ };
	virtual ~Graphic(){ };
	virtual void Draw() = 0;
	virtual void Add(Graphic* graphic)
	{

	};
	virtual void Remove(Graphic* graphic)
	{

	}
	virtual Graphic* GetChild(int idx)
	{
		return NULL;
	}
};

class Line : public Graphic
{
public:
	Line()
	{

	}
	virtual ~Line()
	{

	}
	void Draw()
	{
		cout << "Line Draw ..." << endl;
	}
};

class Text :public Graphic
{
public:
	Text()
	{

	}
	~Text()
	{

	}
	void Draw()
	{
		cout << "Text Draw ..." << endl;
	}
};

class Picture :public Graphic
{
public:
	Picture(){};
	~Picture()
	{
		vector<Graphic*>::iterator iter = graphics_.begin();
		for (; iter != graphics_.end(); ++iter)
		{
			if ((*iter) != NULL)
			{
				delete *iter;
			}
		}
	};
	void Draw()
	{
		vector<Graphic*>::iterator iter = graphics_.begin();
		for (; iter != graphics_.end(); ++iter)
		{
			(*iter)->Draw();
		}
	}
	void Add(Graphic* graphic)
	{
		graphics_.push_back(graphic);
	}
	void Remove(Graphic* graphic)
	{
		
		vector<Graphic*>::iterator iter = std::find(graphics_.begin(), graphics_.end(), graphic);
		if (iter != graphics_.end())
		{
			graphics_.erase(iter);
		}
	}
	Graphic* GetChild(int idx)
	{
		return graphics_[idx];
	}
private:
	vector<Graphic*> graphics_;
};
void test_composite()
{
	Picture* picture = new Picture();
	picture->Add(new Text());
	picture->Add(new Line());
	picture->Add(new Line());
	picture->Add(new Text());
	picture->Draw();
	delete picture;
}

}
#endif