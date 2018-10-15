#ifndef __ModuleScene_H__
#define __ModuleScene_H__
#include<list>
#include "Module.h"
#include "SDL/include/SDL.h"
#include "glew/include/GL/glew.h"

struct SDL_Scene;
struct SDL_Texture;

class ModuleScene : public Module
{
public:

	ModuleScene();
	virtual ~ModuleScene();

	bool Init();
	bool Start();
	update_status Update();

	// Called before quitting
	bool CleanUp();

public:
	std::list<SDL_Scene*> scenes;
	GLuint vbo;
};


#endif // __ModuleScene_H__
