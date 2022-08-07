#include <iostream>
#include <string>

void MakeStringAndShow();

int main()
{
	MakeStringAndShow();
}

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