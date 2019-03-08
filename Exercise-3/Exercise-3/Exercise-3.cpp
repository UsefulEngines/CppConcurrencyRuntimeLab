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

// Exercise-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ppl.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
using namespace Concurrency;

 
//number of iterations each thread performs
static const int NUM_ITERATIONS = 2;
//the shared data that needs protection from race/tearing
static unsigned int sharedData = 0;

//Demonstrates the use of the reader lock
void Reader()

{

    for( int i = 0; i < NUM_ITERATIONS; ++i)
    {
        printf_s("Reading %d\n", sharedData);
        //Sleep for some time, this is to simulate potential work done while holding the lock
        Sleep(1000);
    }
}


//Demonstrates the use of the writer lock
void Writer()
{
   for( int i = 0; i < NUM_ITERATIONS; ++i)
    {
        printf_s("\tWriting %d\n", ++sharedData);
        //Sleep for some time, this is to simulate potential work done while holding the lock
        Sleep(1000);
    }

}

int _tmain(int argc, _TCHAR* argv[])
{

	//performs reader writer operations in parallel
   parallel_invoke(
        [&] { Reader(); },
        [&] { Reader(); },
        [&] { Reader(); },
        [&] { Reader(); },
        [&] { Writer(); }
    );
    return 0;
}