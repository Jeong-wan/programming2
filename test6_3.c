#include<stdio.h>
unsigned long long pack_employee_data(unsigned id_no, unsigned  job_type, unsigned  salary, unsigned family);//1,9,3,6
void print_employee_data(unsigned long long employee);
int main()
{
    unsigned id_no, salary, job_type, family;
    print_employee_data(pack_employee_data(999999,999,999999999,9));
    return 0;
}
unsigned long long pack_employee_data(unsigned  id_no, unsigned  job_type, unsigned  salary, unsigned family)
{
    unsigned long long employee=0;
    employee|=(unsigned long long)id_no;
    employee|=(unsigned long long)job_type << 20;
    employee|=(unsigned long long)salary << 30;
    employee|=(unsigned long long)family << 60;
    return employee;
}
void print_employee_data(unsigned long long employee)
{
    unsigned  id_no,job_type,salary,family;
    id_no=employee & 0xFFFFF;
    job_type = (employee >> 20) & 0x3FF;
    salary=(employee >> 30 ) & 0x3FFFFFFF;
    family=(employee >> 60) & 0xF;
    printf("ID : %u\n",id_no);
    printf("작업 형태 : %u\n",job_type);
    printf("연봉: %u\n",salary);
    printf("부양가족 수 : %u\n",family);
}

