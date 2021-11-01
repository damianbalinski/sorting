#pragma once
#include <iostream>

#ifndef NDEBUG_STREAM
	#define check_istream_open(S)		__check_istream_open(S)
	#define check_ostream_open(S)		__check_ostream_open(S)
#else
	#define check_istream_open(S)
	#define check_ostream_open(S)
#endif

void __check_istream_open(const std::istream& input);

void __check_ostream_open(const std::ostream& output);
