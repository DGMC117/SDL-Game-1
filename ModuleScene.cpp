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
	texSection->x = 72;
	texSection->y = 208;
	texSection->w = 768;
	texSection->h = 170;
	renSection->x = 0 - SCREEN_WIDTH * 0.0125 * scrollPercent;
	renSection->y = 0;
	renSection->w = SCREEN_WIDTH * 2.25;
	renSection->h = SCREEN_HEIGHT * 3 / 4;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	// Boat Texture 8, 24, 520, 180
	texSection->x = 8;
	texSection->y = 24;
	texSection->w = 520;
	texSection->h = 180;
	renSection->x = 0 - SCREEN_WIDTH * 0.0125 * scrollPercent;
	renSection->y = 0;
	renSection->w = SCREEN_WIDTH;
	renSection->h = SCREEN_HEIGHT * 3 / 4;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	// Floor Texture 8, 392, 896, 72
	texSection->x = 8;
	texSection->y = 392;
	texSection->w = 896;
	texSection->h = 72;
	renSection->x = 0 - SCREEN_WIDTH * 0.0125 * scrollPercent;
	renSection->y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4;
	renSection->w = SCREEN_WIDTH * 2.25;
	renSection->h = SCREEN_HEIGHT / 4;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	// String Stump 800, 184, 20, 16 (413)
	texSection->x = 800;
	texSection->y = 184;
	texSection->w = 20;
	texSection->h = 16;
	renSection->x = 1495 - SCREEN_WIDTH * 0.0125 * scrollPercent - 20 * 2.25;
	renSection->y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4 - 20 * 2.25;
	renSection->w = 30 * 2.25;
	renSection->h = 24 * 2.25;
	ret = App->renderer->Blit(sceneTexture, texSection, renSection);

	// Stump Textures 760, 176, 30, 24
	texSection->x = 760;
	texSection->y = 176;
	texSection->w = 30;
	texSection->h = 24;
	renSection->y = SCREEN_HEIGHT - SCREEN_HEIGHT / 4 - 20 * 2.25;
	renSection->w = 30 * 2.25;
	renSection->h = 24 * 2.25;
	for (int i = -1; i < 3; ++i) {
		renSection->x = 1495 - SCREEN_WIDTH * 0.0125 * scrollPercent - 20 * 2.25 + (double) i * SCREEN_WIDTH * 2.25 / 4;
		if (i != 0) ret = App->renderer->Blit(sceneTexture, texSection, renSection);
	}


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