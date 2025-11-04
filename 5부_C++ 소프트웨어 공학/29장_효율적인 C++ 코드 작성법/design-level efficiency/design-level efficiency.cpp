#include <iostream>
#include <vector>
#include <numeric>

// 디폴트 생성자가 있는 모든 클래스에서 사용할 수 있는 객체 풀
//
// acquireObject()는 사용 가능 상태에 있는 객체를 리턴한다.
// 사용할 객체가 남아 있지 않다면 새 인스턴스를 생성한다.
// 풀은 커지기만 할 뿐 줄어들지 않는다.
// 다시 말해 풀이 제거되기 전에는 그 안에 있는 객체를 제거하지 않는다.
// acquireObject()는 커스텀 딜리터가 있는 std::shared_ptr 객체를 리턴한다.
// 그러므로 shared_ptr이 제거될 때 레퍼런스 카운트가 0에 도달하면 자동으로 풀에 반환된다.
//
// 풀에 있는 객체의 생성자와 소멸자는 객체를 사용할 때마다 호출되지 않고,
// 풀이 생성되어 제거될 때까지 단 한 번씩만 호출된다.
// 

export template <typename T, typename Allocator = std::allocator<T>>
class ObjectPool
{
    public:
        ObjectPool() = default;
        explicit ObjectPool(const Allocator& allocator);
        virtual ~ObjectPool();

        // 이동 생성 및 이동 대입을 허용한다.
        ObjectPool(ObejctPool&& src) noexcept = default;
        ObjectPool& operator=(ObejctPool&& rhs) noexcept = default;

        // 복제 생성과 복제 대입을 막는다.
        ObjectPool(const ObjectPool& src) = delete;
        ObjectPool& operator=(const ObjectPool& rhs) = delete;

        // 사용할 객체를 풀에 보관했다가 리턴한다.
        // 인수를 지정할 수 있으며 T 생성자로 그대로 전달된다.
        template<typename ... Args>
        std::shared_ptr<T> acquireObject(Args... args);

    private:
        // T 인스턴스가 생성될 메모리 덩어리
        // 각 덩어리마다 첫 번째 객체에 대한 포인터가 저장된다.
        std::vector<T*> m_pool;
        // 풀에 있는 할당되지 않은 T 인스턴스에 대한 포인터
        std::vector<T*> m_freeObjects;
        // 첫 번째로 할당된 덩어리에 맞는 T 인스턴스 개수
        static const size_t ms_initialChunkSize{ 5 };
        // 새로 할당된 덩어리에 맞는 T 인스턴스 개수
        // 덩어리가 새로 생성될 때마다 이 값은 두 배로 증가한다.
        size_t m_newChunkSize{ ms_initialChunkSize };
        // 초기화되지 않은 메모리 블록을 새로 생성한다.
        // 크기는 T 인스턴스 m_newChunkSize개를 담을 정도로 커야 한다.
        void addChunk();
        // 덩어리 할당과 해제에 사용할 할당자
        Allocator m_allocator;
};

template <typename T, typename Allocator>
ObjectPool<T, Allocator>::ObjectPool(const Allocator& allocator)
    : m_allocator{ allocator }
{
}

template <typename T, typename Allocator>
void ObjectPool<T, Allocator>::addChunk()
{
    std::cout << "Allocating new chunk..." << std::endl;

    // 초기화되지 않은 메모리 덩어리 하나를
    // T 타입 인스턴스 m_newChunkSize개만큼 충분히 담을 수 있는 크기로 할당해서
    // 풀에 추가한다.
    auto* firstNewObject{ m_allocator.allocate(m_newChunkSize) };
    m_pool.push_back(firstNewObject);

    // 새로 만든 덩어리에 있는 각 객체에 대한 포인터를 생성해서
    // 프리 객체 리스트에 저장한다.
    auto oldFreeObjectsSize{ m_freeObjects.size() };
    m_freeObjects.resize(oldFreeObjectsSize + m_newChunkSize);
    std::iota(begin(m_freeObjects) + oldFreeObjectsSize, end(m_freeObjects),
        firstNewObject);

    // 다음번 덩어리 크기를 두 배로 늘린다.
    m_newChunkSize *= 2;
}

int main()
{
}
