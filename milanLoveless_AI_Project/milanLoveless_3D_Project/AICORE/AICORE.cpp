#include "AICORE.h"
#include "..\\GameCore.h"

#define UPKEEP 1

////////////////////////////////////////////////////////////////////////////////////////////////

int ZObject::GetHP()
	{
		return this->HP;
	}

void ZObject::Initialize(int w, int h)
{
	srand(time(NULL));
	this->D = 10;
	int ww = ((int)rand % w) - (2 * this->D);
	if(ww < this->D) ww = this->D;
	int hh = ((int)rand % h) - (2 * this->D);
	if(hh < this->D) hh = this->D;
	this->SetPos(ww, hh);
	this->SetHP(100);
}

void ZObject::SetHP(int hpMod)
{
	this->HP += hpMod;
}

void ZObject::SetPos(int xx, int yy)
{
	if(xx > (800 - this->D  * 2)) x = 800 - this->D * 2;
	if(xx < (50 + this->D * 2)) x = 0 + this->D * 2;
	if(yy > (600 - this->D * 2)) y = 600 - this->D * 2;
	if(yy < (50 + this->D * 2)) y = 0 + this->D * 2;
	this->x = xx;
	this->y = yy;
}

void ZObject::AssessFTarget(ZObject* Tar)
{
	return;
}

void ZObject::AssessWTarget(ZObject* Tar)
{
	return;
}

void ZObject::AssessETarget(ZObject* Tar)
{
	return;
}

void ZObject::AssessTTarget(ZObject* Tar)
{
	return;
}

