#include "Board.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Board::Board()
{
}

int Board::GetRowCount() const
{
	return this->_mRowCount;
}

int Board::GetColCount() const
{
	return this->_mColCount;
}

char Board::GetElem(const int row, const int col) const
{
	CheckRow(row);
	CheckCol(col);

	return this->_mFields[row][col];
}

void Board::SetElem(const int row, const int col, const char& elem)
{
	CheckRow(row);
	CheckCol(col);

	this->_mFields[row][col] = elem;
}

void Board::CheckRow(const int row) const
{
	if (row < 0 || row > _mRowCount - 1)
	{
		cout << "Row out of range!";
	}
}

void Board::CheckCol(const int col) const
{
	if (col < 0 || col > this->_mColCount)
	{
		cout << "Column out of range!";
	}
}

void Board::ClearBoard()
{
	for (size_t i = 1; i < this->_mRowCount - 2; i++)
	{
		for (size_t j = 1; j < this->_mColCount - 2; j++)
		{
			if (this->GetElem(i, j) != 'R')
			{
				this->SetElem(i, j, ' ');
			}
		}
	}
}

void Board::operator=(const Board& other)
{
	for (size_t i = 0; i < this->_mRowCount - 1; i++)
	{
		for (size_t j = 0; j < this->_mColCount - 1; j++)
		{
			this->_mFields[i][j] = other._mFields[i][j];
		}
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

	while (src && line < this->_mRowCount - 1)
	{
		getline(src, input);
		if (input.size() > this->_mColCount)
		{
			cout << "Line > 18 chars";
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
			cout << this->_mFields[row][col];
		}
		cout << '\n';
	}
}

Board::~Board()
{
}
