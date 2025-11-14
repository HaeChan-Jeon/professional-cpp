export module derived_simple;

export import simple;

// Simple 클래스를 상속하는 클래스
export class DerivedSimple : public Simple
{
public:
	DerivedSimple() : Simple()
	{ /* 생성자 구현 코드 */ }

	void publicMethod() override // 오버라이드한 메서드
	{
		// 오버라이드한 메서드의 구현 코드
		Simple::publicMethod(); // 베이스 클래스 구현에 접근 가능
	}

	virtual void anotherMethod() // 새로 추가한 메서드
	{ /* 새로운 메서드 구현 코드 */ }
};