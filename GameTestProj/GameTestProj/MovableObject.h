#pragma once
class MovableObject
{
private:
	//static int id;
	int _posX;
	int _posY;
	int _health;
	int _damage;
public:
	MovableObject();
	MovableObject(const int x, const int y, int health, int damage);
	int GetPosX();
	int GetPosY();
	void SetPosX(int x);
	void SetPosY(int y);

	int GetHealth();
	int GetDamage();
	void SetHealth(int health);
	void SetDamage(int damage);

	void CheckPosX(const int x);
	void CheckPosY(const int y);
    virtual void MoveObject(int vertical, int horizontal)=0;
	virtual ~MovableObject();
};

