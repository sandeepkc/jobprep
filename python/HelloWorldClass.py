class Employee:
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1

    def displayEmployee(self):
        print ("Name :" + self.name + ", Salary :",  self.salary)

    def displayNum(self):
        print ("Employee count: ",  Employee.empCount)

emp1 = Employee("Test1", 343)
emp2 = Employee("Test2", 123)

emp1.displayEmployee()
emp2.displayEmployee()

emp1.displayNum()
