#pragma once

class Help
{
private:
	double x, y, width, heigth;
	Image image;
	Texture textureBackground;
	Texture textureText;
	Sprite background;
	Sprite back;
	Sprite spriteText;
	Font font;
	Text text;
public:
	Help()
	{
		font.loadFromFile("font.ttf");
		text.setFont(font);
		text.setString("Назад");
		text.setStyle(Text::Bold);
		text.setFillColor(Color::Red);
		text.setScale(1.25, 1.25);
		text.setPosition(SCREEN_WIDTH / 2 - text.getGlobalBounds().width / 2, SCREEN_HEIGTH - 76);
		x = 0;
		y = 0;
		width = SCREEN_WIDTH;
		heigth = SCREEN_HEIGTH;
		textureText.loadFromFile("ZombieNote.png");
		back.setTexture(textureText);
		back.setPosition(SCREEN_WIDTH / 2 - (654 / 2), SCREEN_HEIGTH / 2 - (427 / 2));
		image.loadFromFile("help1.png");
		image.createMaskFromColor(Color::Black);
		textureBackground.loadFromImage(image);
		spriteText.setTexture(textureBackground);
		spriteText.setPosition(SCREEN_WIDTH / 2 - (529 / 2), SCREEN_HEIGTH / 2 - (323 / 2));

	}
	~Help() { };
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double getWidth()
	{
		return width;
	}
	double getHeigth()
	{
		return heigth;
	}
	Sprite getSpriteBackground()
	{
		return background;
	}
	Sprite getSpriteBack()
	{
		return back;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void setWidth(double width)
	{
		this->width = width;
	}
	void setHeigth(double heigth)
	{
		this->heigth = heigth;
	}
	void loadHelp()
	{
		window.clear(Color::Black);
		if (text.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
		{
			text.setOutlineThickness(3);
			text.setOutlineColor(Color(133, 219, 50));
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				scene = 0;
			}
		}
		else
		{
			text.setOutlineThickness(0);
		}
		window.draw(back);
		window.draw(spriteText);
		window.draw(text);
	}
};