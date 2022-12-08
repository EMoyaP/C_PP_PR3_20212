#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "center.h"

// Initialize a center
void center_init(tHealthCenter* center, const char* cp) {
    // PR2 Ex 2a
 	// Check input data   
	assert(center != NULL);
	
	//Initialize appointment and stock
	appointmentData_init(&center->appointmentList);
	stockList_init(&center->stock);

    
    // Allocate the memory for the cp
    center->cp = (char*) malloc(strlen(cp) + 1);
    assert(center->cp != NULL);
    
    // Copy the cp
    strcpy(center->cp, cp);    
    
    // Initialize the stock
    stockList_init(&(center->stock));
}

// Release a center's data
void center_free(tHealthCenter* center) {
    // PR2 Ex 2b
    
    assert(center != NULL);
    
    // Release cp memory
    if(center->cp != NULL) {
        free(center->cp);
        center->cp = NULL;        
    }
    
    // Remove stock data
    stockList_free(&(center->stock));
	appointmentData_free(&(center->appointmentList));  
}

// Initialize a list of centers
void centerList_init(tHealthCenterList* list) {
    // PR2 Ex 2c
    
    assert(list != NULL);
    
    list->count = 0;
    list->first = NULL;
}

// Release a list of centers
void centerList_free(tHealthCenterList* list) {
    // PR2 Ex 2d
    tHealthCenterNode *pNode;
    tHealthCenterNode *pAux;
    
    assert(list != NULL);
    
    // Remove all elements in the list
    pNode = list->first;
    while(pNode != NULL) {
        center_free(&(pNode->elem));
        pAux = pNode;
        pNode = pNode->next;
        free(pAux);
    }
    
    list->count = 0;
    list->first = NULL;
}

// Insert a new center
void centerList_insert(tHealthCenterList* list, const char* cp) {
    // PR2 Ex 2e
    tHealthCenterNode *pNode;
    tHealthCenterNode *pAux;
    
    assert(list != NULL);
    
    if (centerList_find(list, cp) == NULL) {    
        
        // Check if insertion point is the first position
        if (list->first == NULL || strcmp(list->first->elem.cp, cp) > 0) {
            // Insert as initial position
            pAux = list->first;            
            list->first = (tHealthCenterNode*) malloc(sizeof(tHealthCenterNode));
            assert(list->first != NULL);
            list->first->next = pAux;
            center_init(&(list->first->elem), cp);
        } else {        
            // Search insertion point
            pAux = list->first;
            pNode = pAux->next;            
            while(pNode != NULL && strcmp(pNode->elem.cp, cp) > 0) {                
                pAux = pNode;
                pNode = pNode->next;         
            }
            pAux->next = (tHealthCenterNode*) malloc(sizeof(tHealthCenterNode));
            assert(pAux->next != NULL);
            pAux->next->next = pNode;
            center_init(&(pAux->next->elem), cp);
        }
        // Increase the number of elements
        list->count++;
    }
}

// Find a center
tHealthCenter* centerList_find(tHealthCenterList* list, const char* cp) {
    // PR2 Ex 2f
    
    tHealthCenterNode *pNode;    
    tHealthCenter *pCenter;    
    
    assert(list != NULL);
    
    // Search center with provided cp
    pNode = list->first;
    pCenter = NULL;
    while(pNode != NULL && pCenter == NULL) {
        if(strcmp(cp, pNode->elem.cp) == 0) {
            pCenter = &(pNode->elem);
        }        
        pNode = pNode->next;        
    }
    
    return pCenter;
}

