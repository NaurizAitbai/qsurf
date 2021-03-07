#include "surf.h"


QApplication *application;


int main(int argc, char* argv[]) {
    application = new QApplication(argc, argv);

    for(int i = 1; i < argc; i++) {
        qDebug() << "Option: " << QString(argv[i]);
    }
}