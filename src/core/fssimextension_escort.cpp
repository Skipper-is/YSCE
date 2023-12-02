#include "fssimextension_escort.h"
#include "fsworld.h"
#include "fssimulation.h"
#include "fsexistence.h"



FsSimExtension_EscortMode::FsSimExtension_EscortMode()
{
	nEnemyMax=0;
	remainTime=15.0*60.0;
	gLimit=4.0;
	vipAircraft = "AIRBUS320";
	escortAircraft = "EUROFIGHTER_TYPHOON";
	vipStartAtt.Set(0.0,0.0,0.0);
	allowAAM=YSTRUE;
}

/* static */ const char *FsSimExtension_EscortMode::Ident(void)
{
	return "ENDURANCE";
}

/* static */ std::shared_ptr <FsSimExtensionBase> FsSimExtension_EscortMode::Generate(void)
{
	std::shared_ptr <FsSimExtensionBase> ptr;
	ptr.reset(new THISCLASS);
	return ptr;
}

/* static */ std::function <std::shared_ptr <FsSimExtensionBase>(void)> FsSimExtension_EscortMode::Generator(void)
{
	std::function <std::shared_ptr <FsSimExtensionBase>(void)> func;
	func=std::bind(&THISCLASS::Generate);
	return func;
}

/* virtual */ const char *FsSimExtension_EscortMode::GetIdent(void) const
{
	return THISCLASS::Ident();
}
/* virtual */ YsArray <YsString> FsSimExtension_EscortMode::Serialize(const FsSimulation *sim)
{
	YsArray <YsString> encoded;


	return encoded;
}
/* virtual */ YSRESULT FsSimExtension_EscortMode::ProcessCommand(FsSimulation *sim,const YsConstArrayMask <YsString> &argv)
{
	return YSOK;
}

/* virtual */ void FsSimExtension_EscortMode::StartSimulation(FsSimulation *sim)
{
	srand((unsigned int)time(NULL));
	this->gLimit=4.0;
	this->remainTime=15.0*60.0;
	this->nEnemyMax=0;
	sim->AllowAAM(this->allowAAM);
	
}

/* virtual */ void FsSimExtension_EscortMode::EndSimulation(FsSimulation *sim)
{
}

/* virtual */ void FsSimExtension_EscortMode::OnInterval(FsSimulation *sim,double dt)
{
	if(YSTRUE!=sim->Paused())
	{
		remainTime-=dt;
		if(remainTime>0.0)
		{
			// sim->GenerateEnemyAirplane(nEnemyMax,gLimit,remainTime,allowAAM,jet,ww2);
		}
	}
}

/* virtual */ YsArray <FsSimExtensionBase::LowerLeftAndBitmap,0> FsSimExtension_EscortMode::Draw2D(const FsSimulation *sim,int windowId,int winWid,int winHei) const
{
	YsArray <LowerLeftAndBitmap,0> overlay;
	return overlay;
}
