#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now();
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli> delta = current_time - start_time;

		cout << delta.count() << endl;
	}

private:
	time_point<high_resolution_clock> start_time;
};

class Worker
{
public:
	void DoSomething()
	{
		Timer timer;
		for (int i = 0; i < 1e8; i++)
			;
		timer.Elapsed();
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}