#include "surf.h"


QApplication *application;


class WebEngineView: public QWebEngineView {
public:
    WebEngineView() : WebEngineView("", true) {}

    WebEngineView(QString url) : WebEngineView(url, true) {}

    WebEngineView(QString url, bool visible) {
        QObject::connect(page(), &QWebEnginePage::windowCloseRequested, [&]() {
            qDebug() << "Window close requested";
            close();
        });

        if(!url.isEmpty()) {
            load(QUrl(url));
        }

        if(visible) {
            show();
        }

        setAttribute(Qt::WA_DeleteOnClose, true);
    }
};


int main(int argc, char* argv[]) {
    application = new QApplication(argc, argv);

    for(int i = 1; i < argc; i++) {
        qDebug() << "Option: " << QString(argv[i]);
    }

    WebEngineView *view = new WebEngineView(argv[1]);

    return application->exec();
}