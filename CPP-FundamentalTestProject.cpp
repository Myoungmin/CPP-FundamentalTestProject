#include <iostream>
#include <string>
#include "omp.h"

#include "ChronoVectorLoop.h"
#include "OptimallySetMemberString.h"
#include "ConstTest.h"
#include "DelegatingConstructor.h"

void MakeStringAndShow();
void IF_LogicalOperator();
void TestConstTest();
void SystemMethodTest();
void OMPParrallelTest();

int main()
{
	//MakeStringAndShow();
	//IF_LogicalOperator();
	//ChronoVectorLoop();
	//OptimallySet();
	//TestConstTest();
	//DelegatingConstructor();
	//SystemMethodTest();
	OMPParrallelTest();
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void TestConstTest()
{
	ConstTest constTest;

	std::string string1 = "string1";
	const std::string string2 = "string2";

	// 일반 string Argument 가능
	constTest.setName(string1);
	constTest.printName();

	// const string Argument 가능
	constTest.setName(string2);
	constTest.printName();

	// r-value string Argument 가능
	constTest.setName("string3");
	constTest.printName();

	std::string valueString = constTest.getNameRef();	// 일반 변수에는 const ref가 영향이 없이 복사가 일어난다.
	//std::string& refString = constTest.getNameRef();		// 일반 ref에는 const ref 반환하는 함수의 리턴을 받지 못한다.
	const std::string& constRefString = constTest.getNameRef();		// const ref에서는 리턴 받을 수 있다.
	//constRefString = "changed";	// const Ref의 값을 수정하지 못함

	std::vector<std::string> vector1 = { "str1", "str1", "str1" };
	const std::vector<std::string> vector2 = { "str2", "str2", "str2" };

	constTest.setNameFromVect(vector1);
	constTest.printName();
	std::cout << vector1[0] << std::endl;
	//constTest.setNameFromVect(vector2);		//	const vector가 일반 ref 파라미터에 입력되지 않는다.

	std::vector<std::string> vector3 = { "str3", "str3", "str3" };
	const std::vector<std::string> vector4 = { "str4", "str4", "str4" };

	constTest.setNameFromConstVect(vector3);	// const ref로 파라미터가 설정되어 입력 값이 변경이 안되는 것을 보장한다.
	constTest.printName();
	constTest.setNameFromConstVect(vector4);	// 당연히 const vector라 변경이 안일어난다.
	constTest.printName();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemMethodTest()
{
	system("ipconfig");

	// cmd 창 유지하기 위한 명령어
	system("cmd /k ipconfig");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fn()
{
	// thread의 넘버를 출력한다.
	std::cout << omp_get_thread_num() << std::endl;
}


void OMPParrallelTest()
{
	// 아래는 병렬의 수를 직접 지정하는 것
	//omp_set_num_threads(2);
	// 아래만 존재하면 사용자의 CPU 코어 개수를 파악해 코어 수만큼 병렬 실행한다.
#pragma omp parallel
	{
		fn();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////