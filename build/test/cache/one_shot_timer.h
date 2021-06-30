















typedef void (*callback_t)(void*);



typedef struct one_shot_timer_t{

    callback_t callback;

    void* context;

    uint8_t current_time;

    uint8_t stop_time;

}one_shot_timer_t;



void one_shot_timer_init(one_shot_timer_t* timer, uint8_t stop, callback_t callback, void* context);

void one_shot_timer_time_did_change(one_shot_timer_t* timer);

void one_shot_timer_get_time(one_shot_timer_t* timer);
