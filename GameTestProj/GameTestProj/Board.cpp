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
	return this->_mRowCount2;
}

int Board::GetColCount2() const
{
	return this->_mColCount2;
}

char Board::GetElem2(const int row, const int col) const
{
	CheckRow2(row);
	CheckCol2(col);

	return this->_mFields2[row][col];
}

void Board::SetElem2(const int row, const int col, const char & elem)
{
	CheckRow2(row);
	CheckCol2(col);
	this->_mFields2[row].erase(this->_mFields2[row].begin() + col);
	this->_mFields2[row].insert(this->_mFields2[row].begin() + col, elem);
}

void Board::CheckRow2(const int row) const
{
	if (row < 0 || row > _mRowCount2 - 1)
	{
		cout << "Row out of range!";
	}
}

void Board::CheckCol2(const int col) const
{
	if (col < 0 || col > this->_mColCount2)
	{
		cout << "Column out of range!";
	}
}

void Board::ClearBoard()
{
	for (size_t i = 1; i < this->_mRowCount2 - 2; i++)
	{
		for (size_t j = 1; j < this->_mColCount2 - 2; j++)
		{
			if (this->GetElem2(i, j) != 'R')
			{
				this->SetElem2(i, j, ' ');
			}
		}
	}
}

void Board::InitBoard(const int numRow, const int numCol)
{
	std::vector<std::vector<char>> tmpVector(numRow, vector<char>(numCol));
	this->_mFields2 = tmpVector;
	this->_mRowCount2 = numRow;
	this->_mColCount2 = numCol;
}

void Board::operator=(const Board& other)
{
	for (size_t i = 0; i < this->_mRowCount2 - 1; i++)
	{
		for (size_t j = 0; j < this->_mColCount2 - 1; j++)
		{
			this->_mFields2[i][j] = other._mFields2[i][j];
		}
	}
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

	while (src && line < this->_mRowCount2 - 1)
	{
		getline(src, input);
		if (input.size() > this->_mColCount2)
		{
			cout << "Line larger then column size";
		}
		for (size_t i = 0; i < input.size(); i++)
		{
			SetElem2(line, i, input[i]);
		}
		line++;
	}
}

void Board::Display2()
{
	for (int row = 0; row < _mRowCount2 - 1; row++)
	{
		for (int col = 0; col < _mColCount2 - 1; col++)
		{
			cout << this->_mFields2[row][col];
		}
		cout << '\n';
	}
}

Board::~Board()
{
}
