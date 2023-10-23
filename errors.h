#pragma once

#include <iostream>
#include <string>

using namespace std;

string errorMsg[4] = {
	"\033[1;31mYou entered an invalid command!\033[0m\n",
	"\033[1;31mPlease enter a valid number!\033[0m\n",
	"\033[1;31mPlease enter a valid string!\033[0m\n",
	"\033[1;31mPlease enter a valid ID!\033[0m\n"
};

void DisplayErrorMsg(int errorMsgId) {
	try {
		if (errorMsg->size() - 1 < errorMsgId) {
			throw("invalidId");
		}
		else {
			cout << errorMsg[errorMsgId];
		}
	}
	catch (string returned) {
		if (returned == "invalidId") {
			DisplayErrorMsg(3);
		}
	}
}

void SetErrorMsg(int errorMsgId, string newErrorMsg) {
	try {
		if (errorMsg->size() - 1 < errorMsgId) {
			throw("invalidId");
		}
		else {
			errorMsg[errorMsgId] = newErrorMsg;
		}
		errorMsg[errorMsgId] = newErrorMsg;
	}
	catch(string returned) {
		if (returned == "invalidId") {
			DisplayErrorMsg(3);
		}
	}
}