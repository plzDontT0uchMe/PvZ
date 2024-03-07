#pragma once

class PlantsBar
{
private:
	int selectType;
	int count;
	double x, y;
	bool isPeashooterActive;
	bool isSunflowerActive;
	bool isWallnutActive;
	Font font;
	Text textCount;
	string stringCount;
	Texture texturePlantsBar;
	Sprite spritePlantsBar;
	Texture texturePeashooter;
	Sprite spritePeashooter;
	Texture textureSunflower;
	Sprite spriteSunflower;
	Texture textureWallnut;
	Sprite spriteWallnut;
	Texture textureTemp;
	Sprite spriteTemp;
public:
	PlantsBar()
	{
		x = 0;
		y = 0;
		selectType = -1;

		texturePlantsBar.loadFromFile("PlantsBar.png");
		spritePlantsBar.setTexture(texturePlantsBar);
		spritePlantsBar.setPosition(x, y);

		texturePeashooter.loadFromFile("peashoter.png");
		spritePeashooter.setTexture(texturePeashooter);
		spritePeashooter.setTextureRect(IntRect(0, 0, 96, 96));
		spritePeashooter.setScale(0.7, 0.7);
		spritePeashooter.setPosition(x + 80, y + 10);

		textureSunflower.loadFromFile("sunflower.png");
		spriteSunflower.setTexture(textureSunflower);
		spriteSunflower.setTextureRect(IntRect(0, 0, 96, 96));
		spriteSunflower.setScale(0.7, 0.7);
		spriteSunflower.setPosition(x + 80 + 67.2, y + 10);

		textureWallnut.loadFromFile("wallnut.png");
		spriteWallnut.setTexture(textureWallnut);
		spriteWallnut.setTextureRect(IntRect(0, 0, 96, 96));
		spriteWallnut.setScale(0.7, 0.7);
		spriteWallnut.setPosition(x + 80 + 67.2 * 2, y + 10);

		count = 150;
		stringCount = to_string(count);
		font.loadFromFile("font.ttf");
		textCount.setFont(font);
		textCount.setFillColor(Color::Black);
		textCount.setStyle(Text::Bold);
		textCount.setString(stringCount);
		textCount.setPosition(25, 52);

		isPeashooterActive = false;
		isSunflowerActive = true;
		isWallnutActive = true;
	}
	~PlantsBar() { };
	int getSelectType()
	{
		return selectType;
	}
	int getCount()
	{
		return count;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	bool getIsPeashooterActive()
	{
		return isPeashooterActive;
	}
	bool getIsSunflowerActive()
	{
		return isSunflowerActive;
	}
	bool getIsWallnutActive()
	{
		return isWallnutActive;
	}
	Sprite getSpritePlantsBar()
	{
		return spritePlantsBar;
	}
	Sprite getSpritePeashooter()
	{
		return spritePeashooter;
	}
	Sprite getSpriteSunflower()
	{
		return spriteSunflower;
	}
	Sprite getSpriteWallnut()
	{
		return spriteWallnut;
	}
	Sprite getSpriteTemp()
	{
		return spriteTemp;
	}
	Text getTextCount()
	{
		return textCount;
	}
	void setPosition(double x, double y)
	{
		spriteTemp.setPosition(x - spriteTemp.getLocalBounds().width / 2 , y - spriteTemp.getLocalBounds().height / 2);
	}
	void setSelectType(int selectType)
	{
		this->selectType = selectType;
		if (selectType != -1)
		{
			textureTemp.loadFromFile(getSelectTypeImg(selectType));
			spriteTemp.setTexture(textureTemp);
		}
		switch (selectType)
		{
			case 0:
			{
				spriteTemp.setTextureRect(IntRect(0, 0, 75, 75));
				break;
			}
			case 1:
			{
				spriteTemp.setTextureRect(IntRect(0, 0, 66, 75));
				break;
			}
			case 2:
			{
				spriteTemp.setTextureRect(IntRect(0, 0, 66, 75));
				break;
			}
		}
	}
	string getSelectTypeImg(int selectType)
	{
		string img[3] = { "Peashooter2.png", "Sunflower2.png", "Wallnut2.png" };
		if (selectType != -1)
		{
			return img[selectType];
		}
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void setCount(int count)
	{
		this->count = count;
		stringCount = to_string(count);
		textCount.setString(stringCount);
	}
	void checkActive()
	{
		if (count >= 25)
		{
			spriteWallnut.setTextureRect(IntRect(96, 0, 96, 96));
			isWallnutActive = true;
		}
		else
		{
			spriteWallnut.setTextureRect(IntRect(0, 0, 96, 96));
			isWallnutActive = false;
		}
		if (count >= 50)
		{
			spriteSunflower.setTextureRect(IntRect(96, 0, 96, 96));
			isSunflowerActive = true;
		}
		else
		{
			spriteSunflower.setTextureRect(IntRect(0, 0, 96, 96));
			isSunflowerActive = false;
		}
		if (count >= 100)
		{
			spritePeashooter.setTextureRect(IntRect(96, 0, 96, 96));
			isPeashooterActive = true;
		}
		else
		{
			spritePeashooter.setTextureRect(IntRect(0, 0, 96, 96));
			isPeashooterActive = false;
		}
	}
	void getPlantsBar()
	{
		checkActive();
		window.draw(spritePlantsBar);
		window.draw(spritePeashooter);
		window.draw(spriteSunflower);
		window.draw(spriteWallnut);
		window.draw(textCount);
	}
};