#pragma once

class Zombie
{
private:
	int damage, health, attackSpeed, zombieLine, countSuns, time;
	double x, y, speed, distanceAttack;
	float frame;
	Texture texture;
	Sprite spriteZombie;
	Clock clock;
	Sound soundAttack;
	SoundBuffer soundBuffer;
	bool isMove;
	bool isAttack;
	bool isDamage;
	bool isFlicker;
	bool isGameOver;
	double flickerTime;
public:
	Zombie()
	{
		isGameOver = false;
		flickerTime = 0;
		isFlicker = false;
		soundBuffer.loadFromFile("chomp.wav");
		soundAttack.setBuffer(soundBuffer);
		soundAttack.setVolume(0);
		isDamage = false;
		isMove = true;
		isAttack = false;
		countSuns = 25;
		frame = 0;
		damage = 20;
		health = 300;
		time = 4;
		attackSpeed = 1;
		zombieLine = rand() % (5 - 1) + 1;
		x = rand() % (1400 - 1024) + 1024;
		//y = rand() % ((SCREEN_HEIGTH - 200) - 0) + 0;
		y = zombieLine * 100 + 95 - 65;
		speed = 3;
		distanceAttack = 1;
		texture.loadFromFile("Zombie.png");
		spriteZombie.setTexture(texture);
		spriteZombie.setTextureRect(IntRect(0, 0, 81, 130));
		spriteZombie.setPosition(x, y);
	}
	int getCountSunsZombie()
	{
		return countSuns;
	}
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
	double getSpeed()
	{
		return speed;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	bool getIsAttack()
	{
		return isAttack;
	}
	bool getIsMove()
	{
		return isMove;
	}
	Sprite getSpriteZombie()
	{
		return spriteZombie;
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
			spriteZombie.setColor(Color(255, 255, 255, 0));
		}
		else
		{
			spriteZombie.setColor(Color(255, 255, 255, 255));
		}
	}
	void setCountSunsZombie(int countSuns)
	{
		this->countSuns = countSuns;
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
		if (health < this->health)
		{
			setFlickerTime(500);
		}
		this->health = health;
	}
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
	void setIsAttack(bool isAttack)
	{
		this->isAttack = isAttack;
	}
	void setIsMove(bool isMove)
	{
		this->isMove = isMove;
	}
	void setDistanceAttack(double distanceAttack)
	{
		this->distanceAttack = distanceAttack;
	}
	void setAttackSpeed(int attackSpeed)
	{
		this->attackSpeed = attackSpeed;
	}
	void setPosition(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	int Attack()
	{
		if (isAttack)
		{
			if (time >= attackSpeed)
			{
				isDamage = true;
				clock.restart();
			}
			time = clock.getElapsedTime().asMilliseconds() / 1000;
		}
		if (isDamage)
		{
			isDamage = false;
			soundAttack.setVolume(soundVolume);
			soundAttack.play();
			return 20;
		}
		else
		{
			isDamage = false;
			return 0;
		}
	}
	bool getIsGameOver()
	{
		return isGameOver;
	}
	bool checkGameOver()
	{
		return x <= 255 - 130;
	}
	void Move()
	{
		if (isMove)
		{
			frame += 0.05f * frameTime * 50;
			if (frame > 2) frame -= 2;
			spriteZombie.setTextureRect(IntRect(81 * int(frame) + 2, 0, 81, 130));
			this->x = x - 0.25 * 50 * frameTime;
			spriteZombie.move(-0.25 * 50 * frameTime, 0);
		}
	}
};