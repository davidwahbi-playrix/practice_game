#pragma once
#include <vector>
class Board
{
public:
	Board();
	~Board();
	int GetRowCount2() const;
	int GetColCount2() const;

	char GetElem2(const int row, const int col) const;
	void SetElem2(const int row, const int col, const char& elem);

	void CheckRow2(const int row) const;
	void CheckCol2(const int col) const;

	void ClearBoard();
	void InitBoard(const int numRow, const int numCol);
	void operator = (const Board& other);

	void Load2(std::string filename);
	void Display2();

private:
	int _mRowCount2 = 0;
	int _mColCount2 = 0;
	std::vector<std::vector<char>> _mFields2;
};

