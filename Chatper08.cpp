#include <iostream>
#include <cstring>

using namespace std;

/*
p.354
문제 08-01
문제 1
*/
namespace {
	enum RISK_LEVEL {
		RISK_A=30,
		RISK_B=20,
		RISK_C=10
	};

}
class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const {
		return 0;
	}
	virtual void ShowSalaryInfo() const {

	}
};

class PermanentWorker :public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, const  int money) :Employee(name), salary(money) {}
	int GetPay() const { return salary; }
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker :public Employee {
private:
	int workTime;        // 이 달에 일한 시간의 합계
	int payPerHour;        // 시간당 급여
public:
	TemporaryWorker(char* name, int pay) :Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time) {        // 일한 시간의 추가
		workTime += time;
	}
	int GetPay() const {                // 이 달의 급여
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;            // 월 판매실적
	double bonusRatio;            // 상여금 비율
public:
	SalesWorker(const char* name, const int money, const double ratio) :PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker: public SalesWorker {
private:
	int risk;
public:
	ForeignSalesWorker(const char* name, const int salary, const double ratio, int risk): SalesWorker(name, salary, ratio), risk(risk) {

	}
	int GetRiskPay() const {
		return (int)(SalesWorker::GetPay() * (risk / 100.0));
	}
	int GetPay() const{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "riskPay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl<< endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {
	}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);
	
	handler.ShowAllSalaryInfo();
	return 0;
}