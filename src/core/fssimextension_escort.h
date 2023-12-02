#ifndef FSSIMEXTENSION_ENDURANCE_IS_INCLUDED
#define FSSIMEXTENSION_ENDURANCE_IS_INCLUDED
/* { */

#include "fssimextension.h"

class FsSimExtension_EscortMode : public FsSimExtensionBase
{
public:
	typedef FsSimExtension_EscortMode THISCLASS;

    int nEnemyMax;
    double remainTime;
    double gLimit;
    char* vipAircraft;
	char* escortAircraft;
	YsArray <YsVec3> escortRoute;
	YsAtt3 vipStartAtt;

	YSBOOL allowAAM;

	FsSimExtension_EscortMode();

	static const char *Ident(void);
	static std::shared_ptr <FsSimExtensionBase> Generate(void);
	static std::function <std::shared_ptr <FsSimExtensionBase>(void)> Generator(void);

	virtual const char *GetIdent(void) const;
	virtual YsArray <YsString> Serialize(const FsSimulation *sim);
	virtual YSRESULT ProcessCommand(FsSimulation *sim,const YsConstArrayMask <YsString> &argv);

	virtual void StartSimulation(FsSimulation *sim);
	virtual void EndSimulation(FsSimulation *sim);

	virtual void OnInterval(FsSimulation *sim,double dt);
	virtual YsArray <LowerLeftAndBitmap,0> Draw2D(const FsSimulation *sim,int windowId,int winWid,int winHei) const;
};

/* } */
#endif
