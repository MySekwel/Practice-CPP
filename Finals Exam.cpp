//========================================
// - {Module Dependencies}
#include <iostream>
//========================================

//========================================
// - {Constants}
#define MAX_EMPLOYEES       100
#define MAX_WEEKS           4
//========================================

//========================================
// - {Employee Identifier}
int
    employee_id = 1,
    employee_position[MAX_EMPLOYEES];
//========================================

//========================================
// - {Employee Information}
float
    employee_pay[MAX_EMPLOYEES],
    employee_rate[MAX_EMPLOYEES],
    employee_ot_rate[MAX_EMPLOYEES],
    employee_gsis[MAX_EMPLOYEES],
    employee_philhealth[MAX_EMPLOYEES],
    employee_pagibig[MAX_EMPLOYEES],
    employee_deduction[MAX_EMPLOYEES],
    employee_ut_hours[MAX_EMPLOYEES];
//========================================

//========================================
// - {Employee Total}
float
    employee_additional_pay[MAX_EMPLOYEES],
    employee_ot_pay[MAX_EMPLOYEES],
    employee_ut_pay[MAX_EMPLOYEES],
    employee_gross_pay[MAX_EMPLOYEES],
    employee_net_pay[MAX_EMPLOYEES];
//========================================

//========================================
// - {Weekday}
int
    week[4],
    total_week_hours[MAX_EMPLOYEES];
//========================================

//========================================
// - {Border Abstraction}
void border(){
    std::cout<<"=======================================\n";
}
//========================================

bool running = true;
int response;

int main(){
    while(running){
        border();
        std::cout<< "\t\tPAYROLL\n";
        border();
        std::cout<< "Employee #" << employee_id << std::endl << std::endl;
        
        std::cout<< "Employee Type:\n";
        std::cout<< "\t 1 - Instructor\n";
        std::cout<< "\t 2 - Assistant Professor\n";
        std::cout<< "\t 3 - Associate Professor\n";
        std::cout<< "\t 4 - Professor\n";
        goto_employee:
        std::cout<< "Press (1, 2, 3, or 4): "; std::cin>> employee_position[employee_id];
        //========================================
        // - {Input Processing}
        //========================================
        if(employee_position[employee_id] == 1){
            employee_pay[employee_id] = 25000.00;
            employee_rate[employee_id] = 142.05;
            employee_ot_rate[employee_id] = 156.26;
            employee_gsis[employee_id] = 2250.00;
            employee_philhealth[employee_id] = 375.00;
            employee_pagibig[employee_id] = 100.00;
        }
        else if(employee_position[employee_id] == 2){
            employee_pay[employee_id] = 30000.00;
            employee_rate[employee_id] = 170.45;
            employee_ot_rate[employee_id] = 187.50;
            employee_gsis[employee_id] = 2700.00;
            employee_philhealth[employee_id] = 450.00;
            employee_pagibig[employee_id] = 100.00;
        }
        else if(employee_position[employee_id] == 3){
            employee_pay[employee_id] = 35000.00;
            employee_rate[employee_id] = 198.86;
            employee_ot_rate[employee_id] = 218.75;
            employee_gsis[employee_id] = 3150.00;
            employee_philhealth[employee_id] = 525.00;
            employee_pagibig[employee_id] = 100.00;
        }
        else if(employee_position[employee_id] == 4){
            employee_pay[employee_id] = 40000.00;
            employee_rate[employee_id] = 227.27;
            employee_ot_rate[employee_id] = 250.00;
            employee_gsis[employee_id] = 3600.00;
            employee_philhealth[employee_id] = 600.00;
            employee_pagibig[employee_id] = 100.00;
        }
        else{
            std::cout<< "INVALID INPUT.\t";
            goto goto_employee;
        }

        border();
        std::cout<< "TOTAL HOURS\n";
        for(int i = 0; i < MAX_WEEKS; i++){
            std::cout<< "\tWeek " << i + 1 << ": "; std::cin>> week[i];
        }

        //========================================
        // - {Salary Processing}
        //========================================
        // ---------
        // Gross Pay
        // ---------
        for(int i = 0; i < MAX_WEEKS; i++){
            if(week[i] > 40){
                employee_additional_pay[employee_id] += (week[i] - 40) * employee_ot_rate[employee_id];
            }
        }
        employee_gross_pay[employee_id] =
            employee_additional_pay[employee_id] +
            employee_pay[employee_id];
        // -------
        // Net Pay
        // -------
        for(int i = 0; i < MAX_WEEKS; i++){
            if(week[i] < 40){
                employee_ut_hours[employee_id] += 40 - week[i];
            }
        }
        employee_ut_pay[employee_id] = employee_rate[employee_id] * employee_ut_hours[employee_id];
        employee_deduction[employee_id] =
            employee_ut_pay[employee_id] +
            employee_gsis[employee_id] +
            employee_philhealth[employee_id] +
            employee_pagibig[employee_id];
        employee_net_pay[employee_id] = employee_gross_pay[employee_id] - employee_deduction[employee_id];
        
        //========================================
        // - {Gross Pay Output}
        //========================================
        border();
        std::cout<< "GROSS PAY\n";
        std::cout<< "\tBasic Pay: " << employee_pay[employee_id] << std::endl;
        std::cout<< "\tOvertime Pay: " << employee_additional_pay[employee_id] << std::endl;

        //========================================
        // - {Deduction Output}
        //========================================
        border();
        std::cout<< "DEDUCTIONS\n";
        std::cout<< "\tUndertime Pay: " << employee_ut_pay[employee_id] << std::endl;
        std::cout<< "\tGSIS: " << employee_gsis[employee_id] << std::endl;
        std::cout<< "\tPhilHealth: " << employee_philhealth[employee_id] << std::endl;
        std::cout<< "\tPAGIBIG: " << employee_pagibig[employee_id] << std::endl;
        //========================================
        // - {Net Pay Output}
        //========================================
        border();
        std::cout<< "NETPAY: " << employee_net_pay[employee_id] << std::endl;
        border();
        std::cout<< std::endl << std::endl;
        std::cout<< "Input Again?"; std::cin>>response;
        if(response == 1){
            employee_id++;
            system("cls");
        }
        else{
            system("cls");
            std::cout<< "==============================================================\n";
            std::cout<< "\t\t\tPAYROLL SUMMARY\n";
            std::cout<< "==============================================================\n";
            std::cout<< "EMP.ID\tGROSS PAY\tTOTAL DEDUCTIONS\tNET PAY\n";
            std::cout<< "==============================================================\n";
            for(int i = 0; i < MAX_EMPLOYEES; i++){
                if(employee_position[i]){
                    std::cout<< i << "\t" << employee_gross_pay[i] << "\t" << employee_deduction[i] << "\t" << employee_net_pay[i] << std::endl;
                }
            }
            std::cout<< "==============================================================\n";
            running = false;
        }
    }
    system("pause");
}
