/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int dfs(Employee* me, array<Employee*,2001>& employeeMap) {
        int ret = me->importance;
        for(int subId : me->subordinates) {
            Employee* sub = employeeMap[subId];
            ret += dfs(sub, employeeMap);
        }
        return ret;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        array<Employee*,2001> employeeMap;
        for(auto employee : employees) {
            employeeMap[employee->id] = employee;
        }
        return dfs(employeeMap[id], employeeMap);
    }
};
