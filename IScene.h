#pragma once
#include <Novice.h>
enum SCENE { TITLE, STAGE, CLEAR };
class IScene {
protected:

public:
	static int sceneNo;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual ~IScene();
	int GetSceneNo();
	//IScene();

};
