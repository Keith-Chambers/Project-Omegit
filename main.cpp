#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "guicontrollayer.h"
#include "util.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
	
	GuiControlLayer guiControlLayer(Util::readJson(QString("C:/libs/client_info.json")), &app);

    engine.rootContext()->setContextProperty("BackEnd", &guiControlLayer);
	
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
