//
// Created by flawless on 07.03.19.
//

#include "Led.h"
#include <iostream>


Led::Led(){

    set_title("LED Sim");
    set_default_size(100,50);
    Gtk::HBox hbox;

    Gtk::Grid grid;

    grid.set_column_spacing(5);

    Gtk::Label label1("");
    Gtk::Label label2("");
    Gtk::Label label3("");
    Gtk::Label label4("");
    Gtk::Label label5("LED'S");
    label1.set_size_request(10,10);
    label2.set_size_request(10,10);
    label3.set_size_request(10,10);
    label4.set_size_request(10,10);

    label1.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
    label2.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
    label3.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
    label4.override_background_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);


    grid.attach(label5,0,0,4,1);
    grid.attach(label1,0,1,1,1);
    grid.attach(label2,1,1,1,1);
    grid.attach(label3,2,1,1,1);
    grid.attach(label4,3,1,1,1);


    hbox.add(grid);
    add(hbox);
    hbox.show_all();

}