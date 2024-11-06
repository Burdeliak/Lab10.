#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.1A/Lab10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLab101A
{
	TEST_CLASS(TestLab101A)
	{
	public:

		TEST_METHOD(TestCountExcellentStudents)
		{
			// Створюємо тестовий набір студентів
			std::vector<Student> students = {
				{"Ivanov", 1, ComputerScience, 5, 5, 5},
				{"Petrov", 2, Informatics, 4, 5,  4},
				{"Sidorov", 3, MathEconomics, 5, 5, 5}
			};

			// Перевіряємо, чи функція повертає правильну кількість студентів з оцінками "5" з фізики та математики
			int excellentCount = countExcellentStudents(students);
			Assert::AreEqual(2, excellentCount); // Очікуємо 2 студенти з відмінними оцінками
		}
	};
}
