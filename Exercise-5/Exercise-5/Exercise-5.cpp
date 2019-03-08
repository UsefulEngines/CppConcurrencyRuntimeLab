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

// Exercise-5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <agents.h>
#include <string>

using namespace Concurrency;
using namespace std;

// This agent writes a string to its target and reads an integer
// from its source.
class agent1 : public agent 
{
public:
   explicit agent1(ISource<int>& source, ITarget<string>& target)
      : _source(source)
      , _target(target)
   {
   }

protected:
   void run()
   {
      // Send the request.

      // Read the response.

	 // Signal Completion

   }

private:   
   ISource<int>& _source;
   ITarget<string>& _target;
};

// This agent reads a string to its source and then writes an integer
// to its target.
class agent2 : public agent 
{
public:
   explicit agent2(ISource<string>& source, ITarget<int>& target)
      : _source(source)
      , _target(target)
   {
   }

protected:
   void run()
   {
      // Read the request.

      // Send the response.

	 // Signal Completion

   }

private:   
   ISource<string>& _source;
   ITarget<int>& _target;
};

int _tmain(int argc, _TCHAR* argv[])
{
   // Step 1: Create two message buffers to serve as communication channels
   // between the agents.
   
   // The first agent writes messages to this buffer; the second
   // agents reads messages from this buffer.
  
	// Declare the unbounded buffer below
	
   // The first agent reads messages from this buffer; the second
   // agents writes messages to this buffer.
   
   // Declare the overwrite buffer below
	
   // Step 2: Create the agents.
   
   // Step 3: Start the agents. The runtime calls the run method on
   // each agent.
   
   // Step 4: Wait for both agents to finish.


}