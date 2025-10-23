#include <iostream>
#include <format>
#include <stack>

class Error final
{
public:
    Error(int priority, std::string errorString)
        : m_priority{ priority }, m_errorString{ std::move(errorString) } {
    }
    int getPriority() const { return m_priority; }
    const std::string& getErrorString() const { return m_errorString; }
    auto operator<=>(const Error& rhs) const {
        return getPriority() <=> rhs.getPriority();
    }
private:
    int m_priority;
    std::string m_errorString;
};

std::ostream& operator<<(std::ostream& os, const Error& err)
{
    os << std::format("{} (priority {})", err.getErrorString(), err.getPriority());
    return os;
}

class ErrorCorrelator final
{
public:
    void addError(const Error& error) { m_errors.push(error); }
    [[nodiscard]] Error getError()
    {
        if (m_errors.empty()) {
            throw std::out_of_range{ "No more errors." };
        }
        Error top{ m_errors.top() };
        m_errors.pop();
        return top;
    }
private:
    std::stack<Error> m_errors;
};

int main()
{
    ErrorCorrelator ec;
    ec.addError(Error{ 3, "Unable to read file" });
    ec.addError(Error{ 1, "Incorrect entry from user" });
    ec.addError(Error{ 10, "Unable to allocate memory!" });

    while (true) {
        try {
            Error e{ ec.getError() };
            std::cout << e << std::endl;
        }
        catch (const std::out_of_range&) {
            std::cout << "Finished processing errors" << std::endl;
            break;
        }
    }
}