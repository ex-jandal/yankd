#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  app.setOrganizationDomain("me.abujandal");
  app.setApplicationName("Clipy");

  QQmlApplicationEngine engine;

  const QUrl url(QString::fromUtf8("qrc:/main.qml"));

  QObject::connect(
    &engine, &QQmlApplicationEngine::objectCreated, &app,
    [url](QObject *obj, const QUrl &objUrl) {
      if (!obj && url == objUrl)
        QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection
  );

  engine.load(url);

  return app.exec();
}
