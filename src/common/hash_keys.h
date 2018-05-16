#ifndef HASH_KEYS_H
#define HASH_KEYS_H

#include <string>

static const uint Position_Hash = qHash('P') ^ qHash('o') ^ qHash('s') ^ qHash('i') ^ qHash('t') ^ qHash('i') ^ qHash('o') ^ qHash('n');
static const uint Profile_Variable_Value_Hash = qHash('P') ^ qHash('r') ^ qHash('o') ^ qHash('f') ^ qHash('i') ^ qHash('l') ^ qHash('e') ^ qHash('_') ^ qHash('V') ^ qHash('a') ^ qHash('r') ^ qHash('i') ^ qHash('a') ^ qHash('b') ^ qHash('l') ^ qHash('e')^ qHash('_') ^ qHash('V') ^ qHash('a') ^ qHash('l') ^ qHash('u') ^ qHash('e');
static const uint Sensed_Voltage_Hash = qHash('S') ^ qHash('e') ^ qHash('n') ^ qHash('s') ^ qHash('e') ^ qHash('d') ^ qHash('_') ^ qHash('V') ^ qHash('o') ^ qHash('l') ^ qHash('t') ^ qHash('a') ^ qHash('g') ^ qHash('e');

//static const std::string

#endif // HASH_KEYS_H
