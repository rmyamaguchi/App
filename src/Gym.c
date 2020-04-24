
#include "Gym.h"

#include "Work.h"
#include "Home.h"

#define MAX_EVENTS 10

static struct Event events[MAX_EVENTS] = {};
static unsigned int size = 0;

/**
 * @brief Put an event in the Gym list of events
 */
void putGymEvent(EventPtr event)
{
    if (size < MAX_EVENTS)
        events[size++] = *event;
}

/**
 * @brief Gym event
 */
EVENT(Gym, {
    /* 
    do somethings and 
        return the next event;
    else */
        return &events[FALLBACK];
})

/**
 * @brief Append Gym event to Home and Work array of events
 * @note The priority level is last
 */
static void QUEUE(ANY) pany(void)
{
    putHomeEvent(&Gym); /* Gym as a event of Home */
    putWorkEvent(&Gym); /* Gym as a event of Work */
}