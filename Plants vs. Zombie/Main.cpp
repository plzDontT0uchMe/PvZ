#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <locale>
#include <chrono>
#include <Windows.h>
#include <ctime>
#include <list>
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGTH 600
#define TILE_MAP_WIDTH 9
#define TILE_MAP_HEIGHT 5

using namespace std;
using namespace sf;

ContextSettings settings;

RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGTH), "", Style::Default, settings);

Event event;

View view;

int scene;

double tileMap[TILE_MAP_WIDTH * TILE_MAP_HEIGHT][2];

bool tileMapCollision[TILE_MAP_WIDTH * TILE_MAP_HEIGHT];

double frameTime;

float soundVolume;

float musicVolume;

bool gameOverWin = false;

bool gameOverLose = false;

bool restart = true;

#include"Menu.h"
#include"Zombie.h"
#include"Suns.h"
#include"Camera.h"
#include"PlantsBar.h"
#include"ProgressBar.h"
#include"Help.h"
#include"Plants.h"
#include"LawnMower.h"
#include"Game.h"
#include"GameMenu.h"
#include"Settings.h"
#include"GameOver.h"
// 80 на 100

// 255 на 95

// 9 на 5

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	Menu m;
	Game g;
	Help h;
	Settings s;
	GameMenu gm;
	GameOver go;

	float fps = 0;
	Clock clockFPS = Clock::Clock();
	Time previousTime = clockFPS.getElapsedTime();
	Time currentTime;

	Music musicMenu;
	musicMenu.openFromFile("menu.wav");

	Music musicGame;
	musicGame.openFromFile("background.wav");

	musicMenu.setLoop(true);
	musicGame.setLoop(true);

	settings.antialiasingLevel = 8;

	for (int i = 0, j = 0, k = 0; i < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; i++)
	{
		tileMapCollision[i] = false;
		tileMap[i][0] = 255 + 80 * k;
		tileMap[i][1] = 95 + 100 * j;
		if ((i + 1) % TILE_MAP_WIDTH == 0 && i != 0)
		{
			k = 0;
			j++;

		}
		else
		{
			k++;
		}
	}
	musicMenu.play();
	musicGame.play();

	while (window.isOpen())
	{
		Clock clock2;
		double time2 = clock2.getElapsedTime().asMilliseconds();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		switch (scene)
		{
		case 0:
		{
			musicMenu.setVolume(musicVolume);
			musicGame.setVolume(0);
			m.loadMenu();
			break;
		}
		case 1:
		{
			musicMenu.setVolume(0);
			musicGame.setVolume(musicVolume);
			g.loadGame();
			break;
		}
		case 2:
		{
			s.loadSetting();
			break;
		}
		case 3:
		{
			h.loadHelp();
			break;
		}
		case 4:
		{
			window.close();
			break;
		}
		case 5:
		{
			gm.loadGameMenu();
			break;
		}
		case 6:
		{
			go.loadGameOver();
			break;
		}
		}
		currentTime = clockFPS.getElapsedTime();
		frameTime = currentTime.asSeconds() - previousTime.asSeconds();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		previousTime = currentTime;
		window.display();
		clock2.restart();
	}
	return 0;
}