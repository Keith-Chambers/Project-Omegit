#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

//#include "guicontrollayer.h"
#include "ditalkbackendcontroller.h"
#include "ditalkguilayer.h"
#include "util.h"
#include "ditalkstate.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");
	
    DitalkBackendController backend(&engine);
    DitalkGuiLayer guiLayer(backend);
    DitalkState::declareQML();

    engine.rootContext()->setContextProperty("BackEnd", &guiLayer);
	
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
