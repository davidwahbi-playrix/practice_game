#include "Board.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Board::Board()
{
}

int Board::GetRowCount()
{
	return _mRowCount;
}

int Board::GetColCount()
{
	return _mColCount;
}

char Board::GetElem(const int row, const int col)
{
	CheckRow(row);
	CheckCol(col);

	return _mFields[row][col];
}

void Board::SetElem(const int row, const int col, const char elem)
{
	CheckRow(row);
	CheckCol(col);

	_mFields[row][col] = elem;
}

void Board::CheckRow(const int row)
{
	if (row < 0 || row > _mRowCount - 1)
	{
		cout << "Row out of range!";
	}
}

void Board::CheckCol(const int col)
{
	if (col < 0 || col > _mColCount)
	{
		cout << "Column out of range!";
	}
}


void Board::Load(const char * filename)
{
	ifstream src(filename);
	if (!src)
	{
		cout << "Unable to load file";
	}
	int line = 0;
	string input;

	while (src && line < _mRowCount - 1)
	{
		getline(src, input);
		if (input.size() > _mColCount)
		{
			cout << "Line > 10 chars";
		}
		for (size_t i = 0; i < input.size(); i++)
		{
			SetElem(line, i, input[i]);
		}
		line++;
	}
}

void Board::Display()
{
	for (int row = 0; row < _mRowCount - 1; row++)
	{
		for (int col = 0; col < _mColCount - 1; col++)
		{
			cout << _mFields[row][col];
		}
		cout << '\n';
	}
}

Board::~Board()
{
}
