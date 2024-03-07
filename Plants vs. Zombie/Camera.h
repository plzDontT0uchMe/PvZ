#pragma once

class Camera
{
private:
	Texture textureStartSet;
	Texture textureStartReady;
	Texture textureStartPlant;
	Sprite spriteStartSet;
	Sprite spriteStartReady;
	Sprite spriteStartPlant;
	bool quit;
	int dir;
	double x, y;
	int key;
public:
	Camera()
	{
		quit = false;
		dir = 1;
		x = SCREEN_WIDTH / 2;
		y = SCREEN_HEIGTH / 2;
	}
	~Camera() { };
	bool getQuit()
	{
		return quit;
	}
	void setQuit(bool quit)
	{
		this->quit = quit;
	}
	void Move()
	{
		if (x * 2 <= 1750 && dir == 1)
		{
			x += 0.1;
			view.setCenter(x, y);
			view.setSize(SCREEN_WIDTH, SCREEN_HEIGTH);
			if (x * 2 >= 1750)
			{
				Sleep(2000);
				dir = -1;
			}
		}
		if (x * 2 >= 1024 && dir == -1)
		{
			x -= 0.1;
			view.setCenter(x, y);
			view.setSize(SCREEN_WIDTH, SCREEN_HEIGTH);
			if (x * 2 <= 1024)
			{
				dir = 0;
				quit = true;
				//Sleep(100);
			}
		}
		window.setView(view);
	}
};