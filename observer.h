#include <list>

class Subject;

class Observer
{
public:
	virtual ~Observer();
	virtual void Update(Subject* change_subject) = 0;
protected:
	Observer();
}

class Subject
{
public:
	virtual ~Subject();
	virtual void Attach(Observer* ob);
	virtual void Detach(Observer* ob);
	virtual void Notify();
protected:
	Subject();
private:
	std::list<Observer*> observers_;
};

void Subject::Attach(Observer* ob)
{
	observers_.push_back(ob);
}

void Subject::Detach(Observer* ob)
{
	observers_.remove(ob);
}

void Subject::Notify()
{
	std::list<Observer*>::iterator iter = observers_.begin();
	for (; iter != observers_.end(); ++iter)
	{
		(*iter)->Update(this);
	}
}

/*
	������ClockTimerΪ����˵���۲���ģʽ��ʹ��
*/
class ClockTimer : public Subject
{
public:
	ClockTimer();
	virtual int GetHour();
	virtual int GetMinute();
	virtual int GetSecond();
	void Tick();
};

void ClockTimer::Tick()
{
	//ʱ��任 ����ʱ�� 
	Notify();
}

class DigitClock : public Observer
{
public:
	DigitClock(ClockTimer* timer);
	virtual ~DigitClock();
	//����update
	void Update(Subject* change_subject);
private:
	ClockTimer* timer_;
};

DigitClock::DigitClock(ClockTimer* timer)
{
	timer_ = timer;
	timer_->Attach(this);
}

DigitClock::~DigitClock()
{
	timer_->Detach(this);
}

void DigitClock::Update(Subject* change_subject)
{
	if (change_subject == timer_)
	{
		//ʱ��仯 Draw();
	}
}





