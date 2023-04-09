#include "ui_newapp.hpp"
#include "portapack.hpp"
#include <cstring>

using namespace portapack;

namespace ui
{

    void NewAppView::focus() {
        button_helloWorld.focus();                          //default selection to button_helloWorld upon start
    }

    NewAppView::NewAppView(NavigationView &nav)             // Application Main
    {
        add_children({                                      //add pointers for widgets
            &button_helloWorld,
            &label_progress,
            &numberField_progress,
            &progressBar_progress,
            &timestamp,
        });

        progressBar_progress.set_max(PROGRESS_MAX);         //Set progressbar MAX

        button_helloWorld.on_select = [this](Button &){     //Button Logic
            if(progress < 100) {
                numberField_progress.set_value(100);        //Because numberField_progress has an on_change function,
            } else {                                        //progressBar_progress will update automatically.
                numberField_progress.set_value(0);
            }
        };

        numberField_progress.on_change = [this](int32_t v) { //When NumberField is Changed
            progress = v;
            progressBar_progress.set_value(progress);
        };

        timestamp.set_seconds_enabled(true);                 // DateTime enable seconds
    }

    void NewAppView::update()                   // Every time you get a DisplayFrameSync message this function will be ran
    {
         // Message code
    }
}