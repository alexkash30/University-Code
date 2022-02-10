/*
 Computing I -- COMP.1010 Honor Statement

 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University’s Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog.  Violations
 will be dealt with as outlined therein.

 All programming assignments in this class are to be done by the
 student alone.  No outside help is permitted except the instructor
 and approved tutors.

 I certify that the work submitted with this assignment is mine and
 was generated in a manner consistent with this document, the
 course academic policy on the course website on Blackboard, and
 the UMass Lowell academic code.

 Date:
 Name:
 */
#include <stdio.h>

char* reverse(char word[]);

int main(int argc, const char* argv[]) {
    char word[] = "Computer";

    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", word);

    return 0;
}

char* reverse(char word[]){
    int i;
    char temp;
    for (i = 0; word[i] != '\0'; i++);
    i--;
    for (int c = 0; c < i/2; c++) {
        temp = word[c];
        word[c] = word[i - c];
        word[i - c] = temp;
        
    }
    i++;
    word[i] = '\0';
    return word;

}