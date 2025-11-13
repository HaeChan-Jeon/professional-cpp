export module simple;

// 클래스 정의 문법을 보여주기 위해 간단히 작성한 클래스
export class Simple
{
	public:
		Simple();								// 생성자
		virtual ~Simple() = default;			// 디폴트로 지정한 가상 소멸자

		// 대입과 값 전달 방식 허용하지 않기
		Simple(const Simple& src) = delete;
		Simple& operator=(const Simple& rhs) = delete;

		// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정하기
		Simple(Simple&& src) noexcept = default;
		Simple& operator=(Simple&& rhs) noexcept = default;

		virtual void publicMethod();			// public 메서드
		int m_publicInteger;					// public 데이터 멤버

	protected:
		virtual void protectedMethod();			// protected 메서드
		int m_protectedInteger { 41 };			// protected 데이터 멤버

	private:
		virtual void privateMethod();			// private 메서드
		int m_privateInteger { 42 };			// private 데이터 멤버
		static const int Constant { 2 };		// private 상수
		static inline int ms_staticInt { 3 };	// private static 데이터 멤버
};