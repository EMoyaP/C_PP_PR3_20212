#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "appointment.h"

// Initializes a vaccination appointment data list
void appointmentData_init(tAppointmentData* list) {
    //////////////////////////////////
    // Ex PR3 1a
    /////////////////////////////////

	// Check input data
	assert(list != NULL);

	//Initialize the list
	list->elems = NULL;
	list->count = 0;

}

// Insert a new vaccination appointment
void appointmentData_insert(tAppointmentData* list, tDateTime timestamp, tVaccine* vaccine, tPerson* person) {
    //////////////////////////////////
    // Ex PR3 1b
    /////////////////////////////////

	// Check input data
	assert(list != NULL);
	assert(vaccine != NULL);
	assert(person != NULL);  
  
	int i = 0;
	int pos = 0;
	int j = 0;
	bool inserted = false;



	// If the list is empty, just add a new element
	if (list->count == 0) {
		// Create the new element
		list->elems = ( tAppointment*) malloc(sizeof(tAppointment));
		
		// Copy the data from the source to destination
		list->elems->timestamp = timestamp;
		list->elems->person = person;
		list->elems->vaccine = vaccine;
		list->count++;
	// If the list is not empty
	} else {
    
		inserted = 0;
		while (i < list->count && !inserted) {
			if (dateTime_cmp(list->elems[i].timestamp, timestamp) == 0) {
				if (strcmp(list->elems[i].person->document, person->document) > 0) {
					list->elems = (tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment));
					for (int j = list->count; j > i; j--) {
						list->elems[j] = list->elems[j - 1];
					}
					list->elems[i].timestamp = timestamp;
					list->elems[i].vaccine = vaccine;
					list->elems[i].person = person;
					list->count++;
					inserted = true;
				}
			} else if (dateTime_cmp(list->elems[i].timestamp, timestamp) > 0) {
				list->elems = (tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment));
				for (int j = list->count; j > i; j--) {
					list->elems[j] = list->elems[j - 1];
				}
				list->elems[i].timestamp = timestamp;
				list->elems[i].vaccine = vaccine;
				list->elems[i].person = person;
				list->count++;
				inserted = true;
			}
			i++;
		}
		if (!inserted) {
			list->elems = (tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment));
			list->elems[list->count].timestamp = timestamp;
			list->elems[list->count].vaccine = vaccine;
			list->elems[list->count].person = person;
			list->count++;
		}
	}
      
    
}

// Remove a vaccination appointment
void appointmentData_remove(tAppointmentData* list, tDateTime timestamp, tPerson* person) {
    //////////////////////////////////
    // Ex PR3 1c
    /////////////////////////////////

	// Check input data
	assert(list != NULL);
	assert(person != NULL);

	int i = 0;
    bool removed = false;

	//Erase the appointment from the list
	while (i < list->count && !removed) {
		if (dateTime_cmp(list->elems[i].timestamp, timestamp) == 0 &&
				strcmp(list->elems[i].person->document, person->document) == 0) {
			for (int j = i; j < list->count - 1; j++) {
				list->elems[j] = list->elems[j + 1];
			}
			list->count--;
			removed = true;
		}
		i++;
	}

}

// Find the first instance of a vaccination appointment for given person
int appointmentData_find(tAppointmentData list, tPerson* person, int start_pos) {
    //////////////////////////////////
    // Ex PR3 1d
    /////////////////////////////////   

	// Check input data
	assert(person != NULL);

	//recursive function that is searching for the first instance of a vaccination appointment for a given person
	if (start_pos==list.count) return(-1);
	else if (list.elems[start_pos].person->document == person->document) return(start_pos);
	else return(appointmentData_find(list, person, start_pos+1)); 
 
}

// Release a vaccination appointment data list
void appointmentData_free(tAppointmentData* list) {
    //////////////////////////////////
    // Ex PR3 1e
    /////////////////////////////////

	// Check input data
	assert(list != NULL);

	//Freeing the memory allocated for the list
    if (list->count > 0) {
        free(list->elems);
        list->elems = NULL;
        list->count = 0;
    }
	
}
