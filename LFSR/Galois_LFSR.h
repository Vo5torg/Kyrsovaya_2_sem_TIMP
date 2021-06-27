
#pragma once
#include <iostream>
#include <random>
using namespace std;

/**
 * @class Galois_LFSR
 * @author vo5torg
 * @date 06/22/21
 * @file Galois_LFSR.h
 * @brief Программа генерации псевдослучайно последовательности на базе регистра сдвига с линейной обратной связью с разрядностью 48 бит в конфигурации Галуа.
 */
class Galois_LFSR
{
private:
	uint64_t polinom_bits = 0xC00000180000; ///< Полином, показывающий какие биты подвергаются операции XOR(48, 47, 21, 20)
	uint64_t first_bit = 0x000000000001; ///< Вспомогальная переменная, первый бит которой равен 1
	uint64_t last_bit = 0x800000000000; ///< Вспомогальная переменная, последний бит которой равен 1
	uint64_t start_bits = 0x000000000000; ///< Начальная позиция регистра
	const int num_bits = 48; ///< Длина регистра
	const int num_numbers = 48; ///< Количество сдвигов регистра

public:
	Galois_LFSR(); ///< Конструктор
	void print_bits(uint64_t bits); ///< Функция для вывода числа в битном представлении
	void set_start_bits(uint64_t bits); ///< Функция для установки начальной позиции
	uint64_t get_start_bits(); ///< Функция возвращает начальное значение
	uint64_t get_random_bits(); ///< Функция для генерации случайной начальной позиции
	uint64_t reverse_bits(uint64_t bits); ///< Функция для нахождения перевёрнутого числа
	uint64_t get_respond_bits(bool is_random_bits); ///< Функция для генерации псевдослучайного числа

};

/**
 * @brief Класс-исключение
 */
class GaloisError: public runtime_error
{
public:

	/**
	 * @brief Принимает си строку, поднимает исключение
	 * @param what_arg
	 */
	explicit GaloisError (const char* what_arg):
		runtime_error(what_arg) {}
};
