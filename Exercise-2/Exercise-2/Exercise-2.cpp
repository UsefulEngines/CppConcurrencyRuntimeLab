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
#include <ppl.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
using namespace Concurrency;

//number of iterations each thread performs
static const int NUM_ITERATIONS = 150000;
int number = 0;

//Demonstrates use of critical section
void FunctionA()
{
    for( int i = 0; i < NUM_ITERATIONS; ++i)
    {
		++number;
    }
}

//Demonstrates use of critical section

void FunctionB()

{
    for( int i = 0; i < NUM_ITERATIONS; ++i)
    {
 		++number;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    parallel_invoke(
        [&] { FunctionA(); },
        [&] { FunctionB(); }
    );

	printf("Final value of number: %i\n", number);

    return 0;
}