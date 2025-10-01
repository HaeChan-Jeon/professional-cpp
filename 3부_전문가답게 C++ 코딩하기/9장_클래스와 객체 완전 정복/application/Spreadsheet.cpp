module;
#include <cstddef>

module spreadsheet;

import <utility>;
import <stdexcept>;
import <format>;
import <algorithm>;

using namespace std;

// Impl 정의
class Spreadsheet::Impl {
public:
    Impl(const SpreadsheetApplication& theApp, size_t width, size_t height)
        : m_id{ ms_counter++ }
        , m_width{ min(width, Spreadsheet::MaxWidth) }
        , m_height{ min(height, Spreadsheet::MaxHeight) }
        , m_theApp{ theApp }
    {
        m_cells = new SpreadsheetCell * [m_width];
        for (size_t i{ 0 }; i < m_width; i++) {
            m_cells[i] = new SpreadsheetCell[m_height];
        }
    }

    Impl(const Impl& src)
        : m_id{ ms_counter++ }
        , m_width{ src.m_width }
        , m_height{ src.m_height }
        , m_theApp{ src.m_theApp }
    {
        m_cells = new SpreadsheetCell * [m_width];
        for (size_t i{ 0 }; i < m_width; i++) {
            m_cells[i] = new SpreadsheetCell[m_height];
            for (size_t j{ 0 }; j < m_height; j++) {
                m_cells[i][j] = src.m_cells[i][j];
            }
        }
    }

    ~Impl() {
        for (size_t i{ 0 }; i < m_width; i++) {
            delete[] m_cells[i];
        }
        delete[] m_cells;
    }

    void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) {
        if (x >= m_width || y >= m_height) {
            throw out_of_range{ format("({}, {}) out of range", x, y) };
        }
        m_cells[x][y] = cell;
    }

    SpreadsheetCell& getCellAt(size_t x, size_t y) {
        if (x >= m_width || y >= m_height) {
            throw out_of_range{ format("({}, {}) out of range", x, y) };
        }
        return m_cells[x][y];
    }

    size_t getId() const { return m_id; }

private:
    static inline size_t ms_counter{ 0 };
    const size_t m_id;
    size_t m_width;
    size_t m_height;
    SpreadsheetCell** m_cells{ nullptr };
    const SpreadsheetApplication& m_theApp;
};

// 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& other) noexcept = default;

// 이동 대입 연산자
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
    this->swap(rhs);
    return *this;
}

// 복사 생성자
Spreadsheet::Spreadsheet(const Spreadsheet& src) {
    m_impl = std::make_unique<Impl>(*src.m_impl);
}

// 복사 대입 연산자
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
    if (this != &rhs) {
        m_impl = std::make_unique<Impl>(*rhs.m_impl);
    }
    return *this;
}

// 생성자
Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp,
    size_t width, size_t height) {
    m_impl = std::make_unique<Impl>(theApp, width, height);
}

// 멤버 함수들
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) {
    m_impl->setCellAt(x, y, cell);
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) {
    return m_impl->getCellAt(x, y);
}

size_t Spreadsheet::getId() const {
    return m_impl->getId();
}

// swap 멤버
void Spreadsheet::swap(Spreadsheet& other) noexcept {
    std::swap(m_impl, other.m_impl);
}

// 전역 swap
void swap(Spreadsheet& first, Spreadsheet& second) noexcept {
    first.swap(second);
}

// 소멸자
Spreadsheet::~Spreadsheet() = default;
