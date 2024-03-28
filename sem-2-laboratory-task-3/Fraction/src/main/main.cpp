#include "src/Fraction/Fraction.hpp"
int main()
{
	try {
		/*
		Fraction defaultFraction;
		Fraction parametrFraction(1,2);
		Fraction copiedFractiond(parametrFraction);
		Fraction movedFraction(3,8);
		Fraction newOwnerFraction(std::move(movedFraction));
		*/

		/*
		std::cout << "Constructors" << '\n';
		std::cout << "Default " << defaultFraction << '\n';
		std::cout << "Parametric " << parametrFraction << '\n';
		std::cout << "Move " << newOwnerFraction << '\n';
		*/

		/*
		Fraction assignment;
		assignment = 5;
		std::cout << "5 = " << assignment << '\n';
		assignment = parametrFraction;
		std::cout << "1/2 = " << assignment << '\n';
		assignment = std::move(newOwnerFraction);
		std::cout << "3/8 = " << assignment << '\n';
		*/

		/*
		Fraction arifmeticNumRhs;
		Fractoin half(1, 2);
		arifmeticNumRhs = half + 1;
		std::cout << "3/2 = " << arifmeticNumRhs << '\n';
		arifmeticNumRhs = half - 1;
		std::cout << "-1/2 = " << arifmeticNumRhs << '\n';
		arifmeticNumRhs = half * 2;
		std::cout << "1 = " << arifmeticNumRhs << '\n';
		arifmeticNumRhs = half / 3;
		std::cout << "1/6 = " << arifmeticNumRhs << '\n';
		*/
		
		/*
		Fraction arifmeticNumLhs;
		Fraction two(2,1);
		arifmeticNumLhs = 1 + two;
		std::cout << "3/2 = " << arifmeticNumLhs << '\n';
		arifmeticNumLhs = 1 - two;
		std::cout << "1/2 = " << arifmeticNumLhs << '\n';
		arifmeticNumLhs = 2 * two;
		std::cout << "1 = " << arifmeticNumLhs << '\n';
		arifmeticNumLhs = 2 / two;
		std::cout << "4 = " << arifmeticNumLhs << '\n';
		*/

		/*
		Fraction arifmeticFraction;
		Fraction third(1,3);
		Fraction five(5,1);
		arifmeticFraction = third + five;
		std::cout << "16/3 = " << arifmeticFraction << '\n';
		arifmeticFraction = third - five;
		std::cout << "-14/3 = " << arifmeticFraction << '\n';
		arifmeticFraction = third * five;
		std::cout << "5/3 = " << arifmeticFraction << '\n';
		arifmeticFraction = third / five;
		std::cout << "1/15 = " << arifmeticFraction << '\n';
		*/

		/*
		Fraction compoundAssignmentNum;
		compoundAssignmentNum += 1;
		std::cout << "1 = " << compoundAssignmentNum << '\n';
		compoundAssignmentNum -= 2;
		std::cout << "-1 = " << compoundAssignmentNum << '\n';
		compoundAssignmentNum *= 3;
		std::cout << "-3 = " << compoundAssignmentNum << '\n';
		compoundAssignmentNum /= 4;
		std::cout << "-3/4 = " <<compoundAssignmentNum << '\n';
		*/

		/*
		Fraction compoundAssignmentFraction;
		Fraction one(1, 1);
		Fraction four(4, 1);
		compoundAssignmentFraction += four;
		std::cout << "4 = " << compoundAssignmentFraction << '\n';
		compoundAssignmentFraction -= one;
		std::cout << "3 = " << compoundAssignmentFraction << '\n';
		compoundAssignmentFraction *= four;
		std::cout << "12 = " << compoundAssignmentFraction << '\n';
		compoundAssignmentFraction /= four;
		compoundAssignmentFraction /= four;
		std::cout << "3/4 = " << compoundAssignmentFraction << '\n';
		*/

		/*
		Fraction compareWithNum(4,5);
		std::cout << "4/5 = 1 " << (compareWithNum == 1 ? "True" : "False") << '\n';
		std::cout << "4/5 != 1 " << (compareWithNum != 1 ? "True" : "False") << '\n';
		std::cout << "4/5 > 1 " << (compareWithNum > 1 ? "True" : "False") << '\n';
		std::cout << "4/5 >= 1 " << (compareWithNum >= 1 ? "True" : "False") << '\n';
		std::cout << "4/5 < 1 " << (compareWithNum < 1 ? "True" : "False") << '\n';
		std::cout << "4/5 <= 1 " << (compareWithNum <= 1 ? "True" : "False") << '\n';
		*/
		
		/*
		Fraction compareWithFractionFirst(4,5);
		Fraction compareWithFractionSecond(1,1);
		std::cout << "4/5 = 1 " << (compareWithFractionFirst == compareWithFractionSecond ? "True" : "False") << '\n';
		std::cout << "4/5 != 1 " << (compareWithFractionFirst != compareWithFractionSecond ? "True" : "False") << '\n';
		std::cout << "4/5 > 1 " << (compareWithFractionFirst > compareWithFractionSecond ? "True" : "False") << '\n';
		std::cout << "4/5 >= 1 " << (compareWithFractionFirst >= compareWithFractionSecond ? "True" : "False") << '\n';
		std::cout << "4/5 < 1 " << (compareWithFractionFirst < compareWithFractionSecond ? "True" : "False") << '\n';
		std::cout << "4/5 <= 1 " << (compareWithFractionFirst <= compareWithFractionSecond ? "True" : "False") << '\n';
		*/
		
		/*
		Fraction plusPlusMinusMinus;
		std::cout << plusPlusMinusMinus++ << '\n';
		std::cout << ++plusPlusMinusMinus << '\n';
		std::cout << plusPlusMinusMinus-- << '\n';
		std::cout << --plusPlusMinusMinus << '\n';
		*/

		/*
		Fraction unoMinus(3,7);
		std::cout << "-3/7 = " << -unoMinus << '\n';
		*/

		/*
		Fraction reverse(3,7);
		std::cout << "7/3 = " << !reverse << '\n';
		*/

		/*
		Fraction decFraction(714, 1000);
		std::cout << decFraction.toDouble() << '\n';
		*/
	
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what() << '\n';
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << '\n';
	}
	catch (std::exception e) {
		std::cerr << e.what() << '\n';
	}
}
