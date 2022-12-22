#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* p = new Student[2];
			p[0].fizyka = 3;
			p[0].matematyka = 4;
			p[0].programuvanna = 4;

			p[1].fizyka = 5;
			p[1].matematyka = 5;
			p[1].programuvanna = 3;

			double amount = Amount(p, 2);
			Assert::AreEqual(amount, 50.);
			double count = Counter(p, 2);
			Assert::AreEqual(count, 2.);
		}
	};
}
