#include "SCENES.AICritter.h"
#include <stdlib.h>
#include <time.h>

AICritter::AICritter(void)
{	

	this->_Initialize();
}


AICritter::~AICritter(void)
{
	AICritter::_Uninitialize();
}

void AICritter::_Initialize()
{
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 50, 50)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 750, 50)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 750, 550)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 50, 550)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 400, 300)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 55, 55)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 755, 55)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 755, 555)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 55, 555)));
	Waters.push_back(auto_ptr<ZObject>(new Water(800, 600, 405, 305)));

	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 100, 100)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 300, 300)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 500, 300)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 300, 500)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 100, 200)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 100, 100)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 300, 300)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 500, 300)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 300, 500)));
	Foods.push_back(auto_ptr<ZObject>(new Food(800, 600, 100, 200)));

	Critters.push_back(auto_ptr<ZObject>(new Creature(800, 600, 450, 150)));
	Critters.push_back(auto_ptr<ZObject>(new Creature(800, 600, 150, 350)));
	//Critters.push_back(auto_ptr<ZObject>(new Creature(800, 600, 250, 250)));
	//Critters.push_back(auto_ptr<ZObject>(new Creature(800, 600, 350, 450)));
}

void AICritter::_Uninitialize()
{

}

void AICritter::_Update()
{

}

void AICritter::_Draw(float *zb, int *video, int w, int h)
{
	for(auto i = Foods.begin(); i != Foods.end(); i++)
	{
		(*i)->Draw(video, w, h);
	}

	for(auto i = Waters.begin(); i != Waters.end(); i++)
	{
		(*i)->Draw(video, w, h);
	}

	for(auto i = Critters.begin(); i != Critters.end(); i++)
	{
		for(auto p = Foods.begin(); p != Foods.end(); p++)
		{
			ZObject* COb = p->get();
			(*i)->AssessFTarget(COb);
		}
		for(auto q = Waters.begin(); q != Waters.end(); q++)
		{
			ZObject* COb = q->get();
			(*i)->AssessWTarget(COb);
		}
		for(auto r = Critters.begin(); r != Critters.end(); r++)
		{
			ZObject* COb = r->get();
			(*i)->AssessETarget(COb);
		}
		(*i)->RunAI();
		(*i)->Draw(video, w, h);
	}
	//Update Critter States
	//this->AICritter::_Update();
}
