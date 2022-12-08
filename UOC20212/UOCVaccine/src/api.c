#include <stdio.h>
#include <assert.h>
#include "csv.h"
#include "api.h"
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "vaccine.h"


#define FILE_READ_BUFFER_SIZE 2048

// Get the API version information
const char* api_version() {
    return "UOC PP 20212";
}

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset) {
    tApiError error;
    FILE *fin;    
    char buffer[FILE_READ_BUFFER_SIZE];
    tCSVEntry entry;
    
    // Check input data
    assert( data != NULL );
    assert(filename != NULL);
    
    // Reset current data    
    if (reset) {
        // Remove previous information
        error = api_freeData(data);
        if (error != E_SUCCESS) {
            return error;
        }
        
        // Initialize the data
        error = api_initData(data);
        if (error != E_SUCCESS) {
            return error;
        }
    }

    // Open the input file
    fin = fopen(filename, "r");
    if (fin == NULL) {
        return E_FILE_NOT_FOUND;
    }
    
    // Read file line by line
    while (fgets(buffer, FILE_READ_BUFFER_SIZE, fin)) {
        // Remove new line character     
        buffer[strcspn(buffer, "\n\r")] = '\0';
        
        csv_initEntry(&entry);
        csv_parseEntry(&entry, buffer, NULL);
        // Add this new entry to the api Data
        error = api_addDataEntry(data, entry);
        if (error != E_SUCCESS) {
            return error;
        }
        csv_freeEntry(&entry);
    }
    
    fclose(fin);
    
    return E_SUCCESS;
}

// Initialize the data structure
tApiError api_initData(tApiData* data) {            
    //////////////////////////////////
    // Ex PR1 2b
    /////////////////////////////////
    // Check input data structure
    assert(data != NULL);
    
    // Initialize data structures
    population_init(&(data->population));
    vaccineList_init(&(data->vaccines));
    vaccineLotData_init(&(data->vaccineLots));
    
    
    //////////////////////////////////
    // Ex PR1 2b
    /////////////////////////////////
    centerList_init(&(data->centers));
    /////////////////////////////////
    
    return E_SUCCESS;
    
    /////////////////////////////////
    // return E_NOT_IMPLEMENTED;
}

// Add a new vaccines lot
tApiError api_addVaccineLot(tApiData* data, tCSVEntry entry) {
    //////////////////////////////////
    // Ex PR1 2c
    /////////////////////////////////
    tVaccine vaccine;
    tVaccineLot lot;
    tVaccine *pVaccine;
    
    //////////////////////////////////
    // Ex PR2 3c
    /////////////////////////////////
    tHealthCenter *pCenter;
    /////////////////////////////////
    
    // Check input data structure
    assert(data != NULL);
    
    // Check the entry type
    if (strcmp(csv_getType(&entry), "VACCINE_LOT") != 0) {
        return E_INVALID_ENTRY_TYPE;
    }
    
    // Check the number of fields
    if(csv_numFields(entry) != 7) {
        return E_INVALID_ENTRY_FORMAT;
    }
    
    // Parse the entry
    vaccineLot_parse(&vaccine, &lot, entry);
    
    // Check if vaccine exists
    pVaccine = vaccineList_find(data->vaccines, vaccine.name);
    if (pVaccine == NULL) {
        // Add the vaccine
        vaccineList_insert(&(data->vaccines), vaccine);
        pVaccine = vaccineList_find(data->vaccines, vaccine.name);
    }
    assert(pVaccine != NULL);
    
    // Assign this vaccine to the lot
    lot.vaccine = pVaccine;
    
    // Add the lot to the data
    vaccineLotData_add(&(data->vaccineLots), lot);
    
    
    //////////////////////////////////
    // Ex PR2 3c
    /////////////////////////////////
    pCenter = centerList_find(&(data->centers), lot.cp);
    if (pCenter == NULL) {
        centerList_insert(&(data->centers), lot.cp);
        pCenter = centerList_find(&(data->centers), lot.cp);
    }
    stockList_update(&(pCenter->stock), lot.timestamp.date, lot.vaccine, lot.doses);
    /////////////////////////////////
    
    
    // Release temporal data
    vaccine_free(&vaccine);
    vaccineLot_free(&lot);
    
    return E_SUCCESS;
    
    /////////////////////////////////
    
    //return E_NOT_IMPLEMENTED;
}

// Get the number of persons registered on the application
int api_populationCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2d
    /////////////////////////////////
    return population_len(data.population);
    /////////////////////////////////
    //return -1;
}

// Get the number of vaccines registered on the application
int api_vaccineCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2d
    /////////////////////////////////
    return vaccineList_len(data.vaccines);    
    /////////////////////////////////
    //return -1;
}

