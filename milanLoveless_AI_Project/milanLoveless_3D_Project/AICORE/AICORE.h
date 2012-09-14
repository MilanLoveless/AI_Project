#pragma once
#include <stdlib.h>
#include <math.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////////////////////

class ZObject
{
public:
	int GetHP();
	void SetHP(int hpMod);
	void SetPos(int xx, int yy);
	virtual void Initialize(int w, int h);
	virtual void Draw(int* video, int w, int h) = 0;
	int HP;
	int D;
	int x;
	int y;
	virtual void RunAI();
	virtual void AssessFTarget(ZObject* Tar);
	virtual void AssessWTarget(ZObject* Tar);
	virtual void AssessETarget(ZObject* Tar);
	virtual void AssessTTarget(ZObject* Tar);
};

////////////////////////////////////////////////////////////////////////////////////////////////

class Food : public ZObject
{
public:
	Food(int w, int h, int x, int y);
	void Initialize(int w, int h);
	void Draw(int* video, int w, int h);
};

////////////////////////////////////////////////////////////////////////////////////////////////

class Water : public ZObject
{
public:
	Water(int w, int h, int x, int y);
	void Initialize(int w, int h);
	void Draw(int* video, int w, int h);
};

////////////////////////////////////////////////////////////////////////////////////////////////

class Attribute3F
{
public:
	Attribute3F();
	void Initialize(float Cur, float Max, float Min);
	float IsItMax();
	float IsItEqual();
	float IsItMin();
	float fCurrent;
	float fMaximum;
	float fMinimum;
};

////////////////////////////////////////////////////////////////////////////////////////////////

class ZAction
{
public:
	ZAction();
	~ZAction();
	void SetAttributes(Attribute3F* AttrA, int AttrR);
	void SetTarget(ZObject* Tar);
	float ZPctComplete();
	virtual void RunBehavior();
	ZObject* Target;
	int AttrRates;
	Attribute3F* Attribute;
};
////////////////////////////////////////////////////////////////////////////////////////////////

class ZMatrix2Attr
{
public:
	void SetAttrs(Attribute3F* Attr1, Attribute3F* Attr2);
	void SetCo(float Co1, float Co2, float Co3, float Co4);
	float Contemplate();
	void ErrorCorrection(float ZError, float Attr1, float Attr2);
	Attribute3F* Attribute1;
	Attribute3F* Attribute2;
	float Coefficient1;
	float Coefficient2;
	float Coefficient3;
	float Coefficient4;
};

////////////////////////////////////////////////////////////////////////////////////////////////

class ZMatrix3Attr
{
public:
	void SetAttrs(Attribute3F* Attr1, Attribute3F* Attr2, Attribute3F* Attr3);
	void SetCo(float Co1, float Co2, float Co3, float Co4, float Co5, float Co6, float Co7, float Co8);
	float Contemplate();
	void ErrorCorrection(float ZError, float Attr1, float Attr2, float Attr3);
	Attribute3F* Attribute1;
	Attribute3F* Attribute2;
	Attribute3F* Attribute3;
	float Coefficient1;
	float Coefficient2;
	float Coefficient3;
	float Coefficient4;
	float Coefficient5;
	float Coefficient6;
	float Coefficient7;
	float Coefficient8;
};

////////////////////////////////////////////////////////////////////////////////////////////////

class Creature : public ZObject
{
public:
	Creature(int w, int h, int x, int y);
	~Creature();
	void Initialize(int w, int h);
	void Upkeep();
	void Contemplate();
	void Draw(int* video, int w, int h);
	void RunAI();
	void AssessFTarget(ZObject* Tar);
	void AssessWTarget(ZObject* Tar);
	void AssessETarget(ZObject* Tar);
	void AssessTTarget(ZObject* Tar);
	Attribute3F Busy;
	Attribute3F Food;
	Attribute3F Water;
	Attribute3F Boredom;
	Attribute3F CDistance;
	Attribute3F FDistance;
	Attribute3F WDistance;
	Attribute3F TDistance;
	Attribute3F EDistance;
	Attribute3F MyHP;
	Attribute3F EHP;
	//ZAction* Occupation;
	ZAction Eating;
	ZAction Drinking;
	ZAction Moving;
	ZAction Playing;
	ZAction RunAway;
	ZAction Hunting;
	ZMatrix2Attr ZConsume;
	ZMatrix2Attr ZEat;
	ZMatrix2Attr ZDrink;
	ZMatrix2Attr ZBored;
	ZMatrix3Attr ZHunt;
	ZMatrix3Attr ZDanger;
};
