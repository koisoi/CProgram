#include "patient.h"

patient::patient(const std::string &nm, const std::string &gd, const int ag, const std::string &dg): fullname(nm), gender(gd), diagnoses(dg) {
    if (ag < 0)
        age = 0;
    else
        age = ag;
}

patient::patient(const std::string &nm, const std::string &gd, const int ag): fullname(nm), gender(gd), diagnoses("None") {
    if (ag < 0)
        age = 0;
    else
        age = ag;
}

void patient::print(std::ostream &out) const {
    out << "Full name: " << fullname << "\n";
    out << "Gender: " << gender << "\n";
    out << "Age: " << age << " years\n";
    if (age < 18)
        out << "This patient is underage\n";
    else if (age >= 60)
        out << "This patient is old\n";
    out << "Diagnoses: " << diagnoses << "\n";
    out << "******************************\n";
}

void patient::read(std::istream &in) {
    std::getline(in, fullname);
    std::getline(in, gender);
    in >> age;
    do
        in.clear();
    while (in.get() != '\n');
    std::getline(in, diagnoses);
}

void patient::setFullname(const std::string nm) {
    fullname = nm;
}

std::string patient::getFullname() const {
    return fullname;
}

void patient::setGender(const std::string gd) {
    gender = gd;
}

std::string patient::getGender() const {
    return gender;
}

void patient::setDiagnoses(const std::string dg) {
    diagnoses = dg;
}

std::string patient::getDiagnoses() const {
    return diagnoses;
}

void patient::addDiagnose(const std::string diagnose) {
    if (diagnoses == "None")
        diagnoses = diagnose;
    else
        diagnoses = diagnoses + ", " + diagnose;
}

void patient::addYearToAge() {
    age++;
}

bool patient::operator==(const patient &right) const {
    return (fullname == right.fullname and age == right.age and gender == right.gender and diagnoses == right.diagnoses);
}

bool patient::operator!=(const patient &right) const {
    return (!(*this == right));
}

patient& patient::operator=(const patient &right) {
    if (this != &right)
    {
        fullname = right.fullname;
        gender = right.gender;
        age = right.age;
        diagnoses = right.diagnoses;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const patient &patient) {
    patient.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, patient &patient) {
    patient.read(in);
    return in;
}

patient& patient::operator++() {
    ++age;
    return *this;
}

patient patient::operator++(int) {
    patient copy(*this);
    ++age;
    return copy;
}

patient& patient::operator--() {
    --age;
    return *this;
}

patient patient::operator--(int) {
    patient copy(*this);
    --age;
    return copy;
}