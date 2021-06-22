#include <stdio.h>
#include <iostream>
#include "Galois_LFSR.h"
using namespace std;
int main(int argc, char **argv)
{
	unsigned num_operation,num_numbers ;
	cout<<"Генератор псевдослучайной последовательности на базе регистра сдвига с линейной обратной связью."<<endl;
	cout<<"Разрядность: 48 бит."<<endl;
	cout<<"Конфигурация: Галуа."<<endl;
	cout<<endl;
	do {
		cout<<"Выберите операцию (0-выход, 1-генератор чисел): ";
		cin>>num_operation;
		if (num_operation==1) {
			Galois_LFSR generator;
			cout<<"Сколько чисел cгенерировать?: ";
			cin>>num_numbers;
			if (!(num_numbers<1)) {
				for (unsigned i = 0; i<num_numbers; i++) {
					uint64_t num_gen = generator.get_respond_bits(true);
					cout<<"Число номер "<<i+1<<endl;
					cout<<"В шестнадцатеричной системе: "<<hex<<num_gen<<endl;
					cout<<"В двоичнаой системе: ";
					generator.print_bits(num_gen);
					cout<<endl;
				}
			} else {
				cout<<"Невозможно сгенерировать меньше одного числа"<<endl;
			}
		}
	} while(num_operation!=0);
	cout<<"Выхожу."<<endl;
}
