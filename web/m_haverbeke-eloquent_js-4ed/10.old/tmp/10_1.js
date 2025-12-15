console.log("[Module 10_1] =>");

import {dayName} from "./dayname.js";
let now = new Date();
console.log(`Today is ${dayName(now.getDay())}`);

import {dayName as nomDeJour} from "./dayname.js";
console.log(nomDeJour(3));

import seasonNames from "./seasonname.js";
console.log(seasonNames);

import * as dayName2 from "./dayname.js";
console.log(dayName2.dayName(3));

import * as iniPackage from "./ini.js";
console.log(iniPackage.decode("x = 10\ny = 20"));