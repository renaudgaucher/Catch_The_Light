#ifndef DEF_STAGEMENU
#define DEF_STAGEMENU

#include "Stage.h"


class StageMenu : public Stage
{
public:
	StageMenu(Gameboard* gameboard);
	virtual byte run();
	void launch();
};

#endif
