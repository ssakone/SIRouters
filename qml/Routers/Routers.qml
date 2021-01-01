import QtQuick 2.15
import Qaterial 1.0 as Qaterial

QtObject {
    id: _control
    property var _routes: {"":""}
    property var _view: {"":""}
    function push(arg) {
        for(let _route in arg.routes) {
            _control._view[arg.name]=arg.target
           _control._routes[arg.name+"/"+_route] = {route:_route,component: arg.routes[_route], target: arg.target, source: arg}
        }
    }
    function back(name) {
        let _view = _control._view[name]
        if(_view.depth!==1){
            _view.pop()
        }
    }

    function route(name,arg={}) {
        let _route = _control._routes[name]
        console.log(Object.keys(_control._routes))
        if(_route.source.enabled) {
            let component = _route.component
            _route.target.push(component, arg)
            return 0;
        } else {
            return -1;
        }
    }
}
