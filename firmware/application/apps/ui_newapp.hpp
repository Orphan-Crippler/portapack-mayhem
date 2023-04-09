#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"
#include "string_format.hpp"
#include "file.hpp"
#include "sd_card.hpp"

// Define a constant
#define PROGRESS_MAX 100

namespace ui
{
    class NewAppView : public View                                // App class declaration
    {
    public:

        // Public delcarations
        void focus() override;

        NewAppView(NavigationView &nav);                          // App class init function declaration
        std::string title() const override {
            return "New App"; //App title
            };

    private:

        // Private declarations
        void update();                                            // Function declaration
        MessageHandlerRegistration message_handler_update{        // Example, not required: MessageHandlerRegistration class
            Message::ID::DisplayFrameSync,                        // relays messages to your app code from baseband. Every time you 
            [this](const Message *const) {                        // get a  DisplayFrameSync message the update() function will
                this->update();                                   // be triggered.  
            }
        };

        //Variables
        uint32_t progress = 0;

        //Widgets
        //Note: Usable screen space is 240x304px
        //Note: Each char takes up 8x8px so you can multiply
        //      the amount of spaces and rows you want by 8.
        //      This gives you 30x38 char

        Button button_helloWorld{
            {70, 128, 100, 24}, //Coordinates are in {X, Y, Width, Height}
            "Hello World!" //Title
        };

        LiveDateTime timestamp {
            {6*8, 22*8, 19*8, 20} //Coordinates & Dimensions
        };

        Labels label_progress {
            {{8*8, 33*8},
            "Progress:      %",
            Color::light_grey()}
        };

        NumberField numberField_progress {
            {18*8, 33*8},               //Coordinates
            3,                          //Length of number3
            {0, PROGRESS_MAX},          //Range
            1,                          //step
            '0',                        //Fill Char
            false                       //loop?
        };

        ProgressBar progressBar_progress {
            {2*8, 35*8, 208, 16}, //Coordinates and Dimensions
        };
    };
} 