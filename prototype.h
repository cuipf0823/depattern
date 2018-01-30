#ifndef PROTOTYPE_H
#define PROTOTYPE_H
/*
*	 原型模式
*/
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Graphic
{
public:
	Graphic(){};
	virtual ~Graphic(){};
	virtual void Draw() = 0;
	virtual Graphic* Clone() = 0;
};

//五线谱
class Staff : public Graphic
{
public:
	Staff(){};
	~Staff(){};
	Staff(const Staff& rhs)
	{

	}
	virtual void Draw()
	{
		cout << "Staff Draw ..." << endl;
	}
	virtual Graphic* Clone()
	{
		return new Staff(*this);
	}
};

//音符
class MusicalNote : public Graphic
{
public:
	MusicalNote(){};
	~MusicalNote(){};
	MusicalNote(const MusicalNote& note)
	{

	}
	virtual void Draw()
	{
		cout << "Musical Note Draw ..." << endl;
	}
	virtual Graphic* Clone()
	{
		return new MusicalNote(*this);
	}
};

void test_prototype()
{
	Graphic* graphic = new MusicalNote();
	Graphic* graphic1 = graphic->Clone();
	graphic->Draw();
	delete graphic;
	delete graphic1;

}

//接上面 添加原型管理器的使用
class GraphicManager
{
public:
	GraphicManager(){};
	void add(Graphic* graphic)
	{
		graphics_.push_back(graphic);
	}
	Graphic* get(int idx)
	{
		assert(idx < graphics_.size() && idx >= 0);
		return graphics_[idx];
	}
private:
	vector<Graphic*> graphics_;
};

void test_prototype_manager()
{
	GraphicManager* manager = new GraphicManager();
	Graphic* graphicA = new Staff();
	manager->add(graphicA);
	Graphic* graphicB = new MusicalNote();
	manager->add(graphicB);
	manager->get(0)->Draw();
	Graphic* graphicC = manager->get(1)->Clone();
	graphicC->Draw();
	delete graphicA;
	delete graphicB;
	delete graphicC;
	delete manager;
}
#endif