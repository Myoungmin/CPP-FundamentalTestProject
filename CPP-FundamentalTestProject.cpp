#include <iostream>
#include <string>
#include "ChronoVectorLoop.h"

void MakeStringAndShow();
void IF_LogicalOperator();

int main()
{
	//MakeStringAndShow();
	//IF_LogicalOperator();
	ChronoVectorLoop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*  std::to_string 메서드로 int를 string으로 변환, 연산자로 string 합치기, c_str() 메서드로 string에서 const char* 반환 */


void MakeStringAndShow()
{
	int number = 12;
	std::string stringNumber = std::to_string(number);

	// 시행 착오 /////////////////////////////////////////////////////////////////////////////////
	
	//const char* stringToChar = ("DeviceName" + stringNumber + "appendedName").c_str();
	 
	// 처음에 위와 같이 출력하려고 했으나 제대로된 문자열이 출력되지 않았다.
	// c_str()은 원본 객체가 담고있는 문자열에 대해 const char* 타입을 리턴한다.
	// 이 값은 원본 객체인 'string이 메모리를 재할당'받거나 'string 객체가 사라지는 순간' 무효화된다.
	// 그래서 메모리에 할당하지 않고 임시로 만든 문자열은 제대로 출력할 수가 없다.
	 
	//////////////////////////////////////////////////////////////////////////////////////////////

	std::string device = "DeviceName";
	std::string appendedString = "appendedName";

	std::string completeString = device + stringNumber + appendedString;

	const char* stringToChar = completeString.c_str();

	std::cout << stringToChar << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*  if문 안에서 논리 연산자를 적용할 때 함수를 모두 실행하는지 확인하는 실습 */

// 결론 : 처음 bool로 if문 안의 조건이 결정되면 뒤에 함수는 실행하지 않고 넘어간다.

bool BoolTrue()
{
	std::cout << "BoolTrue" << std::endl;
	return true;
}

bool BoolFalse()
{
	std::cout << "BoolFalse" << std::endl;
	return false;
}

void IF_LogicalOperator()
{
	std::cout << "////////// if문 안에 OR 연산자 실습 ///////////" << std::endl;

	// 처음 BoolTrue() 함수만 실행되고 뒤에 함수들은 실행하지 않고 넘어간다.
	if (BoolTrue() || BoolFalse() || BoolTrue())
	{
		std::cout << "****** if문 안 ******" << std::endl;
	}

	std::cout << "////////// if문 안에 OR 연산자 실습 종료 ///////////" << std::endl;

	std::cout << "////////// if문 안에 AND 연산자 실습 ///////////" << std::endl;

	// 처음 BoolFalse() 함수만 실행되고 뒤에 함수들은 실행하지 않고 넘어간다.
	if (BoolFalse() && BoolTrue() && BoolFalse())
	{
		std::cout << "****** if문 안 ******" << std::endl;
	}

	std::cout << "////////// if문 안에 AND 연산자 실습 종료 ///////////" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////