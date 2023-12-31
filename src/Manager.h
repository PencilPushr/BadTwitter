// include your own comments

#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <string>
#include <vector>
#include <stdexcept>
#include "Person.h"

using namespace std;

class Manager: public Person
{   public:
        // constructor should initialise name and registration number using arguments
        Manager(const string &name, int regNo);

	   // method to return registration number
	   int getRegNo() const;

    private:
		//not needed because of the edit to Person
	   //int regNo;
};

#endif
