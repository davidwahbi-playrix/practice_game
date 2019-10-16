#pragma once
class Board
{
private:
	static const int _mRowCount = 7;
	static const int _mColCount = 11;
	char _mFields[_mRowCount][_mColCount];
public:
	Board();
	int GetRowCount();
	int GetColCount();
	char GetElem(const int row, const int col);
	void SetElem(const int row, const int col, const char elem);

	void CheckRow(const int row);
	void CheckCol(const int col);

	void Load(const char *filename);
	void Display();
	~Board();
};

