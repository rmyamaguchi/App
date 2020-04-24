
#include <stdlib.h>
#include "App.h"
#include "AppEvent.h"

struct AppDeref
{
    void *param;
    struct Event next;
};

App createApp(void *param, EventPtr init)
{
    App app = malloc(sizeof(*app));
    if (app != NULL) {
        app->param = param;
        app->next = *init;
    }
    return app;
}

void deleteApp(App app)
{
    free(app);
}

void *getParam(App app)
{
    return app->param;
}

EventPtr getNextEvent(App app)
{
    EventPtr next = app->next.action(app);
    if (next != NULL)
        app->next = *next;
    return next;
}