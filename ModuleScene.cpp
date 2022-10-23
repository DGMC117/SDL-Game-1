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

	sceneTexture = App->textures->Load(SPRITE_FILE);
	if (sceneTexture == NULL) ret = false;

	return ret;
}

update_status ModuleScene::PreUpdate()
{
	bool ret = true;
	SDL_Rect* texSection = new SDL_Rect;
	SDL_Rect* renSection = new SDL_Rect;

	// Background Texture 72, 208, 768, 170
	texSection->x = 72 + (768 / 2.25) * 0.0125 * scrollPercent;
	texSection->y = 208;
	texSection->w = 768 / 2.25;
	texSection->h = 170;
	renSection->x = 0;
	renSection->y = 0;
	renSection->w = SCREEN_WIDTH;
	renSection->h = SCREEN_HEIGHT * 3 / 4;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	// Floor Texture 8, 392, 896, 72
	texSection->x = 8 + (896 / 2.25) * 0.0125 * scrollPercent;
	texSection->y = 392;
	texSection->w = 896 / 2.25;
	texSection->h = 72;
	renSection->x = 0;
	renSection->y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4;
	renSection->w = SCREEN_WIDTH;
	renSection->h = SCREEN_HEIGHT / 4;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	delete texSection;
	delete renSection;

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