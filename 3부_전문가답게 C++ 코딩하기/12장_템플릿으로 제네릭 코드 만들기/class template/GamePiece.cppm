export module gamePiece;

import <memory>;

export class GamePiece
{
public:
	virtual ~GamePiece() = default;
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};

export class ChessPiece : public GamePiece
{
public:
	std::unique_ptr<GamePiece> clone() const override
	{
		return std::make_unique<ChessPiece>(*this);
	}
};