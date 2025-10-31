#include <iostream>
#include <thread>
#include <format>

using namespace std;

jthread job{ [](stop_token token) {
	while (!token.stop_requested()) {
		// ...
	}
} };

int main()
{
	job.request_stop();
}