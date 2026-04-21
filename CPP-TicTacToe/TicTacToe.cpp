#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() : m_currentPlayer('X'), m_gameOver(false)
{
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = '1' + i;
	}
}



bool TicTacToe::IsGameOver() const
{
	return m_gameOver;
}


void TicTacToe::Display() const
{
	std::cout << "\n";
	std::cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
	std::cout << "---|---|---\n";
	std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
	std::cout << "---|---|---\n";
	std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
	std::cout << "\n";

	if (m_gameOver)
	{
		if (CheckWin())
		{
			std::cout << "And Player " << m_currentPlayer << " wins!\n";
		}
		else
		{
			std::cout << "And that is a draw folks!\n";
		}
	}
}

void TicTacToe::TakeTurn()
{
	int position;
	std::cout << "Player " << m_currentPlayer << ", enter position (1-9): ";
	std::cin >> position;

	if (position < 1 || position > 9)
	{
		std::cout << "Hey man, that's an invalid position! Try again.\n";
		return;
	}


	int index = position - 1;
	


	if (!IsValidMove(index))
	{
		std::cout << "Nope! Position already taken! Try again!\n";
		return;
	}

	m_board[index] = m_currentPlayer;

	if (CheckWin() || CheckDraw())
	{
		m_gameOver = true;
	}
	else
	{
		m_currentPlayer = (m_currentPlayer == 'X') ? 'O' : 'X';
	}
}

bool TicTacToe::CheckWin() const
{
	if (m_board[0] == m_board[1] && m_board[1] == m_board[2]) return true;
	if (m_board[3] == m_board[4] && m_board[4] == m_board[5]) return true;
	if (m_board[6] == m_board[7] && m_board[7] == m_board[8]) return true;
	if (m_board[0] == m_board[3] && m_board[3] == m_board[6]) return true;
	if (m_board[1] == m_board[4] && m_board[4] == m_board[7]) return true;
	if (m_board[2] == m_board[5] && m_board[5] == m_board[8]) return true;
	if (m_board[0] == m_board[4] && m_board[4] == m_board[8]) return true;
	if (m_board[2] == m_board[4] && m_board[4] == m_board[6]) return true;
	return false;





}

bool TicTacToe::CheckDraw() const
{
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] != 'X' && m_board[i] != 'O')
			return false;
	}
	return true;
}




bool TicTacToe::IsValidMove(int index) const
{
	//int index = row * 3 + col;
	return m_board[index] != 'X' && m_board[index] != 'O';
}