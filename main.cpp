#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "patient.h"
#include "patient.cpp"
#include "hospital.h"
#include "hospital.cpp"
#include "hospitals.h"
#include "hospitals.cpp"

int main(int argc, char * argv[]) {

    if (argc < 3) {
        std::cout << "Error opening files";
        return -1;
    }
    std::ifstream readfile(argv[1]);
    std::ofstream writefile(argv[2]);
    if (!readfile.is_open()) {
        std::cout << "Error reading file";
        return -2;
    }
    if (!writefile.is_open()) {
        std::cout << "Error writing file";
        return -3;
    }

    hospitals hs;
    int choice;

    while (true) {
    std::cout << "1. Add hospital\n2. Print all hospitals...\n3. Operations with hospital number... \n\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        {
            std::cout << "1. Create new\n2. Read from input.txt\n\n";
            std::cin >> choice;
            if (choice == 1) {
                hs.createHospital();
            }
            else if (choice == 2) {
                hs.readHospital(readfile);
            }
            break;
        }
    case 2:
        {
            hs.printHospitals(writefile);
            break;
        }
    case 3:
        {
            int num = 0;
            std::cout << "Input number of the hospital.\n\n";
            std::cin >> num;
            if (!hs.isNumber(num))
                std::cout << "There's no hospitals with such number.\n\n";
            else {
                std::cout << "1. Print the hospital...\n2. Add patient to the hospital\n3. Print all underage patients...\n4. Operations with patient number...\n\n";
                std::cin >> choice;
                switch (choice) 
                {
                case 1: 
                {
                    hs.printHospital(writefile, num);
                    break;
                }
                case 2:
                {
                    hs.addPatient(num);
                    break;
                }
                case 3:
                {
                    hs.printUnderages(writefile, num);
                    break;
                }
                case 4:
                {
                    int pat_num = 0;
                    std::cout << "Input number of the patient.\n\n";
                    while (pat_num < 1 || pat_num > hs.getHospitalByNumber(num).getSize())
                        std::cin >> pat_num;
                    std::cout << "1. Change full name\n2. Change gender\n3. Add year to age\n4. Add diagnose\n5. Remove the patient from the hospital\n\n";
                    std::cin >> choice;
                    switch (choice)
                    {
                        case 1:
                        {
                            hs.changePatName(num, pat_num);
                            break;
                        }
                        case 2:
                        {
                            hs.changePatGender(num, pat_num);
                            break;
                        }
                        case 3:
                        {
                            hs.addYear(num, pat_num);
                            break;
                        }
                        case 4:
                        {
                            hs.addDiagnose(num, pat_num);
                            break;
                        }
                        case 5:
                        {
                            hs.removePat(num, pat_num);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
                }
            }
            break;
        }
    default:
        break;
    }
    }

    readfile.close();
    writefile.close();

    return 0;
}
