# Random String
- This is a simple thing for generate random strings in NodeJS

## Four modes:
- Basic (Basic string on the range of A-Za-z0-9)
- Medium (Basic with few more things)
- Advanced (You mean random?)
- Custom (Require charset)

## How to use:
```
// ECMAScript
import randomString from "@dviih/randomstring";
// CommonJS
const randomString = require("@dviih/randomstring");

// Usage
new randomString({length: <length>}).<mode>();

// Usage (Custom)
new randomString({length: <length>, charset: "<charset>"}).custom();
```

Made by @Dviih
