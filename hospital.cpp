#include "hospital.h"

hospital::hospital() {}

hospital::hospital(const int num): number(num) {}

hospital::hospital(const int num, std::vector<patient>& vec): number(num), hosp(vec) {}

void hospital::print(std::ostream &out) const {
    if (!hosp.size())
        out << "Hospital number " << number << " has no patients at the moment.\n";        
        else {
        out << "Hospital number " << number << ":\n";
        out << "******************************\n";
        };
        for (int i = 0; i < hosp.size(); i++) {
            out << i + 1 << ". ";
            out << hosp[i];
        }
}

void hospital::read(std::istream &in) {
    in >> number;
    in.ignore();
    int amount = 0;
    in >> amount;
    in.ignore();
    for (int i = 0; i < amount; i++) {
        patient temp;
        in >> temp;
        addPatient(temp);
    }
}

void hospital::addPatient(const patient &pat) {
    hosp.push_back(pat);
}

bool hospital::removePatient(const patient &pat) {
    int size = hosp.size();
    if (hosp.begin() == hosp.end())
		return false;
    hosp.erase(std::remove(hosp.begin(), hosp.end(), pat), hosp.end());
    return hosp.size() < size;
}

patient &hospital::getPatientByNumber (int nm) {
    return hosp.at(nm-1);
}

void hospital::showAllUnderages(std::ostream &out) const {
    int count = 0;
    out << "These patients need pediatrician instead of therapist:\n";
    out << "******************************\n";
    for (int i = 0; i < hosp.size(); i++) {
        if (hosp[i].getAge() < 18) {
            out << hosp[i];
            count++;
        }
        if (count == 0)
            out << "There's no underage patients in this hospital.\n";
    }
}

int hospital::getSize() const {
    return hosp.size();
}

int hospital::getNumber() const{
    return number;
}

bool hospital::operator==(const hospital &right) const {
    return (number == right.number && hosp == right.hosp);
}

bool hospital::operator!=(const hospital &right) const {
    return (!(*this == right));
}

hospital& hospital::operator=(const hospital &right) {
    if (this != &right)
        hosp = right.hosp;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const hospital &hospital) {
    hospital.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, hospital &hospital) {
    hospital.read(in);
    return in;
}

patient hospital::operator[](const int number) {
    return (getPatientByNumber(number));
}