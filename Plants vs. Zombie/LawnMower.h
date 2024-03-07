#pragma once

class LawnMower
{
private:
	bool isClearTrash;
	double x, y;
	float frame;
	Texture texture;
	Sprite spriteLawnMower;
public:
	LawnMower(double x, double y)
	{
		frame = 0;
		isClearTrash = false;
		this->x = x;
		this->y = y;
		texture.loadFromFile("LawnMower.png");
		spriteLawnMower.setTexture(texture);
		spriteLawnMower.setTextureRect(IntRect(0, 0, 82, 70));
		spriteLawnMower.setPosition(x, y);
	}
	~LawnMower() { };
	bool getIsClearTrash()
	{
		return isClearTrash;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	Sprite getSpriteLawnMower()
	{
		return spriteLawnMower;
	}
	void setIsClearTrash(bool isClearTrash)
	{
		this->isClearTrash = isClearTrash;
	}
	void clearTrash()
	{
		if (isClearTrash)
		{
			frame += 0.05f * frameTime * 50;
			if (frame > 2) frame -= 2;
			spriteLawnMower.setTextureRect(IntRect(82 * int(frame), 0, 82, 70));
			spriteLawnMower.move(1.5 * frameTime * 50, 0);
		}
	}
};