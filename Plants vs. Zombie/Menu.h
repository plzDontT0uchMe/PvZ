#pragma once

class Menu
{
private:
	bool isMenuLoad;
	double x, y, width, heigth;
	string loadBar;
	Texture texture;
	Sprite spriteLoadMenu;
	Texture textureMenu;
	Sprite spriteMenu;
	Clock clock;
	Font font;
	Text loadText;
	Text Start;
	Text Settings;
	Text Help;
	Text Exit;
public:
	Menu()
	{
		isMenuLoad = false;
		x = 0;
		y = 0;
		loadBar = "0";
		width = SCREEN_WIDTH;
		heigth = SCREEN_HEIGTH;
		font.loadFromFile("font.ttf");
		loadText.setFont(font);
		loadText.setFillColor(Color::Red);
		loadText.setStyle(Text::Bold);
		loadText.setScale(1.25, 1.25);
		loadText.setString("Çàãðóçêà: " + loadBar + "%");
		loadText.setPosition(SCREEN_WIDTH / 2 - loadText.getGlobalBounds().width / 2, SCREEN_HEIGTH / 1.25);
		Start.setFont(font);
		Settings.setFont(font);
		Help.setFont(font);
		Exit.setFont(font);
		Start.setFillColor(Color::Red);
		Settings.setFillColor(Color::Red);
		Help.setFillColor(Color::Red);
		Exit.setFillColor(Color::Red);
		Start.setStyle(Text::Bold);
		Settings.setStyle(Text::Bold);
		Help.setStyle(Text::Bold);
		Exit.setStyle(Text::Bold);
		Start.setScale(1.25, 1.25);
		Settings.setScale(1.25, 1.25);
		Help.setScale(1.25, 1.25);
		Exit.setScale(1.25, 1.25);
		Start.setString("ÏÐÈÊËÞ×ÅÍÈÅ");
		Settings.setString("   ÎÏÖÈÈ   ");
		Help.setString("   ÏÎÌÎÙÜ   ");
		Exit.setString("   ÂÛÕÎÄ   ");
		Start.setPosition(SCREEN_WIDTH / 2 - Start.getGlobalBounds().width / 2 , 200);
		Settings.setPosition(SCREEN_WIDTH / 2 - Settings.getGlobalBounds().width / 2, 300);
		Help.setPosition(SCREEN_WIDTH / 2 - Help.getGlobalBounds().width / 2, 400);
		Exit.setPosition(SCREEN_WIDTH / 2 - Exit.getGlobalBounds().width / 2, 500);
		textureMenu.loadFromFile("titlescreen.jpg");
		spriteMenu.setTexture(textureMenu);
		spriteMenu.setScale(SCREEN_WIDTH / spriteMenu.getLocalBounds().width, SCREEN_HEIGTH / spriteMenu.getLocalBounds().height);
		texture.loadFromFile("titlescreen1.jpg");
		spriteLoadMenu.setTexture(texture);
		spriteLoadMenu.setScale(SCREEN_WIDTH / spriteLoadMenu.getLocalBounds().width, SCREEN_HEIGTH / spriteLoadMenu.getLocalBounds().height);
	}
	~Menu() { };
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
	bool getIsMenuLoad()
	{
		return isMenuLoad;
	}
	Sprite getSpriteLoadMenu()
	{
		return spriteLoadMenu;
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
	void loadMenu()
	{
		if (!isMenuLoad)
		{
			if (loadText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				loadText.setOutlineColor(Color(133, 219, 50));
				loadText.setOutlineThickness(3);
			}
			else
			{
				loadText.setOutlineThickness(0);
			}
			int timeLoad = clock.getElapsedTime().asMilliseconds() / 25;
			if (timeLoad >= 100)
			{
				loadText.setString("Ù¸ëêíèòå ìûøüþ!");
				loadText.setPosition(SCREEN_WIDTH / 2 - loadText.getGlobalBounds().width / 2, SCREEN_HEIGTH / 1.25);
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
				{
					isMenuLoad = true;
				}
			}
			else
			{
				loadBar = to_string(timeLoad);
				loadText.setString("Çàãðóçêà: " + loadBar + "%");
			}
			window.draw(spriteLoadMenu);
			window.draw(loadText);
		}
		else
		{
			renderMenu();
		}
	}
	void renderMenu()
	{
		
		if (Start.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) scene = 1;
			Start.setOutlineColor(Color(133, 219, 50));
			Start.setOutlineThickness(3);
		}
		else
		{
			Start.setOutlineThickness(0);
		}
		if (Settings.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) scene = 2;
			Settings.setOutlineColor(Color(133, 219, 50));
			Settings.setOutlineThickness(5);
		}
		else
		{
			Settings.setOutlineThickness(0);
		}
		if (Help.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) scene = 3;
			Help.setOutlineColor(Color(133, 219, 50));
			Help.setOutlineThickness(5);
		}
		else
		{
			Help.setOutlineThickness(0);
		}
		if (Exit.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) scene = 4;
			Exit.setOutlineColor(Color(133, 219, 50));
			Exit.setOutlineThickness(5);
		}
		else
		{
			Exit.setOutlineThickness(0);
		}
		window.draw(spriteMenu);
		window.draw(Start);
		window.draw(Settings);
		window.draw(Help);
		window.draw(Exit);
	}
};