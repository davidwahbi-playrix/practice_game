#pragma once
class Board
{
public:
	Board();
	int GetRowCount() const;
	int GetColCount() const;
	char GetElem(const int row, const int col) const;
	void SetElem(const int row, const int col, const char& elem);

	void CheckRow(const int row) const;
	void CheckCol(const int col) const;

	void ClearBoard();

	void operator = (const Board& other);

	void Load(const char* filename);
	void Display();
	~Board();
private:
	static const int _mRowCount = 10;
	static const int _mColCount = 50;
	char _mFields[_mRowCount][_mColCount];
};