// Get the number of vaccine lots registered on the application
int api_vaccineLotsCount(tApiData data) {
    //////////////////////////////////
    // Ex PR1 2d
    /////////////////////////////////
    return vaccineLotData_len(data.vaccineLots);
    /////////////////////////////////
    //return -1;
}


// Free all used memory
tApiError api_freeData(tApiData* data) {
    //////////////////////////////////
    // Ex PR1 2e
    /////////////////////////////////
    population_free(&(data->population));
    vaccineLotData_free(&(data->vaccineLots));
    vaccineList_free(&(data->vaccines));
    
    //////////////////////////////////
    // Ex PR2 3d
    /////////////////////////////////
    centerList_free(&(data->centers));
    /////////////////////////////////
    
    return E_SUCCESS;
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED;
}


// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry) { 
    //////////////////////////////////
    // Ex PR1 2f
    /////////////////////////////////
    int personIdx;
    tPerson person;
        
    assert(data != NULL);
    
    // Initialize the person object
    person_init(&person);
        
    if (strcmp(csv_getType(&entry), "PERSON") == 0) {
        // Check the number of fields
        if(csv_numFields(entry) != 7) {
            return E_INVALID_ENTRY_FORMAT;
        }
        // Parse the data
        person_parse(&person, entry);
        
        // Check if this person already exists
        if (population_find(data->population, person.document) >= 0) {
            // Release person object
            person_free(&person);
            return E_DUPLICATED_PERSON;
        }
        
        // Add the new person
        population_add(&(data->population), person);
        
        // Release person object
        person_free(&person);
        
    } else if (strcmp(csv_getType(&entry), "VACCINE_LOT") == 0) {
        return api_addVaccineLot(data, entry);        
    } else {
        return E_INVALID_ENTRY_TYPE;
    }
    return E_SUCCESS;
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED;
}

// Get vaccine data
tApiError api_getVaccine(tApiData data, const char *name, tCSVEntry *entry) {
    //////////////////////////////////
    // Ex PR1 3a
    /////////////////////////////////
    char buffer[2048];
    tVaccine* vaccine = NULL;
        
    assert(name != NULL);
    assert(entry != NULL);
    
    // Search vaccine
    vaccine = vaccineList_find(data.vaccines, name);
    
    if (vaccine == NULL) {
        return E_VACCINE_NOT_FOUND;
    }
    
    // Print data in the buffer
    sprintf(buffer, "%s;%d;%d", vaccine->name, vaccine->required, vaccine->days);
    
    // Initialize the output structure
    csv_initEntry(entry);
    csv_parseEntry(entry, buffer, "VACCINE");
    
    return E_SUCCESS;
    
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED; 
}

// Get vaccine lot data
tApiError api_getVaccineLot(tApiData data, const char* cp, const char* vaccine, tDateTime timestamp, tCSVEntry *entry) {
    //////////////////////////////////
    // Ex PR1 3b
    /////////////////////////////////
    char buffer[2048];
    int idx;
        
    assert(cp != NULL);
    assert(vaccine != NULL);
    assert(entry != NULL);
    
    // Search vaccine
    idx = vaccineLotData_find(data.vaccineLots, cp, vaccine, timestamp);
        
    if (idx < 0) {
        return E_LOT_NOT_FOUND;
    }
    
    // Print data in the buffer
    sprintf(buffer, "%02d/%02d/%04d;%02d:%02d;%s;%s;%d;%d;%d", 
        data.vaccineLots.elems[idx].timestamp.date.day, data.vaccineLots.elems[idx].timestamp.date.month, data.vaccineLots.elems[idx].timestamp.date.year,
        data.vaccineLots.elems[idx].timestamp.time.hour, data.vaccineLots.elems[idx].timestamp.time.minutes,
        data.vaccineLots.elems[idx].cp,
        data.vaccineLots.elems[idx].vaccine->name, data.vaccineLots.elems[idx].vaccine->required, data.vaccineLots.elems[idx].vaccine->days,
        data.vaccineLots.elems[idx].doses
    );
    
    // Initialize the output structure
    csv_initEntry(entry);
    csv_parseEntry(entry, buffer, "VACCINE_LOT");
    
    return E_SUCCESS;
    
    
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED; 
}

// Get registered vaccines
tApiError api_getVaccines(tApiData data, tCSVData *vaccines) {
    //////////////////////////////////
    // Ex PR1 3c
    /////////////////////////////////
    char buffer[2048];
    tVaccineNode *pNode = NULL;
    
    csv_init(vaccines);
        
    pNode = data.vaccines.first;
    while(pNode != NULL) {
        sprintf(buffer, "%s;%d;%d", pNode->vaccine.name, pNode->vaccine.required, pNode->vaccine.days);
        csv_addStrEntry(vaccines, buffer, "VACCINE");
        pNode = pNode->next;
    }    
    
    return E_SUCCESS;
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED; 
}

