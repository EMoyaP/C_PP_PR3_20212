#ifndef __APPOINTMENT__H
#define __APPOINTMENT__H
#include "date.h"
#include "person.h"
#include "vaccine.h"

// Type that stores a vaccination appointment data
typedef struct _tAppointment {    
    // Timestamp of the vaccination appointment
    tDateTime timestamp;
    // Person
    tPerson* person;
    // Vaccine
    tVaccine* vaccine;
} tAppointment;


// Type that stores a list of vaccination appointments
typedef struct _tAppointmentData {    
    // Vaccination appointments
    tAppointment* elems;
    // Number of elements
    int count;    
} tAppointmentData;

// Initializes a vaccination appointment data list
void appointmentData_init(tAppointmentData* list);

// Insert a new vaccination appointment
void appointmentData_insert(tAppointmentData* list, tDateTime timestamp, tVaccine* vaccine, tPerson* person);

// Remove a vaccination appointment
void appointmentData_remove(tAppointmentData* list, tDateTime timestamp, tPerson* person);

// Find the first instance of a vaccination appointment for given person
int appointmentData_find(tAppointmentData list, tPerson* person, int start_pos);

// Release a vaccination appointment data list
void appointmentData_free(tAppointmentData* list);

#endif // __APPOINTMENT__H