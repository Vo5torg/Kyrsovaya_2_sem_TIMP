#include <stdio.h>
#include <iostream>
#include "Galois_LFSR.h"
using namespace std;
/**
 * @file main.cpp
 */
int main(int argc, char **argv)
{
	int num_operation,num_numbers ;
	cout<<"Генератор псевдослучайной последовательности на базе регистра сдвига с линейной обратной связью."<<endl;
	cout<<"Разрядность: 48 бит."<<endl;
	cout<<"Конфигурация: Галуа."<<endl;
	cout<<endl;
	try {
		do {
			cout<<"Выберите операцию (0-выход, 1-генератор чисел): ";
			cin>>num_operation;
			if (num_operation==0) {
			}
			else if (num_operation==1) {
				Galois_LFSR generator;
				cout<<"Сколько чисел cгенерировать?: ";
				cin>>num_numbers;
				if ((num_numbers>=1)&&(num_numbers<=100)) {
					for (int i = 0; i<num_numbers; i++) {
						uint64_t num_gen = generator.get_respond_bits(true);
						cout<<"В шестнадцатеричной системе: "<<hex<<num_gen<<endl;
						cout<<"В двоичнаой системе: ";
						generator.print_bits(num_gen);
						cout<<endl;
					}
				} else {
					cout<<"Невозможно сгенерировать такое количество чисел."<<endl;
				}
			} else {
				cout<<"Такой операции нет."<<endl;
			}
		} while(num_operation!=0);
	} catch (const GaloisError &error) {
		cout<<error.what()<<endl;
	}
	cout<<"Завершение программы."<<endl;
}
