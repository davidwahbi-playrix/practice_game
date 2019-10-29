#pragma once
class MovableObject
{
public:
	MovableObject();
	MovableObject(const int x, const int y);
	int GetPosX();
	int GetPosY();
	void SetPosX(int x);
	void SetPosY(int y);

	void CheckPosX(const int x);
	void CheckPosY(const int y);
	virtual void MoveObject(int vertical, int horizontal) = 0;
	virtual ~MovableObject();
private:
	int _posX;
	int _posY;
};

