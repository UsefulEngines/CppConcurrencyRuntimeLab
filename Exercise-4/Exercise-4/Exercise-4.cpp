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
#include <windows.h>
#include <concrt.h>
#include <concrtrm.h>
#include <ppl.h>

using namespace Concurrency;
using namespace std;
 
class WindowsEvent
{
    HANDLE m_event;
public:
    WindowsEvent()
        :m_event(CreateEvent(NULL,TRUE,FALSE,TEXT("WindowsEvent")))
    {
    }
 
    ~WindowsEvent()
    {
        CloseHandle(m_event);
    }
 
    void set()
    {
        SetEvent(m_event);
    }
 
    void wait(int count = INFINITE)
    {
        WaitForSingleObject(m_event,count);
    }
};
 


int _tmain(int argc, _TCHAR* argv[])
{
	
	//Create a scheduler that uses two threads.

	//Declare an Event
	
	//Create a Lambda Waiting for the Event
	
	//Create a taskgroup and schedule multiple copies of the task
	
	//Sleep
	
	//Wait for the events
	
	//Wait for the tasks
	
}