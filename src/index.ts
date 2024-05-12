import generator from "./generator.js";

export default class RandomString {
    static charsets =  class {
        static Standard = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        static Extended = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_=+{}[]|\";:/?.,!@#$%^&*()";
    }

    static generate(size: number, charset: string = RandomString.charsets.Standard) {
        return generator(size, charset);
    }
};
