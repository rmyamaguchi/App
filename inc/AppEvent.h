#ifndef APPEVENT_H
#define APPEVENT_H

#include "App.h"

#define FALLBACK 0
#define ANY 10

/**
 * @brief Function attribute to decide the order to put events in the events 
 * array.
 * Priorities indicate the preferable position of an event on a first come,
 * first served basis.
 * The closer PRIORITY is to 0, the highest priority the function will have: 
 * the events will be put in the chosen arrays closer to the 0 position
 * @note QUEUE functions with equal PRIORITY will put the events in alphabetical 
 * order based on their respective source file names.
 * 
 */
#define QUEUE(PRIORITY) __attribute__((constructor((PRIORITY) + 101)))

/**
 * @brief Macro to create an Event struct with name NAME and action as 
 * directly defined through the second argument
 * @note The App argument for the action function is always named app.
 * 
 */
#define EVENT(NAME, ...) \
    static EventPtr action##NAME(App app) __VA_ARGS__ \
    static struct Event NAME = {.name = #NAME, .action = action##NAME};

typedef EventPtr (*Action)(App);

struct Event
{
    char *name;
    Action action;
};

#endif /* APPEVENT_H */