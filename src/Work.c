

#include "Work.h"

#include "Home.h"
#include "Gym.h"

#define MAX_EVENTS 10

static struct Event events[MAX_EVENTS] = {};
static unsigned int size = 0;

/**
 * @brief Put an event in the Work list of events
 */
void putWorkEvent(EventPtr event)
{
    if (size < MAX_EVENTS)
        events[size++] = *event;
}

/**
 * @brief Work event
 */
EVENT(Work, {
    /* 
    do somethings and 
        return the next event;
    else */
        return &events[FALLBACK];
})

/**
 * @brief Append Work event to Home array of events
 * @note The priority level is 1
 * 
 */
static void QUEUE(1) p1(void)
{
    putHomeEvent(&Work); /* Work as a event 1 of Home */
}

/**
 * @brief Append Work event to Gym array of events
 * @note The priority level is last
 * 
 */
static void QUEUE(ANY) pany(void)
{
    putGymEvent(&Work);  /* Work as a event of Gym */
}