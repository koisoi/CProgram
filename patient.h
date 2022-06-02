#pragma once

class patient {
    public:
        patient(): age(0), fullname(""), gender(""), diagnoses("None") {}
        patient(const std::string &fullname, const std::string &gender, const int age, const std::string &diagnoses);
        patient(const std::string &fullname, const std::string &gender, const int age);

        void print(std::ostream &output_stream) const;
        void read(std::istream &input_stream);

        void setFullname(const std::string name);
        std::string getFullname() const;
        void setGender(const std::string gender);
        std::string getGender() const;
        void setAge(const int age) { this->age = age; };
        int getAge() const { return age; };
        void setDiagnoses(const std::string diagnoses);
        std::string getDiagnoses() const;

        void addDiagnose(const std::string diagnose);
        void addYearToAge();

        bool operator==(const patient &right) const;
        bool operator!=(const patient &right) const;
        patient &operator=(const patient &right);
        patient &operator++();
        patient operator++(int);
        patient &operator--();
        patient operator--(int);

    private:
        std::string fullname;
        std::string gender;
        int age;
        std::string diagnoses;
};

std::ostream &operator<<(std::ostream &out, const patient &patient);
std::istream &operator>>(std::istream &in, patient &patient);