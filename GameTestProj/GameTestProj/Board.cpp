#include "Board.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Board::Board()
{
}

int Board::GetRowCount2() const
{
	return _mRowCount2;
}

int Board::GetColCount2() const
{
	return _mColCount2;
}

char Board::GetElem3(const int row, const int col) const
{
	CheckRow3(row);
	CheckCol3(col);

	return _mFields3[row][col];
}

void Board::SetElem3(const int row, const int col, const char & elem)
{
	CheckRow3(row);
	CheckCol3(col);

	_mFields3[row][col] = elem;
}

void Board::CheckRow3(const int row) const
{
	if (row < 0 || row > _mRowCount2 - 1)
	{
		cout << "Row out of range!";
	}
}

void Board::CheckCol3(const int col) const
{
	if (col < 0 || col > _mColCount2)
	{
		cout << "Column out of range!";
	}
}

void Board::ClearBoard()
{
	for (size_t i = 1; i < _mRowCount2 - 2; i++)
	{
		for (size_t j = 1; j < _mColCount2 - 2; j++)
		{
			if (GetElem3(i, j) != 'R')
			{
				SetElem3(i, j, ' ');
			}
		}
	}
}

void Board::InitBoard(const int numRow, const int numCol)
{
	_mRowCount2 = numRow;
	_mColCount2 = numCol;
}

void Board::operator=(const Board& other)
{
	_mFields3 = other._mFields3;
}

void Board::Load2(string filename)
{
	ifstream src(filename);
	if (!src)
	{
		cout << "Unable to load file";
	}
	int line = 0;
	string input;

	while (src && line < _mRowCount2 - 1)
	{
		getline(src, input);
		if (input.size() > _mColCount2)
		{
			cout << "Line larger then column size";
		}
		_mFields3.emplace(_mFields3.begin() + line, input);
		line++;
	}
}

void Board::Display2()
{
	for (int row = 0; row < _mRowCount2 - 1; row++)
	{
		cout << _mFields3[row];
		cout << '\n';
	}
}

Board::~Board()
{
}
