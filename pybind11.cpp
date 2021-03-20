#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <model.hpp>



PYBIND11_MODULE(capy, m ) {

pybind11::class_<SIZE>(m,"SIZE",pybind11::dynamic_attr())
.def (pybind11::init<>())
.def (pybind11::init<const int &,const int &>())
.def("assign", &SIZE::operator=)
.def(pybind11::self +=  pybind11::self )
.def(pybind11::self -=  pybind11::self)
.def("fromPos",&SIZE::fromPos)
.def("inflate",&SIZE::inflate)	
.def(pybind11::self+pybind11::self)	
.def(pybind11::self-pybind11::self)	
.def("toString",&SIZE::toString);	

pybind11::class_<POS>(m,"POS",pybind11::dynamic_attr())
.def (pybind11::init<>())
.def (pybind11::init<const int &,const int &>())
.def("assign", &POS::operator=)
.def(pybind11::self +=  pybind11::self)
.def(pybind11::self -=  pybind11::self)
.def("fromSIZE",&POS::fromSize)
.def("move",pybind11::overload_cast<const int,const int>(&POS::move))
.def("move",pybind11::overload_cast<const POS &>(&POS::move))
.def(pybind11::self+pybind11::self)	
.def(pybind11::self-pybind11::self)	
.def("toString",&POS::toString);	

pybind11::class_<BaseObj>(m, "BaseObj",pybind11::dynamic_attr() )
.def (pybind11::init<>())
.def (pybind11::init<const int &,const int &, const int &,const int &>())
.def ( "getSize" , &BaseObj::getSize )
.def ( "getPos" , &BaseObj::getPos )
.def ( "setSize" , &BaseObj::setSize )
.def ( "toString", &BaseObj::toString )
.def("move",pybind11::overload_cast<const int,const int>(&BaseObj::move))
.def("move",pybind11::overload_cast<const POS &>(&BaseObj::move))
.def("inflate",&BaseObj::inflate)
.def ( "setPos" , &BaseObj::setPos );

pybind11::class_<Circle,BaseObj>(m, "Circle",pybind11::dynamic_attr() )
.def (pybind11::init<>())
.def (pybind11::init<const int &,const int &, const int &>())
.def ( "toString", &Circle::toString )
.def ( "setRadius",&Circle::setRadius );

pybind11::class_<Rectangle,BaseObj>(m, "Rectangle",pybind11::dynamic_attr() )
.def (pybind11::init<>())
.def (pybind11::init<const int &,const int &, const int &,const int &>())
.def ( "toString", &Rectangle::toString );
}

