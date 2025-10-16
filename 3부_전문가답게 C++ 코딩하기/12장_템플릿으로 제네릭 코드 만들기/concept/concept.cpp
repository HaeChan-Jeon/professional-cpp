#include <concepts>
#include <string>

// 단순 요구사항
template <typename T>
concept Incrementable = requires(T x) { x++, ++x; };

// 복합 요구사항
template <typename T>
concept C = requires (T x, T y) {
	{ x.swap(y) } noexcept;
};

// 타입 제약 조건
template <typename T>
concept D = requires (const T x) {
	{ x.size() } -> std::convertible_to<size_t>;
};

template <typename T>
concept E = requires (T t) {
	requires sizeof(t) == 4;
	++t; --t, t++, t--;
};

// 콘셉트 표현식 조합하기
template <typename T>
concept IncrementableAndC = Incrementable<T> && C<T>;

// 타입 제약 조건과 함수 템플릿
template <std::convertible_to<bool> T>
void handle(const T& t);

template <Incrementable T>
void Process(const T& t)
{
};

//template <typename T> requires Incrementable<T>
//template <typename T> requires std::convertible_to<T, bool>
//template <typename T> requires requires<T, x> { x++; ++x; };
//template <typename T> requires (sizeof(T) == 4)
//...

// 깔끔한 버전
void process2(const Incrementable auto& t);

int main()
{
	Process(1);
	//std::string test = "s";
	//Process(test); // 오류 발생
	Incrementable auto value1{ 1 };
}