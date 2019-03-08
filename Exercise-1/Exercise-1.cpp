// ----------------------------------------------------------------------------------
// Microsoft Developer & Platform Evangelism
// 
// Copyright (c) Microsoft Corporation. All rights reserved.
// 
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES 
// OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// ----------------------------------------------------------------------------------
// The example companies, organizations, products, domain names,
// e-mail addresses, logos, people, places, and events depicted
// herein are fictitious.  No association with any real company,
// organization, product, domain name, email address, logo, person,
// places, or events is intended or should be inferred.
// ----------------------------------------------------------------------------------

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <array>


using namespace std::tr1;
using namespace std;


array<int, 10> GetTenNumbers () {
	array<int, 10> rList;
	rList[0] = 10;
	for(int i = 1; i < 10 ; ++i) {
		rList[i] = rList[i - 1] + 10;
	}
	return rList;
}

int SumList(array<int, 10> theList) {
	int sum = 0;
	for (int i = 0; i < 10; i++)  {
		sum = sum + theList[i];
	}
	return sum;
}

array<int, 10> DoubleArrayValues(array<int, 10> theList) {
	for (int i = 0; i < 10; i++)  {
		theList[i] = theList[i] * 2;
	}
	return theList;
}

int _tmain(int argc, _TCHAR* argv[])
{
	array<int, 10> theList = GetTenNumbers();
	theList = DoubleArrayValues(theList);
	for_each(theList.begin(), theList.end(), [&](int n) {
      printf_s("%d\n", n);
   	});

	printf("Sum of List: %i\n",  SumList(theList));
	return 0;
}