#pragma once

class Settings
{
private:
	double x, y;
	Texture texture;
	Sprite spriteSetting;
	Font font;
	Text textMusic;
	Text textSound;
	Text textBack;
	Texture textureLine;
	Sprite spriteLine1;
	Sprite spriteLine2;
	Texture textureCircle;
	Sprite spriteCircle1;
	Sprite spriteCircle2;
	bool isCircle1;
	bool isCircle2;
public:
	Settings()
	{

		isCircle1 = false;
		isCircle2 = false;

		textureLine.loadFromFile("line.png");

		spriteLine1.setTexture(textureLine);
		spriteLine1.setScale(0.1,0.0025);
		spriteLine1.setPosition(410, 220);

		spriteLine2.setTexture(textureLine);
		spriteLine2.setScale(0.1, 0.0025);
		spriteLine2.setPosition(410, 336);

		textureCircle.loadFromFile("kryg.png");

		spriteCircle1.setTexture(textureCircle);
		spriteCircle1.setScale(0.01, 0.01);
		spriteCircle1.setPosition(400, 213);

		spriteCircle2.setTexture(textureCircle);
		spriteCircle2.setScale(0.01, 0.01);
		spriteCircle2.setPosition(400, 329);

		x = SCREEN_WIDTH / 4;
		y = 51;
		texture.loadFromFile("GameMenu.png");
		spriteSetting.setTexture(texture);
		spriteSetting.setScale(1.2, 1);
		spriteSetting.setPosition(x, y);

		font.loadFromFile("font.ttf");

		textMusic.setFont(font);
		textMusic.setFillColor(Color::Red);
		textMusic.setStyle(Text::Bold);
		textMusic.setScale(1.25, 1.25);
		textMusic.setString("ÌÓÇÛÊÀ");
		textMusic.setPosition(SCREEN_WIDTH / 2 - textMusic.getGlobalBounds().width / 2, y + 100);
		//textMusic.setPosition(x + 170, y + 100);

		textSound.setFont(font);
		textSound.setFillColor(Color::Red);
		textSound.setStyle(Text::Bold);
		textSound.setScale(1.25, 1.25);
		textSound.setString("ÇÂÓÊÈ");
		textSound.setPosition(SCREEN_WIDTH / 2 - textSound.getGlobalBounds().width / 2, y + 200);

		textBack.setFont(font);
		textBack.setFillColor(Color::Red);
		textBack.setStyle(Text::Bold);
		textBack.setScale(1.25, 1.25);
		textBack.setString("ÍÀÇÀÄ");
		textBack.setPosition(SCREEN_WIDTH / 2 - textBack.getGlobalBounds().width / 2, y + 410);
	}
	~Settings() { };
	void loadSetting()
	{
		window.clear(Color(101, 101, 137));
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		if (spriteCircle1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				isCircle1 = true;
			}
		}
		if (spriteCircle2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				isCircle2 = true;
			}
		}
		if (isCircle1)
		{
			spriteCircle1.setPosition(pos.x - 12, 213);
			musicVolume = (pos.x - 12 - 400) / 2;
			if (pos.x - 12 > 600)
			{
				spriteCircle1.setPosition(600, 213);
				musicVolume = (600 - 400) / 2;
			}
			if (pos.x - 12 < 400)
			{
				spriteCircle1.setPosition(400, 213);
				musicVolume = (400 - 400) / 2;
			}
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				isCircle1 = false;
			}
		}
		if (isCircle2)
		{
			spriteCircle2.setPosition(pos.x - 12, 329);
			soundVolume = (pos.x - 12 - 400) / 2;
			if (pos.x - 12 > 600)
			{
				spriteCircle2.setPosition(600, 329);
				soundVolume = (600 - 400) / 2;
			}
			if (pos.x - 12 < 400)
			{
				spriteCircle2.setPosition(400, 329);
				soundVolume = (400 - 400) / 2;
			}
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				isCircle2 = false;
			}
		}
		if (textMusic.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			textMusic.setOutlineColor(Color(133, 219, 50));
			textMusic.setOutlineThickness(3);
		}
		else
		{
			textMusic.setOutlineThickness(0);
		}
		if (textSound.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			textSound.setOutlineColor(Color(133, 219, 50));
			textSound.setOutlineThickness(3);
		}
		else
		{
			textSound.setOutlineThickness(0);
		}
		if (textBack.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)	scene = 0;
			textBack.setOutlineColor(Color(133, 219, 50));
			textBack.setOutlineThickness(3);
		}
		else
		{
			textBack.setOutlineThickness(0);
		}
		window.draw(spriteSetting);
		window.draw(spriteLine1);
		window.draw(spriteCircle1);
		window.draw(spriteLine2);
		window.draw(spriteCircle2);
		window.draw(textMusic);
		window.draw(textSound);
		window.draw(textBack);
	}
};