#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

	LFSR l("00111", 2);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);

	LFSR l2("00111", 2);
	BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(oneBitTest){
	
	LFSR p("0", 0);
	BOOST_REQUIRE(p.step() == 0);

	LFSR p2("1", 0);
	BOOST_REQUIRE(p2.step() == 0);

}

BOOST_AUTO_TEST_CASE(threeBitTest){
	LFSR l("101", 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);	
	BOOST_REQUIRE(l.step() == 0);	
	BOOST_REQUIRE(l.step() == 1);
}
