#include <iostream>
#include <vector>

using namespace std;

class Patient
{
public:
	Patient(const string& name)
		: name(name)
	{}

	void AddDoctor(class Doctor* const doctor)
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor(); // Doctor가 정의되기 전 이므로 클래스 밖에서 정의해야함


private:
	string name;
	friend class Doctor;
	vector<class Doctor*> doctors;
};

class Doctor
{
public:
	Doctor(const string& name)
		: name(name)
	{}

	void AddPatient(class Patient* const patient)
	{
		patients.push_back(patient);
	}

	void MeetPatient()
	{
		for (const auto& patient : patients)
		{
			cout << "Meet Patient : " << patient->name << endl;
		}
	}

private:
	string name;
	friend class Patient;
	vector<class Patient*> patients;
};

int main()
{
	Patient* p1 = new Patient("Kim");
	Patient* p2 = new Patient("Park");
	Patient* p3 = new Patient("Lee");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d1);
	d1->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	p1->MeetDoctor();
	p2->MeetDoctor();
	p3->MeetDoctor();
	d1->MeetPatient();
	d2->MeetPatient();
	
	delete d2; // 만든 순서의 역순으로 delete
	delete d1;
	delete p3;
	delete p2;
	delete p1;

	return 0;
}

void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
	{
		cout << "Meet Doctor : " << doctor->name << endl;
	}
}
