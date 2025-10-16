module;

#include <stdexcept>

export module grid;

import gamePiece;

import <vector>;
import <optional>;
import <format>;

export template <typename T = int, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid
{
public:
	Grid() = default;
	virtual ~Grid() = default;

	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	Grid(Grid&& src) = default;
	Grid<T, WIDTH, HEIGHT>& operator=(Grid&& rhs) = default;

	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid(const Grid<E, WIDTH2, HEIGHT2>& src);


	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid& operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs);

	void swap(Grid& other) noexcept;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid <E, WIDTH2, HEIGHT2>& src)
{
	for (size_t i{ 0 }; i < WIDTH; i++)	{
		for (size_t j{ 0 }; j < HEIGHT; j++) {
			if (i < WIDTH2 && j < HEIGHT2) {
				m_cells[i][j] = src.at(i, j);
			} else {
				m_cells[i][j].reset();
			}
		}
	}
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid& other) noexcept
{
	std::swap(m_cells, other.m_cells);
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
	const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
	Grid<T, WIDTH, HEIGHT> temp{ rhs };
	swap(temp);
	return *this;
}

export template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", x, WIDTH) };
	}
	if (y >= HEIGHT) {
		throw std::out_of_range{
			std::format("{} must be less than {}.", y, HEIGHT) };
	}
}

export template <typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

export template <typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}