#ifndef TEST_VECTOR_H_
#define TEST_VECTOR_H_

#include <iostream>
using namespace std;

string test[] = {"ID = 0x4c \"Pierwszy Task\" TTL = 600ms",
                    "ID = 0x00 \"Drugi Task\" TTL = 6000ms",
                    "ID = 0xff \"Trzeci Task\" TTL = 400ms",
                    "ID = 0x3c \"Pierwszy Task\" TTL = 1230ms",
                    "ID = 0x10 \"Sprawdz gen\" TTL = 0ms",
                    "ID = 0x66 \"Sprawdz int\" TTL = 10ms",
                    "ID = 0x96 \"Sprawdz ext\" TTL = 1000ms",
                    "ID = 0x96 \"Drugi nadpisuje Sprawdz ext\" TTL = 1000ms",
                    "ID = 0x66 \"nadp\" TTL = 10ms",
                    "ID = 0xf \"rb general\" TTL = 1234ms",
                    "ID = 0x10 \"lb internal \" TTL = 10ms",
                    "ID = 0x6f \"rb internal \" TTL = 1001ms",
                    "ID = 0x70 \"lb external \" TTL = 10ms",
                    "ID = 0xff \"rb external \" TTL = 10ms",};

#endif