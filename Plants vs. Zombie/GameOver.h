#pragma once

class GameOver
{
private:
	Texture texture;
	Sprite sprite;
	Font font;
	Text textBack;
	Texture textureWin;
	Sprite spriteWin;
	Text textWin;
public:
	GameOver()
	{
		font.loadFromFile("font.ttf");
		textBack.setFont(font);
		textBack.setFillColor(Color::Red);
		textBack.setStyle(Text::Bold);
		textBack.setScale(1.25, 1.25);
		textBack.setString("¬ Ã≈Õﬁ");
		textBack.setPosition(SCREEN_WIDTH / 2 - textBack.getGlobalBounds().width / 2, SCREEN_HEIGTH - 100);
		texture.loadFromFile("GameOver.png");
		sprite.setTexture(texture);
		sprite.setPosition(SCREEN_WIDTH / 2 - 564 / 2, 0);
		textureWin.loadFromFile("titlescreen.jpg");
		spriteWin.setTexture(textureWin);
		spriteWin.setScale(SCREEN_WIDTH / spriteWin.getLocalBounds().width, SCREEN_HEIGTH / spriteWin.getLocalBounds().height);
		textWin.setFont(font);
		textWin.setFillColor(Color::Red);
		textWin.setStyle(Text::Bold);
		textWin.setScale(2, 2);
		textWin.setString("¬€ œŒ¡≈ƒ»À»");
		textWin.setPosition(SCREEN_WIDTH / 2 - textWin.getGlobalBounds().width / 2, SCREEN_HEIGTH / 2 - textWin.getGlobalBounds().height / 2);
		textWin.setOutlineThickness(3);
		textWin.setOutlineColor(Color(133, 219, 50));
	}
	~GameOver() { };
	void loadGameOver()
	{
		if (gameOverLose)
		{
			if (textBack.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
				{
					scene = 0;
					gameOverLose = false;
					restart = true;
				}
				textBack.setOutlineColor(Color(133, 219, 50));
				textBack.setOutlineThickness(3);
			}
			else
			{
				textBack.setOutlineThickness(0);
			}
			window.clear(Color::Black);
			window.draw(sprite);
			window.draw(textBack);
		}
		if (gameOverWin)
		{
			if (textBack.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
				{
					scene = 0;
					gameOverWin = false;
					restart = true;
				}
				textBack.setOutlineColor(Color(133, 219, 50));
				textBack.setOutlineThickness(3);
			}
			else
			{
				textBack.setOutlineThickness(0);
			}
			window.draw(spriteWin);
			window.draw(textWin);
			window.draw(textBack);
		}
	}
};