#pragma once

class Plants
{
protected:
	int time, damage, health, price, attackSpeed;
	double x, y, distanceAttack;
	float frame;
	Clock clock;
	Texture texture;
	Sprite spritePlants;
public:
	int getDamage()
	{
		return damage;
	}
	int getHealth()
	{
		return health;
	}
	double getDistanceAttack()
	{
		return distanceAttack;
	}
	int getAttackSpeed()
	{
		return attackSpeed;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	Sprite getSpritePlants()
	{
		return spritePlants;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void setDamage(int damage)
	{
		this->damage = damage;
	}
	void setHealth(int health)
	{
		this->health = health;
	}
	void setDistanceAttack(double distanceAttack)
	{
		this->distanceAttack = distanceAttack;
	}
	void setAttackSpeed(int attackSpeed)
	{
		this->attackSpeed = attackSpeed;
	}
	virtual void Anim() { };
};

class Pea
{
private:
	Texture texturePea;
	Sprite spritePea;
	double x, y;
	bool isHit;
public:
	Pea(double x, double y)
	{
		isHit = false;
		texturePea.loadFromFile("Pea.png");
		spritePea.setTexture(texturePea);
		this->x = x;
		this->y = y;
		spritePea.setPosition(x + 75, y);
	}
	void setIsHit(bool isHit)
	{
		this->isHit = isHit;
	}
	bool getIsHit()
	{
		return isHit;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	Sprite getSpritePea()
	{
		return spritePea;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void Move()
	{
		x += 1.5 * frameTime * 50;
		spritePea.move(1.5 * frameTime * 50, 0);
	}
};

class Peashooter : Plants
{
private:
	list<Pea*> pea;
	list<Pea*>::iterator itPea;
	bool quit;
	bool isAttack;
	bool isIdle;
	bool isDamage;
	bool isFlicker;
	double flickerTime;
public:
	Peashooter(double x, double y)
	{
		flickerTime = 0;
		isFlicker = false;
		isIdle = false;
		isDamage = false;
		isAttack = false;
		quit = false;
		time = 2;
		frame = 0;
		this->x = x;
		this->y = y;
		damage = 25;
		health = 100;
		price = 100;
		attackSpeed = 1;
		distanceAttack = 800;
		texture.loadFromFile("Peashooter2.png");
		spritePlants.setTexture(texture);
		spritePlants.setTextureRect(IntRect(0, 0, 75, 75));
		spritePlants.setPosition(x, y);
	}
	double getFlickerTime()
	{
		return flickerTime;
	}
	void setFlickerTime(double flickerTime)
	{
		if (flickerTime < 0)
		{
			this->flickerTime = 0;
			isFlicker = true;
		}
		else this->flickerTime = flickerTime;
	}
	void setFlicker()
	{
		isFlicker = !isFlicker;
		if (isFlicker)
		{
			spritePlants.setColor(Color(255, 255, 255, 0));
		}
		else
		{
			spritePlants.setColor(Color(255, 255, 255, 255));
		}
	}
	int getHealth()
	{
		return health;
	}
	void setHealth(int health)
	{
		if (health < this->health)
		{
			setFlickerTime(500);
		}
		this->health = health;
	}
	Sprite getSpritePlants()
	{
		return spritePlants;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	void Anim()
	{
		frame += 0.05f * frameTime * 50;
		if (frame > 2) frame -= 2;
		spritePlants.setTextureRect(IntRect(75 * int(frame), 0, 75, 75));
	}
	void checkZombie(double yPlants, double yZombie, double xZombie)
	{
		if (yPlants == yZombie + 65 && xZombie <= SCREEN_WIDTH)
		{
			isAttack = true;
			isIdle = false;
		}
		else
		{
			isAttack = false;
			isIdle = true;
		}
	}
	void isCollide(Sprite s1)
	{
		for (itPea = pea.begin(); itPea != pea.end(); itPea++)
		{
			if ((*itPea)->getSpritePea().getGlobalBounds().intersects(s1.getGlobalBounds()))
			{
				(*itPea)->setIsHit(true);
			}
		}
	}
	int Attack()
	{
		for (itPea = pea.begin(); itPea != pea.end(); itPea++)
		{
			window.draw((*itPea)->getSpritePea());
		}
		if (isIdle)
		{
			for (itPea = pea.begin(); itPea != pea.end(); itPea++)
			{
				(*itPea)->Move();
				if ((*itPea)->getX() >= SCREEN_WIDTH)
				{
					pea.erase(itPea);
					itPea = pea.begin();
				}
				if (pea.size() == 0) break;
			}
		}
		if (isAttack)
		{
			if (time >= attackSpeed)
			{
				pea.push_back(new Pea(x, y));
				clock.restart();
			}
			time = clock.getElapsedTime().asMilliseconds() / 1000;
			for (itPea = pea.begin(); itPea != pea.end(); itPea++)
			{
				(*itPea)->Move();
				if ((*itPea)->getIsHit())
				{
					pea.erase(itPea);
					itPea = pea.begin();
					isDamage = true;
				}
				if (pea.size() == 0) break;
			}
		}
		if (isDamage)
		{
			isDamage = false;
			return damage;
		}
		else
		{
			isDamage = false;
			return 0;
		}
	}
};

class Sunflower : Plants
{
private:
	list<Suns*> suns;
	list<Suns*>::iterator itSuns;
	bool isClick;
	bool isFlicker;
	double flickerTime;
public:
	Sunflower(double x, double y)
	{
		flickerTime = 0;
		isFlicker = false;
		isClick = false;
		frame = 0;
		this->x = x;
		this->y = y;
		damage = 0;
		health = 100;
		price = 50;
		attackSpeed = 0;
		distanceAttack = 0;
		texture.loadFromFile("Sunflower2.png");
		spritePlants.setTexture(texture);
		spritePlants.setTextureRect(IntRect(0, 0, 66, 75));
		spritePlants.setPosition(x, y);
	}
	Sprite getSpritePlants()
	{
		return spritePlants;
	}
	int getHealth()
	{
		return health;
	}
	double getFlickerTime()
	{
		return flickerTime;
	}
	void setFlickerTime(double flickerTime)
	{
		if (flickerTime < 0)
		{
			this->flickerTime = 0;
			isFlicker = true;
		}
		else this->flickerTime = flickerTime;
	}
	void setFlicker()
	{
		isFlicker = !isFlicker;
		if (isFlicker)
		{
			spritePlants.setColor(Color(255, 255, 255, 0));
		}
		else
		{
			spritePlants.setColor(Color(255, 255, 255, 255));
		}
	}
	void setHealth(int health)
	{
		if (health < this->health)
		{
			setFlickerTime(500);
		}
		this->health = health;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	void Anim()
	{
		frame += 0.05f * frameTime * 50;
		if (frame > 2) frame -= 2;
		spritePlants.setTextureRect(IntRect(66 * int(frame), 0, 66, 75));
	}
	int checkClick()
	{
		for (itSuns = suns.begin(); itSuns != suns.end(); itSuns++)
		{
			if ((*itSuns)->getSpriteSuns().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				suns.erase(itSuns);
				itSuns = suns.begin();
				isClick = true;
				if (suns.size() == 0) break;
			}
		}
		if (isClick)
		{
			isClick = false;
			return 25;
		}
		else
		{
			isClick = false;
			return 0;
		}
	}
	void getSuns()
	{
		time = clock.getElapsedTime().asMilliseconds() / 1000;
		if (time >= 10)
		{
			suns.push_back(new Suns(x, y));
			clock.restart();
		}
		for (itSuns = suns.begin(); itSuns != suns.end(); itSuns++)
		{
			window.draw((*itSuns)->getSpriteSuns());
		}
	}
};

class Wallnut : Plants
{
private:
	bool isFlicker;
	double flickerTime;
public:
	Wallnut(double x, double y)
	{
		flickerTime = 0;
		isFlicker = false;
		frame = 0;
		this->x = x;
		this->y = y;
		damage = 0;
		health = 500;
		price = 25;
		attackSpeed = 0;
		distanceAttack = 0;
		texture.loadFromFile("Wallnut2.png");
		spritePlants.setTexture(texture);
		spritePlants.setTextureRect(IntRect(0, 0, 66, 75));
		spritePlants.setPosition(x, y);
	}
	Sprite getSpritePlants()
	{
		return spritePlants;
	}
	int getHealth()
	{
		return health;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double getFlickerTime()
	{
		return flickerTime;
	}
	void setFlickerTime(double flickerTime)
	{
		if (flickerTime < 0)
		{
			this->flickerTime = 0;
			isFlicker = true;
		}
		else this->flickerTime = flickerTime;
	}
	void setFlicker()
	{
		isFlicker = !isFlicker;
		if (isFlicker)
		{
			spritePlants.setColor(Color(255, 255, 255, 0));
		}
		else
		{
			spritePlants.setColor(Color(255, 255, 255, 255));
		}
	}
	void setHealth(int health)
	{
		if (health < this->health)
		{
			setFlickerTime(500);
		}
		this->health = health;
	}
	void Anim()
	{
		frame += 0.05f * frameTime * 50;
		if (frame > 4) frame -= 4;
		spritePlants.setTextureRect(IntRect(66 * int(frame), 0, 66, 75));
	}
};