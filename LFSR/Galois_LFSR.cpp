#include "Galois_LFSR.h"
/**
 * @brief Конструктор по-умолчанию, не принимает ничего на вход.
 */
Galois_LFSR::Galois_LFSR()
{
}
/**
 * @brief Функция, принимающая на вход число. Выводит число по битам.
 * @param bits
 */
void Galois_LFSR::print_bits(uint64_t bits)
{
	int N(num_bits);
	for (int i = N-1; i>=0; i--) {
		if (bits & ((uint64_t)1<<i)) cout<<"1";
		else cout<<"0";
	}
	cout<<endl;
}
/**
 * @brief Функция, принимающая на вход число. "Отзеркаливает" его по битам.
 * @param bits
 * @return Перевёрнутое число
 * @throw GaloisError, если число равно нулю
 */
uint64_t  Galois_LFSR::reverse_bits(uint64_t bits)
{
	if (bits==0) {
		throw GaloisError("Число не может быть равно нулю.");
	}
	uint64_t val_mirror = 0;
	for (int N(num_bits); N > 0; --N) {
		val_mirror <<= 1;
		val_mirror |= (bits & 1);
		bits >>= 1;
	}
	return val_mirror;
}
/**
 * @brief Функция генерирует случайное число.
 * @return Случайное число
 */
uint64_t  Galois_LFSR::get_random_bits()
{
	random_device rd;
	ranlux48_base rnd(rd());
	return rnd();
}
/**
 * @brief Функция принимает на вход число. Устанавливает начальный регистр.
 * @param bits
 * @throw GaloisError, если число равно нулю
 */
void Galois_LFSR::set_start_bits(uint64_t bits)
{
	start_bits = bits;
	if (start_bits == 0) {
		throw GaloisError("Начальное число не может быть равно нулю");
	}
}
/**
 * @brief Функция принимает на вход булеву переменную. Генерирует псевдослучайное число.
 * @param is_random_bits
 * @return Псевдослучайное число
 */
uint64_t Galois_LFSR::get_respond_bits(bool is_random_bits)
{
	uint64_t respond_bits = 0;
	if (is_random_bits == true) start_bits = get_random_bits();
	for (int i = 0 ; i<=num_numbers; i++) {
		if (start_bits & first_bit) {
			start_bits = ((start_bits^reverse_bits(polinom_bits)) >> (uint64_t)1) | last_bit;
			respond_bits |= first_bit;
			respond_bits <<= (uint64_t) 1;

		} else {
			respond_bits <<= (uint64_t) 1;
			start_bits>>=(uint64_t) 1;
		}
	}
	return respond_bits;
}
