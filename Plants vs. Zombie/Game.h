#pragma once

class Game
{
private:
	bool isMove;
	bool quit;
	int time;
	int timeZombie;
	float timeStart;
	double x, y, width, heigth;
	bool isGameOver;
	Texture texture;
	Sprite background;
	Clock clock;
	Clock clockZombie;
	Clock clockStart;
	Camera camera;
	list<Zombie*> zombie;
	list<Zombie*>::iterator it;
	PlantsBar plantsBar;
	ProgressBar progressBar;
	list<Suns*> suns;
	list<Suns*>::iterator itSuns;
	list<Peashooter*> peashooter;
	list<Peashooter*>::iterator itPeashooter;
	list<Sunflower*> sunflower;
	list<Sunflower*>::iterator itSunflower;
	list<Wallnut*> wallnut;
	list<Wallnut*>::iterator itWallnut;
	list<LawnMower*> lawnMower;
	list<LawnMower*>::iterator itLawnMower;
	Texture textureStartSet;
	Texture textureStartReady;
	Texture textureStartPlant;
	Sprite spriteStartSet;
	Sprite spriteStartReady;
	Sprite spriteStartPlant;
	int key;
	bool isStart;
	bool quitPB;
public:
	Game()
	{
		quitPB = false;
		isStart = true;
		key = 0;
		textureStartSet.loadFromFile("StartSet.png");
		spriteStartSet.setTexture(textureStartSet);
		spriteStartSet.setPosition(SCREEN_WIDTH / 2 - 345 / 2, SCREEN_HEIGTH / 2 - 132 / 2);
		textureStartReady.loadFromFile("StartReady.png");
		spriteStartReady.setTexture(textureStartReady);
		spriteStartReady.setPosition(SCREEN_WIDTH / 2 - 300 / 2, SCREEN_HEIGTH / 2 - 133 / 2);
		textureStartPlant.loadFromFile("StartPlant.png");
		spriteStartPlant.setTexture(textureStartPlant);
		spriteStartPlant.setPosition(SCREEN_WIDTH / 2 - 300 / 2, SCREEN_HEIGTH / 2 - 133 / 2);
		isGameOver = false;
		isMove = false;
		time = 0;
		timeZombie = 0;
		timeStart = 0;
		quit = false;
		for (int i = 0; i < 2; i++)
		{
			zombie.push_back(new Zombie);
		}
		for (it = zombie.begin(); it != zombie.end(); it++)
		{
			window.draw((*it)->getSpriteZombie());
		}
		for (int i = 0; i < 5; i++)
		{
			lawnMower.push_back(new LawnMower(255 - 82, 100 * i + 95));
		}
		x = SCREEN_WIDTH / 2;
		y = SCREEN_HEIGTH / 2;
		width = SCREEN_WIDTH;
		heigth = SCREEN_HEIGTH;
		texture.loadFromFile("background.jpg");
		background.setTexture(texture);
		background.setScale(1, 1);
	}
	~Game() { };
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
	bool isCollide(Sprite s1, Sprite s2)
	{
		return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
		
	}
	void loadGame()
	{
		window.draw(background);
		if (!camera.getQuit())
		{
			camera.Move();
			for (it = zombie.begin(); it != zombie.end(); it++)
			{
				window.draw((*it)->getSpriteZombie());
			}
			clock.restart();
			clockZombie.restart();
			clockStart.restart();
		}
		else
		{
			if (!isGameOver)
			{
				if (isStart)
				{
					timeStart = clockStart.getElapsedTime().asMilliseconds();
					if (timeStart >= 0 && timeStart <= 700)
					{
						window.draw(spriteStartSet);
						plantsBar.getPlantsBar();
						progressBar.getProgressBar();
						for (itLawnMower = lawnMower.begin(); itLawnMower != lawnMower.end(); itLawnMower++)
						{
							(*itLawnMower)->clearTrash();
							window.draw((*itLawnMower)->getSpriteLawnMower());
						}
					}
					if (timeStart >= 700 && timeStart <= 1400)
					{
						window.draw(spriteStartReady);
						plantsBar.getPlantsBar();
						progressBar.getProgressBar();
						for (itLawnMower = lawnMower.begin(); itLawnMower != lawnMower.end(); itLawnMower++)
						{
							(*itLawnMower)->clearTrash();
							window.draw((*itLawnMower)->getSpriteLawnMower());
						}
					}
					if (timeStart >= 1400 && timeStart <= 2100)
					{
						window.draw(spriteStartPlant);
						plantsBar.getPlantsBar();
						progressBar.getProgressBar();
						for (itLawnMower = lawnMower.begin(); itLawnMower != lawnMower.end(); itLawnMower++)
						{
							(*itLawnMower)->clearTrash();
							window.draw((*itLawnMower)->getSpriteLawnMower());
						}
					}
					if (timeStart >= 2300) isStart = false;
				}
				else
				{
					if (progressBar.getLVL() >= 150 && !quitPB)
					{
						for (int i = 0; i < 10; i++)
						{
							zombie.push_back(new Zombie);
						}
						quitPB = true;
					}
					plantsBar.getPlantsBar();
					progressBar.getProgressBar();
					time = clock.getElapsedTime().asMilliseconds() / 1000;
					timeZombie = clockZombie.getElapsedTime().asMilliseconds() / 1000;
					if (time % 10 == 0 && time != 0)
					{
						clock.restart();
						suns.push_back(new Suns);
					}
					if (timeZombie % 9 == 0 && timeZombie != 0 && !quitPB)
					{
						clockZombie.restart();
						zombie.push_back(new Zombie);
					}
					if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
						scene = 5;
					}
					if (event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left)
					{
						if (plantsBar.getSpriteWallnut().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && plantsBar.getIsWallnutActive())
						{
							plantsBar.setSelectType(2);
							isMove = true;
						}
						else if (plantsBar.getSpriteSunflower().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && plantsBar.getIsSunflowerActive())
						{
							plantsBar.setSelectType(1);
							isMove = true;
						}
						else if (plantsBar.getSpritePeashooter().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && plantsBar.getIsPeashooterActive())
						{
							plantsBar.setSelectType(0);
							isMove = true;
						}
					}
					if (plantsBar.getSelectType() != -1 && isMove)
					{
						Vector2i pixelPos = Mouse::getPosition(window);
						Vector2f pos = window.mapPixelToCoords(pixelPos);
						plantsBar.setPosition(pixelPos.x, pixelPos.y);
						if (pos.x > tileMap[0][0] && pos.x < tileMap[44][0] + 80 && pos.y > tileMap[0][1] && pos.y < tileMap[44][1] + 100)
						{
							int nearestTileMap = -1;
							double minNearestDistance = 9999.0f;
							double nearestDistance = 99999.0f;
							for (int i = 0; i < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; i++)
							{
								nearestDistance = sqrt(pow(pos.x - tileMap[i][0], 2) + pow(pos.y - tileMap[i][1], 2));
								if (minNearestDistance > nearestDistance)
								{
									nearestTileMap = i;
									minNearestDistance = nearestDistance;
								}
							}
							if (nearestTileMap != -1 && tileMapCollision[nearestTileMap] == false)
							{
								Texture t;
								Sprite s;
								t.loadFromFile(plantsBar.getSelectTypeImg(plantsBar.getSelectType()));
								s.setTexture(t);
								if (plantsBar.getSelectType() == 0)
								{
									s.setTextureRect(IntRect(0, 0, 75, 75));
								}
								if (plantsBar.getSelectType() == 1)
								{
									s.setTextureRect(IntRect(0, 0, 66, 75));
								}
								if (plantsBar.getSelectType() == 2)
								{
									s.setTextureRect(IntRect(0, 0, 66, 75));
								}
								s.setPosition(tileMap[nearestTileMap][0], tileMap[nearestTileMap][1]);
								s.setColor(Color(255, 255, 255, 150));
								window.draw(s);
								if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
								{
									if (plantsBar.getSelectType() == 0)
									{
										peashooter.push_back(new Peashooter(tileMap[nearestTileMap][0], tileMap[nearestTileMap][1]));
										tileMapCollision[nearestTileMap] = true;
										plantsBar.setCount(plantsBar.getCount() - 100);
									}
									else if (plantsBar.getSelectType() == 1)
									{
										sunflower.push_back(new Sunflower(tileMap[nearestTileMap][0], tileMap[nearestTileMap][1]));
										tileMapCollision[nearestTileMap] = true;
										plantsBar.setCount(plantsBar.getCount() - 50);
									}
									else if (plantsBar.getSelectType() == 2)
									{
										wallnut.push_back(new Wallnut(tileMap[nearestTileMap][0], tileMap[nearestTileMap][1]));
										tileMapCollision[nearestTileMap] = true;
										plantsBar.setCount(plantsBar.getCount() - 25);
									}
									plantsBar.setSelectType(-1);
									isMove = false;
								}
							}
						}
						else
						{
							if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
							{
								plantsBar.setSelectType(-1);
								isMove = false;
							}
						}
					}
					for (itPeashooter = peashooter.begin(); itPeashooter != peashooter.end(); itPeashooter++)
					{
						(*itPeashooter)->Anim();
						for (it = zombie.begin(); it != zombie.end(); it++)
						{
							(*itPeashooter)->checkZombie((*itPeashooter)->getY(), (*it)->getY(), (*it)->getX());
							(*itPeashooter)->isCollide((*it)->getSpriteZombie()); //
							(*it)->setHealth((*it)->getHealth() - (*itPeashooter)->Attack());
						}
						if ((*itPeashooter)->getHealth() == 0)
						{
							int x, y, count = 0;
							x = (*itPeashooter)->getX();
							y = (*itPeashooter)->getY();
							x -= 255;
							y -= 95;
							count = (y / 100) * 9 + x / 80;
							tileMapCollision[count] = false;
							peashooter.erase(itPeashooter);
							itPeashooter = peashooter.begin();
						}
						if (peashooter.size() == 0) break;
					}
					for (itSunflower = sunflower.begin(); itSunflower != sunflower.end(); itSunflower++)
					{
						(*itSunflower)->Anim();
						if ((*itSunflower)->getHealth() == 0)
						{
							int x, y, count = 0;
							x = (*itSunflower)->getX();
							y = (*itSunflower)->getY();
							x -= 255;
							y -= 95;
							count = (y / 100) * 9 + x / 80;
							tileMapCollision[count] = false;
							sunflower.erase(itSunflower);
							itSunflower = sunflower.begin();
						}
						if (sunflower.size() == 0) break;
					}
					for (itWallnut = wallnut.begin(); itWallnut != wallnut.end(); itWallnut++)
					{
						(*itWallnut)->Anim();
						if ((*itWallnut)->getHealth() == 0)
						{
							int x, y, count = 0;
							x = (*itWallnut)->getX();
							y = (*itWallnut)->getY();
							x -= 255;
							y -= 95;
							count = (y / 100) * 9 + x / 80;
							tileMapCollision[count] = false;
							wallnut.erase(itWallnut);
							itWallnut = wallnut.begin();
						}
						if (wallnut.size() == 0) break;
					}
					for (itPeashooter = peashooter.begin(); itPeashooter != peashooter.end(); itPeashooter++)
					{
						for (it = zombie.begin(); it != zombie.end(); it++)
						{
							if (isCollide((*it)->getSpriteZombie(), (*itPeashooter)->getSpritePlants()) && (*it)->getY() + 65 == ((*itPeashooter)->getY()))
							{
								(*it)->setIsAttack(true);
								(*it)->setIsMove(false);
								(*itPeashooter)->setHealth((*itPeashooter)->getHealth() - (*it)->Attack());
								if ((*itPeashooter)->getHealth() <= 0)
								{
									(*it)->setIsAttack(false);
									(*it)->setIsMove(true);
								}
							}
						}
					}
					for (it = zombie.begin(); it != zombie.end(); it++)
					{
						for (itSunflower = sunflower.begin(); itSunflower != sunflower.end(); itSunflower++)
						{
							if (isCollide((*it)->getSpriteZombie(), (*itSunflower)->getSpritePlants()) && (*it)->getY() + 65 == ((*itSunflower)->getY()))
							{
								(*it)->setIsAttack(true);
								(*it)->setIsMove(false);
								(*itSunflower)->setHealth((*itSunflower)->getHealth() - (*it)->Attack());
								if ((*itSunflower)->getHealth() <= 0)
								{
									(*it)->setIsAttack(false);
									(*it)->setIsMove(true);
								}
							}
						}
						for (itWallnut = wallnut.begin(); itWallnut != wallnut.end(); itWallnut++)
						{
							if (isCollide((*it)->getSpriteZombie(), (*itWallnut)->getSpritePlants()) && (*it)->getY() + 65 == ((*itWallnut)->getY()))
							{
								(*it)->setIsAttack(true);
								(*it)->setIsMove(false);
								(*itWallnut)->setHealth((*itWallnut)->getHealth() - (*it)->Attack());
								if ((*itWallnut)->getHealth() <= 0)
								{
									(*it)->setIsAttack(false);
									(*it)->setIsMove(true);
								}
							}
						}
						for (itLawnMower = lawnMower.begin(); itLawnMower != lawnMower.end(); itLawnMower++)
						{
							if (isCollide((*it)->getSpriteZombie(), (*itLawnMower)->getSpriteLawnMower()) && (*it)->getY() + 65 == ((*itLawnMower)->getY()))
							{
								(*it)->setHealth(0);
							}
							if (isCollide((*it)->getSpriteZombie(), (*itLawnMower)->getSpriteLawnMower()) && (*it)->getY() + 65 == ((*itLawnMower)->getY()))
							{
								(*itLawnMower)->setIsClearTrash(true);
							}
							if (zombie.size() == 0) break;
						}
						(*it)->Move();
						if ((*it)->getHealth() <= 0)
						{
							plantsBar.setCount(plantsBar.getCount() + (*it)->getCountSunsZombie());
							progressBar.Move(10);
							zombie.erase(it);
							it = zombie.begin();
						}
						if (zombie.size() == 0) break;
					}
					for (itSuns = suns.begin(); itSuns != suns.end(); itSuns++)
					{
						(*itSuns)->checkSuns();
						if ((*itSuns)->getSpriteSuns().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
						{
							plantsBar.setCount(plantsBar.getCount() + (*itSuns)->getCountSuns());
							suns.erase(itSuns);
							itSuns = suns.begin();
						}
						if (suns.size() == 0) break;
					}
				}
				for (itSuns = suns.begin(); itSuns != suns.end(); itSuns++)
				{
					window.draw((*itSuns)->getSpriteSuns());
				}
				for (itPeashooter = peashooter.begin(); itPeashooter != peashooter.end(); itPeashooter++)
				{
					if ((*itPeashooter)->getFlickerTime() > 0)
					{
						(*itPeashooter)->setFlickerTime((*itPeashooter)->getFlickerTime() - frameTime * 1000);
						(*itPeashooter)->setFlicker();
					}
					window.draw((*itPeashooter)->getSpritePlants());
				}
				for (itSunflower = sunflower.begin(); itSunflower != sunflower.end(); itSunflower++)
				{
					if ((*itSunflower)->getFlickerTime() > 0)
					{
						(*itSunflower)->setFlickerTime((*itSunflower)->getFlickerTime() - frameTime * 1000);
						(*itSunflower)->setFlicker();
					}
					window.draw((*itSunflower)->getSpritePlants());
					(*itSunflower)->getSuns();
					plantsBar.setCount(plantsBar.getCount() + (*itSunflower)->checkClick());
				}
				for (itWallnut = wallnut.begin(); itWallnut != wallnut.end(); itWallnut++)
				{
					if ((*itWallnut)->getFlickerTime() > 0)
					{
						(*itWallnut)->setFlickerTime((*itWallnut)->getFlickerTime() - frameTime * 1000);
						(*itWallnut)->setFlicker();
					}
					window.draw((*itWallnut)->getSpritePlants());
				}
				for (itLawnMower = lawnMower.begin(); itLawnMower != lawnMower.end(); itLawnMower++)
				{
					(*itLawnMower)->clearTrash();
					window.draw((*itLawnMower)->getSpriteLawnMower());
				}
				for (it = zombie.begin(); it != zombie.end(); it++)
				{
					gameOverLose = (*it)->checkGameOver();
					if (gameOverLose)
					{
						scene = 6;
						break;
					}
					if ((*it)->getFlickerTime() > 0)
					{
						(*it)->setFlickerTime((*it)->getFlickerTime() - frameTime * 1000);
						(*it)->setFlicker();
					}
					window.draw((*it)->getSpriteZombie());
				}
				if (plantsBar.getSelectType() != -1)
				{
					window.draw(plantsBar.getSpriteTemp());
				}
				if (quitPB && zombie.size() == 0)
				{
					gameOverWin = true;
					scene = 6;
				}
			}
		}
	}
};