// Get vaccine lots
tApiError api_getVaccineLots(tApiData data, tCSVData *lots) {
    //////////////////////////////////
    // Ex PR1 3d
    /////////////////////////////////
    char buffer[2048];
    int i;
    
    csv_init(lots);
    for(i=0; i<data.vaccineLots.count ; i++) {
        sprintf(buffer, "%02d/%02d/%04d;%02d:%02d;%s;%s;%d;%d;%d", 
            data.vaccineLots.elems[i].timestamp.date.day, 
			data.vaccineLots.elems[i].timestamp.date.month, 
			data.vaccineLots.elems[i].timestamp.date.year,
            data.vaccineLots.elems[i].timestamp.time.hour, 
			data.vaccineLots.elems[i].timestamp.time.minutes,
            data.vaccineLots.elems[i].cp,
            data.vaccineLots.elems[i].vaccine->name, 
			data.vaccineLots.elems[i].vaccine->required, 
			data.vaccineLots.elems[i].vaccine->days,
            data.vaccineLots.elems[i].doses
        );
        csv_addStrEntry(lots, buffer, "VACCINE_LOT");
    }
    
    return E_SUCCESS;
    
    /////////////////////////////////
    //return E_NOT_IMPLEMENTED; 
}

// Get the number of health centers registered on the application
int api_centersCount(tApiData data) {
    //////////////////////////////////
    // Ex PR2 3e
    
    return data.centers.count;
    
    /////////////////////////////////
    // return -1;
}

// Print center stock
void api_printCenterStock(tApiData data, const char* cp) {
    tHealthCenter *pCenter;
    
    // Check input data    
    assert(cp != NULL);
    
    // Search the health center
    pCenter = centerList_find(&(data.centers), cp);
    if (pCenter != NULL) {
        printf("==============================\n");
        printf("STOCK FOR CENTER %s\n", cp);
        printf("==============================\n");
        stockList_print(pCenter->stock);
        printf("==============================\n\n");
    }    
}

// Add a new vaccination appointment
tApiError api_addAppointment(tApiData* data, const char* cp, const char* document, const char* vaccine, tDateTime timestamp) {
    //////////////////////////////////
    // Ex PR3 2c
    /////////////////////////////////

	// Check input data  
	assert(data != NULL);
	assert(cp != NULL);
	assert(document != NULL);
	assert(vaccine != NULL);
  
	tDateTime date;
	tHealthCenter* pCenter = NULL;
	tVaccine* pVaccine = NULL;
	tPerson * pPerson = NULL;
	int i = -1;
	int j = 0;
  
	//Finding the center in the list
	pCenter=centerList_find(&data->centers, cp);
	if (pCenter==NULL){
		return E_HEALTH_CENTER_NOT_FOUND;
	}

	//Finding the position of the person in the population
	i = population_find(data->population, document);

	if (i == -1){
		return E_PERSON_NOT_FOUND;
	}
  
    //Finding the vaccine in the list
	pVaccine = vaccineList_find(data->vaccines, vaccine);
  
	if (pVaccine==NULL){
		return E_VACCINE_NOT_FOUND;
	}

	//Creating a pointer to the person at index i in the population array
	pPerson = &(data->population.elems[i]);
	
	//Inserting the appointment into the appointment list
    appointmentData_insert(&(pCenter->appointmentList), timestamp, pVaccine, pPerson);

	//Adding the required number of appointments to the appointment list
    if (pVaccine->required > 1) {
        for(int j=1; j<pVaccine->required; j++) {
            dateTime_addDay(&timestamp, pVaccine->days);
            appointmentData_insert(&(pCenter->appointmentList), timestamp, pVaccine, pPerson);
        }
    }

    return E_SUCCESS;
}

