#ifndef APP_H
#define APP_H

typedef struct Event *EventPtr;
typedef struct AppDeref *App;

extern EventPtr entryPoint;

App createApp(void *param, EventPtr init);
void deleteApp(App);

void *getParam(App app);
EventPtr getNextEvent(App app);

#endif /* APP_H */