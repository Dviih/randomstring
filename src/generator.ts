import {createRequire} from "node:module";

const require = createRequire(import.meta.url);

export default require("../build/Release/generator.node").generate as (size: number, charset: string) => string;
