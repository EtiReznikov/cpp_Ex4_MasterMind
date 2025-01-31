/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"

#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		} 
	
//My tests:

	testcase.setname("My- Calculate bull and pgia")
	  .CHECK_OUTPUT(calculateBullAndPgia("9106","1111"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9106","1000"), "1,1")      // 1 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9106","1022"), "0,2")      // 0 bull, 1 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("3516","3516"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3561"), "2,2")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3156"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","1234"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","3214"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","2478"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3516","1365"), "0,4")      // 0 bull, 4 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("8","1"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8","8"), "1,0")      // 1 bull, 0 pgia
	
		.CHECK_OUTPUT(calculateBullAndPgia("82","12"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","21"), "0,1")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","14"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","82"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("82","28"), "0,2")      // 0 bull, 2 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("371","371"), "3,0")      // 3 bull, 0 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","137"), "0,3")      // 0 bull, 3 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","317"), "1,2")      // 1 bull, 2 pgia
    .CHECK_OUTPUT(calculateBullAndPgia("371","242"), "0,0")      // 0 bull, 0 pgia

;

		ConstantChooser c9106{"9106"}, c1000{"1000"}, c123{"123"}, c1111{"1111"};
		ConstantGuesser g9106{"9106"}, g0000{"0000"}, g1111{"1111"}, g123{"123"};


	
		testcase.setname("My- Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c9106, g9106, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1000, g0000, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c123, g1111, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c1111, g123, 3, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c123, g123, 3, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c123, g9106, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c9106, g123, 3, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;
			testcase.setname("My- Play with smart guesser");
		RandomChooser randy10;
		SmartGuesser smarty10;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy10, smarty10, 10, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
					testcase.setname("My- Play with smart guesser");
		RandomChooser randy9;
		SmartGuesser smarty9;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy9, smarty9, 9, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
					testcase.setname("My- Play with smart guesser");
		RandomChooser randy8;
		SmartGuesser smarty8;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy8, smarty8, 8, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
					testcase.setname("My- Play with smart guesser");
		RandomChooser randy7;
		SmartGuesser smarty7;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy7, smarty7, 7, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
					testcase.setname("My- Play with smart guesser");
		RandomChooser randy6;
		SmartGuesser smarty6;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy6, smarty6, 6, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
							testcase.setname("My- Play with smart guesser");
		RandomChooser randy5;
		SmartGuesser smarty5;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy5, smarty5, 5, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		testcase.setname("My- Play with smart guesser");
		RandomChooser randy4;
		SmartGuesser smarty4;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy4, smarty4, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

			testcase.setname("My- Play with smart guesser");
		RandomChooser randy3;
		SmartGuesser smarty3;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy3, smarty3, 3, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
			testcase.setname("My- Play with smart guesser");
		RandomChooser randy2;
		SmartGuesser smarty2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy2, smarty2, 2, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
			testcase.setname("My- Play with smart guesser");
		RandomChooser randy1;
		SmartGuesser smarty1;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy1, smarty1, 1, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}




    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}