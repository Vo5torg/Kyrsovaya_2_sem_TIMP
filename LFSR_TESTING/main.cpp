#include <UnitTest++/UnitTest++.h>
#include <../LFSR/Galois_LFSR.cpp>
#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;
struct LFSR_fixture {
	Galois_LFSR * p;
	LFSR_fixture()
	{
		p = new Galois_LFSR();

	}
	~LFSR_fixture()
	{
		delete p;
	}
};
SUITE(RevesreTest)
{
	TEST(ValidKey_1) {
		CHECK_EQUAL(0x000000000001, Galois_LFSR().reverse_bits(0x800000000000));
	}
	TEST(ValidKey_2) {
		CHECK_EQUAL(0x808a085300c1, Galois_LFSR().reverse_bits(0x8300ca105101));
	}
	TEST(ZeroKey) {
		CHECK_THROW(Galois_LFSR().reverse_bits(0x000000000000), GaloisError);
	}
}
SUITE(SetBitsTest)
{
	TEST_FIXTURE(LFSR_fixture, NonZeroStartBits) {
		p->set_start_bits(0x000000000001);
		CHECK_EQUAL(p->get_start_bits(),0x000000000001);
	}
	TEST_FIXTURE(LFSR_fixture, ZeroStartBits) {
		CHECK_THROW(p->set_start_bits(0x000000000000),GaloisError);
	}
}
SUITE(GenerateTest)
{
	
	TEST_FIXTURE(LFSR_fixture, GenBits_1) {
		p->set_start_bits(0x000000000001);
		CHECK_EQUAL(0x3ffffff800002,p->get_respond_bits(false));
	}
	TEST_FIXTURE(LFSR_fixture, GenBits_2) {
		p->set_start_bits(0x701973f04f0c);
		CHECK_EQUAL(0x828fd5c3ee2a,p->get_respond_bits(false));
	}
	
}
SUITE(RandomTest)
{
	TEST_FIXTURE(LFSR_fixture, RandBits_1) {
		CHECK(p->get_random_bits() != p->get_random_bits());
	}
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
