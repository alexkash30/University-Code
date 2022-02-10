//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//class ZipCode
//{
//public:
//    ZipCode();
//    ZipCode(int initZip);
//    ZipCode(string initBarcode);
//
//    int getZipCode();
//    string getBarCode();
//
//private:
//    int zipCode;
//    string barCode;
//    int convertToZip(string bar) {
//        int zipper = 0;
//        string str_local = bar.substr(1, bar.length() - 2);
//
//        for (int i = 0; i < static_cast<int>(str_local.length()); i += 5) {
//
//            int local = 0;
//            local = 7 * (str_local[i] - '0') + 4 * (str_local[i + 1] - '0') +
//                2 * (str_local[i + 2] - '0') + 1 * (str_local[i + 3] - '0');
//
//            if (local == 11)
//                local = 0;
//            zipper = zipper * 10 + local;
//        }
//        return zipper;
//    }
//    string convertToBar(int zip) {
//        string result = "1";
//        int divisor = 10000;
//        int number = zip;
//        int currentDigit;
//        for (int i = 0; i < 5; i++) {
//            currentDigit = number / divisor;
//            switch (currentDigit) {
//            case 0:
//                result += "11000";
//                break;
//            case 1:
//                result += "00011";
//                break;
//            case 2:
//                result += "00101";
//                break;
//            case 3:
//                result += "00110";
//                break;
//            case 4:
//                result += "01001";
//                break;
//            case 5:
//                result += "01010";
//                break;
//            case 6:
//                result += "01100";
//                break;
//            case 7:
//                result += "10001";
//                break;
//            case 8:
//                result += "10010";
//                break;
//            case 9:
//                result += "10100";
//                break;
//            default:
//                result += "00000";
//                cout << "Error!" << endl;
//            }
//            number = number % divisor;
//            divisor = divisor / 10;
//        }
//        result.append("1");
//        return result;
//    }
//};
//
//
//int main(int argc, char* argv[]) {
//    ZipCode zip(99504),
//        zip2("100101010011100001100110001"),
//        zip3(12345),
//        zip4(67890);
//
//    cout << zip.getZipCode() << "'s bar code is '"
//        << zip.getBarCode() << "'" << endl;
//    cout << zip2.getZipCode() << "'s bar code is '"
//        << zip2.getBarCode() << "'" << endl;
//    cout << zip3.getZipCode() << "'s bar code is '"
//        << zip3.getBarCode() << "'" << endl;
//    cout << zip4.getZipCode() << "'s bar code is '"
//        << zip4.getBarCode() << "'" << endl;
//
//    cout << endl;
//
//    // Test a range of values by first constructing a zip code
//    // with an integer, then retrieving the bar code and using
//    // that to construct another ZipCode.
//    int zip_int = 0;
//    for (int i = 0; i < 25; i++)
//    {
//        // Make an aribrary 5-digit zip code integer, and use it
//        // to construct a ZipCode
//        int five_digit_zip = (zip_int * zip_int) % 100000;
//        ZipCode z1(five_digit_zip);
//
//        // Construct a second ZipCode from the first's bar code
//        string z1_barcode = z1.getBarCode();
//        ZipCode z2(z1_barcode);
//
//        cout.width(3);
//        cout << (i + 1) << ": ";
//        cout.width(5);
//        cout << z2.getZipCode() << " has code '"
//            << z1_barcode << "'";
//
//        if ((z1_barcode == z2.getBarCode()) &&
//            (z1.getZipCode() == z2.getZipCode()) &&
//            (z2.getZipCode() == five_digit_zip))
//        {
//            cout << " [OK]" << endl;
//        }
//        else
//        {
//            cout << " [ERR]" << endl;
//        }
//
//        // Increment the test value arbitrarily
//        zip_int += (233 + zip_int % 7);
//    }
//    cout << endl;
//
//    // Test some error conditions. This test assumes that
//    // ZipCode will simply set its value to a flag that indicates
//    // an error, and will not exit the program.
//    int BAD_ZIP_COUNT = 2;
//    string bad_zips[][2] = {
//        { "100101010011100001100110000", "bad start/end character" },
//        { "100101010011100001100110021", "bad digit" },
//    };
//    for (int i = 0; i < BAD_ZIP_COUNT; i++)
//    {
//        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
//        ZipCode test(bad_zips[i][0]);
//        cout << endl;
//    }
//
//    cout << "Enter a character to quit." << endl;
//    char c;
//    cin >> c;
//    return 0;
//}
//
//ZipCode::ZipCode() {
//    int zipCode = 0;
//    string barCode = "0";
//}
//
//ZipCode::ZipCode(int initZip) {
//    zipCode = initZip;
//    barCode = convertToBar(initZip);
//}
//
//ZipCode::ZipCode(string initBar) {
//    if (initBar.length() > 27)
//        cout << "Invalid Bar code passed to constructor." << endl;
//    else {
//        zipCode = convertToZip(initBar);
//    }
//}
//
//string ZipCode::getBarCode() {
//    return barCode;
//}
//int ZipCode::getZipCode() {
//    return zipCode;
//}
