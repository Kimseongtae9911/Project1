#pragma once

#define SINGLE(type) public:\
						static type* GetInst()\
						{\
								static type mgr;\
								return &mgr;\
						}\
					 private:\
						type();\
						~type();

#define fDeltaTime CFrameMgr::GetInst()->GetfDT()
#define DelatTime CFrameMgr::GetInst()->GetDT()

#define PI 3.1415926535f

enum class GROUP_TYPE
{
	DEFAULT, // 0
	PLAYER,  // 1
	MONSTER, // 2


	END = 3
};

enum class SCENE_TYPE
{
	TITLE,		// 0
	START,		// 1
	STAGE_01,	// 2

	END = 3
};

enum class BRUSH_TYPE
{
	HOLLOW,
	
	END
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	
	END
};