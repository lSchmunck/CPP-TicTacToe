#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:
	char m_board[9];
	char m_currentPlayer;
	bool m_gameOver;

	bool CheckWin() const;
	bool CheckDraw() const;
	bool IsValidMove(int index) const;

public:
	TicTacToe();
	
	bool IsGameOver() const override;
	void TakeTurn() override;
	void Display() const override;
};