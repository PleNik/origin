#include"Timer.h"

Timer::Timer() : m_beg(clock_t::now()) { }

void Timer::start() {
    m_beg = clock_t::now();
}
void Timer::print() const {
    std::cout << elapsed() << "s" << '\n';
}

double Timer::elapsed() const
{
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}


