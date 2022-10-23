#include "Globals.h"
#include "ModuleScene.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene()
{
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	return true;
}

bool ModuleScene::Start()
{
	bool ret = true;

	sceneTexture = App->textures->Load(sceneTexturePath);
	if (sceneTexture == NULL) ret = false;

	return ret;
}

update_status ModuleScene::PreUpdate()
{
	bool ret = true;
	SDL_Rect* section = new SDL_Rect;

	// Floor
	section->x = 8;
	section->y = 392;
	section->w = 896;
	section->h = 72;
	ret = App->renderer->Blit(sceneTexture, 0, 408, section);

	delete section;
	if (!ret) return UPDATE_ERROR;
	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	return true;
}