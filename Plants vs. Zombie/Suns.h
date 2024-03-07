#pragma once

class Suns
{
private:
	int countSuns;
	double x, y, yEnd;
	Texture texture;
	Sprite spriteSuns;
	Clock clock;
public:
	Suns()
	{
		countSuns = 25;
		x = rand() % (900 - 250) + 250;
		y = -100;
		yEnd = rand() % (500 - 100) + 100;
		texture.loadFromFile("suns.png");
		spriteSuns.setTexture(texture);
		spriteSuns.setPosition(x, y);
	}
	Suns(double x, double y)
	{
		countSuns = 25;
		this->x = x;
		this->y = y;
		yEnd = rand() % (500 - 100) + 100;
		texture.loadFromFile("suns.png");
		spriteSuns.setTexture(texture);
		spriteSuns.setPosition(x, y);
	}
	~Suns() { };
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	int getCountSuns()
	{
		return countSuns;
	}
	Sprite getSpriteSuns()
	{
		return spriteSuns;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void checkSuns()
	{
		if (y < yEnd)
		{
			y += 1 * frameTime * 50;
			spriteSuns.move(0, 1 * frameTime * 50);
		}
	}
};