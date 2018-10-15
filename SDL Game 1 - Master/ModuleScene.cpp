#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"

ModuleScene::ModuleScene()
{
}

// Destructor
ModuleScene::~ModuleScene()
{
}

// Called before render is available
bool ModuleScene::Init()
{
	float buffer_data[] = { -1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f };
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data,
		GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}

// Called before first frame
bool ModuleScene::Start()
{
	//SDL_Texture* texture;
	//texture = App->textures->Load("sprites.PNG");
	return true;
}

update_status ModuleScene::Update() {
	glEnableVertexAttribArray(0); // attribute 0

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		0,			// attribute 0
		3,			// number of componentes (3 floats)
		GL_FLOAT,	// data type
		GL_FALSE,	// should be normalized?
		0,			// stride
		(void*)0	// array buffer offset
	);
	glDrawArrays(GL_TRIANGLES, 0, 3); // start at 0 and 3 tris
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleScene::CleanUp()
{
	return true;
}