void ZObject::RunAI()
{
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////

Food::Food(int w, int h, int x, int y)
{
	this->SetHP(100);
	this->D = 10;
	if(x > w-this->D) x = w-this->D;
	if(x < 0 + this->D) x = 0 + this->D;
	if(y > h-this->D) y = h-this->D;
	if(y < 0 + this->D) y = 0 + this->D;
	this->SetPos(x, y);
}

void Food::Initialize(int w, int h)
{
	srand(time(NULL));
	this->D = 10;
	int ww = ((int)rand % w) - (2 * this->D);
	if(ww < this->D) ww = this->D;
	int hh = ((int)rand % h) - (2 * this->D);
	if(hh < this->D) hh = this->D;
	this->SetPos(ww, hh);
	this->SetHP(100);
}

void Food::Draw(int* video, int w, int h)
{
	for(int x = this->x; x < this->x + this->D; x++)
	{
		for(int y = this->y; y < this->y + this->D; y++)
		{
			video[y * w + x ] = 0xFFFF0000;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////

Water::Water(int w, int h, int x, int y)
{
	this->SetHP(100);
	this->D = 10;
	if(x > w-this->D) x = w-this->D;
	if(x < 0 + this->D) x = 0 + this->D;
	if(y > h-this->D) y = h-this->D;
	if(y < 0 + this->D) y = 0 + this->D;
	this->SetPos(x, y);
}

void Water::Initialize(int w, int h)
{
	srand(time(NULL));
	this->D = 10;
	int ww = ((int)rand() % w) - (2 * this->D);
	if(ww < this->D) ww = this->D;
	int hh = ((int)rand() % h) - (2 * this->D);
	if(hh < this->D) hh = this->D;
	this->SetPos(ww, hh);
	this->SetHP(100);
}

void Water::Draw(int* video, int w, int h)
{
	for(int x = this->x; x < this->x + this->D; x++)
	{
		for(int y = this->y; y < this->y + this->D; y++)
		{
			video[y * w + x ] = 0xFF0000FF;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////

Attribute3F::Attribute3F()
{
	this->Initialize(50, 100, 0);
}
void Attribute3F::Initialize(float Cur, float Max, float Min)
{
	this->fCurrent = Cur;
	this->fMaximum = Max;
	this->fMinimum = Min;
}

float Attribute3F::IsItMax()
{
	return (1.0 - (this->fMaximum - this->fCurrent) / (this->fMaximum - this->fMinimum));
}

float Attribute3F::IsItEqual()
{
	return 1.0;
}

float Attribute3F::IsItMin()
{
	return (1.0 - (this->fMinimum - this->fCurrent) / (this->fMinimum - this->fMaximum));
}

////////////////////////////////////////////////////////////////////////////////////////////////

ZAction::ZAction()
{
	Attribute = NULL;
	AttrRates = NULL;
	Target = NULL;
}

ZAction::~ZAction()
{
	this->Attribute = NULL;
	this->AttrRates = NULL;
	this->Target = NULL;
}

void ZAction::SetAttributes(Attribute3F* AttrA, int AttrR)
{
	Attribute = AttrA;
	AttrRates = AttrR;
}

void ZAction::SetTarget(ZObject* Tar)
{
	Target = Tar;
}

float ZAction::ZPctComplete()
{
	float ZV = this->Attribute->IsItMax();
	if(ZV < 0.0) ZV = 0.0;
	if(ZV > 1.0) ZV = 1.0;
	return ZV;
}

void ZAction::RunBehavior()
{
	this->Attribute->fCurrent += this->AttrRates;
	if(this->Attribute->fCurrent > this->Attribute->fMaximum) this->Attribute->fCurrent = this->Attribute->fMaximum;
	if(this->Attribute->fCurrent < this->Attribute->fMinimum) this->Attribute->fCurrent = this->Attribute->fMinimum;
	int IsItDead = this->Target->HP - AttrRates;
	this->Target->SetHP(-1*this->AttrRates);
	if(IsItDead <= 0)
	{
		this->Target->Initialize(800, 600);
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////

Creature::Creature(int w, int h, int x, int y)
{
	this->HP = 1000; // Public Hit Points
	this->D = 20; // Diameter
	if(x > w-this->D) x = w-this->D;
	if(x < 0 + this->D) x = 0 + this->D;
	if(y > h-this->D) y = h-this->D;
	if(y < 0 + this->D) y = 0 + this->D;
	this->SetPos(x, y);

	// Initialize Attributes /////////////////////////////////////////////////////////
	this->Busy.Initialize(0.0, 100.0, 0.0);
	this->Food.Initialize((int)rand%100, 100.0, 0.0); // Random Starting Hunger Levels
	this->Water.Initialize((int)rand%100, 100.0, 0.0); // Random Starting Thirst Levels
	this->Boredom.Initialize(this->Water.IsItMin()*this->Food.IsItMin()*100, 100.0, 0.0); // Boredom is the NOT of Hunger AND Thirst
	this->CDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current target
	this->FDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current food target
	this->WDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current water target
	this->TDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current toy target
	this->EDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current default enemy
	this->MyHP.Initialize(1000.0, 1000.0, 0.0);
	this->EHP.Initialize(0.0, 1000.0, 0.0);
	
	//this->Occupation = NULL;

	// Assign Attributes to coresponding Actions //////////////////////////////////////////
	this->Eating.SetAttributes(&this->Food, 20);  // Attach Eating action to Food attribute
	this->Drinking.SetAttributes(&this->Water, 20); // Attach Drinking action to Water attribute
	this->Playing.SetAttributes(&this->Boredom, 0); // Attach Playing to Boredom attribute - it keeps playing unless it is hungry or thirsty
	this->Moving.SetAttributes(&this->CDistance, 5); // Attach the Move action to the Target Distance attribute
	this->RunAway.SetAttributes(&this->EDistance, 5); // Attach the Run Away action to the Enemy Distance attribute
	this->Hunting.SetAttributes(&this->EDistance, 5);
	
	// Initialize Behavior Matricies
	this->ZConsume.SetAttrs(&this->Food, &this->Water); // Consume Attributes
	this->ZConsume.SetCo(1.0, 0.5, 0.5, 0.0); // Consume Coefficients

	this->ZConsume.SetAttrs(&this->Food, &this->Water);
	this->ZConsume.SetCo(1.0, 0.5, 0.5, 0.0);
	
	this->ZEat.SetAttrs(&this->Food, &this->FDistance);
	this->ZEat.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZDrink.SetAttrs(&this->Water, &this->WDistance);
	this->ZDrink.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZBored.SetAttrs(&this->Boredom, &this->TDistance);
	this->ZBored.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZHunt.SetAttrs(&this->MyHP, &this->EHP, &this->EDistance);
	this->ZHunt.SetCo(1.0, 0.5, 0.5, 0.0, 1.0, 0.5, 0.5, 0.0);

	this->ZDanger.SetAttrs(&this->MyHP, &this->EHP, &this->EDistance);
	this->ZDanger.SetCo(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
}

Creature::~Creature()
{
	
}

void Creature::Initialize(int w, int h)
{
	this->HP = 1000; // Public Hit Points
	this->D = 20; // Diameter

	// Randomize Position /////////////////
	srand(time(NULL));

	int x = ((int)rand()%w) - (2 * this->D); // X Position
	if(x < 50 + this->D) x = 50 + this->D;

	int y = ((int)rand()%h) - (2 * this->D); // Y Position
	if(y < 50 + this->D) y = 50 + this->D;

	this->SetPos(x, y); // Assignment

	// Initialize Attributes /////////////////////////////////////////////////////////
	this->Busy.Initialize(0.0, 100.0, 0.0);
	this->Food.Initialize((int)rand()%100, 100.0, 0.0); // Random Starting Hunger Levels
	this->Water.Initialize((int)rand()%100, 100.0, 0.0); // Random Starting Thirst Levels
	this->Boredom.Initialize(this->Water.IsItMin()*this->Food.IsItMin()*100, 100.0, 0.0); // Boredom is the NOT of Hunger AND Thirst
	this->CDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current target
	this->FDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current food target
	this->WDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current water target
	this->TDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current toy target
	this->EDistance.Initialize(1000.0, 1000.0, 0.0); // Distance to current default enemy
	this->MyHP.Initialize(1000.0, 1000.0, 0.0);
	this->EHP.Initialize(0.0, 100.0, 0.0);
	
	//this->Occupation = NULL;

	// Assign Attributes to coresponding Actions //////////////////////////////////////////
	this->Eating.SetAttributes(&this->Food, 20);  // Attach Eating action to Food attribute
	this->Drinking.SetAttributes(&this->Water, 20); // Attach Drinking action to Water attribute
	this->Playing.SetAttributes(&this->Boredom, 0); // Attach Playing to Boredom attribute - it keeps playing unless it is hungry or thirsty
	this->Moving.SetAttributes(&this->CDistance, 5); // Attach the Move action to the Target Distance attribute
	this->RunAway.SetAttributes(&this->EDistance, 5); // Attach the Run Away action to the Enemy Distance attribute
	this->Hunting.SetAttributes(&this->EDistance, 5);
	
	// Initialize Behavior Matricies
	this->ZConsume.SetAttrs(&this->Food, &this->Water); // Consume Attributes
	this->ZConsume.SetCo(1.0, 0.5, 0.5, 0.0); // Consume Coefficients

	this->ZConsume.SetAttrs(&this->Food, &this->Water);
	this->ZConsume.SetCo(1.0, 0.5, 0.5, 0.0);
	
	this->ZEat.SetAttrs(&this->Food, &this->FDistance);
	this->ZEat.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZDrink.SetAttrs(&this->Water, &this->WDistance);
	this->ZDrink.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZBored.SetAttrs(&this->Boredom, &this->TDistance);
	this->ZBored.SetCo(1.0, 0.5, 0.5, 0.0);

	this->ZHunt.SetAttrs(&this->MyHP, &this->EHP, &this->EDistance);
	this->ZHunt.SetCo(1.0, 0.5, 0.5, 0.0, 1.0, 0.5, 0.5, 0.0);

	this->ZDanger.SetAttrs(&this->MyHP, &this->EHP, &this->EDistance);
	this->ZDanger.SetCo(1.0, 0.5, 0.5, 0.0, 1.0, 0.5, 0.5, 0.0);
}

void Creature::AssessFTarget(ZObject* Tar)
{
	if(this->Eating.Target != NULL) this->FDistance.fCurrent = sqrt(pow((this->x - this->Eating.Target->x), 2.0) + pow((this->y - this->Eating.Target->y), 2.0));
	float CurDist = sqrt(pow((this->x - Tar->x), 2.0) + pow((this->y - Tar->y), 2.0));
	if(this->FDistance.fCurrent > CurDist && CurDist != 0.0)
	{
		this->Eating.Target = Tar;
		this->FDistance.fCurrent = CurDist;
	}
}

void Creature::AssessWTarget(ZObject* Tar)
{
	if(this->Drinking.Target != NULL) this->WDistance.fCurrent = sqrt(pow((this->x - this->Drinking.Target->x), 2.0) + pow((this->y - this->Drinking.Target->y), 2.0));
	float CurDist = sqrt(pow((this->x - Tar->x), 2.0) + pow((this->y - Tar->y), 2.0));
	if(this->WDistance.fCurrent > CurDist && CurDist != 0.0)
	{
		this->Drinking.Target = Tar;
		this->WDistance.fCurrent = CurDist;
	}
}

void Creature::AssessETarget(ZObject* Tar)
{
	if(this->RunAway.Target != NULL) this->EDistance.fCurrent = sqrt(pow((this->x - this->RunAway.Target->x), 2.0) + pow((this->y - this->RunAway.Target->y), 2.0));
	float CurDist = sqrt(pow((this->x - Tar->x), 2.0) + pow((this->y - Tar->y), 2.0));
	if(this->EDistance.fCurrent > CurDist && CurDist != 0.0)
	{
		this->RunAway.SetTarget(Tar);
		this->Hunting.SetTarget(Tar);
		this->EDistance.fCurrent = CurDist;
	}
}

void Creature::AssessTTarget(ZObject* Tar)
{
	float CurDist = sqrt(pow((this->x - Tar->x), 2.0) + pow((this->y - Tar->y), 2.0));
	if(this->TDistance.fCurrent > CurDist && CurDist != 0.0)
	{
		this->Playing.Target = Tar;
		this->TDistance.fCurrent = CurDist;
	}
}

void Creature::Upkeep()
{
	this->MyHP.fCurrent = this->HP;
	this->Food.fCurrent -= UPKEEP;
	if(this->Food.fCurrent <= 0)
	{
		this->HP -= UPKEEP;
		this->MyHP.fCurrent = this->HP;
		this->ZEat.ErrorCorrection(this->MyHP.IsItMin(), this->ZEat.Attribute1->fCurrent, this->ZEat.Attribute2->fCurrent);
		this->Food.fCurrent = 0;
		//if(this->HP <= 0) this->Initialize(800, 600);
	}
	this->Water.fCurrent -= UPKEEP;
	if(this->Water.fCurrent <= 0)
	{
		this->HP -= UPKEEP;
		this->MyHP.fCurrent = this->HP;
		this->ZDrink.ErrorCorrection(this->MyHP.IsItMin(), this->ZDrink.Attribute1->fCurrent, this->ZDrink.Attribute2->fCurrent);
		this->Water.fCurrent = 0;
		//if(this->HP <= 0) this->Initialize(800, 600);
	}
	this->Boredom.fCurrent = this->Water.IsItMax()*this->Food.IsItMax()*100;
	//if(this->Moving.Target != NULL && this->CDistance.fCurrent > 0)
	//{
	//	float deltaX = this->Moving.Target->x - this->x;
	//	float deltaY = this->Moving.Target->y - this->y;
	//	float Magnitude = sqrt(pow((double)deltaX, 2.0) + pow((double)deltaY, 2.0));
	//	this->SetPos((this->x + (int)(deltaX/Magnitude)*this->Moving.AttrRates), this->y + (int)((deltaY/Magnitude)*this->Moving.AttrRates));
	//}
	//else this->Moving.Target = NULL;
}

void Creature::Contemplate()
{
	//if(this->Occupation->Target != NULL)
	//{
	//	this->Busy.fCurrent = 100.0 - this->Occupation->Target->HP;
	//}
	srand(time(NULL));
	//float SPlay = this->ZBored.Contemplate();
	float SMagnitude = sqrt(pow((double)this->ZConsume.Contemplate(), 2.0) + pow((double)this->ZDanger.Contemplate(), 2.0));
	//float SMagnitude = sqrt(pow((double)SConsume, 2.0) + pow((double)SRun, 2.0) + pow((double)SPlay, 2.0));
	float SConsume = this->ZConsume.Contemplate()/SMagnitude;
	float SRun = this->ZDanger.Contemplate()/SMagnitude;
	int Suggestion1 = (int)rand()%10000;
	
	if(this->Eating.Target != NULL && this->Drinking.Target != NULL && this->RunAway.Target != NULL && this->Hunting.Target != NULL)
	{
		if(Suggestion1 < (int)(SRun*10000))
		{
			float XC = this->x - RunAway.Target->x;
			float YC = this->y - RunAway.Target->y;
			float CurDist = sqrt(pow((double)XC, 2.0) + pow((double)YC, 2.0));
			XC = (XC/CurDist)*this->RunAway.AttrRates;
			YC = (YC/CurDist)*this->RunAway.AttrRates;
			this->SetPos((this->x+(int)XC), (this->y+(int)YC));
		}
		else
		{
			float SFood = this->ZEat.Contemplate();
			float SWater = this->ZDrink.Contemplate();
			float SNorm = sqrt(pow((double)SFood, 2.0) + pow((double)SWater, 2.0));
			SFood /= SNorm;
			SWater /= SNorm;
			int Suggestion2 = (int)rand()%10000;
			if(Suggestion2 < (int)(SFood*10000))
			{
				if(this->FDistance.fCurrent < 20) this->Eating.RunBehavior();
				else
				{
					this->Moving.Target = this->Eating.Target;
					float XC = ((this->Moving.Target->x - this->x)/this->FDistance.fCurrent)*this->Moving.AttrRates;
					float YC = ((this->Moving.Target->y - this->y)/this->FDistance.fCurrent)*this->Moving.AttrRates;
					this->SetPos((this->x + (int)XC), (this->y + int(YC)));
				}
			}
			else
			{
				if(this->WDistance.fCurrent < 20) this->Drinking.RunBehavior();
				else
				{
					this->Moving.Target = this->Drinking.Target;
					float XC = ((this->Moving.Target->x - this->x)/this->FDistance.fCurrent)*this->Moving.AttrRates;
					float YC = ((this->Moving.Target->y - this->y)/this->FDistance.fCurrent)*this->Moving.AttrRates;
					this->SetPos((this->x + (int)XC), (this->y + int(YC)));
				}
			}
		}
	}
}

void Creature::RunAI()
{
	this->Upkeep();
	this->Contemplate();
}

void Creature::Draw(int* video, int w, int h)
{
	if(this->y < 0 || this->y > 579 || this->x < 0 || this->x > 779) this->SetPos(400,300);
	for(int x = this->x; x < this->x + this->D; x++)
	{
		for(int y = this->y; y < this->y + this->D; y++)
		{
			video[y * w + x ] = 0xFF00FF00;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////

void ZMatrix2Attr::SetAttrs(Attribute3F* Attr1, Attribute3F* Attr2)
{
	this->Attribute1 = Attr1;
	this->Attribute2 = Attr2;
}

void ZMatrix2Attr::SetCo(float Co1, float Co2, float Co3, float Co4)
{
	this->Coefficient1 = Co1;
	this->Coefficient2 = Co2;
	this->Coefficient3 = Co3;
	this->Coefficient4 = Co4;
}

float ZMatrix2Attr::Contemplate()
{
	float ZSuggestion = (1.0 - this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*this->Coefficient1 +	// 0 0
						(1.0 - this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*this->Coefficient2 +			// 0 1
						(this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*this->Coefficient3 +			// 1 0
						(this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*this->Coefficient4;					// 1 1
	if(ZSuggestion < 0.0) ZSuggestion = 0.0;
	if(ZSuggestion > 1.0) ZSuggestion = 1.0;
	return ZSuggestion;
}

void ZMatrix2Attr::ErrorCorrection(float ZError, float Attr1, float Attr2)
{
	float ZDistance1 = sqrt(pow((0.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0));
	float ZDistance2 = sqrt(pow((0.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0));
	float ZDistance3 = sqrt(pow((1.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0));
	float ZDistance4 = sqrt(pow((1.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0));
	
	this->Coefficient1 -= (1.0 - ZDistance1)*ZError;
	if(this->Coefficient1 > 1.0) this->Coefficient1 = 1.0;
	if(this->Coefficient1 < 0.0) this->Coefficient1 = 0.0;

	this->Coefficient2 -= (1.0 - ZDistance2)*ZError;
	if(this->Coefficient2 > 1.0) this->Coefficient2 = 1.0;
	if(this->Coefficient2 < 0.0) this->Coefficient2 = 0.0;

	this->Coefficient3 -= (1.0 - ZDistance3)*ZError;
	if(this->Coefficient3 > 1.0) this->Coefficient3 = 1.0;
	if(this->Coefficient3 < 0.0) this->Coefficient3 = 0.0;

	this->Coefficient4 -= (1.0 - ZDistance4)*ZError;
	if(this->Coefficient4 > 1.0) this->Coefficient4 = 1.0;
	if(this->Coefficient4 < 0.0) this->Coefficient4 = 0.0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void ZMatrix3Attr::SetAttrs(Attribute3F* Attr1, Attribute3F* Attr2, Attribute3F* Attr3)
{
	this->Attribute1 = Attr1;
	this->Attribute2 = Attr2;
	this->Attribute3 = Attr3;
}

void ZMatrix3Attr::SetCo(float Co1, float Co2, float Co3, float Co4, float Co5, float Co6, float Co7, float Co8)
{
	this->Coefficient1 = Co1;
	this->Coefficient2 = Co2;
	this->Coefficient3 = Co3;
	this->Coefficient4 = Co4;
	this->Coefficient5 = Co5;
	this->Coefficient6 = Co6;
	this->Coefficient7 = Co7;
	this->Coefficient8 = Co8;
}

float ZMatrix3Attr::Contemplate()
{
	float ZSuggestion = (1.0 - this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*(1.0 - this->Attribute3->IsItMax())*this->Coefficient1 +	// 0 0 0
						(1.0 - this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*(this->Attribute3->IsItMax())*this->Coefficient2 +			// 0 0 1
						(1.0 - this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*(1.0 - this->Attribute3->IsItMax())*this->Coefficient3 +			// 0 1 0
						(1.0 - this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*(this->Attribute3->IsItMax())*this->Coefficient4 +				// 0 1 1
						(this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*(1.0 - this->Attribute3->IsItMax())*this->Coefficient5 +			// 1 0 0
						(this->Attribute1->IsItMax())*(1.0 - this->Attribute2->IsItMax())*(this->Attribute3->IsItMax())*this->Coefficient6 +				// 1 0 1
						(this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*(1.0 - this->Attribute3->IsItMax())*this->Coefficient7 +				// 1 1 0
						(this->Attribute1->IsItMax())*(this->Attribute2->IsItMax())*(this->Attribute3->IsItMax())*this->Coefficient8;						// 1 1 1
	if(ZSuggestion < 0.0) ZSuggestion = 0.0;
	if(ZSuggestion > 1.0) ZSuggestion = 1.0;
	return ZSuggestion;
}

void ZMatrix3Attr::ErrorCorrection(float ZError, float Attr1, float Attr2, float Attr3)
{
	float ZDistance1 = sqrt(pow((0.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0) + pow((0.0 - Attr3), 2.0));
	float ZDistance2 = sqrt(pow((0.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0) + pow((1.0 - Attr3), 2.0));
	float ZDistance3 = sqrt(pow((0.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0) + pow((0.0 - Attr3), 2.0));
	float ZDistance4 = sqrt(pow((0.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0) + pow((1.0 - Attr3), 2.0));
	float ZDistance5 = sqrt(pow((1.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0) + pow((0.0 - Attr3), 2.0));
	float ZDistance6 = sqrt(pow((1.0 - Attr1), 2.0)+pow((0.0 - Attr2), 2.0) + pow((1.0 - Attr3), 2.0));
	float ZDistance7 = sqrt(pow((1.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0) + pow((0.0 - Attr3), 2.0));
	float ZDistance8 = sqrt(pow((1.0 - Attr1), 2.0)+pow((1.0 - Attr2), 2.0) + pow((1.0 - Attr3), 2.0));	

	this->Coefficient1 -= (1.0 - ZDistance1)*ZError;
	if(this->Coefficient1 > 1.0) this->Coefficient1 = 1.0;
	if(this->Coefficient1 < 0.0) this->Coefficient1 = 0.0;

	this->Coefficient2 -= (1.0 - ZDistance2)*ZError;
	if(this->Coefficient2 > 1.0) this->Coefficient2 = 1.0;
	if(this->Coefficient2 < 0.0) this->Coefficient2 = 0.0;

	this->Coefficient3 -= (1.0 - ZDistance3)*ZError;
	if(this->Coefficient3 > 1.0) this->Coefficient3 = 1.0;
	if(this->Coefficient3 < 0.0) this->Coefficient3 = 0.0;

	this->Coefficient4 -= (1.0 - ZDistance4)*ZError;
	if(this->Coefficient4 > 1.0) this->Coefficient4 = 1.0;
	if(this->Coefficient4 < 0.0) this->Coefficient4 = 0.0;
	
	this->Coefficient5 -= (1.0 - ZDistance5)*ZError;
	if(this->Coefficient5 > 1.0) this->Coefficient5 = 1.0;
	if(this->Coefficient5 < 0.0) this->Coefficient5 = 0.0;

	this->Coefficient6 -= (1.0 - ZDistance6)*ZError;
	if(this->Coefficient6 > 1.0) this->Coefficient6 = 1.0;
	if(this->Coefficient6 < 0.0) this->Coefficient6 = 0.0;

	this->Coefficient7 -= (1.0 - ZDistance7)*ZError;
	if(this->Coefficient7 > 1.0) this->Coefficient4 = 1.0;
	if(this->Coefficient4 < 0.0) this->Coefficient4 = 0.0;

	this->Coefficient8 -= (1.0 - ZDistance8)*ZError;
	if(this->Coefficient8 > 1.0) this->Coefficient8 = 1.0;
	if(this->Coefficient8 < 0.0) this->Coefficient8 = 0.0;
}