#pragma once
#include "hospital.h"

class hospitals {
    public:
        void print(std::ostream &out) const;

        void addHospital(const hospital &hospital);
        bool isNumber(int nm);
        hospital &getHospitalByNumber(int nm);

        void cinclear();

        void createHospital();
        void readHospital(std::istream &readfile);
        void addPatient(int num);
        void changePatName(int num, int pat_num);
        void printHospitals(std::ostream &writefile) const;
        void printHospital(std::ostream &writefile, int num);
        void printUnderages(std::ostream &writefile, int num);
        void changePatGender(int num, int pat_num);
        void addYear(int num, int pat_num);
        void addDiagnose(int num, int pat_num);
        void removePat(int num, int pat_num);

    private:
        std::vector<hospital> hosps;
};

std::ostream &operator<<(std::ostream &out, const hospitals &hospitals);