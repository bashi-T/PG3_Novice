#pragma once
#include<Novice.h>
enum SCENE { TITLE, STAGE, CLEAR };
class IScene {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	int GetSceneNo() { return SceneNo; }
	virtual ~IScene();

protected:
	static int SceneNo;
};
