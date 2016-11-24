#include "Game.h"
#include <gl/GL.h>
#include <gl/GLU.h> 


Game::Game() : window(VideoMode(800, 600), "OpenGL")
{

}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glRotatef(0.1, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(1.0f, 1.0f, 1.0001f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLES);
	{ 
		glVertex3f(0.0, 1.0, -12.0);
		glVertex3f(-2.0, -1.0, -12.0);
		glVertex3f(-1.0, -1.0, -12.0);

	}
	glEnd();

	glBegin(GL_POINTS);
	{ 
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();

	glBegin(GL_LINES);
	{
		glVertex3f(0.0, 0.0, -1.0);
		glVertex3f(1.0, -1.0, -3.0);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.0, 0.0, -1.0);
		glVertex3f(2.0, -1.0, -2.0);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	{ 
		glVertex3f(0.0, -1.0, -3.0);
		glVertex3f(2.0, -2.0, -5.0); 
		glVertex3f(5.0, -1.0, -12.0);
		//glVertex3f(2.0, 1.0, -12.0);

	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	{ 
		glVertex3f(4.0, 1.0, -12.0);
		glVertex3f(3.0, -1.0, -12.0);
		glVertex3f(5.0, -1.0, -12.0);
		glVertex3f(2.0, 1.0, -12.0);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	{ 
		glVertex3f(0.0, 4.0, -15.0);
		glVertex3f(-2.0, 2.0, -15.0);
		glVertex3f(2.0, 2.0, -15.0); 
	}

	glEnd();

	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(0.0, 2.0, -50.0);
		glVertex3f(-2.0, -2.0, -50.0);
		glVertex3f(2.0, 0.0, -12.0);
		glVertex3f(0.0, 0.0, -155.0);
	}
	glEnd();

	glBegin(GL_QUADS);
	{ 
		glVertex3f(-9.0, -13.0, -90.0);
		glVertex3f(-22.0, -13.0, -90.0);
		glVertex3f(-22.0, -13.0, -90.0);
		glVertex3f(-22.0, 2.0, -90.0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{ 
		glVertex3f(0.0, 2.0, -50.0);
		glVertex3f(-2.0, -2.0, -50.0);
		glVertex3f(2.0, -2.0, -50.0);
		glVertex3f(4.0, -2.0, -30.0);
	}
	glEnd();


	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