// Get person appointments
tApiError api_getPersonAppointments(tApiData data, const char* document, tCSVData *appointments) {
    //////////////////////////////////
    // Ex PR3 2d
    /////////////////////////////////

	// Check input data  
	assert(document != NULL);
	assert(appointments != NULL);

	int i = 0;
    tPerson *pPerson = NULL;
    tHealthCenter *healthCenter = NULL;
    int j = 0;
	char buffer[2048];    
   
    //Check non existing person
    i = population_find(data.population, document);
    if (i == -1) {
        return E_PERSON_NOT_FOUND;
    }
    
    //Creating a pointer to the person at the position i in the population
    pPerson = &(data.population.elems[i]);

    //Finding the center that the person is currently in
    healthCenter = centerList_find(&(data.centers), pPerson->cp);

    //Search the person appointments and add the appointments to the csv file
	j = appointmentData_find(healthCenter->appointmentList, pPerson, j);
    while (j != -1) {
		sprintf(buffer,"%02u/%02u/%04u;%02u:%02u;%s;%s",
			healthCenter->appointmentList.elems[j].timestamp.date.day,
			healthCenter->appointmentList.elems[j].timestamp.date.month,
			healthCenter->appointmentList.elems[j].timestamp.date.year,
			healthCenter->appointmentList.elems[j].timestamp.time.hour,
			healthCenter->appointmentList.elems[j].timestamp.time.minutes,
			healthCenter->cp,
			healthCenter->appointmentList.elems[j].vaccine->name);
		csv_addStrEntry(appointments, buffer, "APPOINTMENT");
		j++;
		j = appointmentData_find(healthCenter->appointmentList, pPerson, j);
    }

    return E_SUCCESS;
	//return E_NOT_IMPLEMENTED; 
}

// Check availability of a vaccine in a given health center
bool api_checkAvailability(tApiData data, const char* cp, const char* vaccine, tDate date) {
    //////////////////////////////////
    // Ex PR3 3a
    /////////////////////////////////

	// Check input data    
    assert(cp != NULL);
    assert(vaccine != NULL);

	tHealthCenter *healthCenter = NULL;
    tVaccine *pVaccine = NULL;
	int numDosses =0; 

    // Search the healthcenter
    healthCenter = centerList_find(&(data.centers), cp);
    if (healthCenter == NULL) {
        return false;
    }
    
    // Search the vaccine
    pVaccine = vaccineList_find(data.vaccines, vaccine);
    if (pVaccine == NULL) {
        return false;
    }

	//Checking if there are enough doses of a vaccine in the stock of a center to vaccinate
    if (pVaccine->required == 1) {
        numDosses = stockList_getDoses(&(healthCenter->stock), date, pVaccine);
        if (numDosses >= 1) {
            return true;
        } else {
            return false;
        }
    } else {
        for (int i = 1; i <= pVaccine->required; i++) {
            numDosses = stockList_getDoses(&(healthCenter->stock), date, pVaccine);
            if (numDosses < i) {
                return false;
            }
            date_addDay(&date, pVaccine->days);
        }
        return true;
    }
}

// Find available vaccination appointment
tApiError api_findAppointmentAvailability(tApiData* data, const char* cp, const char* document, tDateTime timestamp) {
    //////////////////////////////////
    // Ex PR3 3b
    /////////////////////////////////

	// Check input data    
	assert(data != NULL);
	assert(cp != NULL);
	assert(document != NULL);

	int i;
	int week = 7;
	tPerson *pPerson = NULL;
	tHealthCenter *healthCenter = NULL;
	tDateTime auxTime;
	tVaccineNode *nVaccine = NULL;

	//Finding the position of the person in the population
	i = population_find(data->population, document);
	if (i == -1) {
		return E_PERSON_NOT_FOUND;
	}

	//Creating a pointer to the person at the position finded on the population
	pPerson = &(data->population.elems[i]);

	//Finding the center in the list
	healthCenter = centerList_find(&(data->centers), cp);
	if (healthCenter == NULL) {
		return E_HEALTH_CENTER_NOT_FOUND;
	}

	//Checking if the person is already in the center
	if (appointmentData_find(healthCenter->appointmentList, pPerson, 0) != -1) {
        return E_DUPLICATED_PERSON;
	}
	
	//Checking if there is an available appointment for the next 7 days
	for (i = 0; i < week; i++) {
		auxTime = timestamp;
		dateTime_addDay(&auxTime, i);
		nVaccine = data->vaccines.first;
		while (nVaccine != NULL) {
			if (api_checkAvailability(*data, cp, nVaccine->vaccine.name, auxTime.date)) {
				api_addAppointment(data, cp, document, nVaccine->vaccine.name, auxTime);
				return E_SUCCESS;
			}
			nVaccine = nVaccine->next;
		}
	}

	// Checking if there is any vaccine available in the stock for the next 7 days. 
	// If there is, it adds an appointment for the first vaccine found
	dateTime_addDay(&timestamp, week);
	for (i = 0; i < week; i++) {
		auxTime = timestamp;
		dateTime_addDay(&auxTime, i);
		nVaccine = data->vaccines.first;
		while (nVaccine != NULL) {
			int numVaccines = stockList_getDoses(&(healthCenter->stock), auxTime.date, &(nVaccine->vaccine));
			if (numVaccines) {
				api_addAppointment(data, cp, document, nVaccine->vaccine.name, auxTime);
				return E_SUCCESS;
			}
			nVaccine = nVaccine->next;
		}
	}

	return E_NO_VACCINES;
	//return E_NOT_IMPLEMENTED; 
}
