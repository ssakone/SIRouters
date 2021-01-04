#include <routers/routers.h>

routers::routers(QObject *parent) : QObject(parent)
{

}

QObject *routers::engine(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    return new routers();
}
void routers::init()
{
    Q_INIT_RESOURCE(SIRouters);
    qmlRegisterSingletonType<routers>("si.Routerss", 1, 0, "SIRouters", &routers::engine);

}
