#ifndef __UOCVACCINE_API__H
#define __UOCVACCINE_API__H
#include <stdbool.h>
#include "error.h"
#include "csv.h"

#include "person.h"
#include "vaccine.h"
#include "center.h"
#include "stock.h"
#include "appointment.h"


// Type that stores all the application data
typedef struct _ApiData {
    ////////////////////////////////
    // PR1 EX2a
    // Population
    tPopulation population;
    // Vaccines
    tVaccineList vaccines;
    // Vaccine lots
    tVaccineLotData vaccineLots;
    ////////////////////////////////
    
    ////////////////////////////////
    // PR2 EX1a
    tHealthCenterList centers;
    ////////////////////////////////    
} tApiData;

// Get the API version information
const char* api_version();

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset);

// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry);

// Free all used memory
tApiError api_freeData(tApiData* data);

// Initialize the data structure
tApiError api_initData(tApiData* data);

// Add a new vaccines lot
tApiError api_addVaccineLot(tApiData* data, tCSVEntry entry);

// Get the number of persons registered on the application
int api_populationCount(tApiData data);

// Get the number of vaccines registered on the application
int api_vaccineCount(tApiData data);

// Get the number of vaccine lots registered on the application
int api_vaccineLotsCount(tApiData data);

// Get vaccine data
tApiError api_getVaccine(tApiData data, const char *name, tCSVEntry *entry);

// Get vaccine lot data
tApiError api_getVaccineLot(tApiData data, const char* cp, const char* vaccine, tDateTime timestamp, tCSVEntry *entry);

// Get registered vaccines
tApiError api_getVaccines(tApiData data, tCSVData *vaccines);

// Get vaccine lots
tApiError api_getVaccineLots(tApiData data, tCSVData *lots);

// Get the number of health centers registered on the application
int api_centersCount(tApiData data);

// Print center stock
void api_printCenterStock(tApiData data, const char* cp);

// Add a new vaccination appointment
tApiError api_addAppointment(tApiData* data, const char* cp, const char* document, const char* vaccine, tDateTime timestamp);

// Get person appointments
tApiError api_getPersonAppointments(tApiData data, const char* document, tCSVData *appointments);


// Check availability of a vaccine in a given health center
bool api_checkAvailability(tApiData data, const char* cp, const char* vaccine, tDate date);

// Find available vaccination appointment
tApiError api_findAppointmentAvailability(tApiData* data, const char* cp, const char* document, tDateTime timestamp);

#endif // __UOCVACCINE_API__H