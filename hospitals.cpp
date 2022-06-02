#include "hospitals.h"

void hospitals::addHospital(const hospital &hospital) {
    hosps.push_back(hospital);
}

bool hospitals::isNumber(int nm) {
    for (int i = 0; i < hosps.size(); i++) {
        if (hosps[i].getNumber() == nm)
            return true;
    }
    return false;
}

hospital &hospitals::getHospitalByNumber(int nm) {
    for (int i = 0; i < hosps.size(); i++) {
        if (hosps[i].getNumber() == nm)
            return hosps[i];
    }
}


void hospitals::print(std::ostream &out) const {
    for (int i = 0; i < hosps.size(); i++) {
        out << hosps[i];
    }
}

std::ostream &operator<<(std::ostream &out, const hospitals &hospitals) {
    hospitals.print(out);
    return out;
}

void hospitals::cinclear() {
    do
        std::cin.clear();
    while (std::cin.get() != '\n');
}

void hospitals::createHospital() {
    hospital h_temp;
    std::cout << "Input number, amount of patients, and then full name, gender, age and diagnoses of every patient.\n\n";
    std::cin >> h_temp;
    addHospital(h_temp);
}

void hospitals::readHospital(std::istream &readfile) {
    hospital h_temp;
    readfile >> h_temp;
    addHospital(h_temp);
}

void hospitals::addPatient(int num) {
    patient p_temp;
    std::cout << "Input full name, gender, age and diagnoses of the patient.\n\n";
    cinclear();
    std::cin >> p_temp;
    getHospitalByNumber(num).addPatient(p_temp);
}

void hospitals::changePatName(int num, int pat_num) {
    std::string str_temp;
    std::cout << "Input new name.\n\n";
    cinclear();
    std::getline(std::cin, str_temp);
    getHospitalByNumber(num).getPatientByNumber(pat_num).setFullname(str_temp);
}

void hospitals::printHospitals(std::ostream &writefile) const {
    std::cout << "1. ...to the screen\n2. ...to output.txt\n\n";
    int choice;
    std::cin >> choice;
    if (choice == 1)
        print(std::cout);
    else if (choice == 2)
        print(writefile);
}

void hospitals::printHospital(std::ostream &writefile, int num) {
    std::cout << "1. ...to the screen\n2. ...to output.txt\n\n";
    int choice;
    std::cin >> choice;
    if (choice == 1)
        std::cout << getHospitalByNumber(num);
    else if (choice == 2)
        writefile << getHospitalByNumber(num);
}

void hospitals::printUnderages(std::ostream &writefile, int num) {
    std::cout<<"1. ...to the screen\n2. ...to output.txt\n\n";
    int choice;
    std::cin >> choice;
    if (choice == 1)
        getHospitalByNumber(num).showAllUnderages(std::cout);
    else if (choice == 2)
        getHospitalByNumber(num).showAllUnderages(writefile);
}

void hospitals::changePatGender(int num, int pat_num) {
    std::string str_temp;
    std::cout << "Input the gender.\n\n";
    cinclear();
    std::cin >> str_temp;
    getHospitalByNumber(num).getPatientByNumber(pat_num).setGender(str_temp);
}

void hospitals::addYear(int num, int pat_num) {
    getHospitalByNumber(num).getPatientByNumber(pat_num)++;
    std::cout << getHospitalByNumber(num).getPatientByNumber(pat_num).getFullname() << "'s age is now " << getHospitalByNumber(num).getPatientByNumber(pat_num).getAge() << "\n\n";
}

void hospitals::addDiagnose(int num, int pat_num) {
    std::string str_temp;
    std::cout << "Input new diagnose.\n\n";
    cinclear();
    std::getline(std::cin, str_temp);
    getHospitalByNumber(num).getPatientByNumber(pat_num).addDiagnose(str_temp);
}

void hospitals::removePat(int num, int pat_num) {
    if (getHospitalByNumber(num).removePatient(getHospitalByNumber(num).getPatientByNumber(pat_num)))
        std::cout << "The patient removed succesfully.\n\n";
    else
        std::cout << "Unable to remove the patient.\n\n";
}