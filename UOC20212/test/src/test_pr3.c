#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "test_pr3.h"
#include "api.h"

// Run all tests for PR1
bool run_pr3(tTestSuite* test_suite, const char* input) {
    bool ok = true;
    tTestSection* section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR3", "Tests for PR3 exercices");

    section = testSuite_getSection(test_suite, "PR3");
    assert(section != NULL);

    ok = run_pr3_ex1(section, input);
    ok = run_pr3_ex2(section, input) && ok;
    ok = run_pr3_ex3(section, input) && ok;

    return ok;
}

// Run all tests for Exercice 1 of PR3
bool run_pr3_ex1(tTestSection* test_section, const char* input) {            
    tPerson person1, person2;
    tVaccine vModerna, vPfizer;
    tCSVEntry entry;
    tAppointmentData data;
    tDateTime dt1, dt2;
    int pos;
    bool passed = true;
    bool failed = false;
    bool fail_all = false;
    
    
    // Initialize sample persons
    csv_initEntry(&entry);
    person_init(&person1);
    csv_parseEntry(&entry, "87654321K;John;Smith;john.smith@example.com;My street, 25;08001;30/12/1980", "PERSON");
    person_parse(&person1, entry);
    csv_freeEntry(&entry);    
        
    csv_initEntry(&entry);    
    person_init(&person2);
    csv_parseEntry(&entry, "98765432J;Jane;Doe;jane.doe@example.com;Her street, 5;08500;12/01/1995", "PERSON");
    person_parse(&person2, entry);
    csv_freeEntry(&entry);
        
    // Initialize sample vaccines
    vPfizer.name = "PFIZER";
    vPfizer.days = 21;
    vPfizer.required = 2;
    vModerna.name = "MODERNA";
    vModerna.days = 0;
    vModerna.required = 1; 
    
    /////////////////////////////
    /////  PR3 EX1 TEST 1  //////
    /////////////////////////////    
    start_test(test_section, "PR3_EX1_1", "Initialize appointment data");
    appointmentData_init(&data);
    if (data.count != 0 || data.elems != NULL) {
        failed = true;
        fail_all = true;
        passed = false;
    }
    end_test(test_section, "PR3_EX1_1", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 2  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_2", "Insert a vaccination appointment");    
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        appointmentData_insert(&data, dt1, &vPfizer, &person1);        
        if (data.count != 1 || data.elems[0].person != &person1 || data.elems[0].vaccine != &vPfizer || !dateTime_equals(data.elems[0].timestamp, dt1)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_2", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 3  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_3", "Insert an earlier second vaccination appointment");    
    if (!fail_all) {
        dateTime_parse(&dt2, "03/05/2022", "15:24");
        appointmentData_insert(&data, dt2, &vPfizer, &person2);        
        if (data.count != 2 || data.elems[0].person != &person2 || data.elems[0].vaccine != &vPfizer || !dateTime_equals(data.elems[0].timestamp, dt2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_3", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 4  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_4", "Insert another vaccination appointment");    
    if (!fail_all) {
        dateTime_parse(&dt2, "03/05/2022", "15:24");
        appointmentData_insert(&data, dt2, &vModerna, &person1);        
        if (data.count != 3 || data.elems[0].person != &person1 || data.elems[0].vaccine != &vModerna || !dateTime_equals(data.elems[0].timestamp, dt2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_4", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 5  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_5", "Remove last inserted vaccination appointment");    
    if (!fail_all) {
        dateTime_parse(&dt2, "03/05/2022", "15:24");
        appointmentData_remove(&data, dt2, &person1);
        if (data.count != 2 || data.elems[0].person != &person2 || data.elems[0].vaccine != &vPfizer || !dateTime_equals(data.elems[0].timestamp, dt2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_5", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 6  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_6", "Remove previously removed vaccination appointment");    
    if (!fail_all) {
        dateTime_parse(&dt2, "03/05/2022", "15:24");
        appointmentData_remove(&data, dt2, &person1);
        if (data.count != 2 || data.elems[0].person != &person2 || data.elems[0].vaccine != &vPfizer || !dateTime_equals(data.elems[0].timestamp, dt2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_6", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 7  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_7", "Remove first added appointment");    
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        appointmentData_remove(&data, dt1, &person1);
        if (data.count != 1 || data.elems[0].person != &person2 || data.elems[0].vaccine != &vPfizer || !dateTime_equals(data.elems[0].timestamp, dt2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_7", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 8  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_8", "Search for an existing appointment");    
    if (!fail_all) {        
        pos = appointmentData_find(data, &person2, 0);
        if (pos != 0) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_8", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 9  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_9", "Search for a non existing appointment");    
    if (!fail_all) {        
        pos = appointmentData_find(data, &person1, 0);
        if (pos != -1) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_9", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 10  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_10", "Search for an existing appointment but invalid start position");    
    if (!fail_all) {        
        pos = appointmentData_find(data, &person2, 1);
        if (pos != -1) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_10", !failed);
    
    /////////////////////////////
    /////  PR3 EX1 TEST 11  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX1_11", "Free all appointments");
    if (!fail_all) {        
        appointmentData_free(&data);
        if(person1.document == NULL || strcmp(person1.document, "87654321K") != 0) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX1_11", !failed);
    
    // Release appointment data
    appointmentData_free(&data);
    
    return passed;
}


// Run all tests for Exercice 2 of PR3
bool run_pr3_ex2(tTestSection* test_section, const char* input) {                
    tApiData data;
    tApiError error;
    tCSVData csv_report;
    tDateTime dt1, dt2;
    bool passed = true;
    bool failed = false;
    bool fail_all = false;
    
    // Initialize the data    
    error = api_initData(&data);
    if (error != E_SUCCESS) {        
        passed = false; 
        failed = true;
        fail_all = true;
    } 
    
    // Load the test data    
    if (!fail_all) {
        error = api_loadData(&data, input, true);
        if (error != E_SUCCESS) {        
            passed = false; 
            failed = true;
            fail_all = true;
        }        
    }    
    
    /////////////////////////////
    /////  PR3 EX2 TEST 1  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX2_1", "Add an appointment for a non-existing person");
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        error = api_addAppointment(&data, "08500", "67654329J", "MODERNA", dt1);
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX2_1", !failed);
    
    /////////////////////////////
    /////  PR3 EX2 TEST 2  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX2_2", "Add an appointment for a non-existing vaccine");
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        error = api_addAppointment(&data, "08500", "98765432J", "NON-EXITING", dt1);
        if (error != E_VACCINE_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX2_2", !failed);
    
    /////////////////////////////
    /////  PR3 EX2 TEST 3  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX2_3", "Add an appointment for a non-existing center");
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        error = api_addAppointment(&data, "08509", "98765432J", "MODERNA", dt1);
        if (error != E_HEALTH_CENTER_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX2_3", !failed);

    /////////////////////////////
    /////  PR3 EX2 TEST 4  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX2_4", "Get appointments for a non-existing person");
    if (!fail_all) {        
        csv_init(&csv_report);
        error = api_getPersonAppointments(data, "67654329J", &csv_report);
        csv_free(&csv_report);
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX2_4", !failed);    
    
    /////////////////////////////
    /////  PR3 EX2 TEST 5  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX2_5", "Get appointments for a valid person without appointments");
    if (!fail_all) {        
        csv_init(&csv_report);
        error = api_getPersonAppointments(data, "98765432J", &csv_report);        
        if (error != E_SUCCESS || csv_report.count !=0) {
            failed = true;
            fail_all = true;
            passed = false;
        }
        csv_free(&csv_report);
    }
    end_test(test_section, "PR3_EX2_5", !failed);    
    
    /////////////////////////////
    /////  PR3 EX2 TEST 6  //////
    /////////////////////////////        
    failed = fail_all;
    start_test(test_section, "PR3_EX2_6", "Create a valid appointment for a one shot vaccine");
    if (!fail_all) {
        dateTime_parse(&dt1, "03/05/2022", "15:25");
        error = api_addAppointment(&data, "08500", "98765432J", "MODERNA", dt1);       
        if (error != E_SUCCESS) {
            failed = true;
            fail_all = true;
            passed = false;
        } else {
            // Check report
            csv_init(&csv_report);
            error = api_getPersonAppointments(data, "98765432J", &csv_report);
            if (error != E_SUCCESS || csv_report.count != 1) {
                failed = true;
                fail_all = true;
                passed = false;
            } 
            
            csv_free(&csv_report);            
        }
    }
    end_test(test_section, "PR3_EX2_6", !failed);
    
    /////////////////////////////
    /////  PR3 EX2 TEST 7  //////
    /////////////////////////////        
    failed = fail_all;
    start_test(test_section, "PR3_EX2_7", "Create a valid appointment for a multi-shot vaccine");
    if (!fail_all) {
        dateTime_parse(&dt2, "13/05/2022", "10:15");
        error = api_addAppointment(&data, "08001", "87654321K", "PFIZER", dt2);       
        if (error != E_SUCCESS) {
            failed = true;
            fail_all = true;
            passed = false;
        } else {
            csv_init(&csv_report);
            error = api_getPersonAppointments(data, "87654321K", &csv_report);
            if (error != E_SUCCESS || csv_report.count != 2) {
                failed = true;
                fail_all = true;
                passed = false;
            }            
        }
    }
    end_test(test_section, "PR3_EX2_7", !failed);
    
    // Release all data
    api_freeData(&data);
    
    return passed;
}

// Run all tests for Exercice 3 of PR3
bool run_pr3_ex3(tTestSection* test_section, const char* input) {                
    tApiData data;
    tApiError error;
    tDate date1, date2;
    tDateTime dt1, dt2;
    bool passed = true;
    bool failed = false;
    bool fail_all = false;
    
    // Initialize the data    
    error = api_initData(&data);
    if (error != E_SUCCESS) {        
        passed = false; 
        failed = true;
        fail_all = true;
    } 
    
    // Load the test data    
    if (!fail_all) {
        error = api_loadData(&data, input, true);
        if (error != E_SUCCESS) {        
            passed = false; 
            failed = true;
            fail_all = true;
        }        
    }    
    
    /////////////////////////////
    /////  PR3 EX3 TEST 1  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_1", "Check availability for a one-shot vaccine with availability");
    if (!fail_all) {
        date_parse(&date1, "05/04/2022");
        if (!api_checkAvailability(data, "08001", "MODERNA", date1)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_1", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 2  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_2", "Check availability for a two-shots vaccine with availability");
    if (!fail_all) {
        date_parse(&date2, "01/04/2022");
        if (!api_checkAvailability(data, "08001", "PFIZER", date2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_2", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 3  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_3", "Check availability for a one-shot vaccine without availability");
    if (!fail_all) {
        date_parse(&date1, "01/04/2022");
        if (api_checkAvailability(data, "08001", "MODERNA", date1)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_3", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 4  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_4", "Check availability for a two-shots vaccine without availability I");
    if (!fail_all) {
        date_parse(&date2, "30/03/2022");
        if (api_checkAvailability(data, "08500", "PFIZER", date2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_4", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 5  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_5", "Check availability for a two-shots vaccine without availability II");
    if (!fail_all) {
        date_parse(&date2, "02/04/2022");
        if (api_checkAvailability(data, "08500", "PFIZER", date2)) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_5", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 6  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_6", "Find appointment availability for a non existing person");
    if (!fail_all) {        
        dateTime_parse(&dt1, "02/04/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08001", "65432187G", dt1);
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_6", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 7  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_7", "Find appointment availability for a non existing center");
    if (!fail_all) {        
        dateTime_parse(&dt1, "02/04/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08002", "87654321K", dt1);
        if (error != E_HEALTH_CENTER_NOT_FOUND) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_7", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 8  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_8", "Find appointment availability for a period without vaccine stock");
    if (!fail_all) {        
        dateTime_parse(&dt1, "02/01/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08001", "87654321K", dt1);
        if (error != E_NO_VACCINES) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_8", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 9  //////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_9", "Find appointment availability for existing one-shot vaccine");
    if (!fail_all) {        
        dateTime_parse(&dt1, "06/04/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08500", "87654321K", dt1);
        if (error != E_SUCCESS) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_9", !failed);
            
    /////////////////////////////
    /////  PR3 EX3 TEST 10  /////
    /////////////////////////////   
    failed = fail_all;
    start_test(test_section, "PR3_EX3_10", "Request availability again for the same person and center");
    if (!fail_all) {        
        dateTime_parse(&dt1, "02/01/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08500", "87654321K", dt1);
        if (error != E_DUPLICATED_PERSON) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_10", !failed);

    /////////////////////////////
    /////  PR3 EX3 TEST 11  /////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_11", "Find appointment availability for existing two-shot vaccine");
    if (!fail_all) {        
        dateTime_parse(&dt1, "02/04/2022", "10:15");
        error = api_findAppointmentAvailability(&data, "08001", "98765432J", dt1);
        if (error != E_SUCCESS) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_11", !failed);
    
    /////////////////////////////
    /////  PR3 EX3 TEST 12  /////
    /////////////////////////////    
    failed = fail_all;
    start_test(test_section, "PR3_EX3_12", "Find appointment availability for existing first dose of two-shot vaccine I");
    if (!fail_all) {        
        dateTime_parse(&dt2, "06/04/2022", "11:15");
        error = api_findAppointmentAvailability(&data, "08500", "76543210P", dt2);
        if (error != E_SUCCESS) {
            failed = true;
            fail_all = true;
            passed = false;
        }
    }
    end_test(test_section, "PR3_EX3_12", !failed);
    
    // Release all data
    api_freeData(&data);
    
    return passed;    
}