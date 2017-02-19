const modules = require("./api.js");
modules._sayHi();
modules.ccall("sayHi");
console.log(modules._daysInWeek());
console.log(modules.Pointer_stringify());