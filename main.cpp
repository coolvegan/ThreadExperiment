#include <iostream>
#include <gtkmm.h>
#include <thread>
#include "LedController.h"

int main(int argc, char *argv[]) {

    LedController ledController;

    std::thread t2(ledController);

    std::thread t3([&]{
        do {

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            ledController.setLEDState(true, false, false, true);
        } while(true);
    });

    std::thread t4([&]{
        do {
            ledController.setLEDState(!ledController.getled1(), true, false, true);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } while(true);//ist gewollt//
    });

    std::thread t5([&]{
        do {
            ledController.setLEDState(true, false, true, true);
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            ledController.setLEDState(true, false, !ledController.getled3(), false);
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        } while(true);//ist gewollt
    });


    auto app = Gtk::Main("GTK");
    Gtk::Window window;
    window.set_title("LED Simulation");
    window.set_default_size(100,50);
    Gtk::HBox hbox;
    Gtk::Grid grid;
    grid.set_column_spacing(5);
    Gtk::Label label1("");
    Gtk::Label label2("");
    Gtk::Label label3("");
    Gtk::Label label4("");
    Gtk::Label label5("LED'Sim");


    std::thread t1 ([&]{
        do {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            if (ledController.getled1()) {
                label1.override_background_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
            } else {
                label1.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
            }
            if (ledController.getled2()) {
                label2.override_background_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
            } else {
                label2.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
            }
            if (ledController.getled3()) {
                label3.override_background_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
            } else {
                label3.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
            }
            if (ledController.getled4()) {
                label4.override_background_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
            } else {
                label4.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
            }

        } while(true);//ist gewollt.
    });

    label1.set_size_request(60,60);
    label2.set_size_request(60,60);
    label3.set_size_request(60,60);
    label4.set_size_request(60,60);
    label1.override_background_color(Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
    label2.override_background_color(Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
    label3.override_background_color(Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
    label4.override_background_color(Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
    grid.attach(label5,0,0,4,1);
    grid.attach(label1,0,1,1,1);
    grid.attach(label2,1,1,1,1);
    grid.attach(label3,2,1,1,1);
    grid.attach(label4,3,1,1,1);

    hbox.add(grid);
    window.add(hbox);
    hbox.show_all();
    Gtk::Main::run(window);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}