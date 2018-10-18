#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::Update()
{
	static SDL_Event event;
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);

	// TODO 1: Make the application properly close when ESC is pressed (do not use exit())
	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		if (!CleanUp())
		{
			return UPDATE_ERROR;
		}
		return UPDATE_STOP;
	}

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			break;
		}
	}

	// Homework: Make the application close up when pressing “X” button of the window

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}