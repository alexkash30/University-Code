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
Date: 2/12
Effort: 40 mins
Purpose: to check, set, and unset flags using bitwise Operators and left and right shift operators using an array to give more flexability in our code
***********************************************************/

#include <stdio.h>
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);


int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.
	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);

	display_flags(flag_holder, 5);

	printf("\n\n");

	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);

	display_flags(flag_holder, 5);

	return 0;
}
void set_flag(unsigned int flag_holder[], int flag_position) {
	int r = flag_position / 32;
	int flagPos = flag_position % 32;
	int x = 1 << flagPos;
	flag_holder[r] = flag_holder[r] | x;

}

int check_flag(unsigned int flag_holder[], int flag_position) {
	int r = flag_position / 32;
	int flagPos = flag_position % 32;
	int x = 1 << flagPos;

	if (flag_holder[r] & x) {
		return 1;
	}
	else {
		return 0;
	}
}

void unset_flag(unsigned int flag_holder[], int flag_position) {
	int r = flag_position / 32;
	int flagPos = flag_position % 32;
	int x = 1 << flagPos;

	x = ~x;
	flag_holder[r] = flag_holder[r] & x;

}

void display_32_flags_as_array(unsigned int flag_holder) {

	for (int i = 0; i < 32; i++) {
		if (i > 0 && i % 4 == 0) {
			printf(" ");
		}
		printf("%d", check_flag(&flag_holder, i));
	}
	printf("\n");
}

void display_flags(unsigned int flag_holder[], int size) {
	for (int i = 0; i < size; i++) {
		display_32_flags_as_array(flag_holder[i]);
	}
}