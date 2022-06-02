#pragma once
#include "patient.h"

class hospital {
    public:
        hospital();
        hospital(const int _number);
        hospital(const int _number, std::vector<patient>& _vec);
        
        void print(std::ostream &out) const;
        void read(std::istream &in);

        void addPatient(const patient &patient);
        bool removePatient(const patient &patient);
        patient &getPatientByNumber(int nm);
        int getSize() const;
        int getNumber() const;
        void showAllUnderages(std::ostream &out) const;

        bool operator==(const hospital &right) const;
        bool operator!=(const hospital &right) const;
        hospital &operator=(const hospital &right);
        patient operator[](const int number);

    private:
        int number;
        std::vector<patient> hosp;
};

std::ostream &operator<<(std::ostream &out, const hospital &hospital);
std::istream &operator>>(std::istream &in, hospital &hospital);