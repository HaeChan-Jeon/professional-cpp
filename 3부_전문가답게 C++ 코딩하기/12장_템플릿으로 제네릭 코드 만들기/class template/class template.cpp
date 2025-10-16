import GameBoard;

using namespace std;

int main()
{
	GameBoard chessBoard{ 8,8 };
	auto pawn{ make_unique<ChessPiece>() };
	chessBoard.at(0, 0) = move(pawn);
	chessBoard.at(0, 1) = make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;
}