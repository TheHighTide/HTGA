#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

int Log(string content, bool returnFeedback) {
	time_t logTime = system_clock::to_time_t(system_clock::now());
	char* editedLogTime;
	editedLogTime = strtok(ctime(&logTime), "\n");
	ofstream file("htga.log", ios::app);
	file <<"[" << editedLogTime << "]: " << content << "\n";
	file.close();
	if (returnFeedback) {
		cout << "Logged \"" << content << "\" to the log\n"; // This will only be logged if returnFeedback is true
	}
	return 0;
}