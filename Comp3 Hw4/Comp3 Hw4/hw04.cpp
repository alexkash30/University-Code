/***********************************************
Author: Alex Kashian
Date: 9/26
Purpose: covert a zip code to a barcode 
Sources of Help: 
Time Spent: 2.5 hrs
***********************************************/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 9/26
Name: Alex Kashian
*/

#include <iostream>
#include <string>
using namespace std;


class ZipCode {

public:
    ZipCode(int barcode);
    ZipCode(string barcode);
    string getBarCode();
    int getZipCode();

private:
    int zipcode;

    //function to calculate the 5 digit string for each number in the zip code
    string getString(int num) {

        int count = 0;
        string str = "";
        if (num == 0)
            return "11000";

        if (num >= 7) {

            str.append("1");
            num = num - 7;
            count++;
        }
        else
            str.append("0");

        if (num >= 4) {

            str.append("1");
            num = num - 4;
            count++;
        }
        else
            str.append("0");

        if (num >= 2) {

            str.append("1");
            num = num - 2;
            count++;
        }
        else
            str.append("0");

        if (num >= 1) {

            str.append("1");
            num = num - 1;
            count++;
        }
        else
            str.append("0");
        if (count == 1) {

            str.append("1");
        }
        else
            str.append("0");

        return str;
    }
};
ZipCode::ZipCode(int initBar) {

    if (initBar < 00000 || initBar > 99999)
        cout << "Invalid Bar code passed to constructor." << endl;
    else
        zipcode = initBar;
}
ZipCode::ZipCode(string initbar) {

    if (initbar.length() > 27)
        cout << "Invalid Bar code passed to constructor." << endl;
    else {

        int hold = 0;
        string str = initbar.substr(1, initbar.length() - 2);

        for (int i = 0; i < static_cast<int>(str.length()); i += 5) {

            int section = 0;
            section = 7 * (str[i] - '0') + 4 * (str[i + 1] - '0') +
                2 * (str[i + 2] - '0') + 1 * (str[i + 3] - '0');

            if (section == 11)
                section = 0;
            hold = hold * 10 + section;
        }
        zipcode = hold;
    }
}
string ZipCode::getBarCode() {
    string str = "1";
    int divisor = 10000;
    int section1 = zipcode / divisor;
    int section2 = (zipcode % divisor) / 1000;
    divisor = 1000;
    int section3 = (zipcode %divisor) / 100;
    divisor = 100;
    int section4 = (zipcode % divisor) / 10;
    divisor = 10;
    int section5 = (zipcode % divisor);
    str.append(getString(section1));
    str.append(getString(section2));
    str.append(getString(section3));
    str.append(getString(section4));
    str.append(getString(section5));
    str.append("1");
    return str;
}
int ZipCode::getZipCode() {
    return zipcode;
}
int main(int argc, char* argv[]) {
    ZipCode zip(99504),
        zip2("100101010011100001100110001"),
        zip3(12345),
        zip4(67890);

    cout << zip.getZipCode() << "'s bar code is '"
        << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
        << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
        << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
        << zip4.getBarCode() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
            << z1_barcode << "'";

        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;

    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }

    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}