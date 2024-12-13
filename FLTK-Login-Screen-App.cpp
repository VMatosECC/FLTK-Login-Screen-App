//A Login screen (User & Password)
//FLTK documentation https://www.fltk.org/doc-1.4/index.html
//FLTK download https://www.fltk.org/software.php
// Better if you use => vcpkg install fltk:x64-windows
// You may use the FLUID UI Designer (although it is not necessary) 
// to create the UI and then export the code to C++ (looks 1980s style)
// Try QT Creator for a more modern UI design
//-----------------------------------------------------------------------------
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/fl_ask.H>
#include <string>

// Callback to handle Login button click
void login_callback(Fl_Widget* widget, void* data) {
    Fl_Input* username_input = (Fl_Input*)data;
    const char* username = username_input->value();
    // Here you can add code to handle login logic, e.g., validate credentials
    fl_alert("Welcome, %s!", username);
}

// Callback to handle Clear button click
void clear_callback(Fl_Widget* widget, void* data) {
    Fl_Input** inputs = (Fl_Input**)data;
    inputs[0]->value(""); // Clear username input
    inputs[1]->value(""); // Clear password input
}

// Callback to handle Exit button click
void exit_callback(Fl_Widget* widget, void* data) {
    exit(0); // Exit the application
}

int main() {
    // Initialize shared image support
    Fl::lock();
    Fl_Shared_Image::get("image1.png");

    // Create main window
    Fl_Window* window = new Fl_Window(400, 300, "ECC Login Window");

    // Add an image to the UI
    Fl_PNG_Image* image = new Fl_PNG_Image("image2.png");
    Fl_Box* image_box = new Fl_Box(150, 10, 70, 70);
    image_box->image(image);

    // Add username label and input box
    Fl_Box* username_label = new Fl_Box(50, 120, 100, 25, "Username:");
    Fl_Input* username_input = new Fl_Input(150, 120, 200, 25);

    // Add password label and input box
    Fl_Box* password_label = new Fl_Box(50, 160, 100, 25, "Password:");
    Fl_Input* password_input = new Fl_Input(150, 160, 200, 25);
    password_input->type(FL_SECRET_INPUT); // Mask password input

    // Add buttons for Login, Clear, and Exit
    Fl_Button* login_button = new Fl_Button(50, 210, 100, 30, "Login");
    login_button->callback(login_callback, username_input);

    Fl_Input* inputs[2] = { username_input, password_input };
    Fl_Button* clear_button = new Fl_Button(160, 210, 100, 30, "Clear");
    clear_button->callback(clear_callback, inputs);

    Fl_Button* exit_button = new Fl_Button(270, 210, 100, 30, "Exit");
    exit_button->callback(exit_callback);

    window->end();
    window->show();

    return Fl::run();
}