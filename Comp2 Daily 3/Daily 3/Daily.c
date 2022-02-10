/***********************************************************
Computing II -- COMP.1020 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom,
providing an enriching learning experience for students, and as training as a practicing
computing professional upon graduation. This practice is manifested in the University's
Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and
adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be
dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help
is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner
consistent with this document, the course academic policy on the course website on Blackboard,
and the UMass Lowell academic code.
Author: Alex Kashian
Date: 2/8
Effort: 25 mins
Purpose: to check and set flags using bitwise functions and left and right shift operators
***********************************************************/


#include <stdio.h>
void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);
int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void set_flag(int* flag_holder, int flag_position) {

	int hold = 1 << flag_position;
	*flag_holder = *flag_holder | hold;

}

int check_flag(int flag_holder, int flag_position) {

	int position = 1 << flag_position;

	if (flag_holder & position) {

		return 1;

	}
	else {
		return 0;
	}
}