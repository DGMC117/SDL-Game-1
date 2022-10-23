#pragma once
#include "Module.h"
#include "Globals.h"
#include "ModuleRender.h"

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

private:
	SDL_Texture* sceneTexture;

public:
	int scrollPercent = 0;
};