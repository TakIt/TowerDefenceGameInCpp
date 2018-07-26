#pragma once

typedef enum {
	eTitle,
	eGame,
	eOption,
	eKeyConfig,
	eEnd,

	eNone,
}eMainScene;

/// <summary>
/// the interface class to change scene
/// </summary>
class ISceneChanger {
public:
	virtual ~ISceneChanger() {}
	virtual void ChangeMainScene(eMainScene eNextScene) = 0;

};


