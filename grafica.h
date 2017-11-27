//
// Created by Alexandru Chirea on 27.11.2017.
//

#ifndef HUFFMANCODING_GRAFICA_H
#define HUFFMANCODING_GRAFICA_H

#endif //HUFFMANCODING_GRAFICA_H

//Pentru instalarea GTK rulati "brew install gtk+3"

#include <gtk/gtk.h>

void startFereastra (int argc, char *argv[]) {
    GtkWidget *window;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_show  (window);

    gtk_main ();

    return;
}
