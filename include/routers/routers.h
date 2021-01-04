#ifndef ROUTERS_H
#define ROUTERS_H

#include <QObject>
#include <QtQml>
class routers : public QObject
{
    Q_OBJECT
public:
    explicit routers(QObject *parent = nullptr);
    static QObject *qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine) {

        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        engine->addImportPath("qrc:/Routers/");
        return new routers;
    }
     static QObject* engine(QQmlEngine *engine, QJSEngine *scriptEngine);
    static void init();
private:
    QQmlEngine *m_engine;

};

#endif // ROUTERS_H
