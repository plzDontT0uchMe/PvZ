#pragma once

class ProgressBar
{
private:
	double x, y, lvl;
	Texture textureBar;
	Sprite spriteBar;
	Texture textureFlag;
	Sprite spriteFlag;
	Texture textureBarCon;
	Sprite spriteBarCon;
	Texture textureBrain;
	Sprite spriteBrain;
	Texture textureBarProgress;
	Sprite spriteBarProgress;
public:
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double getLVL()
	{
		return lvl;
	}
	Sprite getSpriteBar()
	{
		return spriteBar;
	}
	Sprite getSpriteBrain()
	{
		return spriteBrain;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void setLVL(double lvl)
	{
		this->lvl = lvl;
	}
	ProgressBar()
	{
		x = SCREEN_WIDTH - 25;
		y = SCREEN_HEIGTH - 27;
		lvl = 0;
		textureBarProgress.loadFromFile("FlagMeterLevelProgress.png");
		spriteBarProgress.setTexture(textureBarProgress);
		spriteBarProgress.setPosition(SCREEN_WIDTH - 158 / 2 - 86 / 2, SCREEN_HEIGTH - 11);
		textureBar.loadFromFile("FlagMeter.png");
		spriteBar.setTexture(textureBar);
		spriteBar.setTextureRect(IntRect(0, 0, 158, 27));
		spriteBar.setPosition(SCREEN_WIDTH - 158, SCREEN_HEIGTH - 27);
		textureBarCon.loadFromFile("FlagMeter.png");
		spriteBarCon.setTexture(textureBar);
		spriteBarCon.setTextureRect(IntRect(0, 27, 158, 27));
		textureBrain.loadFromFile("FlagMeterParts.png");
		spriteBrain.setTexture(textureBrain);
		spriteBrain.setTextureRect(IntRect(0, 0, 25, 25));
		spriteBrain.setPosition(SCREEN_WIDTH - 25, SCREEN_HEIGTH - 27);
		textureFlag.loadFromFile("FlagMeterParts.png");
		spriteFlag.setTexture(textureBrain);
		spriteFlag.setTextureRect(IntRect(50, 0, 25, 25));
		spriteFlag.setPosition(SCREEN_WIDTH - 158, SCREEN_HEIGTH - 27);
	}
	~ProgressBar() { };
	void getProgressBar()
	{
		window.draw(spriteBar);
		window.draw(spriteBarProgress);
		window.draw(spriteFlag);
		window.draw(spriteBrain);
	}
	void Move(double x)
	{
		if (lvl <= 125)
		{
			spriteBrain.move(-x, 0);
		}
		this->x -= x;
		lvl += x;
	}
};