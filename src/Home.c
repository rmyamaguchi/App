#include <stdlib.h>
#include "Home.h"

#include "Work.h"
#include "Gym.h"

#define MAX_EVENTS 10

static struct Event events[MAX_EVENTS] = {};
static unsigned int size = 0;

/**
 * @brief Put an event in the Home list of events
 */
void putHomeEvent(EventPtr event)
{
    if (size < MAX_EVENTS)
        events[size++] = *event;
}


/**
 * @brief Home event
 */
EVENT(Home, {
    unsigned int sel;
    unsigned char opt = 0;
    unsigned char indexes[size];
    char *strings[size];
    /* generate 2 arrays of Event strings and actions */
    for (int i = FALLBACK + 1; i < FALLBACK + size && &events[i] != NULL; i++)
    {
        indexes[opt] = i;
        strings[opt] = events[i].name;
        opt++;
    }
    /* 
    Show menu using these arrays;
    if selection is valid
        return &events[indexes[selection]];
    else */
        return &events[FALLBACK];
})

/**
 * @brief Quit event as a pseudo state
 */
EVENT(Quit, {
    /*
    Show Quit confirmation message;
    if confirmed
        return NULL;
    else */
        return &Home;
})

/**
 * @brief Append Home events as fallbacks to its dependencies array of events
 * @note The priority level is 0 (highest)
 * 
 */
static void QUEUE(FALLBACK) pfallback(void)
{
    EventPtr entryPoint = &Home;

    putHomeEvent(&Quit); /* Quit as fallback event of Home */
    putWorkEvent(&Home); /* Home as fallback event of Work */
    putGymEvent(&Home);  /* Home as fallback event of Gym */
}